void ATestRun (const std::string& submitDir)
{
  //===========================================
  // FOR ROOT6 WE DO NOT PUT THIS LINE 
  // (ROOT6 uses Cling instead of CINT)
  // Load the libraries for all packages
  // gROOT->Macro("$ROOTCOREDIR/scripts/load_packages.C");
  // Instead on command line do:
  // > root -l '$ROOTCOREDIR/scripts/load_packages.C' 'ATestRun.cxx ("submitDir")'
  // The above works for ROOT6 and ROOT5
  //==========================================


  // Set up the job for xAOD access:
  xAOD::Init().ignore();

  // create a new sample handler to describe the data files we use
  SH::SampleHandler sh;

  // scan for datasets in the given directory
  // this works if you are on lxplus, otherwise you'd want to copy over files
  // to your local machine and use a local path.  if you do so, make sure
  // that you copy all subdirectories and point this to the directory
  // containing all the files, not the subdirectories.

  // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:

  //signal 800 170 169
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/20160819/TT_onestepBB_800_170_169_20k/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);
  
  //signal 800 170 150 alt
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/20160819/TT_onestepBB_800_170_150_20k/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 95 75
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_95_75/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 120 100
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_120_100/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 170 150
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_170_150/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 220 200
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_220_200/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 270 250
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_270_250/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 320 300
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_320_300/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 370 350
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_370_350/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 420 400
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_420_400/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 650 470 450
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_650_470_450/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 700 170 150
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_700_170_150/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 750 170 150
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_750_170_150/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 150
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_800_170_150/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 165
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/5GeV/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 166
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/4GeV/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 167
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/3GeV/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 168
  //const char* inputFilePath = gSystem->ExpandPathName ("/home/herwig/Public/forJames/2GeV/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //signal 800 170 169
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.signal_800_170_169/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //ttbar
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.407012.PowhegPythiaEvtGen_P2012CT10_ttbarMET200_hdamp172p5_nonAH.merge.DAOD_TRUTH1.e4023_p2440/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //single top
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.407019.PowhegPythiaEvtGen_P2012CT10_Wt_inclusive_top_MET200.merge.DAOD_TRUTH1.e4024_p2613/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //single tbar
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.407021.PowhegPythiaEvtGen_P2012CT10_Wt_inclusive_tbar_MET200.merge.DAOD_TRUTH1.e4024_p2613/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 0-70
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361302.Sherpa_CT10_Wenu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 70-140
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361305.Sherpa_CT10_Wenu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 140-280
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361308.Sherpa_CT10_Wenu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 280-500
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361311.Sherpa_CT10_Wenu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 500-700
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361314.Sherpa_CT10_Wenu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 700-1000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361317.Sherpa_CT10_Wenu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 1000-2000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361320.Sherpa_CT10_Wenu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->enu 2000-
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361323.Sherpa_CT10_Wenu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 0-70
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361326.Sherpa_CT10_Wmunu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 70-140
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361329.Sherpa_CT10_Wmunu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 140-280
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361332.Sherpa_CT10_Wmunu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3651_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 280-500
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361335.Sherpa_CT10_Wmunu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 500-700
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361338.Sherpa_CT10_Wmunu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 700-1000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361341.Sherpa_CT10_Wmunu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 1000-2000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361344.Sherpa_CT10_Wmunu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->munu 2000-
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361347.Sherpa_CT10_Wmunu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 0-70
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361350.Sherpa_CT10_Wtaunu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3733_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 70-140
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361353.Sherpa_CT10_Wtaunu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3733_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 140-280
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361356.Sherpa_CT10_Wtaunu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3733_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 280-500
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361359.Sherpa_CT10_Wtaunu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 500-700
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361362.Sherpa_CT10_Wtaunu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 700-1000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361365.Sherpa_CT10_Wtaunu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3973_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 1000-2000
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361368.Sherpa_CT10_Wtaunu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W->taunu 2000-
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.361371.Sherpa_CT10_Wtaunu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //W + jets
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/DAOD_TRUTH1.Wjets/");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  //ttbar truth0
  //const char* inputFilePath = gSystem->ExpandPathName ("/disk/userdata00/atlas_data2/shepj/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.DAOD_TRUTH0.e3698_p2440_tid06893394_00");
  //SH::ScanDir().filePattern("*.root*").scan(sh, inputFilePath);

  // set the name of the tree in our files
  // in the xAOD the TTree containing the EDM containers is "CollectionTree"
  sh.setMetaString ("nc_tree", "CollectionTree");

  // further sample handler configuration may go here

  // print out the samples we found
  sh.print ();

  // this is the basic description of our job
  EL::Job job;
  job.sampleHandler (sh); // use SampleHandler in this job
  //job.options()->setDouble (EL::Job::optMaxEvents, 500); // for testing purposes, limit to run over the first 500 events only!

  // add our algorithm to the job
  MyxAODAnalysis *alg = new MyxAODAnalysis;

  // later on we'll add some configuration options for our algorithm that go here

  job.algsAdd (alg);

  // make the driver we want to use:
  // this one works by running the algorithm directly:
  EL::CondorDriver driver;
  // we can use other drivers to run things on the Grid, with PROOF, etc.

  job.options()->setString(EL::Job::optCondorConf, "getenv = True\n nice_user = TRUE");

  // process the job using the driver
  driver.submitOnly (job, submitDir);

  //SH::SampleHandler sh_hist;
  //sh_hist.load ( submitDir + "/hist");
  //TH1F *hist = (TH1F*)sh_hist.get ("DAOD_TRUTH1.signalDAOD.root.root")->readHist ("h_truthLep1_pt_METcut");
  //hist->Draw ();

}
