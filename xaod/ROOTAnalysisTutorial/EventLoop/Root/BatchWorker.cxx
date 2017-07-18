//          Copyright Nils Krumnack 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (krumnack@iastate.edu) for bug
// reports, feature suggestions, praise and complaints.


//
// includes
//

#include <EventLoop/BatchWorker.h>

#include <EventLoop/Algorithm.h>
#include <EventLoop/BatchJob.h>
#include <EventLoop/BatchSample.h>
#include <EventLoop/BatchSegment.h>
#include <EventLoop/Driver.h>
#include <EventLoop/Job.h>
#include <EventLoop/OutputStream.h>
#include <RootCoreUtils/Assert.h>
#include <RootCoreUtils/ThrowMsg.h>
#include <SampleHandler/DiskOutput.h>
#include "TSystemDirectory.h"
#include <fstream>
#include <unistd.h>
#include <SampleHandler/ToolsOther.h>
#include <TFile.h>
#include <TSystem.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

//
// method implementations
//

namespace EL
{
  void BatchWorker ::
  testInvariant () const
  {
    RCU_INVARIANT (this != 0);
    RCU_INVARIANT (m_job != 0);
    RCU_INVARIANT (m_sample != 0);
    RCU_INVARIANT (m_segment != 0);
  }



  BatchWorker ::
  BatchWorker (const BatchJob *val_job,
	       const BatchSample *val_sample,
	       const BatchSegment *val_segment,
	       TList *output)
    : Worker ((RCU_REQUIRE (val_job != 0),
	       RCU_REQUIRE (val_sample != 0),
	       RCU_REQUIRE (val_segment != 0),
	       RCU_REQUIRE (output != 0),
	       &val_sample->meta), output),
      m_job (val_job), m_sample (val_sample), m_segment (val_segment)
  {
    for (Job::outputIter out = m_job->job.outputBegin(),
	   end = m_job->job.outputEnd(); out != end; ++ out)
    {
      addOutputWriter (out->label(), out->output()->makeWriter ("", m_segment->name, -1, ".root"));
    }

    for (std::vector<Algorithm*>::const_iterator alg = m_job->job.algsBegin(),
	   end = m_job->job.algsEnd(); alg != end; ++ alg)
      addAlg (dynamic_cast<EL::Algorithm*>((*alg)->Clone()));

    RCU_NEW_INVARIANT (this);
  }



