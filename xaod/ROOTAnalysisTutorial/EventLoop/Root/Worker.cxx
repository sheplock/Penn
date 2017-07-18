//          Copyright Nils Krumnack 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (krumnack@iastate.edu) for bug
// reports, feature suggestions, praise and complaints.


//
// includes
//

#include <EventLoop/Worker.h>

#include <EventLoop/Algorithm.h>
#include <EventLoop/D3PDReaderSvc.h>
#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/TEventSvc.h>
#include <RootCore/Packages.h>
#include <RootCoreUtils/Assert.h>
#include <RootCoreUtils/RootUtils.h>
#include <RootCoreUtils/ThrowMsg.h>
#include <SampleHandler/DiskWriter.h>
#include <SampleHandler/MetaFields.h>
#include <SampleHandler/MetaObject.h>
#include <TFile.h>
#include <TH1.h>
#include <TStopwatch.h>
#include <TTree.h>
#include <iostream>
#include <memory>

//
// method implementations
//

namespace EL
{
  namespace
  {
    void checkStatus (const StatusCode& status, const char *function)
    {
      if (status != StatusCode::SUCCESS)
	RCU_THROW_MSG (std::string (function) + " returned StatusCode::FAILURE");
    }

    struct MyWriter : public SH::DiskWriter
    {
      /// description: this is a custom writer for the old-school
      ///   drivers that don't use an actual writer

    public:
      TFile *m_file;

      explicit MyWriter (TFile *val_file)
	: m_file (val_file)
      {}

      ~MyWriter ()
      {
	if (m_file != 0)
	  close();
      }

      std::string getPath () const
      {
	return "";
      }

      TFile *getFile ()
      {
	RCU_REQUIRE2_SOFT (m_file != 0, "file already closed");
	return m_file;
      }

      void doClose ()
      {
	RCU_REQUIRE2_SOFT (m_file != 0, "file already closed");
	m_file->Write ();
	m_file->Close ();
	m_file = 0;
      }
    };
  }



  void Worker ::
  testInvariant () const
  {
    RCU_INVARIANT (this != 0);
    RCU_INVARIANT (m_metaData != 0);
    RCU_INVARIANT (m_output != 0);
    RCU_INVARIANT (m_eventCount != 0 || m_initState == AIS_NONE || m_initState == AIS_NEW);
    RCU_INVARIANT (m_runTime != 0 || m_initState == AIS_NONE || m_initState == AIS_NEW);
    RCU_INVARIANT (m_fileExecuted != 0 || m_initState == AIS_NONE);
    RCU_INVARIANT (m_initState <= AIS_NONE);
    RCU_INVARIANT (m_execState <= AES_NONE);
    RCU_INVARIANT (m_stopwatch != nullptr);
    for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
    {
      RCU_INVARIANT (m_algs[iter] != 0);
      RCU_INVARIANT (m_algs[iter]->wk() == this);
    }
    for (outputFilesIter iter = m_outputFiles.begin(),
	   end = m_outputFiles.end(); iter != end; ++ iter)
    {
      RCU_INVARIANT (iter->second != 0);
    }
  }



  Worker ::
  ~Worker ()
  {
    RCU_DESTROY_INVARIANT (this);

    for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
      delete m_algs[iter];
    for (outputFilesIter iter = m_outputFiles.begin(),
	   end = m_outputFiles.end(); iter != end; ++ iter)
    {
      delete iter->second;
    }

    std::cout << "worker finished:" << std::endl;
    m_stopwatch->Stop ();
    m_stopwatch->Print ();
  }



  void Worker ::
  addOutput (TObject *output_swallow)
  {
    std::auto_ptr<TObject> output (output_swallow);

    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE_SOFT (output_swallow != 0);

    RCU::SetDirectory (output_swallow, 0);
    m_output->Add (output.release());

    TH1 *hist = dynamic_cast<TH1*> (output_swallow);
    if (hist)
      m_outputHistMap[hist->GetName()] = hist;
  }



  void Worker ::
  addOutputList (const std::string& name, TObject *output_swallow)
  {
    std::auto_ptr<TObject> output (output_swallow);

    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE_SOFT (output_swallow != 0);

    RCU::SetDirectory (output_swallow, 0);
    std::auto_ptr<TList> list (new TList);
    list->SetName (name.c_str());
    list->Add (output.release());
    addOutput (list.release());
  }



