//        Copyright Iowa State University 2015.
//                  Author: Nils Krumnack
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (nils.erik.krumnack@cern.ch) for bug
// reports, feature suggestions, praise and complaints.


//
// includes
//

#include <EventLoop/EmptyFileHandler.h>

#include <RootCoreUtils/Assert.h>
#include <RootCoreUtils/ShellExec.h>
#include <RootCoreUtils/hadd.h>
#include <EventLoop/DirectDriver.h>
#include <EventLoop/Job.h>
#include <EventLoop/OutputStream.h>
#include <SampleHandler/MetaObject.h>
#include <SampleHandler/SampleHandler.h>
#include <SampleHandler/SampleLocal.h>
#include <TList.h>
#include <TObjString.h>
#include <memory>

//
// method implementations
//

namespace EL
{
  namespace
  {
    SH::SampleHandler makeReprocessSamples (const std::string& submitdir)
    {
      /// \brief the input sample handler
      SH::SampleHandler shInput;
      shInput.load (submitdir + "/input");

      /// \brief the histogram sample handler
      SH::SampleHandler shHist;
      shHist.load (submitdir + "/hist");

      /// \brief the list of samples we need to reprocess
      SH::SampleHandler shReprocess;

      for (SH::Sample *sampleInput : shInput)
      {
	SH::Sample *sampleHist = shHist.get (sampleInput->name());
	RCU_ASSERT (sampleHist != nullptr);

	std::unique_ptr<TList> list
	  (dynamic_cast<TList*>(sampleHist->readHist ("EventLoop_FileExecuted")));
	if (list == nullptr)
	  list.reset (new TList);

	std::unique_ptr<SH::SampleLocal> sampleReprocess;

	std::vector<std::string> filesInput (sampleInput->makeFileList ());
	for (auto& fileInput : filesInput)
	{
	  bool processed = false;
	  TObject *object = nullptr;
	  for (TIter iter (list.get()); !processed && (object = iter.Next()); )
	  {
	    TObjString *fileHist = dynamic_cast<TObjString*>(object);
	    RCU_ASSERT (fileHist != nullptr);
	    std::string file = ("/" + fileHist->String()).Data();
	    if (fileInput.rfind (file) == fileInput.size() - file.size())
	      processed = true;
	  }
	  if (!processed)
	  {
	    if (sampleReprocess == nullptr)
	    {
	      sampleReprocess.reset (new SH::SampleLocal (sampleInput->name()));
	      *sampleReprocess->meta() = *sampleInput->meta();
	    }
	    sampleReprocess->add (fileInput);
	  }
	}
	if (sampleReprocess != nullptr)
	{
	  RCU_ASSERT (sampleReprocess->makeFileList().size() + list->GetSize() == filesInput.size());
	  shReprocess.add (sampleReprocess.release());
	}
      }
      return shReprocess;
    }



    void mergeHists (const std::string& mainDir,
		     const std::string& extraDir,
		     const SH::SampleHandler& samples)
    {
      for (auto& sample : samples)
      {
	std::string tmp = extraDir + "/hist2-" + sample->name() + ".root";
	std::string target = mainDir + "/hist-" + sample->name() + ".root";

	RCU::hadd (tmp, {target, extraDir + "/hist-" + sample->name() + ".root"});
	RCU::Shell::exec ("mv -f " + RCU::Shell::quote (tmp) + " " + RCU::Shell::quote (target));
      }
    }



    void mergeNtuple (const std::string& mainDir,
		      const std::string& extraDir)
    {
      SH::SampleHandler mainSH;
      mainSH.load (mainDir);
      SH::SampleHandler extraSH;
      extraSH.load (extraDir);
      SH::SampleHandler newSH;

      for (SH::Sample *extraSample : extraSH)
      {
	SH::Sample *mainSample = mainSH.get (extraSample->name());
	RCU_ASSERT (mainSample != nullptr);
	std::unique_ptr<SH::SampleLocal> newSample
	  (new SH::SampleLocal (extraSample->name()));
	*newSample->meta() = *mainSample->meta();

	for (auto& file : mainSample->makeFileList())
	  newSample->add (file);
	for (auto& file : extraSample->makeFileList())
	  newSample->add (file);
	newSH.add (newSample.release());
      }

      for (SH::Sample *mainSample : mainSH)
      {
	if (newSH.get (mainSample->name()) == nullptr)
	  newSH.add (mainSample);
      }

      mainSH.save (mainDir);
    }
  }

  void processEmptyFiles (const std::string& submitdir,
			  const Job& job)
  {
    SH::SampleHandler shReprocess = makeReprocessSamples (submitdir);

    if (shReprocess.size() > 0)
    {
      std::string mysubmitdir = submitdir + "/emptyFiles";
      Job myjob = job;
      myjob.sampleHandler (shReprocess);

      DirectDriver driver;
      driver.submit (myjob, mysubmitdir);

      mergeHists (submitdir, mysubmitdir, shReprocess);
      for (auto output = job.outputBegin(),
	     end = job.outputEnd(); output != end; ++ output)
      {
	mergeNtuple (submitdir + "/output-" + output->label(),
		     mysubmitdir + "/output-" + output->label());
      }
    }
  }
}
