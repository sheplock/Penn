RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -I/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/p2410/data15_13TeV.00270448.physics_Main.merge.AOD.r6943_p2410/AOD.06297575._000522.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"TrigTauMatching\" 
RC_DICTFLAGS = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -I/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/p2410/data15_13TeV.00270448.physics_Main.merge.AOD.r6943_p2410/AOD.06297575._000522.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"TrigTauMatching\" 
RC_INCFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -I/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/include -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/p2410/data15_13TeV.00270448.physics_Main.merge.AOD.r6943_p2410/AOD.06297575._000522.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"TrigTauMatching\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_DICTLIBFLAGS = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic
RC_BINFLAGS  = -L/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib -L/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/lib/x86_64-slc6-gcc49-opt -lTrigTauMatching -lTrigDecisionTool -lTrigSteeringEvent -lEventLoop -lProofPlayer -lProof -lHist -lTree -lSampleHandler -lPyROOT -lProof -lTree -lTrigConfxAOD -lTrigConfHLTData -lboost_system -lTrigConfL1Data -lTrigConfBase -lTrigNavStructure -lxAODTau -lGenVector -lxAODTruth -lTruthUtils -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODCaloEvent -lCaloGeoHelpers -lxAODBTagging -lxAODTracking -lxAODBase -lPhysics -lxAODTrigger -lxAODEventInfo -lPATCore -lPATInterfaces -lRootCoreUtils -lboost_regex -lTree -lHist -lAsgTools -lxAODRootAccess -lNet -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lCxxUtils -lboost_regex -lboost_system -lxAODRootAccessInterfaces -lAsg_GoogleTest -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.12-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_TrigTauMatching : dep_TrigTauMatching package_TrigTauMatching

package_TrigTauMatching :  /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching_Reflex.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/bin/TrigTauMatching_example postcompile_TrigTauMatching

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching.so :  /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching.o | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching.o $(RC_LIBFLAGS) -L/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/lib/x86_64-slc6-gcc49-opt -o $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/%.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/Root/%.cxx | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc TrigTauMatching $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/%.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/Root/%.cxx | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching_Reflex.so :  /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.o | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -L/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib -lTrigTauMatching /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.o $(RC_DICTLIBFLAGS) $(RC_BINFLAGS) -o $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/TrigTauMatching/TrigTauMatchingDict.h /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/TrigTauMatching/selection.xml | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc TrigTauMatching $@
	$(SILENT)rc --internal genreflex /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/TrigTauMatching/TrigTauMatchingDict.h /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/TrigTauMatching/selection.xml /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.cxx /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching_Reflex.rootmap libTrigTauMatching_Reflex.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib $(RC_INCFLAGS)
	$(SILENT)$(RC_CXX) $(RC_DICTFLAGS) $(INCLUDES) -c /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.cxx -o $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/TrigTauMatching/TrigTauMatchingDict.h | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/bin/% : /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/%.o | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/%.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/util/%.cxx | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_example.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc TrigTauMatching $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/%.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.45/TrigTauMatching/util/%.cxx | /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_TrigTauMatching :  /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/lib/libTrigTauMatching_Reflex.so /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/bin/TrigTauMatching_example
	$(SILENT)rc --internal postcompile_pkg TrigTauMatching


dep_TrigTauMatching : /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.d /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching.d /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_example.d


-include  /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_Reflex.d /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching.d /home/shepj/xaod/ROOTAnalysisTutorial/RootCoreBin/obj/x86_64-slc6-gcc49-opt/TrigTauMatching/obj/TrigTauMatching_example.d
