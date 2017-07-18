// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIshepjdIxaoddIROOTAnalysisTutorialdIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIegammaMVACalibdIobjdIegammaMVACalib_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/egammaMVACalib/egammaMVACalib/egammaMVACalibDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *egammaMVACalib_Dictionary();
   static void egammaMVACalib_TClassManip(TClass*);
   static void delete_egammaMVACalib(void *p);
   static void deleteArray_egammaMVACalib(void *p);
   static void destruct_egammaMVACalib(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVACalib*)
   {
      ::egammaMVACalib *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVACalib));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVACalib", "egammaMVACalib/egammaMVACalib.h", 53,
                  typeid(::egammaMVACalib), DefineBehavior(ptr, ptr),
                  &egammaMVACalib_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVACalib) );
      instance.SetDelete(&delete_egammaMVACalib);
      instance.SetDeleteArray(&deleteArray_egammaMVACalib);
      instance.SetDestructor(&destruct_egammaMVACalib);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVACalib*)
   {
      return GenerateInitInstanceLocal((::egammaMVACalib*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVACalib*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVACalib_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVACalib*)0x0)->GetClass();
      egammaMVACalib_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVACalib_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *IegammaMVATool_Dictionary();
   static void IegammaMVATool_TClassManip(TClass*);
   static void delete_IegammaMVATool(void *p);
   static void deleteArray_IegammaMVATool(void *p);
   static void destruct_IegammaMVATool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IegammaMVATool*)
   {
      ::IegammaMVATool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::IegammaMVATool));
      static ::ROOT::TGenericClassInfo 
         instance("IegammaMVATool", "egammaMVACalib/IegammaMVATool.h", 15,
                  typeid(::IegammaMVATool), DefineBehavior(ptr, ptr),
                  &IegammaMVATool_Dictionary, isa_proxy, 0,
                  sizeof(::IegammaMVATool) );
      instance.SetDelete(&delete_IegammaMVATool);
      instance.SetDeleteArray(&deleteArray_IegammaMVATool);
      instance.SetDestructor(&destruct_IegammaMVATool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IegammaMVATool*)
   {
      return GenerateInitInstanceLocal((::IegammaMVATool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::IegammaMVATool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *IegammaMVATool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::IegammaMVATool*)0x0)->GetClass();
      IegammaMVATool_TClassManip(theClass);
   return theClass;
   }

   static void IegammaMVATool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egammaMVATool_Dictionary();
   static void egammaMVATool_TClassManip(TClass*);
   static void delete_egammaMVATool(void *p);
   static void deleteArray_egammaMVATool(void *p);
   static void destruct_egammaMVATool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVATool*)
   {
      ::egammaMVATool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVATool));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVATool", "egammaMVACalib/egammaMVATool.h", 14,
                  typeid(::egammaMVATool), DefineBehavior(ptr, ptr),
                  &egammaMVATool_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVATool) );
      instance.SetDelete(&delete_egammaMVATool);
      instance.SetDeleteArray(&deleteArray_egammaMVATool);
      instance.SetDestructor(&destruct_egammaMVATool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVATool*)
   {
      return GenerateInitInstanceLocal((::egammaMVATool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVATool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVATool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVATool*)0x0)->GetClass();
      egammaMVATool_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVATool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egammaMVACalibNmspcLcLNode_Dictionary();
   static void egammaMVACalibNmspcLcLNode_TClassManip(TClass*);
   static void delete_egammaMVACalibNmspcLcLNode(void *p);
   static void deleteArray_egammaMVACalibNmspcLcLNode(void *p);
   static void destruct_egammaMVACalibNmspcLcLNode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVACalibNmsp::Node*)
   {
      ::egammaMVACalibNmsp::Node *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVACalibNmsp::Node));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVACalibNmsp::Node", "egammaMVACalib/Node.h", 20,
                  typeid(::egammaMVACalibNmsp::Node), DefineBehavior(ptr, ptr),
                  &egammaMVACalibNmspcLcLNode_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVACalibNmsp::Node) );
      instance.SetDelete(&delete_egammaMVACalibNmspcLcLNode);
      instance.SetDeleteArray(&deleteArray_egammaMVACalibNmspcLcLNode);
      instance.SetDestructor(&destruct_egammaMVACalibNmspcLcLNode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVACalibNmsp::Node*)
   {
      return GenerateInitInstanceLocal((::egammaMVACalibNmsp::Node*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVACalibNmsp::Node*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVACalibNmspcLcLNode_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVACalibNmsp::Node*)0x0)->GetClass();
      egammaMVACalibNmspcLcLNode_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVACalibNmspcLcLNode_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egammaMVACalibNmspcLcLBDT_Dictionary();
   static void egammaMVACalibNmspcLcLBDT_TClassManip(TClass*);
   static void delete_egammaMVACalibNmspcLcLBDT(void *p);
   static void deleteArray_egammaMVACalibNmspcLcLBDT(void *p);
   static void destruct_egammaMVACalibNmspcLcLBDT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVACalibNmsp::BDT*)
   {
      ::egammaMVACalibNmsp::BDT *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVACalibNmsp::BDT));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVACalibNmsp::BDT", "egammaMVACalib/BDT.h", 25,
                  typeid(::egammaMVACalibNmsp::BDT), DefineBehavior(ptr, ptr),
                  &egammaMVACalibNmspcLcLBDT_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVACalibNmsp::BDT) );
      instance.SetDelete(&delete_egammaMVACalibNmspcLcLBDT);
      instance.SetDeleteArray(&deleteArray_egammaMVACalibNmspcLcLBDT);
      instance.SetDestructor(&destruct_egammaMVACalibNmspcLcLBDT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVACalibNmsp::BDT*)
   {
      return GenerateInitInstanceLocal((::egammaMVACalibNmsp::BDT*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVACalibNmsp::BDT*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVACalibNmspcLcLBDT_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVACalibNmsp::BDT*)0x0)->GetClass();
      egammaMVACalibNmspcLcLBDT_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVACalibNmspcLcLBDT_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVACalib(void *p) {
      delete ((::egammaMVACalib*)p);
   }
   static void deleteArray_egammaMVACalib(void *p) {
      delete [] ((::egammaMVACalib*)p);
   }
   static void destruct_egammaMVACalib(void *p) {
      typedef ::egammaMVACalib current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVACalib

namespace ROOT {
   // Wrapper around operator delete
   static void delete_IegammaMVATool(void *p) {
      delete ((::IegammaMVATool*)p);
   }
   static void deleteArray_IegammaMVATool(void *p) {
      delete [] ((::IegammaMVATool*)p);
   }
   static void destruct_IegammaMVATool(void *p) {
      typedef ::IegammaMVATool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IegammaMVATool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVATool(void *p) {
      delete ((::egammaMVATool*)p);
   }
   static void deleteArray_egammaMVATool(void *p) {
      delete [] ((::egammaMVATool*)p);
   }
   static void destruct_egammaMVATool(void *p) {
      typedef ::egammaMVATool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVATool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVACalibNmspcLcLNode(void *p) {
      delete ((::egammaMVACalibNmsp::Node*)p);
   }
   static void deleteArray_egammaMVACalibNmspcLcLNode(void *p) {
      delete [] ((::egammaMVACalibNmsp::Node*)p);
   }
   static void destruct_egammaMVACalibNmspcLcLNode(void *p) {
      typedef ::egammaMVACalibNmsp::Node current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVACalibNmsp::Node

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVACalibNmspcLcLBDT(void *p) {
      delete ((::egammaMVACalibNmsp::BDT*)p);
   }
   static void deleteArray_egammaMVACalibNmspcLcLBDT(void *p) {
      delete [] ((::egammaMVACalibNmsp::BDT*)p);
   }
   static void destruct_egammaMVACalibNmspcLcLBDT(void *p) {
      typedef ::egammaMVACalibNmsp::BDT current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVACalibNmsp::BDT

namespace ROOT {
   static TClass *vectorlEegammaMVACalibNmspcLcLNodemUgR_Dictionary();
   static void vectorlEegammaMVACalibNmspcLcLNodemUgR_TClassManip(TClass*);
   static void *new_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p = 0);
   static void *newArray_vectorlEegammaMVACalibNmspcLcLNodemUgR(Long_t size, void *p);
   static void delete_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p);
   static void deleteArray_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p);
   static void destruct_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<egammaMVACalibNmsp::Node*>*)
   {
      vector<egammaMVACalibNmsp::Node*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<egammaMVACalibNmsp::Node*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<egammaMVACalibNmsp::Node*>", -2, "vector", 214,
                  typeid(vector<egammaMVACalibNmsp::Node*>), DefineBehavior(ptr, ptr),
                  &vectorlEegammaMVACalibNmspcLcLNodemUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<egammaMVACalibNmsp::Node*>) );
      instance.SetNew(&new_vectorlEegammaMVACalibNmspcLcLNodemUgR);
      instance.SetNewArray(&newArray_vectorlEegammaMVACalibNmspcLcLNodemUgR);
      instance.SetDelete(&delete_vectorlEegammaMVACalibNmspcLcLNodemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEegammaMVACalibNmspcLcLNodemUgR);
      instance.SetDestructor(&destruct_vectorlEegammaMVACalibNmspcLcLNodemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<egammaMVACalibNmsp::Node*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<egammaMVACalibNmsp::Node*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEegammaMVACalibNmspcLcLNodemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<egammaMVACalibNmsp::Node*>*)0x0)->GetClass();
      vectorlEegammaMVACalibNmspcLcLNodemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEegammaMVACalibNmspcLcLNodemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<egammaMVACalibNmsp::Node*> : new vector<egammaMVACalibNmsp::Node*>;
   }
   static void *newArray_vectorlEegammaMVACalibNmspcLcLNodemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<egammaMVACalibNmsp::Node*>[nElements] : new vector<egammaMVACalibNmsp::Node*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p) {
      delete ((vector<egammaMVACalibNmsp::Node*>*)p);
   }
   static void deleteArray_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p) {
      delete [] ((vector<egammaMVACalibNmsp::Node*>*)p);
   }
   static void destruct_vectorlEegammaMVACalibNmspcLcLNodemUgR(void *p) {
      typedef vector<egammaMVACalibNmsp::Node*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<egammaMVACalibNmsp::Node*>

namespace {
  void TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/egammaMVACalib/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/egammaMVACalib",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/egammaMVACalib/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/egammaMVACalib.h")))  egammaMVACalib;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/IegammaMVATool.h")))  IegammaMVATool;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/egammaMVATool.h")))  egammaMVATool;
