#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIshepjdIxaoddIROOTAnalysisTutorialdIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdICPAnalysisExamplesdIobjdICPAnalysisExamplesCINT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "CPAnalysisExamples/xExample.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_xExample(void *p = 0);
   static void *newArray_xExample(Long_t size, void *p);
   static void delete_xExample(void *p);
   static void deleteArray_xExample(void *p);
   static void destruct_xExample(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xExample*)
   {
      ::xExample *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::xExample >(0);
      static ::ROOT::TGenericClassInfo 
         instance("xExample", ::xExample::Class_Version(), "CPAnalysisExamples/xExample.h", 32,
                  typeid(::xExample), DefineBehavior(ptr, ptr),
                  &::xExample::Dictionary, isa_proxy, 4,
                  sizeof(::xExample) );
      instance.SetNew(&new_xExample);
      instance.SetNewArray(&newArray_xExample);
      instance.SetDelete(&delete_xExample);
      instance.SetDeleteArray(&deleteArray_xExample);
      instance.SetDestructor(&destruct_xExample);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xExample*)
   {
      return GenerateInitInstanceLocal((::xExample*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xExample*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr xExample::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *xExample::Class_Name()
{
   return "xExample";
}

//______________________________________________________________________________
const char *xExample::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::xExample*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int xExample::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::xExample*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *xExample::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::xExample*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *xExample::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::xExample*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void xExample::Streamer(TBuffer &R__b)
{
   // Stream an object of class xExample.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(xExample::Class(),this);
   } else {
      R__b.WriteClassBuffer(xExample::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_xExample(void *p) {
      return  p ? new(p) ::xExample : new ::xExample;
   }
   static void *newArray_xExample(Long_t nElements, void *p) {
      return p ? new(p) ::xExample[nElements] : new ::xExample[nElements];
   }
   // Wrapper around operator delete
   static void delete_xExample(void *p) {
      delete ((::xExample*)p);
   }
   static void deleteArray_xExample(void *p) {
      delete [] ((::xExample*)p);
   }
   static void destruct_xExample(void *p) {
      typedef ::xExample current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xExample

namespace {
  void TriggerDictionaryInitialization_CPAnalysisExamplesCINT_Impl() {
    static const char* headers[] = {
"CPAnalysisExamples/xExample.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/CPAnalysisExamples/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/CPAnalysisExamples",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/CPAnalysisExamples/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/CPAnalysisExamples/Root/LinkDef.h")))  xExample;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 23
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630"
#endif
#ifndef ASG_TEST_FILE_DATA
  #define ASG_TEST_FILE_DATA "/afs/cern.ch/atlas/project/PAT/xAODs/p2410/data15_13TeV.00270448.physics_Main.merge.AOD.r6943_p2410/AOD.06297575._000522.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MC
  #define ASG_TEST_FILE_MC "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1"
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "CPAnalysisExamples"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CPAnalysisExamples/xExample.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"xExample", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CPAnalysisExamplesCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CPAnalysisExamplesCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CPAnalysisExamplesCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CPAnalysisExamplesCINT() {
  TriggerDictionaryInitialization_CPAnalysisExamplesCINT_Impl();
}
