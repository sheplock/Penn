ls
rm -r histograms_1lep/*
ls histograms
mv histograms/*_1lep.root histograms_1lep/
ls
ls histograms
mkdir histograms_MET_bjets
mv histograms/*_MET_bjets histograms_MET_bjets/
mv histograms/*_MET_bjets.root histograms_MET_bjets/
ls histograms
mkdir histograms_mbb
mv histograms/*_mbb.root histograms_mbb/
ls histograms
ls
rm -r histograms_650_170_150/*
mv histograms/* histograms_650_170_150/
ls histograms
root -b StackPlots.cxx
mkdir histograms_nocuts/
mv histograms/* histograms_nocuts/
ls
root
root -l significance_plot2.root 
ls
root -l histograms_1lep/
root -l histograms_1lep/h_MET_1lep.root 
root -l histograms_1lep/h_lepton_pt_1lep.root 
root -l histograms_MET_bjets/h_dphi_bjet_ptmiss_min_MET_bjets.root 
root -l histograms_MET_bjets/h_mbb_MET_bjets.root 
root -l histograms_MET_bjets/h_amt2_MET_bjets.root 
emacs StackPlots.cxx &
ls
root -l signal_650_120_100/hist-DAOD_TRUTH1.signal_650_120_100.root 
root
root -b StackPlots.cxx
mv histograms/ histograms_noLepCut/
mkdir histograms
root
root -b StackPlots.cxx
mv histograms/ histograms_noMETCut/
mkdir histograms/
root -b StackPlots.cxx
mv histograms/ histograms_nobJetsCut/
mkdir histograms
root -b StackPlots.cxx
mv histograms/ histograms_noCloseMETbCut/
mkdir histograms/
root -b StackPlots.cxx
mv histograms/ histograms_nombbCut/
mkdir histograms
root -l histograms_noLepCut/h_pTlep_noLepCut.root 
root -l histograms_noMETCut/h_MET_noMETCut.root 
root -l histograms_nobJetsCut/h_bjet1pt_nobJetsCut.root 
root -l histograms_nobJetsCut/h_bjet2pt_nobJetsCut.root 
emacs StackPlots.cxx &
root -b StackPlots.cxx
mv histograms/ histograms_noamt2Cut/
mkdir histograms/
root -l histograms_noamt2Cut/h_amt2_noamt2Cut.root 
root -l histograms_noCloseMETbCut/h_dphibMET_noCloseMETbCut.root 
root -l histograms_nombbCut/h_mbb_nombbCut.root 
root -l histograms_650_170_150/
root -l signal_800_170_150/hist-DAOD_TRUTH1.signal_800_170_150.root 
ls
setupATLAS
cd xaod/ROOTAnalysisTutorial/
lsetup rcsetup
ls
cd Run/
ls
root
ls
ls lep_pt_new.root 
root
root -l lep_pt_new.root 
root
ls
setupATLAS
cd xaod/ROOTAnalysisTutorial/
ls
lsetup rcsetup
ls
cd Run/
ls
ls /home/herwig/Public/forJames/newSplittings/
emacs ATestRun_local.cxx &
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun.cxx ("signal_800_159.94_150")'
ls /home/herwig/Public/forJames/newSplittings/159.94/DAOD_TRUTH1.TT_onestepBB_800_159.94_150.DAOD_TRUTH1.pool.root 
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rm -r signal_800_159.94_150/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rc compile
rm -r signal_800_159.94_150/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rm -r signal_800_159.94_150/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rc compile
rm -r signal_800_159.94_150/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rm -r signal_800_159.94_150/
rc compile
rm -r signal_800_159.94_150/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rm -r signal_800_159.94_150/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
rm -r signal_800_159.94_150/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
ls
rc compile
rm -r signal_800_159.94_150/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_150")'
ls /home/herwig/Public/forJames/newSplittings/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_155.49_150")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_153.43_150")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_152.35_150")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_150")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
ls
root
ls
setupATLAS
cd xaod/ROOTAnalysisTutorial/
lsetup rcsetup
ls
cd Run/
ls
root -l lep_pt_new.root 
ls
root
ls
root -l lep_number_new.root 
emacs ATestRun_local.cxx &
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
root -l signal_800_151.22_test/hist-151.22.root 
rc compile
rm -r signal_800_151.22_test/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
ls
mv TMVA-v4.2.0 tmva
rm TMVA-v4.2.0\ \(1\).tgz 
mv tmva TMVA-v4.2.0
ls
setupATLAS
cd xaod/ROOTAnalysisTutorial/
lsetup rcsetup
emacs MyAnalysis/Root/MyxAODAnalysis.cxx
bg
cd Run/
ls
rc compile
less sum_weights 
ls
rm -r signal_800_151.22_*
rm -r signal_800_152.35_150/
rm -r signal_800_155.49_150/
rm -r signal_800_159.94_150/
rm -r signal_N2toN1/
ls
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rm -r signal_800_159.94_test/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rm -r signal_800_159.94_test/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rm -r signal_800_159.94_test/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rc compile
rm -r signal_800_159.94_test/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94_test")'
rm -r signal_800_159.94_test/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94")'
root -l signal_800_159.94/hist-159.94.root 
rc compile
rm -r signal_800_159.94/hist-159.94.root 
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94")'
rm -r signal_800_159.94/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_159.94")'
root -l signal_800_159.94/hist-159.94.root 
ls
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_155.49")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_153.43")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_152.35")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22")'
rc compile
rm -r signal_800_151.22/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22")'
rm -r signal_800_151.22/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22")'
rc compile
ls
rm -r signal_800_151.22/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22")'
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
rm -r signal_N2toN1/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
rm -r signal_800_151.22_test/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
rc compile
rm -r signal_800_151.22_test/
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
rm -r signal_800_151.22_test/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_800_151.22_test")'
rm -r signal_800_151.22_test/
rm -r signal_N2toN1/
rc compile
ls
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
rm -r signal_N2toN1/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
rm -r signal_N2toN1/
rc compile
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1")'
ls
root
rm lep_number_new.root 
rm lep_pt_new.root 
root
ls
ls id_c1_children.root 
root
ls
root -l id_c1_children.root 
root -l lep_number_new.root 
root -l lep_pt_new.root 
root -l id_c1_children.root 
setupATLAS
lsetup rcsetup
cd xaod/ROOTAnalysisTutorial/
lsetup rcsetup
ls
cd RU
cd Run/
ls
root -l signal_650_170_150/
root -l signal_650_170_150/hist-DAOD_TRUTH1.signal_650_170_150.root 
emacs ../MyAnalysis/Root/MyxAODAnalysis.cxx
setupATLAS
cd xaod/ROOTAnalysisTutorial/
lsetup rcsetup
ls
cd RU
cd Run/
ls
emacs ../MyAnalysis/Root/MyxAODAnalysis.cxx &
rc compile
ls
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1_test")'
ls
root -l signal_N2toN1_test/hist-N2toN1.root 
rm -r signal_N2toN1_test/
rc compile
root -l signal_N2toN1_test/hist-N2toN1.root 
root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun_local.cxx ("signal_N2toN1_test")'
root -l signal_N2toN1_test/hist-N2toN1.root 
ls
setupATLAS
cd TMVA-v4.2.0/
lsetup root -h
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
ls
cd test/
ls
root -l TMVA.root 
ls
emacs TMVAClassification.C &
ls
ls /home/herwig/Public/forJames/
ls /home/herwig/Public/forJames/bCsoft/
ls /home/herwig/Public/forJames/bCsoft/TT_onestepBB_650_170_150/
root -l /home/herwig/Public/forJames/bCsoft/TT_onestepBB_650_170_150/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.DAOD_SUSY5.root 
ls
setupATLAS
cd TMVA-v4.2.0/
ls
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
ls
cd test
emacs TMVAClassification.C &
root -l /home/herwig/Public/forJames/bCsoft/TT_onestepBB_650_170_150/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.DAOD_SUSY5.root 
root -l /home/herwig/Public/forJames/bCsoft/ttbar/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY5.root 
ls
root -l /home/herwig/Public/forJames/bCsoft/TT_onestepBB_650_170_150/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.DAOD_SUSY5.root 
ls
root -l TMVAClassification.C\(\"Cuts\"\)
root -l TMVAClassification.C\(\"Cuts\"\)+
root -l TMVAClassification.C\(\"Cuts\"\)
ls
cd weights/
ls
emacs TMVAClassification_Cuts.weights.xml 
ls
cd ..
ls
root -l TMVA.root 
ls
root -l TMVAClassification.C\(\"Cuts\"\)
ls
cd plot
cd plots/
ls
root -l
ls
cd ..
ls
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
cd test/
ls
ls /home/herwig/Public/forJames/bCsoft/
ls /home/herwig/Public/forJames/bCsoft/wjets_22/
emacs /home/herwig/Public/forJames/bCsoft/wjets_22/skim.C
ls
ls data/
cd data/
cp /home/herwig/Public/forJames/bCsoft/wjets_22/skim.C skim.C
ls
cp /home/herwig/Public/forJames/bCsoft/wjets_22/all_wjets.root all_wjets.root
ls
emacs skim.C 
bg
root -l all_wjets.root 
root -b skim.C
emacs skim.C &
root -b skim.C
ls
root -l wjets_skim.root 
root
ls
rm -r wjets_skim.root 
root -b skim.C
root -l wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -l all_wjets.root 
root -b skim.C
root -l wjets_skim.root 
rm -r wjets_skim.root 
root -b skim.C
root
ls
rm -r wjets_skim.root 
root -b skim.C
ls
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -l all_wjets.root 
root -b skim.C
ls
root -l wjets_skim.root 
rm -r wjets_skim.root 
root -b skim.C
ls
root -l wjets_skim.root 
ls
rm -r wjets_skim.root 
root -b skim.C
ls
root -l wjets_skim.root 
root -b skim.C
root
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
rm -r wjets_skim.root 
root -b skim.C
ls
setupATLAS
cd TMVA-v4.2.0/
ls
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
ls
cd test
ls
cd data/
ls
cd ..
ls
emacs TMVAClassification.C &
;s
ls
cd data/
ls
pwd
ls
root -l singletop_skim.root 
root -l TMVAClassification.C\(\"Cuts\"\)
cd ..
root -l TMVAClassification.C\(\"Cuts\"\)
cd data
ls
emacs skim.C &
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_650_170_150/
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_650_170_150/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.DAOD_SUSY5.root 
emacs skim.C &
root -b skim.C
ls
root -l TT_onestepBB_650_170_150_skim.root 
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_650_170_150/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.DAOD_SUSY5.root 
root -l TT_onestepBB_650_170_150_skim.root 
root -l TMVAClassification.C\(\"Cuts\"\)
cd ..
root -l TMVAClassification.C\(\"Cuts\"\)
emacs TMVAClassification.C 
bg
root -l TMVAClassification.C\(\"Cuts\"\)
ls
cd plots/
ls
root -l mvaeffs_Cuts.eps
rootmvaeffs_Cuts.eps
root mvaeffs_Cuts.eps
root mvaeffs_Cuts.png
root -l mvaeffs_Cuts.png
ls
cd ..
root -l data/TT_onestepBB_650_170_150_skim.root 
root -l TMVAClassification.C\(\"Cuts\"\)
ls
cd weights
ls
emacs TMVAClassification_Cuts.weights.xml 
ls
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
cd test/
ls
emacs TMVAClassification.C &
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
cd test/
ls
cd weights/
ls
emacs TMVAClassification_CutsGA.class.C 
ls /disk/userdata00/atlas_data2/shepj/
ls /disk/userdata00/atlas_data2/shepj/oldfiles/
rm -r /disk/userdata00/atlas_data2/shepj/oldfiles/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387603.MGPy8EG_A14N_TT_onestepBB_650_95_75_MET60.evgen.EVNT.e4079_tid05760355_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387604.MGPy8EG_A14N_TT_onestepBB_650_120_100_MET60.evgen.EVNT.e4079_tid05760357_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387605.MGPy8EG_A14N_TT_onestepBB_650_170_150_MET60.evgen.EVNT.e4079/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387606.MGPy8EG_A14N_TT_onestepBB_650_220_200_MET60.evgen.EVNT.e4079_tid05760359_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387607.MGPy8EG_A14N_TT_onestepBB_650_270_250_MET60.evgen.EVNT.e4079_tid05760360_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387608.MGPy8EG_A14N_TT_onestepBB_650_320_300_MET60.evgen.EVNT.e4079_tid05760361_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387609.MGPy8EG_A14N_TT_onestepBB_650_370_350_MET60.evgen.EVNT.e4079_tid05760362_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387610.MGPy8EG_A14N_TT_onestepBB_650_420_400_MET60.evgen.EVNT.e4079_tid05760363_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387611.MGPy8EG_A14N_TT_onestepBB_650_470_450_MET60.evgen.EVNT.e4079_tid05760364_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387614.MGPy8EG_A14N_TT_onestepBB_700_170_150_MET60.evgen.EVNT.e4079_tid05760367_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387623.MGPy8EG_A14N_TT_onestepBB_750_170_150_MET60.evgen.EVNT.e4079_tid05760378_00/
rm -r /disk/userdata00/atlas_data2/shepj/mc15_13TeV.387632.MGPy8EG_A14N_TT_onestepBB_800_170_150_MET60.evgen.EVNT.e4079_tid05760387_00/
cd /disk/userdata00/atlas_data2/shepj/
ls
rm -r mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.DAOD_TRUTH0.e3698_p2440_tid06893394_00/
du -sh */
du -sh
ls
rm -r DAOD_TRUTH1.Wjets/
du -sh
cd /home/shepj/TMVA-v4.2.0/test/
ls