  void BatchWorker ::
  run ()
  {
    RCU_CHANGE_INVARIANT (this);
 
    Long64_t beginFile = m_segment->begin_file;
    Long64_t endFile   = m_segment->end_file;
    Long64_t lastFile  = m_segment->end_file;
    RCU_ASSERT (beginFile <= endFile);
    Long64_t beginEvent = m_segment->begin_event;
    Long64_t endEvent   = m_segment->end_event;
    if (endEvent > 0) endFile += 1;

    for (Long64_t file = beginFile; file != endFile; ++ file)
    {
      RCU_ASSERT (std::size_t(file) < m_sample->files.size());
      std::cout << "Processing File " << m_sample->files[file].c_str() << std::endl;
      //std::unique_ptr<TFile> inFile = SH::openFile (m_sample->files[file], *metaData());
      //
      // This file has been edited by EventLoopCondorFileTransferPatch.sh to handle
      // file transfers
      //
      char hostname[1024];
      hostname[1023] = '\0';
      gethostname(hostname, 1023);
      std::cout << "Hostname is " << hostname << std::endl;
      gSystem->MakeDirectory("tempdir");
      std::string vetodir = m_sample->meta.castString("vetodir");
      std::cout << "the metadata had for veto directory: " << vetodir << std::endl;
      if (vetodir.empty()) vetodir = m_job->location+"/veto";
      gSystem->MakeDirectory(vetodir.c_str());
      gSystem->Exec("ls");
      // SRM File
      std::string orig_name = m_sample->files[file];
      std::string new_name = m_sample->files[file];
      
      // For local files
      std::size_t foundlocal = new_name.find("file://");
      if (foundlocal != std::string::npos) {
        orig_name.replace(orig_name.begin()+foundlocal,orig_name.begin()+foundlocal+7,"");
        new_name.replace(new_name.begin()+foundlocal,new_name.begin()+foundlocal+7,"");
      }
      
      // For files stored on srm managed via a softlink from disk
      char buf_filelink[1024];
      std::size_t linkbufpos = ::readlink(orig_name.c_str(), buf_filelink, sizeof(buf_filelink)-1);
      if(linkbufpos != std::string::npos){
        buf_filelink[linkbufpos] = '\0';
        orig_name = std::string(buf_filelink);
        
        std::size_t replaceStr = orig_name.find("/xrootd/srm/");
        if(replaceStr != std::string::npos){
          orig_name.replace(orig_name.begin()+replaceStr, orig_name.begin()+replaceStr+12, "");
          orig_name = "root://hn.at3f//srm/" + orig_name;
        }
        new_name = orig_name;
      }
      
      std::string transfer_done_file = "tempdir/filetransfercomplete";
      std::size_t found = new_name.find("root://hn.at3f//srm/");
      if (found != std::string::npos) {
        new_name.replace(new_name.begin()+found,new_name.begin()+found+20,"");
      }
      found = new_name.find("/");
      while (found != std::string::npos){
        new_name.replace(new_name.begin()+found,new_name.begin()+found+1,"_");
        found = new_name.find("/");
      }
      std::string new_name_loc = "tempdir/"+new_name;
      std::string vetofile = vetodir+"/"+new_name;
      std::cout << "Old file name is " << orig_name << std::endl;
      std::cout << "New file name is " << new_name << std::endl;
      std::cout << "Job location: " << m_job->location << std::endl;
      std::cout << "Veto directory: " << vetodir << std::endl;
      TSystemDirectory dir(vetodir.c_str(),vetodir.c_str());
      int nfiles = 0;
      while(true){ 
        nfiles = dir.GetListOfFiles()->GetEntries();
        if (nfiles >= 8+2) { // Limit to 8 file transfers. ".." and "." are the +2
          std::cout << "nfiles = " << nfiles << ". waiting." << std::endl;
          sleep(5); continue;
        }
        break;
      }
      std::fstream fs;
      //fs.open (vetofile, std::fstream::in | std::fstream::out | std::fstream::app);
      fs.open(vetofile.c_str(),std::fstream::in | std::fstream::out | std::fstream::app);
      fs.close();
      TString command;
      char buffer[512];
      std::string popen_result = "";
      int ntries = 0;
      while(true){
        ntries ++;
        if (ntries>30){std::cout << "Transfer failed 30 times. Exiting." << std::endl; break; }
        
        if(foundlocal != std::string::npos && linkbufpos == std::string::npos){
          // i.e. local file that is not just a link
          command.Form("cp %s %s",orig_name.c_str(),new_name_loc.c_str());
        }
        else{
          //command.Form("xrdcp %s %s && touch %s",orig_name.c_str(),new_name_loc.c_str(),transfer_done_file.c_str());
          command.Form("xrdcp %s %s",orig_name.c_str(),new_name_loc.c_str());
        }
        
        std::cout << "Transfer begin for " << new_name << std::endl;
        std::cout << command << std::endl;
        FILE* pipe = popen(command.Data(), "r"); sleep(5);
        if (!pipe) {
          std::cout << "Error! xrd cmd failed." << std::endl; sleep(15);
          std::cout << "Errno: " << errno << std::endl;
          continue;
        }
        while(!feof(pipe)) { if(fgets(buffer, 512, pipe) != NULL) popen_result += buffer; }
        pclose(pipe);
        std::cout << "Transfer end. xrd command result: " << popen_result << std::endl;
        std::cout << "Checking that file exists " << "tempdir/"+new_name << std::endl;
        //if (std::ifstream(transfer_done_file.c_str())) { 
        TFile* temp = TFile::Open(new_name_loc.c_str());
        if (!temp) { std::cout << "File does not exist." << std::endl; sleep(10); continue; }
        if(!temp->IsZombie()) {
          temp->Close();
          std::cout << "File exists: tempdir/" << new_name << std::endl;
          std::cout << "Breaking out of queue after this many tries: " << ntries << std::endl;
          break;
        } else {
          std::cout << "Something went wrong. Closing file." << std::endl;
          temp->Close();
          std::cout << "Something went wrong. Waiting 10s and Retrying." << std::endl;
          sleep(10);
        }
      }
      while(true){
        unlink((vetodir+"/"+new_name).c_str());
        if (std::ifstream((vetodir+"/"+new_name).c_str())) { 
          std::cout << "rm vetodir command failed. Retrying." << std::endl;
          sleep(5); continue;
        }
        break;
      }
      std::auto_ptr<TFile> inFile (TFile::Open (("tempdir/"+new_name).c_str()));
      //
      if (inFile.get() == 0)
	RCU_THROW_MSG (std::string ("failed to open file ") + m_sample->files[file]);
      setInputFile (inFile.get());

      const Long64_t firstEvent = (file == beginFile ? beginEvent : 0);
      const Long64_t lastEvent
	= (file == lastFile ? endEvent : inputFileNumEntries());

      treeEntry (firstEvent);
      algsChangeInput ();
      for (Long64_t entry = firstEvent; entry != lastEvent; ++ entry)
      {
	treeEntry (entry);
	algsExecute ();
      }
      algsEndOfFile ();
      inFile->Close();
      while(true){
        //unlink(transfer_done_file.c_str());
        unlink(new_name_loc.c_str());
        if (std::ifstream(transfer_done_file.c_str()) ||
            std::ifstream(new_name_loc.c_str())) { 
          std::cout << "rm ftc or root file command failed. Retrying." << std::endl;
          sleep(5); continue;
        }
        break;
      }
      //gSystem->Exec(command.c_str());
    }
    algsFinalize ();
  }



  void BatchWorker ::
  execute (unsigned job_id, const char *confFile)
  {
    try
    {
      std::auto_ptr<TFile> file (TFile::Open (confFile, "READ"));
      RCU_ASSERT_SOFT (file.get() != 0);
      std::auto_ptr<BatchJob> job (dynamic_cast<BatchJob*>(file->Get ("job")));
      RCU_ASSERT_SOFT (job.get() != 0);
      RCU_ASSERT_SOFT (job_id < job->segments.size());
      BatchSegment *segment = &job->segments[job_id];
      RCU_ASSERT_SOFT (segment->job_id == job_id);
      RCU_ASSERT_SOFT (segment->sample < job->samples.size());
      BatchSample *sample = &job->samples[segment->sample];

      gSystem->Exec ("pwd");
      gSystem->MakeDirectory ("output");

      TList output;
      BatchWorker worker (job.get(), sample, segment,
			  &output);
      worker.run ();

      std::ostringstream job_name;
      job_name << job_id;
      Driver::saveOutput (job->location + "/fetch", segment->name, output);
      std::ofstream completed ((job->location + "/fetch/completed-" + job_name.str()).c_str());
    } catch (std::exception& e)
    {
      std::cout << "exception caught: " << e.what() << std::endl;
      exit (EXIT_FAILURE);
    } catch (std::string& s)
    {
      std::cout << "exception caught: " << s << std::endl;
      exit (EXIT_FAILURE);
    }
  }
}
