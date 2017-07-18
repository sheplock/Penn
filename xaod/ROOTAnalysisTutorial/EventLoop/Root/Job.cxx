//          Copyright Nils Krumnack 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (krumnack@iastate.edu) for bug
// reports, feature suggestions, praise and complaints.


//
// includes
//

#include <EventLoop/Job.h>

#include <memory>
#include <EventLoop/Algorithm.h>
#include <EventLoop/D3PDReaderSvc.h>
#include <EventLoop/OutputStream.h>
#include <EventLoop/TEventSvc.h>
#include <RootCore/Packages.h>
#include <RootCoreUtils/Assert.h>
#include <RootCoreUtils/CheckRootVersion.h>
#include <RootCoreUtils/ThrowMsg.h>
#include <SampleHandler/MetaFields.h>
#include <SampleHandler/MetaNames.h>

#include <iostream>

//
// method implementations
//

namespace EL
{
  const std::string Job::optRemoveSubmitDir = "nc_EventLoop_RemoveSubmitDir";
  const std::string Job::optMaxEvents = "nc_EventLoop_MaxEvents";
  const std::string Job::optSkipEvents = "nc_EventLoop_SkipEvents";
  const std::string Job::optFilesPerWorker = "nc_EventLoop_FilesPerWorker";
  const std::string Job::optEventsPerWorker = "nc_EventLoop_EventsPerWorker";
  const std::string Job::optSubmitFlags = "nc_EventLoop_SubmitFlags";
  const std::string Job::optCondorConf = "nc_EventLoop_CondorConf";
  const std::string Job::optCacheLearnEntries = "nc_EventLoop_CacheLearnEntries";
  const std::string Job::optD3PDPerfStats = "nc_EventLoop_D3PDPerfStats";
  const std::string Job::optD3PDReadStats = "nc_EventLoop_D3PDReadStats";
  const std::string Job::optXAODPerfStats = "nc_EventLoop_XAODPerfStats";
  const std::string Job::optXAODReadStats = "nc_EventLoop_XAODReadStats";
  const std::string Job::optD3PDCacheMinEvent = "nc_EventLoop_D3PDCacheMinEvent";
  const std::string Job::optD3PDCacheMinEventFraction = "nc_EventLoop_D3PDCacheMinEventFraction";
  const std::string Job::optD3PDCacheMinByte = "nc_EventLoop_D3PDCacheMinByte";
  const std::string Job::optD3PDCacheMinByteFraction = "nc_EventLoop_D3PDCacheMinByteFraction";
  const std::string Job::optPerfTree = "nc_EventLoop_PerfTree";
  const std::string Job::optXaodAccessMode = "nc_EventLoop_XaodAccessMode";
  const std::string Job::optXaodAccessMode_branch = "branch";
  const std::string Job::optXaodAccessMode_class = "class";
  const std::string Job::optPrintPerFileStats = "nc_print_per_file_stats";
  const std::string Job::optDisableMetrics = "nc_disable_metrics";
  const std::string Job::optResetShell = "nc_reset_shell";
  const std::string Job::optBackgroundProcess = "nc_background_process";
  const std::string Job::optGridDestSE = "nc_destSE";
  const std::string Job::optGridSite = "nc_site";
  const std::string Job::optGridCloud = "nc_cloud";
  const std::string Job::optGridExcludedSite = "nc_excludedSite";
  const std::string Job::optGridNGBPerJob = "nc_nGBPerJob";
  const std::string Job::optGridMemory = "nc_memory";
  const std::string Job::optGridMaxCpuCount = "nc_maxCpuCount";
  const std::string Job::optGridNFiles = "nc_nFiles";
  const std::string Job::optGridNFilesPerJob = "nc_nFilesPerJob";
  const std::string Job::optGridNJobs = "nc_nJobs";
  const std::string Job::optGridMaxFileSize = "nc_maxFileSize";
  const std::string Job::optGridMaxNFilesPerJob = "nc_maxNFilesPerJob";
  const std::string Job::optGridUseChirpServer = "nc_useChirpServer";
  const std::string Job::optGridExpress = "nc_express";
  const std::string Job::optGridNoSubmit = "nc_noSubmit";
  const std::string Job::optGridMergeOutput = "nc_mergeOutput";
  const std::string Job::optBatchSharedFileSystem = "nc_sharedFileSystem";
  const std::string Job::optTmpDir = "nc_tmpDir";
  const std::string Job::optRootVer = "nc_rootVer";
  const std::string Job::optCmtConfig = "nc_cmtConfig";
  const std::string Job::optGridDisableAutoRetry = "nc_disableAutoRetry";
  const std::string Job::optOfficial = "nc_official";
  const std::string Job::optVoms = "nc_voms";

  /// warning: this has to be synchronized with
  ///   SampleHandler::MetaFields.  I can't just copy it here, because
  ///   the order of initialization is undefined
  const std::string Job::optCacheSize = "nc_cache_size";

  const std::string Job::optRetries = SH::MetaNames::openRetries();
  const std::string Job::optRetriesWait = SH::MetaNames::openRetriesWait();



