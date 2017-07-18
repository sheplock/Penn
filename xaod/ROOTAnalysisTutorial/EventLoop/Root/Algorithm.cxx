//          Copyright Nils Krumnack 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (krumnack@iastate.edu) for bug
// reports, feature suggestions, praise and complaints.


//
// includes
//

#include <EventLoop/Algorithm.h>

#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <RootCore/Packages.h>
#include <RootCoreUtils/Assert.h>
#include <RootCoreUtils/ThrowMsg.h>
#include <TH1.h>

#ifdef ROOTCORE_PACKAGE_AsgTools
#include <AsgTools/MsgLevel.h>
#include <AsgTools/MsgStream.h>
#endif

//
// method implementations
//

ClassImp (EL::Algorithm)

namespace EL
{
  void Algorithm ::
  testInvariant () const
  {
    RCU_INVARIANT (this != 0);
  }



  Worker *Algorithm ::
  wk () const
  {
    RCU_READ_INVARIANT (this);
    return m_wk;
  }



  void Algorithm ::
  book (const TH1& hist)
  {
    RCU_CHANGE_INVARIANT (this);
    wk()->addOutput (hist.Clone());
  }



  TH1 *Algorithm ::
  hist (const std::string& name) const
  {
    RCU_READ_INVARIANT (this);
    return wk()->getOutputHist (name);
  }



  Algorithm ::
  Algorithm ()
    : m_wk (0)
  {
    RCU_NEW_INVARIANT (this);
  }



  Algorithm ::
  ~Algorithm ()
  {
#ifdef ROOTCORE_PACKAGE_AsgTools
    delete m_msg;
#endif
  }



  MsgStream& Algorithm ::
  msg () const
  {
    RCU_READ_INVARIANT (this);
    if (m_msg == 0)
    {
#ifdef ROOTCORE_PACKAGE_AsgTools
      std::string name = GetName();
      if (name.empty())
	name = "UnnamedAlgorithm";
      m_msg = new MsgStream (name);
      m_msg->setLevel (MSG::Level (m_msgLevel));
#else
      RCU_THROW_MSG ("package not compiled with AsgTools support");
#endif
    }
    return *m_msg;
  }



  MsgStream& Algorithm ::
  msg (int level) const
  {
    RCU_READ_INVARIANT (this);
#ifdef ROOTCORE_PACKAGE_AsgTools
    MsgStream& result = msg ();
    result << MSG::Level (level);
    return result;
#else
      RCU_THROW_MSG ("package not compiled with AsgTools support");
#endif
  }



  bool Algorithm ::
  msgLvl (int lvl) const
  {
    RCU_READ_INVARIANT (this);
    return m_msgLevel <= lvl;
  }



  void Algorithm ::
  setMsgLevel (int level)
  {
    RCU_READ_INVARIANT (this);
#ifdef ROOTCORE_PACKAGE_AsgTools
    if (m_msg)
      m_msg->setLevel (MSG::Level (level));
#endif
    m_msgLevel = level;
  }



  StatusCode Algorithm ::
  setupJob (Job& /*job*/)
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  fileExecute ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  endOfFile ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  changeInput (bool /*firstFile*/)
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  initialize ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  histInitialize ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  execute ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  postExecute ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  finalize ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  StatusCode Algorithm ::
  histFinalize ()
  {
    RCU_CHANGE_INVARIANT (this);
    return StatusCode::SUCCESS;
  }



  bool Algorithm ::
  hasName (const std::string& name) const
  {
    RCU_CHANGE_INVARIANT (this);
    return GetName() == name;
  }



  void Algorithm ::
  sysSetupJob (Job& job)
  {
    RCU_CHANGE_INVARIANT (this);
    if (setupJob (job) != StatusCode::SUCCESS)
      RCU_THROW_MSG ("Algorithm::setupJob returned StatusCode::FAILURE");
  }
}