namespace egammaMVACalibNmsp{class __attribute__((annotate("$clingAutoload$egammaMVACalib/Node.h")))  Node;}
namespace egammaMVACalibNmsp{class __attribute__((annotate("$clingAutoload$egammaMVACalib/BDT.h")))  BDT;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
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
  #define ROOTCORE_PACKAGE "egammaMVACalib"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef EGAMMAMVACALIB_EGAMMAMVACALIBDICT_H

#include "egammaMVACalib/egammaMVACalib.h"
#include "egammaMVACalib/IegammaMVATool.h"
#include "egammaMVACalib/egammaMVATool.h"
#include "egammaMVACalib/Node.h"
#include "egammaMVACalib/BDT.h"
#include <vector>

namespace egammaMVACalibDict 
{
  struct tmp
  {
    std::vector<egammaMVACalibNmsp::Node*> tmp1;
  };

} // namespace egammaMVACalibDict


#endif // EGAMMAMVACALIB_EGAMMAMVACALIBDICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"IegammaMVATool", payloadCode, "@",
"egammaMVACalib", payloadCode, "@",
"egammaMVACalib::CalibrationType", payloadCode, "@",
"egammaMVACalib::ParticleType", payloadCode, "@",
"egammaMVACalib::ShiftType", payloadCode, "@",
"egammaMVACalib::egammaType", payloadCode, "@",
"egammaMVACalibNmsp::BDT", payloadCode, "@",
"egammaMVACalibNmsp::Node", payloadCode, "@",
"egammaMVATool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("egammaMVACalib_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_egammaMVACalib_Reflex() {
  TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl();
}
