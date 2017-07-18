#ifndef EVENT_LOOP_GLOBAL_HH
#define EVENT_LOOP_GLOBAL_HH

//          Copyright Nils Krumnack 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (krumnack@iastate.edu) for bug
// reports, feature suggestions, praise and complaints.


/// This module provides a lot of global definitions, forward
/// declarations and includes that are used by all modules.  As such it
/// doesn't fall into the user vs. expert classification.

namespace EL
{
  class Algorithm;
  struct BackgroundJob;
  class BackgroundSocket;
  class BackgroundWorker;
  class BatchDriver;
  struct BatchJob;
  struct BatchSample;
  struct BatchSegment;
  class BatchWorker;
  class CondorDriver;
  class DirectDriver;
  class DirectWorker;
  class Driver;
  class GEDriver;
  class Job;
  class LLDriver;
  class LSFDriver;
  class LocalDriver;
  class OutputStream;
  struct ProofArgs;
  class ProofDriver;
  class ProofTSelector;
  class ProofWorker;
  class StatusCode;
  class TorqueDriver;
  struct UnitTest;
  class UnitTestAlg;
  class Worker;
}

#endif