root -l TMVAClassification.C\(\"CutsGA\"\)
ls /disk/userdata00/atlas_data2/herwig/bCsoft/
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
ls /disk/userdata00/atlas_data2/herwig/bCsoft/
ls /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_600_220_200/mc15_13TeV.387597.MGPy8EG_A14N_TT_onestepBB_600_220_200_MET60.DAOD_SUSY5.root 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
ls /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_700_120_100/mc15_13TeV.387613.MGPy8EG_A14N_TT_onestepBB_700_120_100_MET60.DAOD_SUSY5.root 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
ls
setupATLAS
cd TMVA-v4.2.0/
ls
lsetup "root 5.34.00-x86_64-slc5-gcc43-opt"
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test
ls
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
emacs weights/TMVAClassification_CutsGA.weights.xml 
ls
bg
ls
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
ls /disk/userdata00/atlas_data2/herwig/bCsoft/
ls
cd data/
ls
hadd -help
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
cd ..
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
ls
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
ls
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
bg
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
bg
ls
setupATLAS
ls
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test
emacs TMVAClassification.C &
ls
cd histos/
mk histos.root
root
setupATLAS
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd TMVA-v4.2.0/
cd test
ls
emacs TMVAClassification.C &
emacs cut.log
rm cut.log
root -l TMVAClassification.C\(\"CutsGA\"\) > cut.log
ls
emacs cut.log &
root -l TMVA.root 
ls
root -l TMVAClassification.C\(\"CutsGA\"\) > cut.log
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
emacs mvaeffs.C
bg
setupATLAS
ls
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
ls
emacs TMVAClassification.C &
emacs mvaeffs.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
rc compile
lsetup rcsetup
rc compile
compile
emacs README 
ls
cd ..
ls
make
ls
cd test/
ls
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
cd TMVA-v4.2.0/
ls
cd test/
ls
bg
ls
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
ls
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test/
ls
cd /home/herwig/Public/forJames/commoncode/
ls
emacs doAllSig.C &
cd /home/shepj/TMVA-v4.2.0/test/
ls
mkdir significance
cd significance/
ls
cp --help
cp /home/herwig/Public/forJames/commoncode/doAllSig.C 
cp /home/herwig/Public/forJames/commoncode/doAllSig.C doAllSig.C
ls
pwd
ls
cd ..
ls
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
ls
s
ls
cd significance/
ls
emacs doAllSig.C &
root doAllSig.C
root -b doAllSig.C
cd /home/herwig/Public/forJames/commoncode/
ls
root doAllSig.C 
cd /home/shepj/TMVA-v4.2.0/test/significance/
lsetup root
root doAllSig.C 
ls
root out.root 
ls
cd ..
ls
emacs mvaeffs.C &
root -l TMVA.root 
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
emacs mvaeffs.C &
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
root -l TMVAClassification.C\(\"CutsGA\"\)
ls
setupATLAS
cd TMVA-v4.2.0/
ls
lsetup root
cd test/
ls
cd significance/
ls
emacs doAllSig.C &
root -l out.root 
ls
jobs
kill %2
ls
root doAllSig.C
root -l out.root 
root doAllSig.C
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test/
ls
emacs TMVAClassification.C &
ls
setupATLAS
ls
cd TMVA-v4.2.0/
ls
cd test/
ls
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
emacs TMVAClassification.C &
emacs significance/doAllSig.C &
emacs mvaeffs.C &
emacs significance/doAllSig.C &
ls
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
emacs significance/doAllSig.C
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
cd significance/
ls
emacs /home/herwig/Public/forJames/commoncode/calcSig.C 
ls
cp /home/herwig/Public/forJames/commoncode/calcSig.C calcSig.C
ls
emacs calcSig.C &
ls
calcSig.C("sig.root","sf_total * (HLT_xe100_mht_L1XE50 && met>240000 && n_bjet>=2 && bjet_pt[0]>175000 && bjet_pt[1]>85000 && amt2 > 350 && dphi_b_ptmiss_min > 0.9 && m_bb > 240000 && lepPt_over_met<0.04)")
root calcSig.C("sig.root","sf_total * (HLT_xe100_mht_L1XE50 && met>240000 && n_bjet>=2 && bjet_pt[0]>175000 && bjet_pt[1]>85000 && amt2 > 350 && dphi_b_ptmiss_min > 0.9 && m_bb > 240000 && lepPt_over_met<0.04)")
ls
cd ..
ls
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_700_270_250/mc15_13TeV.387616.MGPy8EG_A14N_TT_onestepBB_700_270_250_MET60.DAOD_SUSY5.root 
setupATLAS
cd TMVA-v4.2.0/
cd test/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_800_170_150/mc15_13TeV.387632.MGPy8EG_A14N_TT_onestepBB_800_170_150_MET60.DAOD_SUSY5.root 
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
emacs mvaeffs.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_800_170_150/mc15_13TeV.387632.MGPy8EG_A14N_TT_onestepBB_800_170_150_MET60.DAOD_SUSY5.root 
setupATLAS
cd TMVA-v4.2.0/
lsetup root
cd test/
cd significance/
ls
emacs doAllSig.C &
root doAllSig.C
setupATLAS
ls
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
ls
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
ls
cd TMVA-v4.2.0/
ls
lsetup root
cd test/
ls
cd significance/
emacs doAllSig.C
root doAllSig.C
setupATLAS
cd TMVA-v4.2.0/
ls
cd test/
lsetup rot
lsetup root
cd
cd tes
cd test
cd TMVA-v4.2.0/
cd test/
ls
root -l /disk/userdata00/atlas_data2/herwig/bCsoft/TT_onestepBB_600_370_350/mc15_13TeV.387600.MGPy8EG_A14N_TT_onestepBB_600_370_350_MET60.DAOD_SUSY5.root 
ls
cd significance/
ls
root -l out.root 
ls /disk/userdata00/atlas_data2/herwig/bCsoft/
root -l ../data/all_ttbar.root 
root -l ../data/all_singletop.root 
root -l ../data/all_wjets.root 
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
ls
cd test
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test
emacs TMVAClassification.C &
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
setupATLAS
ls
cd TMVA-v4.2.0/
lsetup root
cd test/
ls
cd significance/
emacs doAllSig.C &
root doAllSig.C
ls
mv out.root out_800_100.root
root -l out_800_100.root 
ls
cd doAllSig.C doAllSig_shapeFit.C
cp doAllSig.C doAllSig_shapeFit.C
ls
emacs doAllSig_shapeFit.C 
root doAllSig_shapeFit.C
emacs doAllSig_shapeFit.C
bg
root doAllSig_shapeFit.C
ls
root
ls
root -l out_shapeFit.root 
root -l out_800_100.root 
setupATLAS
cd TMVA-v4.2.0/
lsetup root
cd test/
ls
emacs TMVAClassification.C &
cd significance/
ls
emacs doAllSig_shapeFit.C
bg
cd ..
ls
cd ..
ls
cd ..
ls
emacs xaod/
cd xaod/
ls
cd ..
ls
cd derivation/
ls
cd 20.1.5.4/
ls
cd WorkArea/
ls
cd run/
ls
cd ..
ls
cd python/
ls
cd ..
ls
cd ..
ls
cd ..
ls
cd 20.7.6.4/
ls
cd WorkArea/
ls
cd run/
ls
cd ..
ls
cd ..
ls
cd ..
ls
cd ..
ls
cd xaod/
ls
cd ROOTAnalysisTutorial/
ls
cd Run/
ls
emacs ClassifyHistograms
bg
emacs sum_weights
bg
cd
ls
cd TMVA-v4.2.0/
cd test/
ls
emacs significance/
cd plot
cd plots/
ls
cd ..
ls
cd significance/
ls
emacs makePlots.C
bg
root
ls
root makePlots.C
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
root -l /disk/userdata00/atlas_data2/herwig/ntuples/161213/TT_onestepBB_800_120_100/mc15_13TeV.387631.MGPy8EG_A14N_TT_onestepBB_800_120_100_MET60.DAOD_SUSY5.root 
root -l data/all_ttbar_new.root 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
ls
emacs TMVAClassification.C &
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l TMVAClassification.C\(\"CutsGA\"\)
emacs weights/TMVAClassification_CutsGA.weights.xml 
root -l /disk/userdata00/atlas_data2/herwig/ntuples/161213/TT_onestepBB_800_120_100/mc15_13TeV.387631.MGPy8EG_A14N_TT_onestepBB_800_120_100_MET60.DAOD_SUSY5.root 
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
cd test/
emacs TMVAClassification.C &
setupATLAS
cd TMVA-v4.2.0/
lsetup "root 5.34.10-x86_64-slc5-gcc43-opt"
setupATLAS
root
lsetup root
root
setupATLAS
lsetup root
root
