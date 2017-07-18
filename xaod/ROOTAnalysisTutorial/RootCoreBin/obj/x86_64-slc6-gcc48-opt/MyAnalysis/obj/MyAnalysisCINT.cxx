#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIshepjdIxaoddIROOTAnalysisTutorialdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIMyAnalysisdIobjdIMyAnalysisCINT

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
#include "MyAnalysis/MyxAODAnalysis.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_MyxAODAnalysis(void *p = 0);
   static void *newArray_MyxAODAnalysis(Long_t size, void *p);
   static void delete_MyxAODAnalysis(void *p);
   static void deleteArray_MyxAODAnalysis(void *p);
   static void destruct_MyxAODAnalysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyxAODAnalysis*)
   {
      ::MyxAODAnalysis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyxAODAnalysis >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyxAODAnalysis", ::MyxAODAnalysis::Class_Version(), "MyAnalysis/MyxAODAnalysis.h", 14,
                  typeid(::MyxAODAnalysis), DefineBehavior(ptr, ptr),
                  &::MyxAODAnalysis::Dictionary, isa_proxy, 4,
                  sizeof(::MyxAODAnalysis) );
      instance.SetNew(&new_MyxAODAnalysis);
      instance.SetNewArray(&newArray_MyxAODAnalysis);
      instance.SetDelete(&delete_MyxAODAnalysis);
      instance.SetDeleteArray(&deleteArray_MyxAODAnalysis);
      instance.SetDestructor(&destruct_MyxAODAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyxAODAnalysis*)
   {
      return GenerateInitInstanceLocal((::MyxAODAnalysis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyxAODAnalysis*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr MyxAODAnalysis::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyxAODAnalysis::Class_Name()
{
   return "MyxAODAnalysis";
}

//______________________________________________________________________________
const char *MyxAODAnalysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyxAODAnalysis*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyxAODAnalysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyxAODAnalysis*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyxAODAnalysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyxAODAnalysis*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyxAODAnalysis::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyxAODAnalysis*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void MyxAODAnalysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyxAODAnalysis.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyxAODAnalysis::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyxAODAnalysis::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyxAODAnalysis(void *p) {
      return  p ? new(p) ::MyxAODAnalysis : new ::MyxAODAnalysis;
   }
   static void *newArray_MyxAODAnalysis(Long_t nElements, void *p) {
      return p ? new(p) ::MyxAODAnalysis[nElements] : new ::MyxAODAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyxAODAnalysis(void *p) {
      delete ((::MyxAODAnalysis*)p);
   }
   static void deleteArray_MyxAODAnalysis(void *p) {
      delete [] ((::MyxAODAnalysis*)p);
   }
   static void destruct_MyxAODAnalysis(void *p) {
      typedef ::MyxAODAnalysis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyxAODAnalysis

namespace {
  void TriggerDictionaryInitialization_MyAnalysisCINT_Impl() {
    static const char* headers[] = {
"MyAnalysis/MyxAODAnalysis.h",
0
    };
    static const char* includePaths[] = {
"/home/shepj/xaod/ROOTAnalysisTutorial/MyAnalysis/Root",
"/home/shepj/xaod/ROOTAnalysisTutorial/MyAnalysis",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/home/shepj/xaod/ROOTAnalysisTutorial/MyAnalysis/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/home/shepj/xaod/ROOTAnalysisTutorial/MyAnalysis/Root/LinkDef.h")))  MyxAODAnalysis;
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
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594/valid3.110401.PowhegPythia_P2012_ttbar_nonallhad.recon.AOD.e3099_s2578_r6594_tid05292824_00/AOD.05292824._000011.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594"
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
  #define ROOTCORE_PACKAGE "MyAnalysis"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "MyAnalysis/MyxAODAnalysis.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"MyxAODAnalysis", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MyAnalysisCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MyAnalysisCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MyAnalysisCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MyAnalysisCINT() {
  TriggerDictionaryInitialization_MyAnalysisCINT_Impl();
}