  TH1 *Worker ::
  getOutputHist (const std::string& name) const
  {
    RCU_READ_INVARIANT (this);

    OutputHistMapIter iter = m_outputHistMap.find (name);
    if (iter == m_outputHistMap.end())
      RCU_THROW_MSG ("unknown output histogram: " + name);
    RCU_ASSERT (iter->second != 0);
    return iter->second;
  }



  TFile *Worker ::
  getOutputFile (const std::string& label) const
  {
    RCU_READ_INVARIANT (this);
    TFile *result = getOutputFileNull (label);
    if (result == 0)
      RCU_THROW_MSG ("no output dataset defined with label: " + label);
    return result;
  }



  TFile *Worker ::
  getOutputFileNull (const std::string& label) const
  {
    RCU_READ_INVARIANT (this);
    outputFilesIter iter = m_outputFiles.find (label);
    if (iter == m_outputFiles.end())
      return 0;
    return iter->second->file();
  }



  const SH::MetaObject *Worker ::
  metaData () const
  {
    RCU_READ_INVARIANT (this);
    return m_metaData;
  }



  TTree *Worker ::
  tree () const
  {
    RCU_READ_INVARIANT (this);
    return m_tree;
  }



  Long64_t Worker ::
  treeEntry () const
  {
    RCU_READ_INVARIANT (this);
    return m_treeEntry;
  }



  TFile *Worker ::
  inputFile () const
  {
    RCU_READ_INVARIANT (this);
    return m_inputFile;
  }



  std::string Worker ::
  inputFileName () const
  {
    // no invariant used
    std::string path = inputFile()->GetName();
    auto split = path.rfind ('/');
    if (split != std::string::npos)
      return path.substr (split + 1);
    else
      return path;
  }



  TTree *Worker ::
  triggerConfig () const
  {
    RCU_READ_INVARIANT (this);
    return dynamic_cast<TTree*>(inputFile()->Get("physicsMeta/TrigConfTree"));
  }



  D3PDReader::Event *Worker ::
  d3pdreader () const
  {
    RCU_READ_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_D3PDReader
    D3PDReaderSvc *const svc
      = dynamic_cast<D3PDReaderSvc*>(getAlg (D3PDReaderSvc::name));
    if (svc == 0)
      RCU_THROW_MSG ("Job not configured for D3PDReader support");
    return svc->event();
#else
    RCU_THROW_MSG ("EventLoop package not compiled with D3PDReader support");
    return 0; //compiler dummy
#endif    
  }



  xAOD::TEvent *Worker ::
  xaodEvent () const
  {
    RCU_READ_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_xAODRootAccess
    TEventSvc *const svc
      = dynamic_cast<TEventSvc*>(getAlg (TEventSvc::name));
    if (svc == 0)
      RCU_THROW_MSG ("Job not configured for xAOD support");
    return svc->event();
#else
    RCU_THROW_MSG ("EventLoop package not compiled with xAOD support");
    return 0; //compiler dummy
#endif    
  }



  xAOD::TStore *Worker ::
  xaodStore () const
  {
    RCU_READ_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_xAODRootAccess
    TEventSvc *const svc
      = dynamic_cast<TEventSvc*>(getAlg (TEventSvc::name));
    if (svc == 0)
      RCU_THROW_MSG ("Job not configured for xAOD support");
    return svc->store();
#else
    RCU_THROW_MSG ("EventLoop package not compiled with xAOD support");
    return 0; //compiler dummy
#endif    
  }



  bool Worker ::
  hasD3pdreader () const
  {
    RCU_READ_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_D3PDReader
    D3PDReaderSvc *const svc
      = dynamic_cast<D3PDReaderSvc*>(getAlg (D3PDReaderSvc::name));
    return svc != 0;
#else
    return false;
#endif    
  }



  Algorithm *Worker ::
  getAlg (const std::string& name) const
  {
    RCU_READ_INVARIANT (this);
    for (algsIter alg = m_algs.begin(), end = m_algs.end(); alg != end; ++ alg)
    {
      if ((*alg)->hasName (name))
	return *alg;
    }
    return 0;
  }



  void Worker ::
  skipEvent ()
  {
    RCU_CHANGE_INVARIANT (this);
    m_skipEvent = true;
  }