  void swap (Job& a, Job& b)
  {
    swap (a.m_sampleHandler, b.m_sampleHandler);
    swap (a.m_algs, b.m_algs);
    swap (a.m_output, b.m_output);
  }



  void Job ::
  testInvariant () const
  {
    RCU_INVARIANT (this);
    for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
      RCU_INVARIANT (m_algs[iter] != 0);
  }



  Job ::
  Job ()
  {
    RCU::check_root_version ();

    RCU_NEW_INVARIANT (this);
  }



  Job ::
  Job (const Job& that)
    : m_sampleHandler ((RCU_READ_INVARIANT (&that),
			that.m_sampleHandler)),
      m_output (that.m_output),
      m_options (that.m_options)
  {
    RCU_NEW_INVARIANT (this);

    m_algs.reserve (that.m_algs.size());
    for (algsIter alg = that.m_algs.begin(), end = that.m_algs.end();
	 alg != end; ++ alg)
    {
      m_algs.push_back (dynamic_cast<Algorithm*>((*alg)->Clone()));
      RCU_ASSERT (m_algs.back() != 0);
    }
  }



  Job ::
  ~Job ()
  {
    RCU_DESTROY_INVARIANT (this);

    for (std::size_t iter = 0, end = m_algs.size(); iter != end; ++ iter)
      delete m_algs[iter];
  }



  Job& Job ::
  operator = (const Job& that)
  {
    // no invariant used
    Job tmp (that);
    swap (*this, tmp);
    return *this;
  }



  const SH::SampleHandler& Job ::
  sampleHandler () const
  {
    RCU_READ_INVARIANT (this);
    return m_sampleHandler;
  }



  void Job ::
  sampleHandler (const SH::SampleHandler& val_sampleHandler)
  {
    RCU_CHANGE_INVARIANT (this);
    m_sampleHandler = val_sampleHandler;
  }



  Job::algsIter Job ::
  algsBegin () const
  {
    RCU_READ_INVARIANT (this);
    return m_algs.begin();
  }



  Job::algsIter Job ::
  algsEnd () const
  {
    RCU_READ_INVARIANT (this);
    return m_algs.end();
  }



  void Job ::
  algsAdd (Algorithm *alg_swallow)
  {
    std::auto_ptr<Algorithm> alg (alg_swallow);    

    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE_SOFT (alg_swallow != 0);

    alg->sysSetupJob (*this);
    m_algs.push_back (alg.get());
    alg.release();
  }



  void Job ::
  algsAddClone (const Algorithm& alg)
  {
    // no invariant used
    algsAdd (dynamic_cast<Algorithm*>(alg.Clone()));
  }



  bool Job ::
  algsHas (const std::string& name) const
  {
    RCU_READ_INVARIANT (this);
    for (algsIter alg = algsBegin(), end = algsEnd();
	 alg != end; ++ alg)
    {
      if ((*alg)->GetName() == name)
	return true;
    }
    return false;
  }



  Job::outputMIter Job ::
  outputBegin ()
  {
    RCU_READ_INVARIANT (this);
    return &m_output[0];
  }



  Job::outputIter Job ::
  outputBegin () const
  {
    RCU_READ_INVARIANT (this);
    return &m_output[0];
  }



  Job::outputMIter Job ::
  outputEnd ()
  {
    RCU_READ_INVARIANT (this);
    return &m_output[m_output.size()];
  }



  Job::outputIter Job ::
  outputEnd () const
  {
    RCU_READ_INVARIANT (this);
    return &m_output[m_output.size()];
  }



  void Job ::
  outputAdd (const OutputStream& val_output)
  {
    RCU_CHANGE_INVARIANT (this);
    RCU_REQUIRE2_SOFT (!outputHas (val_output.label()), ("trying to create two output streams with the label " + val_output.label() + "\nplease make sure that every output stream has a unique label").c_str());
    m_output.push_back (val_output);
  }



  bool Job ::
  outputHas (const std::string& name) const
  {
    RCU_CHANGE_INVARIANT (this);
    for (outputIter iter = outputBegin(),
	   end = outputEnd(); iter != end; ++ iter)
    {
      if (iter->label() == name)
	return true;
    }
    return false;
  }



  void Job ::
  useD3PDReader ()
  {
    RCU_CHANGE_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_D3PDReader
    if (!algsHas (D3PDReaderSvc::name))
      algsAdd (new D3PDReaderSvc);
#else
    RCU_THROW_MSG ("D3PDReaderSvc not configured");
#endif
  }



  void Job ::
  useXAOD ()
  {
    RCU_CHANGE_INVARIANT (this);

#ifdef ROOTCORE_PACKAGE_xAODRootAccess
    if (!algsHas (TEventSvc::name))
      algsAdd (new TEventSvc);
#else
    RCU_THROW_MSG ("TEventSvc not configured");
#endif
  }



  SH::MetaObject *Job ::
  options ()
  {
    RCU_READ_INVARIANT (this);
    return &m_options;
  }



  const SH::MetaObject *Job ::
  options () const
  {
    RCU_READ_INVARIANT (this);
    return &m_options;
  }
}