  Worker ::
  Worker (const SH::MetaObject *val_metaData, TList *output)
    : m_metaData (val_metaData), m_inputFile (0), m_tree (0), m_treeEntry (0),
      m_output (output), m_eventCount (0), m_stopwatch (new TStopwatch),
      m_initState (AIS_NONE), m_execState (AES_NONE)
  {
    RCU_REQUIRE (val_metaData != 0);
    RCU_REQUIRE (output != 0);

    m_stopwatch->Start ();

    RCU_NEW_INVARIANT (this);

    std::unique_ptr<TList> fileExecuted (new TList);
    fileExecuted->SetName ("EventLoop_FileExecuted");
    addOutput (m_fileExecuted = fileExecuted.release());
    m_initState = AIS_NEW;
    m_execState = AES_BLANK;
  }



  void Worker ::
  addOutputFile (const std::string& label, TFile *file_swallow)
  {
    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE (file_swallow != 0);

    addOutputWriter (label, new MyWriter (file_swallow));
  }



  void Worker ::
  addOutputWriter (const std::string& label, SH::DiskWriter *writer_swallow)
  {
    std::auto_ptr<SH::DiskWriter> writer (writer_swallow);

    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE (writer_swallow != 0);

    if (m_outputFiles.find (label) != m_outputFiles.end())
      RCU_THROW_MSG ("output file already defined for label: " + label);
    m_outputFiles[label] = writer.get();
    writer.release();
  }



  void Worker ::
  addAlg (Algorithm *alg_swallow)
  {
    std::auto_ptr<Algorithm> alg (alg_swallow);

    RCU_READ_INVARIANT (this);
    RCU_REQUIRE (alg_swallow != 0);

    alg->m_wk = this;
    m_algs.push_back (alg_swallow);
    alg.release ();
  }



  void Worker ::
  algsChangeInput ()
  {
    RCU_CHANGE_INVARIANT (this);

    changeAlgState (AIS_NONE, AES_BLANK, VALID_FILE);
    changeAlgState (AIS_NONE, AES_FILE_EXECUTED, VALID_FILE);
  }



  void Worker ::
  algsExecute ()
  {
    RCU_CHANGE_INVARIANT (this);

    changeAlgState (AIS_INITIALIZED, AES_INPUT_CHANGED, VALID_EVENT);

    m_runTime->Fill (2);

    m_execState = AES_NONE;
    m_skipEvent = false;
    std::size_t iter = 0;
    for (std::size_t end = m_algs.size();
	 iter != end && !m_skipEvent; ++ iter)
    {
      m_eventCount->Fill (iter);
      checkStatus (m_algs[iter]->execute (), "Algorithm::execute");
    }
    /// rationale: this will make sure that the post-processing runs
    ///   for all algorithms for which the regular processing was run
    RCU_ASSERT (iter <= m_algs.size());
    for (std::size_t jter = 0, end = iter;
	 jter != end && !m_skipEvent; ++ jter)
      checkStatus (m_algs[jter]->postExecute (), "Algorithm::postExecute");
    if (!m_skipEvent)
      m_eventCount->Fill (m_algs.size());
    m_execState = AES_INPUT_CHANGED;
  }



  void Worker ::
  algsEndOfFile ()
  {
    RCU_CHANGE_INVARIANT (this);

    changeAlgState (AIS_NONE, AES_BLANK, VALID_NONE);
  }



  void Worker ::
  algsFinalize ()
  {
    RCU_CHANGE_INVARIANT (this);

    changeAlgState (AIS_HIST_FINALIZED, AES_NONE, VALID_NONE);
  }



  void Worker ::
  setInputFile (TFile *val_inputFile)
  {
    RCU_CHANGE_INVARIANT (this);

    TTree *tree = 0;
    if (val_inputFile != 0)
    {
      tree = dynamic_cast<TTree*>(val_inputFile->Get (m_metaData->castString (SH::MetaFields::treeName, SH::MetaFields::treeName_default).c_str()));
      if (tree)
      {
	double cacheSize = m_metaData->castDouble (Job::optCacheSize, 0);
	if (cacheSize > 0)
	  tree->SetCacheSize (cacheSize);
	double cacheLearnEntries = m_metaData->castDouble (Job::optCacheLearnEntries, 0);
	if (cacheLearnEntries > 0)
	  tree->SetCacheLearnEntries (cacheLearnEntries);
      }
    }
    m_inputFile = val_inputFile;
    m_tree = tree;
  }



  void Worker ::
  setTreeProofOnly (TTree *val_tree)
  {
    RCU_CHANGE_INVARIANT (this);
    if (val_tree)
      m_inputFile = val_tree->GetCurrentFile ();
    else
      m_inputFile = 0;
    m_tree = val_tree;
  }



  Long64_t Worker ::
  inputFileNumEntries () const
  {
    RCU_READ_INVARIANT (this);
    RCU_REQUIRE (inputFile() != 0);

    if (m_tree != 0)
      return m_tree->GetEntries();
    else
      return 0;
  }



  void Worker ::
  treeEntry (Long64_t val_treeEntry)
  {
    RCU_CHANGE_INVARIANT (this);
    m_treeEntry = val_treeEntry;
  }



  void Worker ::
  changeAlgState (const AlgInitState targetInit,
		  const AlgExecState targetExec,
		  const InputState inputState)
  {
    if (m_initState == AIS_NONE || m_execState == AES_NONE)
    {
      RCU_THROW_MSG ("trying to change state, after algorithm error");
      return; // compiler dummy
    }

    if (targetInit != m_initState) switch (targetInit)
    {
    case AIS_NEW:
      RCU_THROW_MSG ("invalid state change request");
      return; //compiler dummy
    case AIS_HIST_INITIALIZED:
      switch (m_initState)
      {
      case AIS_NEW:
	m_initState = AIS_NONE;
	addOutput (m_eventCount = new TH1D ("EventLoop_EventCount", "number of events per algorithm", m_algs.size()+1, 0, m_algs.size()+1));
	addOutput (m_runTime = new TH1D ("EventLoop_RunTime", "worker run-time summary", 5, 0, 5));
	m_runTime->Fill (0);
	m_runTime->GetXaxis()->SetBinLabel (1, "jobs");
	m_runTime->GetXaxis()->SetBinLabel (2, "files");
	m_runTime->GetXaxis()->SetBinLabel (3, "events");
	m_runTime->GetXaxis()->SetBinLabel (4, "cpu time");
	m_runTime->GetXaxis()->SetBinLabel (5, "real time");
	for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	  checkStatus (m_algs[iter]->histInitialize (), "Algorithm::histInitialize");
	m_initState = AIS_HIST_INITIALIZED;
	changeAlgState (targetInit, targetExec, inputState);
	break;
      case AIS_INITIALIZED:
      case AIS_FINALIZED:
      case AIS_HIST_FINALIZED:
	RCU_THROW_MSG ("invalid state change request");
	return; //compiler dummy
      case AIS_HIST_INITIALIZED:
      case AIS_NONE:
	RCU_ASSERT0 ("should not get here");
	return; //compiler dummy
      }
      break;
    case AIS_INITIALIZED:
      if (inputState < VALID_EVENT)
      {
	RCU_ASSERT0 ("invalid state change request");
	return; //compiler dummy
      }
      switch (m_initState)
      {
      case AIS_NEW:
      case AIS_HIST_INITIALIZED:
	changeAlgState (AIS_HIST_INITIALIZED, AES_INPUT_CHANGED, inputState);
	m_initState = AIS_NONE;
	for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	  checkStatus (m_algs[iter]->initialize (), "Algorithm::initialize");
	m_initState = AIS_INITIALIZED;
	break;
      case AIS_FINALIZED:
      case AIS_HIST_FINALIZED:
	RCU_THROW_MSG ("invalid state change request");
	return; //compiler dummy
      case AIS_INITIALIZED:
      case AIS_NONE:
	RCU_ASSERT0 ("should not get here");
	return; //compiler dummy
      }
      break;
    case AIS_FINALIZED:
      changeAlgState (AIS_INITIALIZED, AES_NONE, inputState);
      m_initState = AIS_NONE;
      for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	checkStatus (m_algs[iter]->finalize (), "Algorithm::finalize");
      m_initState = AIS_FINALIZED;
      break;
    case AIS_HIST_FINALIZED:
      switch (m_initState)
      {
      case AIS_NEW:
	changeAlgState (AIS_HIST_INITIALIZED, AES_NONE, inputState);
	break;
      case AIS_INITIALIZED:
	changeAlgState (AIS_FINALIZED, AES_NONE, inputState);
	break;
      case AIS_HIST_INITIALIZED:
      case AIS_FINALIZED:
	break;
      case AIS_HIST_FINALIZED:
      case AIS_NONE:
	RCU_ASSERT0 ("should not get here");
	return; //compiler dummy
      }
      m_initState = AIS_NONE;
      for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	checkStatus (m_algs[iter]->histFinalize (), "Algorithm::histFinalize");
      for (outputFilesIter iter = m_outputFiles.begin(),
	     end = m_outputFiles.end(); iter != end; ++ iter)
      {
	iter->second->close ();
	std::string path = iter->second->path ();
	if (!path.empty())
	  addOutputList ("EventLoop_OutputStream_" + iter->first, new TObjString (path.c_str()));
      }
      m_stopwatch->Stop ();
      m_runTime->Fill (3, m_stopwatch->CpuTime());
      m_runTime->Fill (4, m_stopwatch->RealTime());
      m_stopwatch->Continue ();
      m_initState = AIS_HIST_FINALIZED;
      break;
    case AIS_NONE:
      break;
    }
    RCU_ASSERT (targetInit == AIS_NONE || m_initState == targetInit);

    if (targetExec != m_execState) switch (targetExec)
    {
    case AES_BLANK:
      if (m_execState == AES_INPUT_CHANGED)
      {
	m_execState = AES_NONE;
	if (m_metaData->castBool (Job::optPrintPerFileStats, false))
	{
	  std::cout << "file stats for: " << inputFile()->GetName() << std::endl;
	  m_tree->PrintCacheStats ();
	}
	for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	  checkStatus (m_algs[iter]->endOfFile (), "Algorithm::endOfFile");
      }
      m_execState = AES_BLANK;
      break;
    case AES_FILE_EXECUTED:
      if (inputState < VALID_FILE)
      {
	RCU_ASSERT0 ("invalid state change request");
	return; //compiler dummy
      }
      switch (m_initState)
      {
      case AIS_NEW:
      case AIS_HIST_INITIALIZED:
	changeAlgState (AIS_HIST_INITIALIZED, AES_BLANK, inputState);
	break;
      case AIS_INITIALIZED:
	changeAlgState (AIS_INITIALIZED, AES_BLANK, inputState);
	break;
      case AIS_FINALIZED:
      case AIS_HIST_FINALIZED:
	RCU_ASSERT0 ("invalid state change request");
	return; //compiler dummy
      case AIS_NONE:
	RCU_ASSERT0 ("should not get here");
	return; //compiler dummy
      }
      m_execState = AES_NONE;
      if (m_treeEntry == 0)
      {
	m_runTime->Fill (1);
	for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	  checkStatus (m_algs[iter]->fileExecute (), "Algorithm::fileExecute");
	m_fileExecuted->Add (new TObjString (TString (inputFileName())));
      }
      m_execState = AES_FILE_EXECUTED;
      break;
    case AES_INPUT_CHANGED:
      if (inputState < VALID_EVENT)
      {
	RCU_ASSERT0 ("invalid state change request");
	return; //compiler dummy
      }
      switch (m_initState)
      {
      case AIS_NEW:
      case AIS_HIST_INITIALIZED:
	changeAlgState (AIS_HIST_INITIALIZED, AES_FILE_EXECUTED, inputState);
	break;
      case AIS_INITIALIZED:
	changeAlgState (AIS_INITIALIZED, AES_FILE_EXECUTED, inputState);
	break;
      case AIS_FINALIZED:
      case AIS_HIST_FINALIZED:
	RCU_ASSERT0 ("invalid state change request");
	return; //compiler dummy
      case AIS_NONE:
	RCU_ASSERT0 ("should not get here");
	return; //compiler dummy
      }
      m_execState = AES_NONE;
      for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
	checkStatus (m_algs[iter]->changeInput (m_initState == AIS_HIST_INITIALIZED), "Algorithm::changeInput");
      m_execState = AES_INPUT_CHANGED;
      break;
    case AES_NONE:
      break;
    }

    RCU_PROVIDE (targetInit == AIS_NONE || m_initState == targetInit);
    RCU_PROVIDE (targetExec == AES_NONE || m_execState == targetExec);
  }
}
