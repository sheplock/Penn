#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyAnalysis/MyxAODAnalysis.h>

#include "CPAnalysisExamples/errorcheck.h"

// EDM includes:
#include "xAODEventInfo/EventInfo.h"
#include "xAODTruth/TruthEvent.h"
#include "xAODTruth/TruthEventContainer.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/ShallowCopy.h"
#include "xAODPrimitives/xAODPrimitivesDict.h"

// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"

#include "/home/shepj/xaod/ROOTAnalysisTutorial/Run/MT2_ROOT.h"

// this is needed to distribute the algorithm to the workers
ClassImp(MyxAODAnalysis)

MyxAODAnalysis :: MyxAODAnalysis ()
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().
}



EL::StatusCode MyxAODAnalysis :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.

  // let's initialize the algorithm to use the xAODRootAccess package
  job.useXAOD ();
  xAOD::Init( "MyxAODAnalysis" ).ignore(); // call before opening first file

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  h_num_electrons = new TH1F("h_num_electrons", "h_num_electrons", 5, 0, 5);
  h_num_muons = new TH1F("h_num_muons", "h_num_muons", 5, 0, 5);
  h_num_bjets = new TH1F("h_num_bjets", "h_num_bjets", 5, 0, 5);
  h_num_non_bjets = new TH1F("h_num_non_bjets", "h_num_non_bjets", 10, 0, 10);

  h_W_children = new TH1F("h_W_children", "h_W_children", 40, -20, 20);

  h_bjet1_pt = new TH1F("h_bjet1_pt", "h_bjet1_pt", 100, 0, 1000);
  h_bjet2_pt = new TH1F("h_bjet2_pt", "h_bjet2_pt", 100, 0, 1000);

  h_jj_inv_mass = new TH1F("h_jj_inv_mass", "h_jj_inv_mass", 100, 0, 200);
  h_W_mass = new TH1F("h_W_mass", "h_W_mass", 100, 0, 200);

  h_num_jets = new TH1F("h_num_jets", "h_num_jets", 10, 0, 10);
  h_lepton_pt_0GeV = new TH1F("h_lepton_pt_0GeV", "h_lepton_pt_0GeV", 100, 0, 100);
  h_lepton_pt_MET_b_cuts = new TH1F("h_lepton_pt_MET_b_cuts", "h_lepton_pt_MET_b_cuts", 100, 0, 100);
  h_lepton_pt_MET_b_cuts->Sumw2();
  h_lepton_pt = new TH1F("h_lepton_pt", "h_lepton_pt", 100, 0, 100);
  h_num_leptons = new TH1F("h_num_leptons", "h_num_leptons", 5, 0, 5);
  h_num_leptons->Sumw2();
  h_MET_0GeV = new TH1F("h_MET_0GeV", "h_MET_0GeV", 100, 0, 1000);
  h_MET_200GeV = new TH1F("h_MET_200GeV", "h_MET_200GeV", 100, 0, 1000);

  h_num_jets_200MET = new TH1F("h_num_jets_200MET", "h_num_jets_200MET", 10, 0, 10);
  h_lepton_pt_200MET = new TH1F("h_lepton_pt_200MET", "h_lepton_pt_200MET", 100, 0, 100);
  h_num_leptons_200MET = new TH1F("h_num_leptons_200MET", "h_num_leptons_200MET", 5, 0, 5);
  h_MET_200MET = new TH1F("h_MET_200MET", "h_MET_200MET", 100, 0, 1000);
  h_bjet1_pt_200MET = new TH1F("h_bjet1_pt_200MET", "h_bjet1_pt_200MET", 100, 0, 1000);
  h_bjet2_pt_200MET = new TH1F("h_bjet2_pt_200MET", "h_bjet2_pt_200MET", 100, 0, 1000);




  h_num_leptons_nocuts = new TH1F("h_num_leptons_nocuts", "h_num_leptons_nocuts", 5, 0, 5);
  h_jj_inv_mass_nocuts = new TH1F("h_jj_inv_mass_nocuts", "h_jj_inv_mass_nocuts", 100, 0, 200);

  h_num_jets_nocuts = new TH1F("h_num_jets_nocuts", "h_num_jets_nocuts", 10, 0, 10);
  h_num_jets_nocuts->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_nocuts->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_nocuts = new TH1F("h_num_bjets_nocuts", "h_num_bjets_nocuts", 10, 0, 10);
  h_num_bjets_nocuts->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_nocuts->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_nocuts = new TH1F("h_num_non_bjets_nocuts", "h_num_non_bjets_nocuts", 10, 0, 10);
  h_num_non_bjets_nocuts->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_nocuts->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_nocuts = new TH1F("h_lepton_pt_nocuts", "h_lepton_pt_nocuts", 1000, 0, 1000);
  h_lepton_pt_nocuts->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_nocuts->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_nocuts = new TH1F("h_MET_nocuts", "h_MET_nocuts", 100, 0, 1000);
  h_MET_nocuts->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_nocuts = new TH1F("h_bjet1_pt_nocuts", "h_bjet1_pt_nocuts", 100, 0, 1000);
  h_bjet1_pt_nocuts->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_nocuts = new TH1F("h_bjet2_pt_nocuts", "h_bjet2_pt_nocuts", 100, 0, 1000);
  h_bjet2_pt_nocuts->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_nocuts = new TH1F("h_non_bjet1_pt_nocuts", "h_non_bjet1_pt_nocuts", 100, 0, 1000);
  h_non_bjet1_pt_nocuts->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_nocuts = new TH1F("h_non_bjet2_pt_nocuts", "h_non_bjet2_pt_nocuts", 100, 0, 1000);
  h_non_bjet2_pt_nocuts->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_nocuts = new TH1F("h_bjet_ratio_nocuts", "h_bjet_ratio_nocuts", 100, 0, 1);
  h_bjet_ratio_nocuts->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_nocuts->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_nocuts = new TH1F("h_dphi_bjet_lepton_max_nocuts","h_dphi_bjet_lepton_max_nocuts", 100, -5, 5);
  h_dphi_bjet_lepton_max_nocuts->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_nocuts = new TH1F("h_dphi_bjet_lepton_min_nocuts","h_dphi_bjet_lepton_min_nocuts", 100, -5, 5);
  h_dphi_bjet_lepton_min_nocuts->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_nocuts = new TH1F("h_dphi_bjet_ptmiss_max_nocuts","h_dphi_bjet_ptmiss_max_nocuts", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_nocuts->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_nocuts = new TH1F("h_dphi_bjet_ptmiss_min_nocuts","h_dphi_bjet_ptmiss_min_nocuts", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_nocuts->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_nocuts = new TH1F("h_dphi_b1_b2_nocuts","h_dphi_b1_b2_nocuts", 100, -5, 5);
  h_dphi_b1_b2_nocuts->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2)");
  h_dphi_b1_b2_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_lep_ptmiss_nocuts = new TH1F("h_dphi_lep_ptmiss_nocuts","h_dphi_lep_ptmiss_nocuts", 100, -5, 5);
  h_dphi_lep_ptmiss_nocuts->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_nocuts = new TH1F("h_mbb_nocuts", "h_mbb_nocuts", 100, 0, 1000);
  h_mbb_nocuts->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_nocuts = new TH1F("h_amt2_nocuts", "h_amt2_nocuts", 100, 0, 1000);
  h_amt2_nocuts->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_nocuts = new TH1F("h_amt2_alt_nocuts", "h_amt2_alt_nocuts", 100, 0, 500);
  h_amt2_alt_nocuts->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_nocuts->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_nocuts = new TH1F("h_mlb1_nocuts", "h_mlb1_nocuts", 100, 0, 1000);
  h_mlb1_nocuts->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_nocuts = new TH1F("h_mlb2_nocuts", "h_mlb2_nocuts", 100, 0, 1000);
  h_mlb2_nocuts->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mT_lepMET_nocuts = new TH1F("h_mT_lepMET_nocuts", "h_mT_lepMET_nocuts", 100, 0, 1000);
  h_mT_lepMET_nocuts->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_meff_nocuts = new TH1F("h_meff_nocuts", "h_meff_nocuts", 100, 0, 5000);
  h_meff_nocuts->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_nocuts->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_nocuts = new TH1F("h_meff_minus_bjets_nocuts", "h_meff_minus_bjets_nocuts", 100, 0, 2500);
  h_meff_minus_bjets_nocuts->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_nocuts->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_nocuts = new TH1F("h_hT_nocuts", "h_hT_nocuts", 100, 0, 2500);
  h_hT_nocuts->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_nocuts->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_nocuts = new TH1F("h_hT_minus_bjets_nocuts", "h_hT_minus_bjets_nocuts", 100, 0, 2500);
  h_hT_minus_bjets_nocuts->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_nocuts->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_nocuts = new TH1F("h_mjj_max_nocuts", "h_mjj_max_nocuts", 100, 0, 1000);
  h_mjj_max_nocuts->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_nocuts = new TH1F("h_mjj_min_nocuts", "h_mjj_min_nocuts", 40, 0, 200);
  h_mjj_min_nocuts->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_nocuts->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_pTlep_MET_nocuts = new TH1F("h_pTlep_MET_nocuts","h_pTlep_MET_nocuts", 500, 0, 5);
  h_pTlep_MET_nocuts->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_nocuts->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_nocuts = new TH1F("h_pTlep_MET2_nocuts","h_pTlep_MET2_nocuts", 500, 0, 5);
  h_pTlep_MET2_nocuts->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_nocuts->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_nocuts = new TH1F("h_METproj_nocuts", "h_METproj_nocuts", 100, 0, 1000);
  h_METproj_nocuts->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_nocuts = new TH1F("h_dR_b1b2_nocuts", "h_dR_b1b2_nocuts", 50, 0, 5);
  h_dR_b1b2_nocuts->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_nocuts->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_nocuts = new TH1F("h_m_lvb_max_nocuts", "h_m_lvb_max_nocuts", 200, 0, 2000);
  h_m_lvb_max_nocuts->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_nocuts = new TH1F("h_m_lvb_min_nocuts", "h_m_lvb_min_nocuts", 100, 0, 1000);
  h_m_lvb_min_nocuts->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_nocuts->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_leptons_1lep = new TH1F("h_num_leptons_1lep", "h_num_leptons_1lep", 5, 0, 5);
  h_jj_inv_mass_1lep = new TH1F("h_jj_inv_mass_1lep", "h_jj_inv_mass_1lep", 100, 0, 200);

  h_num_jets_1lep = new TH1F("h_num_jets_1lep", "h_num_jets_1lep", 10, 0, 10);
  h_num_jets_1lep->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_1lep->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_1lep = new TH1F("h_num_bjets_1lep", "h_num_bjets_1lep", 10, 0, 10);
  h_num_bjets_1lep->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_1lep->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_1lep = new TH1F("h_num_non_bjets_1lep", "h_num_non_bjets_1lep", 10, 0, 10);
  h_num_non_bjets_1lep->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_1lep->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_1lep = new TH1F("h_lepton_pt_1lep", "h_lepton_pt_1lep", 1000, 0, 1000);
  h_lepton_pt_1lep->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_1lep->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_1lep = new TH1F("h_MET_1lep", "h_MET_1lep", 100, 0, 1000);
  h_MET_1lep->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_1lep = new TH1F("h_bjet1_pt_1lep", "h_bjet1_pt_1lep", 100, 0, 1000);
  h_bjet1_pt_1lep->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_1lep = new TH1F("h_bjet2_pt_1lep", "h_bjet2_pt_1lep", 100, 0, 1000);
  h_bjet2_pt_1lep->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_1lep = new TH1F("h_non_bjet1_pt_1lep", "h_non_bjet1_pt_1lep", 100, 0, 1000);
  h_non_bjet1_pt_1lep->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_1lep = new TH1F("h_non_bjet2_pt_1lep", "h_non_bjet2_pt_1lep", 100, 0, 1000);
  h_non_bjet2_pt_1lep->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_1lep = new TH1F("h_bjet_ratio_1lep", "h_bjet_ratio_1lep", 100, 0, 1);
  h_bjet_ratio_1lep->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_1lep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_1lep = new TH1F("h_dphi_bjet_lepton_max_1lep","h_dphi_bjet_lepton_max_1lep", 100, -5, 5);
  h_dphi_bjet_lepton_max_1lep->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_1lep = new TH1F("h_dphi_bjet_lepton_min_1lep","h_dphi_bjet_lepton_min_1lep", 100, -5, 5);
  h_dphi_bjet_lepton_min_1lep->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_1lep = new TH1F("h_dphi_bjet_ptmiss_max_1lep","h_dphi_bjet_ptmiss_max_1lep", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_1lep->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_1lep = new TH1F("h_dphi_bjet_ptmiss_min_1lep","h_dphi_bjet_ptmiss_min_1lep", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_1lep->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_1lep = new TH1F("h_dphi_b1_b2_1lep","h_dphi_b1_b2_1lep", 100, -5, 5);
  h_dphi_b1_b2_1lep->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2)");
  h_dphi_b1_b2_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_lep_ptmiss_1lep = new TH1F("h_dphi_lep_ptmiss_1lep","h_dphi_lep_ptmiss_1lep", 100, -5, 5);
  h_dphi_lep_ptmiss_1lep->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_1lep = new TH1F("h_mbb_1lep", "h_mbb_1lep", 100, 0, 1000);
  h_mbb_1lep->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_1lep = new TH1F("h_amt2_1lep", "h_amt2_1lep", 100, 0, 1000);
  h_amt2_1lep->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_1lep = new TH1F("h_amt2_alt_1lep", "h_amt2_alt_1lep", 100, 0, 500);
  h_amt2_alt_1lep->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_1lep->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_1lep = new TH1F("h_mlb1_1lep", "h_mlb1_1lep", 100, 0, 1000);
  h_mlb1_1lep->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_1lep = new TH1F("h_mlb2_1lep", "h_mlb2_1lep", 100, 0, 1000);
  h_mlb2_1lep->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mT_lepMET_1lep = new TH1F("h_mT_lepMET_1lep", "h_mT_lepMET_1lep", 100, 0, 1000);
  h_mT_lepMET_1lep->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_meff_1lep = new TH1F("h_meff_1lep", "h_meff_1lep", 100, 0, 5000);
  h_meff_1lep->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_1lep->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_1lep = new TH1F("h_meff_minus_bjets_1lep", "h_meff_minus_bjets_1lep", 100, 0, 2500);
  h_meff_minus_bjets_1lep->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_1lep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_1lep = new TH1F("h_hT_1lep", "h_hT_1lep", 100, 0, 2500);
  h_hT_1lep->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_1lep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_1lep = new TH1F("h_hT_minus_bjets_1lep", "h_hT_minus_bjets_1lep", 100, 0, 2500);
  h_hT_minus_bjets_1lep->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_1lep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_1lep = new TH1F("h_mjj_max_1lep", "h_mjj_max_1lep", 100, 0, 1000);
  h_mjj_max_1lep->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_1lep = new TH1F("h_mjj_min_1lep", "h_mjj_min_1lep", 40, 0, 200);
  h_mjj_min_1lep->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_1lep->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_pTlep_MET_1lep = new TH1F("h_pTlep_MET_1lep","h_pTlep_MET_1lep", 500, 0, 5);
  h_pTlep_MET_1lep->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_1lep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_1lep = new TH1F("h_pTlep_MET2_1lep","h_pTlep_MET2_1lep", 500, 0, 5);
  h_pTlep_MET2_1lep->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_1lep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_1lep = new TH1F("h_METproj_1lep", "h_METproj_1lep", 100, 0, 1000);
  h_METproj_1lep->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_1lep = new TH1F("h_dR_b1b2_1lep", "h_dR_b1b2_1lep", 50, 0, 5);
  h_dR_b1b2_1lep->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_1lep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_1lep = new TH1F("h_m_lvb_max_1lep", "h_m_lvb_max_1lep", 200, 0, 2000);
  h_m_lvb_max_1lep->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_1lep = new TH1F("h_m_lvb_min_1lep", "h_m_lvb_min_1lep", 100, 0, 1000);
  h_m_lvb_min_1lep->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_1lep->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_leptons_MET_bjets = new TH1F("h_num_leptons_MET_bjets", "h_num_leptons_MET_bjets", 5, 0, 5);
  h_jj_inv_mass_MET_bjets = new TH1F("h_jj_inv_mass_MET_bjets", "h_jj_inv_mass_MET_bjets", 100, 0, 200);

  h_num_jets_MET_bjets = new TH1F("h_num_jets_MET_bjets", "h_num_jets_MET_bjets", 10, 0, 10);
  h_num_jets_MET_bjets->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_MET_bjets->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_MET_bjets = new TH1F("h_num_bjets_MET_bjets", "h_num_bjets_MET_bjets", 10, 0, 10);
  h_num_bjets_MET_bjets->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_MET_bjets->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_MET_bjets = new TH1F("h_num_non_bjets_MET_bjets", "h_num_non_bjets_MET_bjets", 10, 0, 10);
  h_num_non_bjets_MET_bjets->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_MET_bjets->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_MET_bjets = new TH1F("h_lepton_pt_MET_bjets", "h_lepton_pt_MET_bjets", 1000, 0, 1000);
  h_lepton_pt_MET_bjets->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_MET_bjets = new TH1F("h_MET_MET_bjets", "h_MET_MET_bjets", 100, 0, 1000);
  h_MET_MET_bjets->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_MET_bjets = new TH1F("h_bjet1_pt_MET_bjets", "h_bjet1_pt_MET_bjets", 100, 0, 1000);
  h_bjet1_pt_MET_bjets->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_MET_bjets = new TH1F("h_bjet2_pt_MET_bjets", "h_bjet2_pt_MET_bjets", 100, 0, 1000);
  h_bjet2_pt_MET_bjets->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_MET_bjets = new TH1F("h_non_bjet1_pt_MET_bjets", "h_non_bjet1_pt_MET_bjets", 100, 0, 1000);
  h_non_bjet1_pt_MET_bjets->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_MET_bjets = new TH1F("h_non_bjet2_pt_MET_bjets", "h_non_bjet2_pt_MET_bjets", 100, 0, 1000);
  h_non_bjet2_pt_MET_bjets->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_MET_bjets = new TH1F("h_bjet_ratio_MET_bjets", "h_bjet_ratio_MET_bjets", 100, 0, 1);
  h_bjet_ratio_MET_bjets->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_MET_bjets = new TH1F("h_dphi_bjet_lepton_max_MET_bjets","h_dphi_bjet_lepton_max_MET_bjets", 100, -5, 5);
  h_dphi_bjet_lepton_max_MET_bjets->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_MET_bjets = new TH1F("h_dphi_bjet_lepton_min_MET_bjets","h_dphi_bjet_lepton_min_MET_bjets", 100, -5, 5);
  h_dphi_bjet_lepton_min_MET_bjets->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_MET_bjets = new TH1F("h_dphi_bjet_ptmiss_max_MET_bjets","h_dphi_bjet_ptmiss_max_MET_bjets", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_MET_bjets->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_MET_bjets = new TH1F("h_dphi_bjet_ptmiss_min_MET_bjets","h_dphi_bjet_ptmiss_min_MET_bjets", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_MET_bjets->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_MET_bjets = new TH1F("h_dphi_b1_b2_MET_bjets","h_dphi_b1_b2_MET_bjets", 100, -5, 5);
  h_dphi_b1_b2_MET_bjets->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2)");
  h_dphi_b1_b2_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_lep_ptmiss_MET_bjets = new TH1F("h_dphi_lep_ptmiss_MET_bjets","h_dphi_lep_ptmiss_MET_bjets", 100, -5, 5);
  h_dphi_lep_ptmiss_MET_bjets->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_MET_bjets = new TH1F("h_mbb_MET_bjets", "h_mbb_MET_bjets", 100, 0, 1000);
  h_mbb_MET_bjets->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_MET_bjets = new TH1F("h_amt2_MET_bjets", "h_amt2_MET_bjets", 100, 0, 1000);
  h_amt2_MET_bjets->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_MET_bjets = new TH1F("h_amt2_alt_MET_bjets", "h_amt2_alt_MET_bjets", 100, 0, 500);
  h_amt2_alt_MET_bjets->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_MET_bjets->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_MET_bjets = new TH1F("h_mlb1_MET_bjets", "h_mlb1_MET_bjets", 100, 0, 1000);
  h_mlb1_MET_bjets->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_MET_bjets = new TH1F("h_mlb2_MET_bjets", "h_mlb2_MET_bjets", 100, 0, 1000);
  h_mlb2_MET_bjets->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mT_lepMET_MET_bjets = new TH1F("h_mT_lepMET_MET_bjets", "h_mT_lepMET_MET_bjets", 100, 0, 1000);
  h_mT_lepMET_MET_bjets->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_meff_MET_bjets = new TH1F("h_meff_MET_bjets", "h_meff_MET_bjets", 100, 0, 5000);
  h_meff_MET_bjets->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_MET_bjets->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_MET_bjets = new TH1F("h_meff_minus_bjets_MET_bjets", "h_meff_minus_bjets_MET_bjets", 100, 0, 2500);
  h_meff_minus_bjets_MET_bjets->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_MET_bjets->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_MET_bjets = new TH1F("h_hT_MET_bjets", "h_hT_MET_bjets", 100, 0, 2500);
  h_hT_MET_bjets->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_MET_bjets->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_MET_bjets = new TH1F("h_hT_minus_bjets_MET_bjets", "h_hT_minus_bjets_MET_bjets", 100, 0, 2500);
  h_hT_minus_bjets_MET_bjets->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_MET_bjets->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_MET_bjets = new TH1F("h_mjj_max_MET_bjets", "h_mjj_max_MET_bjets", 100, 0, 1000);
  h_mjj_max_MET_bjets->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_MET_bjets = new TH1F("h_mjj_min_MET_bjets", "h_mjj_min_MET_bjets", 40, 0, 200);
  h_mjj_min_MET_bjets->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_MET_bjets->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_pTlep_MET_MET_bjets = new TH1F("h_pTlep_MET_MET_bjets","h_pTlep_MET_MET_bjets", 500, 0, 5);
  h_pTlep_MET_MET_bjets->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_MET_bjets = new TH1F("h_pTlep_MET2_MET_bjets","h_pTlep_MET2_MET_bjets", 500, 0, 5);
  h_pTlep_MET2_MET_bjets->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_MET_bjets = new TH1F("h_METproj_MET_bjets", "h_METproj_MET_bjets", 100, 0, 1000);
  h_METproj_MET_bjets->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_MET_bjets = new TH1F("h_dR_b1b2_MET_bjets", "h_dR_b1b2_MET_bjets", 50, 0, 5);
  h_dR_b1b2_MET_bjets->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_MET_bjets->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_MET_bjets = new TH1F("h_m_lvb_max_MET_bjets", "h_m_lvb_max_MET_bjets", 200, 0, 2000);
  h_m_lvb_max_MET_bjets->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_MET_bjets = new TH1F("h_m_lvb_min_MET_bjets", "h_m_lvb_min_MET_bjets", 100, 0, 1000);
  h_m_lvb_min_MET_bjets->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_MET_bjets->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_leptons_mbb = new TH1F("h_num_leptons_mbb", "h_num_leptons_mbb", 5, 0, 5);
  h_jj_inv_mass_mbb = new TH1F("h_jj_inv_mass_mbb", "h_jj_inv_mass_mbb", 100, 0, 200);

  h_num_jets_mbb = new TH1F("h_num_jets_mbb", "h_num_jets_mbb", 10, 0, 10);
  h_num_jets_mbb->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_mbb->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_mbb = new TH1F("h_num_bjets_mbb", "h_num_bjets_mbb", 10, 0, 10);
  h_num_bjets_mbb->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_mbb->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_mbb = new TH1F("h_num_non_bjets_mbb", "h_num_non_bjets_mbb", 10, 0, 10);
  h_num_non_bjets_mbb->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_mbb->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_mbb = new TH1F("h_lepton_pt_mbb", "h_lepton_pt_mbb", 1000, 0, 1000);
  h_lepton_pt_mbb->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_mbb->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_mbb = new TH1F("h_MET_mbb", "h_MET_mbb", 100, 0, 1000);
  h_MET_mbb->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_mbb = new TH1F("h_bjet1_pt_mbb", "h_bjet1_pt_mbb", 100, 0, 1000);
  h_bjet1_pt_mbb->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_mbb = new TH1F("h_bjet2_pt_mbb", "h_bjet2_pt_mbb", 100, 0, 1000);
  h_bjet2_pt_mbb->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_mbb = new TH1F("h_non_bjet1_pt_mbb", "h_non_bjet1_pt_mbb", 100, 0, 1000);
  h_non_bjet1_pt_mbb->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_mbb = new TH1F("h_non_bjet2_pt_mbb", "h_non_bjet2_pt_mbb", 100, 0, 1000);
  h_non_bjet2_pt_mbb->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_mbb = new TH1F("h_bjet_ratio_mbb", "h_bjet_ratio_mbb", 100, 0, 1);
  h_bjet_ratio_mbb->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_mbb->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_mbb = new TH1F("h_dphi_bjet_lepton_max_mbb","h_dphi_bjet_lepton_max_mbb", 100, -5, 5);
  h_dphi_bjet_lepton_max_mbb->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_mbb = new TH1F("h_dphi_bjet_lepton_min_mbb","h_dphi_bjet_lepton_min_mbb", 100, -5, 5);
  h_dphi_bjet_lepton_min_mbb->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_mbb = new TH1F("h_dphi_bjet_ptmiss_max_mbb","h_dphi_bjet_ptmiss_max_mbb", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_mbb->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_mbb = new TH1F("h_dphi_bjet_ptmiss_min_mbb","h_dphi_bjet_ptmiss_min_mbb", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_mbb->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_mbb = new TH1F("h_dphi_b1_b2_mbb","h_dphi_b1_b2_mbb", 100, -5, 5);
  h_dphi_b1_b2_mbb->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2)");
  h_dphi_b1_b2_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_lep_ptmiss_mbb = new TH1F("h_dphi_lep_ptmiss_mbb","h_dphi_lep_ptmiss_mbb", 100, -5, 5);
  h_dphi_lep_ptmiss_mbb->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_mbb = new TH1F("h_mbb_mbb", "h_mbb_mbb", 100, 0, 1000);
  h_mbb_mbb->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_mbb = new TH1F("h_amt2_mbb", "h_amt2_mbb", 100, 0, 1000);
  h_amt2_mbb->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_mbb = new TH1F("h_amt2_alt_mbb", "h_amt2_alt_mbb", 100, 0, 500);
  h_amt2_alt_mbb->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_mbb->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_mbb = new TH1F("h_mlb1_mbb", "h_mlb1_mbb", 100, 0, 1000);
  h_mlb1_mbb->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_mbb = new TH1F("h_mlb2_mbb", "h_mlb2_mbb", 100, 0, 1000);
  h_mlb2_mbb->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mT_lepMET_mbb = new TH1F("h_mT_lepMET_mbb", "h_mT_lepMET_mbb", 100, 0, 1000);
  h_mT_lepMET_mbb->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_meff_mbb = new TH1F("h_meff_mbb", "h_meff_mbb", 100, 0, 5000);
  h_meff_mbb->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_mbb->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_mbb = new TH1F("h_meff_minus_bjets_mbb", "h_meff_minus_bjets_mbb", 100, 0, 2500);
  h_meff_minus_bjets_mbb->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_mbb->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_mbb = new TH1F("h_hT_mbb", "h_hT_mbb", 100, 0, 2500);
  h_hT_mbb->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_mbb->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_mbb = new TH1F("h_hT_minus_bjets_mbb", "h_hT_minus_bjets_mbb", 100, 0, 2500);
  h_hT_minus_bjets_mbb->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_mbb->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_mbb = new TH1F("h_mjj_max_mbb", "h_mjj_max_mbb", 100, 0, 1000);
  h_mjj_max_mbb->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_mbb = new TH1F("h_mjj_min_mbb", "h_mjj_min_mbb", 40, 0, 200);
  h_mjj_min_mbb->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_mbb->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_pTlep_MET_mbb = new TH1F("h_pTlep_MET_mbb","h_pTlep_MET_mbb", 500, 0, 5);
  h_pTlep_MET_mbb->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_mbb->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_mbb = new TH1F("h_pTlep_MET2_mbb","h_pTlep_MET2_mbb", 500, 0, 5);
  h_pTlep_MET2_mbb->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_mbb->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_mbb = new TH1F("h_METproj_mbb", "h_METproj_mbb", 100, 0, 1000);
  h_METproj_mbb->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_mbb = new TH1F("h_dR_b1b2_mbb", "h_dR_b1b2_mbb", 50, 0, 5);
  h_dR_b1b2_mbb->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_mbb->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_mbb = new TH1F("h_m_lvb_max_mbb", "h_m_lvb_max_mbb", 200, 0, 2000);
  h_m_lvb_max_mbb->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_mbb = new TH1F("h_m_lvb_min_mbb", "h_m_lvb_min_mbb", 100, 0, 1000);
  h_m_lvb_min_mbb->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_mbb->GetYaxis()->SetTitle("Number of Events / 10 GeV");




  h_num_leptons_preselection = new TH1F("h_num_leptons_preselection", "h_num_leptons_preselection", 5, 0, 5);
  h_jj_inv_mass_preselection = new TH1F("h_jj_inv_mass_preselection", "h_jj_inv_mass_preselection", 100, 0, 200);

  h_num_jets_preselection = new TH1F("h_num_jets_preselection", "h_num_jets_preselection", 10, 0, 10);
  h_num_jets_preselection->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_preselection->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_preselection = new TH1F("h_num_bjets_preselection", "h_num_bjets_preselection", 10, 0, 10);
  h_num_bjets_preselection->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_preselection->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_preselection = new TH1F("h_num_non_bjets_preselection", "h_num_non_bjets_preselection", 10, 0, 10);
  h_num_non_bjets_preselection->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_preselection->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_preselection = new TH1F("h_lepton_pt_preselection", "h_lepton_pt_preselection", 1000, 0, 1000);
  h_lepton_pt_preselection->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_preselection->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_preselection = new TH1F("h_MET_preselection", "h_MET_preselection", 100, 0, 1000);
  h_MET_preselection->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_preselection = new TH1F("h_bjet1_pt_preselection", "h_bjet1_pt_preselection", 100, 0, 1000);
  h_bjet1_pt_preselection->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_preselection = new TH1F("h_bjet2_pt_preselection", "h_bjet2_pt_preselection", 100, 0, 1000);
  h_bjet2_pt_preselection->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_preselection = new TH1F("h_non_bjet1_pt_preselection", "h_non_bjet1_pt_preselection", 100, 0, 1000);
  h_non_bjet1_pt_preselection->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_preselection = new TH1F("h_non_bjet2_pt_preselection", "h_non_bjet2_pt_preselection", 100, 0, 1000);
  h_non_bjet2_pt_preselection->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_preselection = new TH1F("h_bjet_ratio_preselection", "h_bjet_ratio_preselection", 100, 0, 1);
  h_bjet_ratio_preselection->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_preselection->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_preselection = new TH1F("h_dphi_bjet_lepton_max_preselection","h_dphi_bjet_lepton_max_preselection", 100, -5, 5);
  h_dphi_bjet_lepton_max_preselection->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_preselection = new TH1F("h_dphi_bjet_lepton_min_preselection","h_dphi_bjet_lepton_min_preselection", 100, -5, 5);
  h_dphi_bjet_lepton_min_preselection->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_preselection = new TH1F("h_dphi_bjet_ptmiss_max_preselection","h_dphi_bjet_ptmiss_max_preselection", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_preselection->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_preselection = new TH1F("h_dphi_bjet_ptmiss_min_preselection","h_dphi_bjet_ptmiss_min_preselection", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_preselection->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_preselection = new TH1F("h_dphi_b1_b2_preselection","h_dphi_b1_b2_preselection", 100, -5, 5);
  h_dphi_b1_b2_preselection->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2)");
  h_dphi_b1_b2_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_lep_ptmiss_preselection = new TH1F("h_dphi_lep_ptmiss_preselection","h_dphi_lep_ptmiss_preselection", 100, -5, 5);
  h_dphi_lep_ptmiss_preselection->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_preselection = new TH1F("h_mbb_preselection", "h_mbb_preselection", 100, 0, 1000);
  h_mbb_preselection->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_preselection = new TH1F("h_amt2_preselection", "h_amt2_preselection", 100, 0, 1000);
  h_amt2_preselection->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_preselection = new TH1F("h_amt2_alt_preselection", "h_amt2_alt_preselection", 100, 0, 500);
  h_amt2_alt_preselection->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_preselection->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_preselection = new TH1F("h_mlb1_preselection", "h_mlb1_preselection", 100, 0, 1000);
  h_mlb1_preselection->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_preselection = new TH1F("h_mlb2_preselection", "h_mlb2_preselection", 100, 0, 1000);
  h_mlb2_preselection->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mT_lepMET_preselection = new TH1F("h_mT_lepMET_preselection", "h_mT_lepMET_preselection", 100, 0, 1000);
  h_mT_lepMET_preselection->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_meff_preselection = new TH1F("h_meff_preselection", "h_meff_preselection", 100, 0, 5000);
  h_meff_preselection->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_preselection->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_preselection = new TH1F("h_meff_minus_bjets_preselection", "h_meff_minus_bjets_preselection", 100, 0, 2500);
  h_meff_minus_bjets_preselection->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_preselection->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_preselection = new TH1F("h_hT_preselection", "h_hT_preselection", 100, 0, 2500);
  h_hT_preselection->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_preselection->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_preselection = new TH1F("h_hT_minus_bjets_preselection", "h_hT_minus_bjets_preselection", 100, 0, 2500);
  h_hT_minus_bjets_preselection->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_preselection->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_preselection = new TH1F("h_mjj_max_preselection", "h_mjj_max_preselection", 100, 0, 1000);
  h_mjj_max_preselection->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_preselection = new TH1F("h_mjj_min_preselection", "h_mjj_min_preselection", 40, 0, 200);
  h_mjj_min_preselection->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_preselection->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_pTlep_MET_preselection = new TH1F("h_pTlep_MET_preselection","h_pTlep_MET_preselection", 500, 0, 5);
  h_pTlep_MET_preselection->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_preselection->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_preselection = new TH1F("h_pTlep_MET2_preselection","h_pTlep_MET2_preselection", 500, 0, 5);
  h_pTlep_MET2_preselection->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_preselection->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_preselection = new TH1F("h_METproj_preselection", "h_METproj_preselection", 100, 0, 1000);
  h_METproj_preselection->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_preselection = new TH1F("h_dR_b1b2_preselection", "h_dR_b1b2_preselection", 50, 0, 5);
  h_dR_b1b2_preselection->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_preselection->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_preselection = new TH1F("h_m_lvb_max_preselection", "h_m_lvb_max_preselection", 200, 0, 2000);
  h_m_lvb_max_preselection->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_preselection = new TH1F("h_m_lvb_min_preselection", "h_m_lvb_min_preselection", 100, 0, 1000);
  h_m_lvb_min_preselection->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_preselection->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_jets_preselection_leplep = new TH1F("h_num_jets_preselection_leplep", "h_num_jets_preselection_leplep", 10, 0, 10);
  h_num_jets_preselection_leplep->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_preselection_leplep->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_preselection_leplep = new TH1F("h_num_bjets_preselection_leplep", "h_num_bjets_preselection_leplep", 10, 0, 10);
  h_num_bjets_preselection_leplep->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_preselection_leplep->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_preselection_leplep = new TH1F("h_num_non_bjets_preselection_leplep", "h_num_non_bjets_preselection_leplep", 10, 0, 10);
  h_num_non_bjets_preselection_leplep->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_preselection_leplep->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_preselection_leplep = new TH1F("h_lepton_pt_preselection_leplep", "h_lepton_pt_preselection_leplep", 1000, 0, 1000);
  h_lepton_pt_preselection_leplep->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_preselection_leplep = new TH1F("h_MET_preselection_leplep", "h_MET_preselection_leplep", 100, 0, 1000);
  h_MET_preselection_leplep->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_preselection_leplep = new TH1F("h_bjet1_pt_preselection_leplep", "h_bjet1_pt_preselection_leplep", 100, 0, 1000);
  h_bjet1_pt_preselection_leplep->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_preselection_leplep = new TH1F("h_bjet2_pt_preselection_leplep", "h_bjet2_pt_preselection_leplep", 100, 0, 1000);
  h_bjet2_pt_preselection_leplep->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_preselection_leplep = new TH1F("h_non_bjet1_pt_preselection_leplep", "h_non_bjet1_pt_preselection_leplep", 100, 0, 1000);
  h_non_bjet1_pt_preselection_leplep->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_preselection_leplep = new TH1F("h_non_bjet2_pt_preselection_leplep", "h_non_bjet2_pt_preselection_leplep", 100, 0, 1000);
  h_non_bjet2_pt_preselection_leplep->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_preselection_leplep = new TH1F("h_bjet_ratio_preselection_leplep", "h_bjet_ratio_preselection_leplep", 100, 0, 1);
  h_bjet_ratio_preselection_leplep->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_preselection_leplep = new TH1F("h_dphi_bjet_lepton_max_preselection_leplep","h_dphi_bjet_lepton_max_preselection_leplep", 100, -5, 5);
  h_dphi_bjet_lepton_max_preselection_leplep->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_preselection_leplep = new TH1F("h_dphi_bjet_lepton_min_preselection_leplep","h_dphi_bjet_lepton_min_preselection_leplep", 100, -5, 5);
  h_dphi_bjet_lepton_min_preselection_leplep->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_preselection_leplep = new TH1F("h_dphi_bjet_ptmiss_max_preselection_leplep","h_dphi_bjet_ptmiss_max_preselection_leplep", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_preselection_leplep->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_preselection_leplep = new TH1F("h_dphi_bjet_ptmiss_min_preselection_leplep","h_dphi_bjet_ptmiss_min_preselection_leplep", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_preselection_leplep->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_preselection_leplep = new TH1F("h_dphi_b1_b2_preselection_leplep","h_dphi_b1_b2_preselection_leplep", 100, -5, 5);
  h_dphi_b1_b2_preselection_leplep->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2) )");
  h_dphi_b1_b2_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_preselection_leplep = new TH1F("h_mbb_preselection_leplep", "h_mbb_preselection_leplep", 100, 0, 1000);
  h_mbb_preselection_leplep->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_preselection_leplep = new TH1F("h_amt2_preselection_leplep", "h_amt2_preselection_leplep", 100, 0, 1000);
  h_amt2_preselection_leplep->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_preselection_leplep = new TH1F("h_amt2_alt_preselection_leplep", "h_amt2_alt_preselection_leplep", 100, 0, 500);
  h_amt2_alt_preselection_leplep->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_preselection_leplep = new TH1F("h_mlb1_preselection_leplep", "h_mlb1_preselection_leplep", 100, 0, 1000);
  h_mlb1_preselection_leplep->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_preselection_leplep = new TH1F("h_mlb2_preselection_leplep", "h_mlb2_preselection_leplep", 100, 0, 1000);
  h_mlb2_preselection_leplep->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_hT_preselection_leplep = new TH1F("h_hT_preselection_leplep", "h_hT_preselection_leplep", 100, 0, 2500);
  h_hT_preselection_leplep->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_preselection_leplep = new TH1F("h_hT_minus_bjets_preselection_leplep", "h_hT_minus_bjets_preselection_leplep", 100, 0, 2500);
  h_hT_minus_bjets_preselection_leplep->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_preselection_leplep = new TH1F("h_mjj_max_preselection_leplep", "h_mjj_max_preselection_leplep", 100, 0, 1000);
  h_mjj_max_preselection_leplep->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_preselection_leplep = new TH1F("h_mjj_min_preselection_leplep", "h_mjj_min_preselection_leplep", 40, 0, 200);
  h_mjj_min_preselection_leplep->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_meff_preselection_leplep = new TH1F("h_meff_preselection_leplep", "h_meff_preselection_leplep", 100, 0, 5000);
  h_meff_preselection_leplep->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_preselection_leplep = new TH1F("h_meff_minus_bjets_preselection_leplep", "h_meff_minus_bjets_preselection_leplep", 100, 0, 2500);
  h_meff_minus_bjets_preselection_leplep->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mT_lepMET_preselection_leplep = new TH1F("h_mT_lepMET_preselection_leplep", "h_mT_lepMET_preselection_leplep", 100, 0, 1000);
  h_mT_lepMET_preselection_leplep->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_dphi_lep_ptmiss_preselection_leplep = new TH1F("h_dphi_lep_ptmiss_preselection_leplep","h_dphi_lep_ptmiss_preselection_leplep", 100, -5, 5);
  h_dphi_lep_ptmiss_preselection_leplep->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_METproj_preselection_leplep = new TH1F("h_METproj_preselection_leplep", "h_METproj_preselection_leplep", 100, 0, 1000);
  h_METproj_preselection_leplep->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_preselection_leplep = new TH1F("h_dR_b1b2_preselection_leplep", "h_dR_b1b2_preselection_leplep", 50, 0, 5);
  h_dR_b1b2_preselection_leplep->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_preselection_leplep = new TH1F("h_m_lvb_max_preselection_leplep", "h_m_lvb_max_preselection_leplep", 200, 0, 2000);
  h_m_lvb_max_preselection_leplep->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_preselection_leplep = new TH1F("h_m_lvb_min_preselection_leplep", "h_m_lvb_min_preselection_leplep", 100, 0, 1000);
  h_m_lvb_min_preselection_leplep->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_jets_preselection_leptau = new TH1F("h_num_jets_preselection_leptau", "h_num_jets_preselection_leptau", 10, 0, 10);
  h_num_jets_preselection_leptau->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_preselection_leptau->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_preselection_leptau = new TH1F("h_num_bjets_preselection_leptau", "h_num_bjets_preselection_leptau", 10, 0, 10);
  h_num_bjets_preselection_leptau->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_preselection_leptau->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_preselection_leptau = new TH1F("h_num_non_bjets_preselection_leptau", "h_num_non_bjets_preselection_leptau", 10, 0, 10);
  h_num_non_bjets_preselection_leptau->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_preselection_leptau->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_preselection_leptau = new TH1F("h_lepton_pt_preselection_leptau", "h_lepton_pt_preselection_leptau", 1000, 0, 1000);
  h_lepton_pt_preselection_leptau->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_preselection_leptau = new TH1F("h_MET_preselection_leptau", "h_MET_preselection_leptau", 100, 0, 1000);
  h_MET_preselection_leptau->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_preselection_leptau = new TH1F("h_bjet1_pt_preselection_leptau", "h_bjet1_pt_preselection_leptau", 100, 0, 1000);
  h_bjet1_pt_preselection_leptau->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_preselection_leptau = new TH1F("h_bjet2_pt_preselection_leptau", "h_bjet2_pt_preselection_leptau", 100, 0, 1000);
  h_bjet2_pt_preselection_leptau->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_preselection_leptau = new TH1F("h_non_bjet1_pt_preselection_leptau", "h_non_bjet1_pt_preselection_leptau", 100, 0, 1000);
  h_non_bjet1_pt_preselection_leptau->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_preselection_leptau = new TH1F("h_non_bjet2_pt_preselection_leptau", "h_non_bjet2_pt_preselection_leptau", 100, 0, 1000);
  h_non_bjet2_pt_preselection_leptau->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_preselection_leptau = new TH1F("h_bjet_ratio_preselection_leptau", "h_bjet_ratio_preselection_leptau", 100, 0, 1);
  h_bjet_ratio_preselection_leptau->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_preselection_leptau = new TH1F("h_dphi_bjet_lepton_max_preselection_leptau","h_dphi_bjet_lepton_max_preselection_leptau", 100, -5, 5);
  h_dphi_bjet_lepton_max_preselection_leptau->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_preselection_leptau = new TH1F("h_dphi_bjet_lepton_min_preselection_leptau","h_dphi_bjet_lepton_min_preselection_leptau", 100, -5, 5);
  h_dphi_bjet_lepton_min_preselection_leptau->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_preselection_leptau = new TH1F("h_dphi_bjet_ptmiss_max_preselection_leptau","h_dphi_bjet_ptmiss_max_preselection_leptau", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_preselection_leptau->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_preselection_leptau = new TH1F("h_dphi_bjet_ptmiss_min_preselection_leptau","h_dphi_bjet_ptmiss_min_preselection_leptau", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_preselection_leptau->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_preselection_leptau = new TH1F("h_dphi_b1_b2_preselection_leptau","h_dphi_b1_b2_preselection_leptau", 100, -5, 5);
  h_dphi_b1_b2_preselection_leptau->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2) )");
  h_dphi_b1_b2_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_preselection_leptau = new TH1F("h_mbb_preselection_leptau", "h_mbb_preselection_leptau", 100, 0, 1000);
  h_mbb_preselection_leptau->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_preselection_leptau = new TH1F("h_amt2_preselection_leptau", "h_amt2_preselection_leptau", 100, 0, 1000);
  h_amt2_preselection_leptau->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_preselection_leptau = new TH1F("h_amt2_alt_preselection_leptau", "h_amt2_alt_preselection_leptau", 100, 0, 500);
  h_amt2_alt_preselection_leptau->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_preselection_leptau = new TH1F("h_mlb1_preselection_leptau", "h_mlb1_preselection_leptau", 100, 0, 1000);
  h_mlb1_preselection_leptau->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_preselection_leptau = new TH1F("h_mlb2_preselection_leptau", "h_mlb2_preselection_leptau", 100, 0, 1000);
  h_mlb2_preselection_leptau->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_hT_preselection_leptau = new TH1F("h_hT_preselection_leptau", "h_hT_preselection_leptau", 100, 0, 2500);
  h_hT_preselection_leptau->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_preselection_leptau = new TH1F("h_hT_minus_bjets_preselection_leptau", "h_hT_minus_bjets_preselection_leptau", 100, 0, 2500);
  h_hT_minus_bjets_preselection_leptau->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_preselection_leptau = new TH1F("h_mjj_max_preselection_leptau", "h_mjj_max_preselection_leptau", 100, 0, 1000);
  h_mjj_max_preselection_leptau->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_preselection_leptau = new TH1F("h_mjj_min_preselection_leptau", "h_mjj_min_preselection_leptau", 40, 0, 200);
  h_mjj_min_preselection_leptau->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_meff_preselection_leptau = new TH1F("h_meff_preselection_leptau", "h_meff_preselection_leptau", 100, 0, 5000);
  h_meff_preselection_leptau->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_preselection_leptau = new TH1F("h_meff_minus_bjets_preselection_leptau", "h_meff_minus_bjets_preselection_leptau", 100, 0, 2500);
  h_meff_minus_bjets_preselection_leptau->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mT_lepMET_preselection_leptau = new TH1F("h_mT_lepMET_preselection_leptau", "h_mT_lepMET_preselection_leptau", 100, 0, 1000);
  h_mT_lepMET_preselection_leptau->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_dphi_lep_ptmiss_preselection_leptau = new TH1F("h_dphi_lep_ptmiss_preselection_leptau","h_dphi_lep_ptmiss_preselection_leptau", 100, -5, 5);
  h_dphi_lep_ptmiss_preselection_leptau->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_METproj_preselection_leptau = new TH1F("h_METproj_preselection_leptau", "h_METproj_preselection_leptau", 100, 0, 1000);
  h_METproj_preselection_leptau->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_preselection_leptau = new TH1F("h_dR_b1b2_preselection_leptau", "h_dR_b1b2_preselection_leptau", 50, 0, 5);
  h_dR_b1b2_preselection_leptau->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_preselection_leptau = new TH1F("h_m_lvb_max_preselection_leptau", "h_m_lvb_max_preselection_leptau", 200, 0, 2000);
  h_m_lvb_max_preselection_leptau->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_preselection_leptau = new TH1F("h_m_lvb_min_preselection_leptau", "h_m_lvb_min_preselection_leptau", 100, 0, 1000);
  h_m_lvb_min_preselection_leptau->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_num_jets_preselection_lephad = new TH1F("h_num_jets_preselection_lephad", "h_num_jets_preselection_lephad", 10, 0, 10);
  h_num_jets_preselection_lephad->GetXaxis()->SetTitle("Number of jets");
  h_num_jets_preselection_lephad->GetYaxis()->SetTitle("Number of Events");

  h_num_bjets_preselection_lephad = new TH1F("h_num_bjets_preselection_lephad", "h_num_bjets_preselection_lephad", 10, 0, 10);
  h_num_bjets_preselection_lephad->GetXaxis()->SetTitle("Number of b-jets");
  h_num_bjets_preselection_lephad->GetYaxis()->SetTitle("Number of Events");

  h_num_non_bjets_preselection_lephad = new TH1F("h_num_non_bjets_preselection_lephad", "h_num_non_bjets_preselection_lephad", 10, 0, 10);
  h_num_non_bjets_preselection_lephad->GetXaxis()->SetTitle("Number of non-b-jets");
  h_num_non_bjets_preselection_lephad->GetYaxis()->SetTitle("Number of Events");

  h_lepton_pt_preselection_lephad = new TH1F("h_lepton_pt_preselection_lephad", "h_lepton_pt_preselection_lephad", 1000, 0, 1000);
  h_lepton_pt_preselection_lephad->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_lepton_pt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_preselection_lephad = new TH1F("h_MET_preselection_lephad", "h_MET_preselection_lephad", 100, 0, 1000);
  h_MET_preselection_lephad->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1_pt_preselection_lephad = new TH1F("h_bjet1_pt_preselection_lephad", "h_bjet1_pt_preselection_lephad", 100, 0, 1000);
  h_bjet1_pt_preselection_lephad->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1_pt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_bjet2_pt_preselection_lephad = new TH1F("h_bjet2_pt_preselection_lephad", "h_bjet2_pt_preselection_lephad", 100, 0, 1000);
  h_bjet2_pt_preselection_lephad->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2_pt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet1_pt_preselection_lephad = new TH1F("h_non_bjet1_pt_preselection_lephad", "h_non_bjet1_pt_preselection_lephad", 100, 0, 1000);
  h_non_bjet1_pt_preselection_lephad->GetXaxis()->SetTitle("leading non-b-jet pT [GeV]");
  h_non_bjet1_pt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_non_bjet2_pt_preselection_lephad = new TH1F("h_non_bjet2_pt_preselection_lephad", "h_non_bjet2_pt_preselection_lephad", 100, 0, 1000);
  h_non_bjet2_pt_preselection_lephad->GetXaxis()->SetTitle("subleading non-b-jet pT [GeV]");
  h_non_bjet2_pt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet_ratio_preselection_lephad = new TH1F("h_bjet_ratio_preselection_lephad", "h_bjet_ratio_preselection_lephad", 100, 0, 1);
  h_bjet_ratio_preselection_lephad->GetXaxis()->SetTitle("b-jet 2 pT / b-jet 1 pT");
  h_bjet_ratio_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_dphi_bjet_lepton_max_preselection_lephad = new TH1F("h_dphi_bjet_lepton_max_preselection_lephad","h_dphi_bjet_lepton_max_preselection_lephad", 100, -5, 5);
  h_dphi_bjet_lepton_max_preselection_lephad->GetXaxis()->SetTitle("max abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_max_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_lepton_min_preselection_lephad = new TH1F("h_dphi_bjet_lepton_min_preselection_lephad","h_dphi_bjet_lepton_min_preselection_lephad", 100, -5, 5);
  h_dphi_bjet_lepton_min_preselection_lephad->GetXaxis()->SetTitle("min abs( dphi(b-jet, lep) )");
  h_dphi_bjet_lepton_min_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_max_preselection_lephad = new TH1F("h_dphi_bjet_ptmiss_max_preselection_lephad","h_dphi_bjet_ptmiss_max_preselection_lephad", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_preselection_lephad->GetXaxis()->SetTitle("max abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_max_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_bjet_ptmiss_min_preselection_lephad = new TH1F("h_dphi_bjet_ptmiss_min_preselection_lephad","h_dphi_bjet_ptmiss_min_preselection_lephad", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_preselection_lephad->GetXaxis()->SetTitle("min abs( dphi(b-jet, MET) )");
  h_dphi_bjet_ptmiss_min_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_dphi_b1_b2_preselection_lephad = new TH1F("h_dphi_b1_b2_preselection_lephad","h_dphi_b1_b2_preselection_lephad", 100, -5, 5);
  h_dphi_b1_b2_preselection_lephad->GetXaxis()->SetTitle("dphi(b-jet 1, b-jet 2) )");
  h_dphi_b1_b2_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_preselection_lephad = new TH1F("h_mbb_preselection_lephad", "h_mbb_preselection_lephad", 100, 0, 1000);
  h_mbb_preselection_lephad->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_preselection_lephad = new TH1F("h_amt2_preselection_lephad", "h_amt2_preselection_lephad", 100, 0, 1000);
  h_amt2_preselection_lephad->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_alt_preselection_lephad = new TH1F("h_amt2_alt_preselection_lephad", "h_amt2_alt_preselection_lephad", 100, 0, 500);
  h_amt2_alt_preselection_lephad->GetXaxis()->SetTitle("alt amT2 [GeV]");
  h_amt2_alt_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_mlb1_preselection_lephad = new TH1F("h_mlb1_preselection_lephad", "h_mlb1_preselection_lephad", 100, 0, 1000);
  h_mlb1_preselection_lephad->GetXaxis()->SetTitle("m_lb max [GeV]");
  h_mlb1_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mlb2_preselection_lephad = new TH1F("h_mlb2_preselection_lephad", "h_mlb2_preselection_lephad", 100, 0, 1000);
  h_mlb2_preselection_lephad->GetXaxis()->SetTitle("m_lb min [GeV]");
  h_mlb2_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_hT_preselection_lephad = new TH1F("h_hT_preselection_lephad", "h_hT_preselection_lephad", 100, 0, 2500);
  h_hT_preselection_lephad->GetXaxis()->SetTitle("H_T [GeV]");
  h_hT_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_hT_minus_bjets_preselection_lephad = new TH1F("h_hT_minus_bjets_preselection_lephad", "h_hT_minus_bjets_preselection_lephad", 100, 0, 2500);
  h_hT_minus_bjets_preselection_lephad->GetXaxis()->SetTitle("H_T - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_hT_minus_bjets_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mjj_max_preselection_lephad = new TH1F("h_mjj_max_preselection_lephad", "h_mjj_max_preselection_lephad", 100, 0, 1000);
  h_mjj_max_preselection_lephad->GetXaxis()->SetTitle("max m_jj non-b-jets [GeV]");
  h_mjj_max_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_mjj_min_preselection_lephad = new TH1F("h_mjj_min_preselection_lephad", "h_mjj_min_preselection_lephad", 40, 0, 200);
  h_mjj_min_preselection_lephad->GetXaxis()->SetTitle("min m_jj non-b-jets [GeV]");
  h_mjj_min_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 5 GeV");

  h_meff_preselection_lephad = new TH1F("h_meff_preselection_lephad", "h_meff_preselection_lephad", 100, 0, 5000);
  h_meff_preselection_lephad->GetXaxis()->SetTitle("m_eff [GeV]");
  h_meff_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 50 GeV");

  h_meff_minus_bjets_preselection_lephad = new TH1F("h_meff_minus_bjets_preselection_lephad", "h_meff_minus_bjets_preselection_lephad", 100, 0, 2500);
  h_meff_minus_bjets_preselection_lephad->GetXaxis()->SetTitle("m_eff - b-jet 1 pT - b-jet 2 pT [GeV]");
  h_meff_minus_bjets_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 25 GeV");

  h_mT_lepMET_preselection_lephad = new TH1F("h_mT_lepMET_preselection_lephad", "h_mT_lepMET_preselection_lephad", 100, 0, 1000);
  h_mT_lepMET_preselection_lephad->GetXaxis()->SetTitle("m_T [GeV]");
  h_mT_lepMET_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_dphi_lep_ptmiss_preselection_lephad = new TH1F("h_dphi_lep_ptmiss_preselection_lephad","h_dphi_lep_ptmiss_preselection_lephad", 100, -5, 5);
  h_dphi_lep_ptmiss_preselection_lephad->GetXaxis()->SetTitle("dphi(lep, MET)");
  h_dphi_lep_ptmiss_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");


  

  h_pTlep_MET_preselection_leplep = new TH1F("h_pTlep_MET_preselection_leplep","h_pTlep_MET_preselection_leplep", 500, 0, 5);
  h_pTlep_MET_preselection_leplep->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_preselection_leplep = new TH1F("h_pTlep_MET2_preselection_leplep","h_pTlep_MET2_preselection_leplep", 500, 0, 5);
  h_pTlep_MET2_preselection_leplep->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_preselection_leplep->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET_preselection_leptau = new TH1F("h_pTlep_MET_preselection_leptau","h_pTlep_MET_preselection_leptau", 500, 0, 5);
  h_pTlep_MET_preselection_leptau->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_preselection_leptau = new TH1F("h_pTlep_MET2_preselection_leptau","h_pTlep_MET2_preselection_leptau", 500, 0, 5);
  h_pTlep_MET2_preselection_leptau->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_preselection_leptau->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET_preselection_lephad = new TH1F("h_pTlep_MET_preselection_lephad","h_pTlep_MET_preselection_lephad", 500, 0, 5);
  h_pTlep_MET_preselection_lephad->GetXaxis()->SetTitle("pTlep / MET");
  h_pTlep_MET_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_pTlep_MET2_preselection_lephad = new TH1F("h_pTlep_MET2_preselection_lephad","h_pTlep_MET2_preselection_lephad", 500, 0, 5);
  h_pTlep_MET2_preselection_lephad->GetXaxis()->SetTitle("pTlep / MET along lep");
  h_pTlep_MET2_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.01");

  h_METproj_preselection_lephad = new TH1F("h_METproj_preselection_lephad", "h_METproj_preselection_lephad", 100, 0, 1000);
  h_METproj_preselection_lephad->GetXaxis()->SetTitle("MET projected along lepton [GeV]");
  h_METproj_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");
  
  h_dR_b1b2_preselection_lephad = new TH1F("h_dR_b1b2_preselection_lephad", "h_dR_b1b2_preselection_lephad", 50, 0, 5);
  h_dR_b1b2_preselection_lephad->GetXaxis()->SetTitle("dR(b1, b2)");
  h_dR_b1b2_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_m_lvb_max_preselection_lephad = new TH1F("h_m_lvb_max_preselection_lephad", "h_m_lvb_max_preselection_lephad", 200, 0, 2000);
  h_m_lvb_max_preselection_lephad->GetXaxis()->SetTitle("max m_lvb [GeV]");
  h_m_lvb_max_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_m_lvb_min_preselection_lephad = new TH1F("h_m_lvb_min_preselection_lephad", "h_m_lvb_min_preselection_lephad", 100, 0, 1000);
  h_m_lvb_min_preselection_lephad->GetXaxis()->SetTitle("min m_lvb [GeV]");
  h_m_lvb_min_preselection_lephad->GetYaxis()->SetTitle("Number of Events / 10 GeV");



  h_entries = new TH1F("h_entries", "h_entries", 10, 0, 10);
  h_entries_1lep = new TH1F("h_entries_1lep", "h_entries_1lep", 10, 0, 10);
  h_entries_1lep_or_more = new TH1F("h_entries_1lep_or_more", "h_entries_1lep_or_more", 10, 0, 10);
  h_entries_200MET = new TH1F("h_entries_200MET", "h_entries_200MET", 10, 0, 10);
  h_entries_2bjets = new TH1F("h_entries_2bjets", "h_entries_2bjets", 10, 0, 10);
  h_entries_bjetspt = new TH1F("h_entries_bjetspt", "h_entries_bjetspt", 10, 0, 10);
  h_entries_amt2 = new TH1F("h_entries_amt2", "h_entries_amt2", 10, 0, 10);
  h_entries_closeMETb = new TH1F("h_entries_closeMETb", "h_entries_closeMETb", 10, 0, 10);
  h_entries_mbb = new TH1F("h_entries_mbb", "h_entries_mbb", 10, 0, 10);
  //h_entries_analysis = new TH1F("h_entries_analysis", "h_entries_analysis", 10, 0, 10);
  h_entries_pTlepMET = new TH1F("h_entries_pTlepMET", "h_entries_pTlepMET", 10, 0, 10);
  h_entries_pTlep = new TH1F("h_entries_pTlep", "h_entries_pTlep", 10, 0, 10);

  
  h_pTlep_noLepCut = new TH1F("h_pTlep_noLepCut", "h_pTlep_noLepCut", 500, 0, 500);
  h_pTlep_noLepCut->GetXaxis()->SetTitle("lepton pT [GeV]");
  h_pTlep_noLepCut->GetYaxis()->SetTitle("Number of Events / 1 GeV");

  h_MET_noMETCut = new TH1F("h_MET_noMETCut", "h_MET_noMETCut", 100, 0, 1000);
  h_MET_noMETCut->GetXaxis()->SetTitle("MET [GeV]");
  h_MET_noMETCut->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet1pt_nobJet1Cut = new TH1F("h_bjet1pt_nobJetsCut", "h_bjet1pt_nobJetsCut", 100, 0, 1000);
  h_bjet1pt_nobJet1Cut->GetXaxis()->SetTitle("leading b-jet pT [GeV]");
  h_bjet1pt_nobJet1Cut->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_bjet2pt_nobJet2Cut = new TH1F("h_bjet2pt_nobJetsCut", "h_bjet2pt_nobJetsCut", 100, 0, 1000);
  h_bjet2pt_nobJet2Cut->GetXaxis()->SetTitle("subleading b-jet pT [GeV]");
  h_bjet2pt_nobJet2Cut->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_amt2_noamt2Cut = new TH1F("h_amt2_noamt2Cut", "h_amt2_noamt2Cut", 100, 0, 1000);
  h_amt2_noamt2Cut->GetXaxis()->SetTitle("amT2 [GeV]");
  h_amt2_noamt2Cut->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  h_dphibMET_noCloseMETbCut = new TH1F("h_dphibMET_noCloseMETbCut", "h_dphibMET_noCloseMETbCut", 50, 0, 5);
  h_dphibMET_noCloseMETbCut->GetXaxis()->SetTitle("min |dPhi(b, MET)|");
  h_dphibMET_noCloseMETbCut->GetYaxis()->SetTitle("Number of Events / 0.1");

  h_mbb_nombbCut = new TH1F("h_mbb_nombbCut", "h_mbb_nombbCut", 100, 0, 1000);
  h_mbb_nombbCut->GetXaxis()->SetTitle("m_bb [GeV]");
  h_mbb_nombbCut->GetYaxis()->SetTitle("Number of Events / 10 GeV");

  // b-tagging
  //std::cout << "initializing histograms" << std::endl;
  //h_num_truthb = new TH1F("h_num_truthb", "h_num_truthb", 10, 0, 10);
  //h_dR_btruth_bjet = new TH1F("h_dR_btruth_bjet", "h_dR_btruth_bjet", 500, 0, 5);
  //h_truthb_parent = new TH1F("h_truthb_parent", "h_truthb_parent", 100, -50, 50);
  //h_dR_bb = new TH1F("h_dR_bb", "h_dR_bb", 500, 0, 5);
  //std::cout << "done histograms" << std::endl;
  
  /*
  h_lepton_pt_preselection_others = new TH1F("h_lepton_pt_preselection_others", "h_lepton_pt_preselection_others", 100, 0, 100);
  h_MET_preselection_others = new TH1F("h_MET_preselection_others", "h_MET_preselection_others", 100, 0, 1000);
  h_bjet1_pt_preselection_others = new TH1F("h_bjet1_pt_preselection_others", "h_bjet1_pt_preselection_others", 100, 0, 1000);
  h_bjet2_pt_preselection_others = new TH1F("h_bjet2_pt_preselection_others", "h_bjet2_pt_preselection_others", 100, 0, 1000);
  h_non_bjet1_pt_preselection_others = new TH1F("h_non_bjet1_pt_preselection_others", "h_non_bjet1_pt_preselection_others", 100, 0, 1000);
  h_non_bjet2_pt_preselection_others = new TH1F("h_non_bjet2_pt_preselection_others", "h_non_bjet2_pt_preselection_others", 100, 0, 1000);
  h_dphi_bjet_lepton_max_preselection_others = new TH1F("h_dphi_bjet_lepton_max_preselection_others","h_dphi_bjet_lepton_max_preselection_others", 100, -5, 5);
  h_dphi_bjet_lepton_min_preselection_others = new TH1F("h_dphi_bjet_lepton_min_preselection_others","h_dphi_bjet_lepton_min_preselection_others", 100, -5, 5);
  h_dphi_bjet_ptmiss_max_preselection_others = new TH1F("h_dphi_bjet_ptmiss_max_preselection_others","h_dphi_bjet_ptmiss_max_preselection_others", 100, -5, 5);
  h_dphi_bjet_ptmiss_min_preselection_others = new TH1F("h_dphi_bjet_ptmiss_min_preselection_others","h_dphi_bjet_ptmiss_min_preselection_others", 100, -5, 5);
  h_dphi_b1_b2_preselection_others = new TH1F("h_dphi_b1_b2_preselection_others","h_dphi_b1_b2_preselection_others", 100, -5, 5);
  h_mbb_preselection_others = new TH1F("h_mbb_preselection_others", "h_mbb_preselection_others", 100, 0, 1000);
  h_amt2_preselection_others = new TH1F("h_amt2_preselection_others", "h_amt2_preselection_others", 100, 0, 500);
  h_amt2_max_preselection_others = new TH1F("h_amt2_max_preselection_others", "h_amt2_max_preselection_others", 100, 0, 500);
  h_mlb1_preselection_others = new TH1F("h_mlb1_preselection_others", "h_mlb1_preselection_others", 100, 0, 1000);
  h_mlb2_preselection_others = new TH1F("h_mlb2_preselection_others", "h_mlb2_preselection_others", 100, 0, 1000);
  h_hT_preselection_others = new TH1F("h_hT_preselection_others", "h_hT_preselection_others", 100, 0, 2000);
  h_hT_minus_bjets_preselection_others = new TH1F("h_hT_minus_bjets_preselection_others", "h_hT_minus_bjets_preselection_others", 100, 0, 2000);
  h_mjj_max_preselection_others = new TH1F("h_mjj_max_preselection_others", "h_mjj_max_preselection_others", 50, 0, 500);
  h_mjj_min_preselection_others = new TH1F("h_mjj_min_preselection_others", "h_mjj_min_preselection_others", 20, 0, 100);
  h_meff_preselection_others = new TH1F("h_meff_preselection_others", "h_meff_preselection_others", 100, 0, 2500);
  h_meff_minus_bjets_preselection_others = new TH1F("h_meff_minus_bjets_preselection_others", "h_meff_minus_bjets_preselection_others", 100, 0, 2500);
  h_mT_lepMET_preselection_others = new TH1F("h_mT_lepMET_preselection_others", "h_mT_lepMET_preselection_others", 100, 0, 1000);
  h_dphi_lep_ptmiss_preselection_others = new TH1F("h_dphi_lep_ptmiss_preselection_others","h_dphi_lep_ptmiss_preselection_others", 100, -5, 5);
  */

  h_num_leptons_total = new TH1F("h_num_leptons_total", "h_num_leptons_total", 5, 0, 5);
  h_num_leptons_total->Sumw2();
  h_theoretical_leptons = new TH1F("h_theoretical_leptons", "h_theoretical_leptons", 5, 0, 5);

  h_lepton_from_top_pt = new TH1F("h_lepton_from_top_pt", "h_lepton_from_top_pt", 100, 0, 100);
  h_lepton_from_others_pt = new TH1F("h_lepton_from_others_pt", "h_lepton_from_others_pt", 100, 0, 100);
  h_top_W_mass = new TH1F("h_top_W_mass", "h_top_W_mass", 100, 0, 200);
  h_other_W_mass = new TH1F("h_other_W_mass", "h_other_W_mass", 100, 0, 200);

  //h_dR_quarks = new TH1F("h_dR_quarks", "h_dR_quarks", 500, 0, 5);
  //h_dR_leptons = new TH1F("h_dR_leptons", "h_dR_leptons", 500, 0, 5);
  //h_deltaPT_quarks = new TH1F("h_deltaPT_quarks", "h_deltaPT_quarks", 100, -5, 5);
  //h_deltaPT_leptons = new TH1F("h_deltaPT_leptons", "h_deltaPT_leptons", 100, -5, 5);
  h_dR_child_jet = new TH1F("h_dR_child_jet", "h_dR_child_jet", 500, 0, 5);
  h_deltaPT_child_jet = new TH1F("h_deltaPT_child_jet", "h_deltaPT_child_jet", 100, -5, 5);

  h_el_pt = new TH1F("h_el_pt", "h_el_pt", 1000, 0, 10);
  h_mu_pt = new TH1F("h_mu_pt", "h_mu_pt", 1000, 0, 10);
  h_nuel_pt = new TH1F("h_nuel_pt", "h_nuel_pt", 1000, 0, 10);
  h_numu_pt = new TH1F("h_numu_pt", "h_numu_pt", 1000, 0, 10);
  h_tau_pt = new TH1F("h_tau_pt", "h_tau_pt" ,1000, 0, 10);
  h_nutau_pt = new TH1F("h_nutau_pt", "h_nutau_pt", 1000, 0, 10);
  h_up_pt = new TH1F("h_up_pt", "h_up_pt", 1000, 0, 10);
  h_down_pt = new TH1F("h_down_pt", "h_down_pt", 1000, 0, 10);
  h_charm_pt = new TH1F("h_charm_pt", "h_charm_pt", 1000, 0, 10);
  h_strange_pt = new TH1F("h_strange_pt", "h_strange_pt", 1000, 0, 10);
  h_bottom_pt = new TH1F("h_bottom_pt", "h_bottom_pt", 1000, 0, 10);

  h_chargino_children = new TH1F("h_chargino_children", "h_chargino_children", 50, -25, 25);
  h_num_chargino_children = new TH1F("h_num_chargino_children", "h_num_chargino_children", 5, 0, 5);

  // b-tagging
  //std::cout << "output histograms" << std::endl;
  //wk()->addOutput (h_num_truthb);
  //wk()->addOutput (h_dR_btruth_bjet);
  //wk()->addOutput (h_truthb_parent);
  //wk()->addOutput (h_dR_bb);
  //std::cout << "done output histograms" << std::endl;

  wk()->addOutput (h_chargino_children);
  wk()->addOutput (h_num_chargino_children);
  wk()->addOutput (h_W_children);
  wk()->addOutput (h_el_pt);
  wk()->addOutput (h_mu_pt);
  wk()->addOutput (h_tau_pt);
  wk()->addOutput (h_nuel_pt);
  wk()->addOutput (h_numu_pt);
  wk()->addOutput (h_nutau_pt);
  wk()->addOutput (h_up_pt);
  wk()->addOutput (h_down_pt);
  wk()->addOutput (h_charm_pt);
  wk()->addOutput (h_strange_pt);
  wk()->addOutput (h_bottom_pt);

  wk()->addOutput (h_entries);
  wk()->addOutput (h_entries_1lep_or_more);
  wk()->addOutput (h_entries_1lep);
  wk()->addOutput (h_entries_200MET);
  wk()->addOutput (h_entries_2bjets);
  wk()->addOutput (h_entries_bjetspt);
  wk()->addOutput (h_entries_amt2);
  wk()->addOutput (h_entries_closeMETb);
  wk()->addOutput (h_entries_mbb);
  //wk()->addOutput (h_entries_analysis);
  wk()->addOutput (h_entries_pTlepMET);
  wk()->addOutput (h_entries_pTlep);

  wk()->addOutput (h_pTlep_noLepCut);
  wk()->addOutput (h_MET_noMETCut);
  wk()->addOutput (h_bjet1pt_nobJet1Cut);
  wk()->addOutput (h_bjet2pt_nobJet2Cut);
  wk()->addOutput (h_amt2_noamt2Cut);
  wk()->addOutput (h_dphibMET_noCloseMETbCut);
  wk()->addOutput (h_mbb_nombbCut);

  //wk()->addOutput (h_dR_child_jet);
  //wk()->addOutput (h_deltaPT_child_jet);
  //wk()->addOutput (h_num_electrons);
  //wk()->addOutput (h_num_muons);
  //wk()->addOutput (h_num_jets);
  //wk()->addOutput (h_num_bjets);
  //wk()->addOutput (h_num_non_bjets);
  //wk()->addOutput (h_bjet1_pt);
  //wk()->addOutput (h_bjet2_pt);
  //wk()->addOutput (h_jj_inv_mass);
  //wk()->addOutput (h_W_mass);
  wk()->addOutput (h_lepton_pt_0GeV);
  //wk()->addOutput (h_lepton_pt_MET_b_cuts);
  //wk()->addOutput (h_lepton_pt);
  wk()->addOutput (h_num_leptons);
  wk()->addOutput (h_num_leptons_total);
  //wk()->addOutput (h_MET_0GeV);
  //wk()->addOutput (h_MET_200GeV);
  //wk()->addOutput (h_num_jets_1lep);
  //wk()->addOutput (h_lepton_pt_1lep);
  //wk()->addOutput (h_num_leptons_1lep);
  //wk()->addOutput (h_MET_1lep);
  //wk()->addOutput (h_bjet1_pt_1lep);
  //wk()->addOutput (h_bjet2_pt_1lep);
  //wk()->addOutput (h_num_jets_200MET);
  //wk()->addOutput (h_lepton_pt_200MET);
  //wk()->addOutput (h_num_leptons_200MET);
  //wk()->addOutput (h_MET_200MET);
  //wk()->addOutput (h_bjet1_pt_200MET);
  //wk()->addOutput (h_bjet2_pt_200MET);

  wk()->addOutput (h_num_jets_nocuts);
  wk()->addOutput (h_num_bjets_nocuts);
  wk()->addOutput (h_num_non_bjets_nocuts);
  wk()->addOutput (h_lepton_pt_nocuts);
  wk()->addOutput (h_num_leptons_nocuts);
  wk()->addOutput (h_MET_nocuts);
  wk()->addOutput (h_bjet1_pt_nocuts);
  wk()->addOutput (h_bjet2_pt_nocuts);
  wk()->addOutput (h_non_bjet1_pt_nocuts);
  wk()->addOutput (h_non_bjet2_pt_nocuts);
  wk()->addOutput (h_jj_inv_mass_nocuts);
  wk()->addOutput (h_bjet_ratio_nocuts);
  wk()->addOutput (h_dphi_bjet_lepton_max_nocuts);
  wk()->addOutput (h_dphi_bjet_lepton_min_nocuts);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_nocuts);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_nocuts);
  wk()->addOutput (h_dphi_b1_b2_nocuts);
  wk()->addOutput (h_dphi_lep_ptmiss_nocuts);
  wk()->addOutput (h_mbb_nocuts);
  wk()->addOutput (h_amt2_nocuts);
  wk()->addOutput (h_amt2_alt_nocuts);
  wk()->addOutput (h_mlb1_nocuts);
  wk()->addOutput (h_mlb2_nocuts);
  wk()->addOutput (h_mT_lepMET_nocuts);
  wk()->addOutput (h_meff_nocuts);
  wk()->addOutput (h_meff_minus_bjets_nocuts);
  wk()->addOutput (h_hT_nocuts);
  wk()->addOutput (h_hT_minus_bjets_nocuts);
  wk()->addOutput (h_mjj_max_nocuts);
  wk()->addOutput (h_mjj_min_nocuts);
  wk()->addOutput (h_pTlep_MET_nocuts);
  wk()->addOutput (h_pTlep_MET2_nocuts);
  wk()->addOutput (h_METproj_nocuts);
  wk()->addOutput (h_dR_b1b2_nocuts);
  wk()->addOutput (h_m_lvb_max_nocuts);
  wk()->addOutput (h_m_lvb_min_nocuts);

  wk()->addOutput (h_num_jets_1lep);
  wk()->addOutput (h_num_bjets_1lep);
  wk()->addOutput (h_num_non_bjets_1lep);
  wk()->addOutput (h_lepton_pt_1lep);
  wk()->addOutput (h_num_leptons_1lep);
  wk()->addOutput (h_MET_1lep);
  wk()->addOutput (h_bjet1_pt_1lep);
  wk()->addOutput (h_bjet2_pt_1lep);
  wk()->addOutput (h_non_bjet1_pt_1lep);
  wk()->addOutput (h_non_bjet2_pt_1lep);
  wk()->addOutput (h_jj_inv_mass_1lep);
  wk()->addOutput (h_bjet_ratio_1lep);
  wk()->addOutput (h_dphi_bjet_lepton_max_1lep);
  wk()->addOutput (h_dphi_bjet_lepton_min_1lep);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_1lep);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_1lep);
  wk()->addOutput (h_dphi_b1_b2_1lep);
  wk()->addOutput (h_dphi_lep_ptmiss_1lep);
  wk()->addOutput (h_mbb_1lep);
  wk()->addOutput (h_amt2_1lep);
  wk()->addOutput (h_amt2_alt_1lep);
  wk()->addOutput (h_mlb1_1lep);
  wk()->addOutput (h_mlb2_1lep);
  wk()->addOutput (h_mT_lepMET_1lep);
  wk()->addOutput (h_meff_1lep);
  wk()->addOutput (h_meff_minus_bjets_1lep);
  wk()->addOutput (h_hT_1lep);
  wk()->addOutput (h_hT_minus_bjets_1lep);
  wk()->addOutput (h_mjj_max_1lep);
  wk()->addOutput (h_mjj_min_1lep);
  wk()->addOutput (h_pTlep_MET_1lep);
  wk()->addOutput (h_pTlep_MET2_1lep);
  wk()->addOutput (h_METproj_1lep);
  wk()->addOutput (h_dR_b1b2_1lep);
  wk()->addOutput (h_m_lvb_max_1lep);
  wk()->addOutput (h_m_lvb_min_1lep);

  wk()->addOutput (h_num_jets_MET_bjets);
  wk()->addOutput (h_num_bjets_MET_bjets);
  wk()->addOutput (h_num_non_bjets_MET_bjets);
  wk()->addOutput (h_lepton_pt_MET_bjets);
  wk()->addOutput (h_num_leptons_MET_bjets);
  wk()->addOutput (h_MET_MET_bjets);
  wk()->addOutput (h_bjet1_pt_MET_bjets);
  wk()->addOutput (h_bjet2_pt_MET_bjets);
  wk()->addOutput (h_non_bjet1_pt_MET_bjets);
  wk()->addOutput (h_non_bjet2_pt_MET_bjets);
  wk()->addOutput (h_jj_inv_mass_MET_bjets);
  wk()->addOutput (h_bjet_ratio_MET_bjets);
  wk()->addOutput (h_dphi_bjet_lepton_max_MET_bjets);
  wk()->addOutput (h_dphi_bjet_lepton_min_MET_bjets);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_MET_bjets);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_MET_bjets);
  wk()->addOutput (h_dphi_b1_b2_MET_bjets);
  wk()->addOutput (h_dphi_lep_ptmiss_MET_bjets);
  wk()->addOutput (h_mbb_MET_bjets);
  wk()->addOutput (h_amt2_MET_bjets);
  wk()->addOutput (h_amt2_alt_MET_bjets);
  wk()->addOutput (h_mlb1_MET_bjets);
  wk()->addOutput (h_mlb2_MET_bjets);
  wk()->addOutput (h_mT_lepMET_MET_bjets);
  wk()->addOutput (h_meff_MET_bjets);
  wk()->addOutput (h_meff_minus_bjets_MET_bjets);
  wk()->addOutput (h_hT_MET_bjets);
  wk()->addOutput (h_hT_minus_bjets_MET_bjets);
  wk()->addOutput (h_mjj_max_MET_bjets);
  wk()->addOutput (h_mjj_min_MET_bjets);
  wk()->addOutput (h_pTlep_MET_MET_bjets);
  wk()->addOutput (h_pTlep_MET2_MET_bjets);
  wk()->addOutput (h_METproj_MET_bjets);
  wk()->addOutput (h_dR_b1b2_MET_bjets);
  wk()->addOutput (h_m_lvb_max_MET_bjets);
  wk()->addOutput (h_m_lvb_min_MET_bjets);

  wk()->addOutput (h_num_jets_mbb);
  wk()->addOutput (h_num_bjets_mbb);
  wk()->addOutput (h_num_non_bjets_mbb);
  wk()->addOutput (h_lepton_pt_mbb);
  wk()->addOutput (h_num_leptons_mbb);
  wk()->addOutput (h_MET_mbb);
  wk()->addOutput (h_bjet1_pt_mbb);
  wk()->addOutput (h_bjet2_pt_mbb);
  wk()->addOutput (h_non_bjet1_pt_mbb);
  wk()->addOutput (h_non_bjet2_pt_mbb);
  wk()->addOutput (h_jj_inv_mass_mbb);
  wk()->addOutput (h_bjet_ratio_mbb);
  wk()->addOutput (h_dphi_bjet_lepton_max_mbb);
  wk()->addOutput (h_dphi_bjet_lepton_min_mbb);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_mbb);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_mbb);
  wk()->addOutput (h_dphi_b1_b2_mbb);
  wk()->addOutput (h_dphi_lep_ptmiss_mbb);
  wk()->addOutput (h_mbb_mbb);
  wk()->addOutput (h_amt2_mbb);
  wk()->addOutput (h_amt2_alt_mbb);
  wk()->addOutput (h_mlb1_mbb);
  wk()->addOutput (h_mlb2_mbb);
  wk()->addOutput (h_mT_lepMET_mbb);
  wk()->addOutput (h_meff_mbb);
  wk()->addOutput (h_meff_minus_bjets_mbb);
  wk()->addOutput (h_hT_mbb);
  wk()->addOutput (h_hT_minus_bjets_mbb);
  wk()->addOutput (h_mjj_max_mbb);
  wk()->addOutput (h_mjj_min_mbb);
  wk()->addOutput (h_pTlep_MET_mbb);
  wk()->addOutput (h_pTlep_MET2_mbb);
  wk()->addOutput (h_METproj_mbb);
  wk()->addOutput (h_dR_b1b2_mbb);
  wk()->addOutput (h_m_lvb_max_mbb);
  wk()->addOutput (h_m_lvb_min_mbb);

  wk()->addOutput (h_num_jets_preselection);
  wk()->addOutput (h_num_bjets_preselection);
  wk()->addOutput (h_num_non_bjets_preselection);
  wk()->addOutput (h_lepton_pt_preselection);
  wk()->addOutput (h_num_leptons_preselection);
  wk()->addOutput (h_MET_preselection);
  wk()->addOutput (h_bjet1_pt_preselection);
  wk()->addOutput (h_bjet2_pt_preselection);
  wk()->addOutput (h_non_bjet1_pt_preselection);
  wk()->addOutput (h_non_bjet2_pt_preselection);
  wk()->addOutput (h_jj_inv_mass_preselection);
  wk()->addOutput (h_bjet_ratio_preselection);
  wk()->addOutput (h_dphi_bjet_lepton_max_preselection);
  wk()->addOutput (h_dphi_bjet_lepton_min_preselection);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_preselection);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_preselection);
  wk()->addOutput (h_dphi_b1_b2_preselection);
  wk()->addOutput (h_dphi_lep_ptmiss_preselection);
  wk()->addOutput (h_mbb_preselection);
  wk()->addOutput (h_amt2_preselection);
  wk()->addOutput (h_amt2_alt_preselection);
  wk()->addOutput (h_mlb1_preselection);
  wk()->addOutput (h_mlb2_preselection);
  wk()->addOutput (h_mT_lepMET_preselection);
  wk()->addOutput (h_meff_preselection);
  wk()->addOutput (h_meff_minus_bjets_preselection);
  wk()->addOutput (h_hT_preselection);
  wk()->addOutput (h_hT_minus_bjets_preselection);
  wk()->addOutput (h_mjj_max_preselection);
  wk()->addOutput (h_mjj_min_preselection);
  wk()->addOutput (h_pTlep_MET_preselection);
  wk()->addOutput (h_pTlep_MET2_preselection);
  wk()->addOutput (h_METproj_preselection);
  wk()->addOutput (h_dR_b1b2_preselection);
  wk()->addOutput (h_m_lvb_max_preselection);
  wk()->addOutput (h_m_lvb_min_preselection);

  wk()->addOutput (h_lepton_pt_preselection_leplep);
  wk()->addOutput (h_MET_preselection_leplep);
  wk()->addOutput (h_bjet1_pt_preselection_leplep);
  wk()->addOutput (h_bjet2_pt_preselection_leplep);
  wk()->addOutput (h_bjet_ratio_preselection_leplep);
  wk()->addOutput (h_non_bjet1_pt_preselection_leplep);
  wk()->addOutput (h_non_bjet2_pt_preselection_leplep);
  wk()->addOutput (h_dphi_bjet_lepton_max_preselection_leplep);
  wk()->addOutput (h_dphi_bjet_lepton_min_preselection_leplep);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_preselection_leplep);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_preselection_leplep);
  wk()->addOutput (h_dphi_b1_b2_preselection_leplep);
  wk()->addOutput (h_dphi_lep_ptmiss_preselection_leplep);
  wk()->addOutput (h_mbb_preselection_leplep);
  wk()->addOutput (h_amt2_preselection_leplep);
  wk()->addOutput (h_amt2_alt_preselection_leplep);
  wk()->addOutput (h_mlb1_preselection_leplep);
  wk()->addOutput (h_mlb2_preselection_leplep);
  wk()->addOutput (h_mT_lepMET_preselection_leplep);
  wk()->addOutput (h_meff_preselection_leplep);
  wk()->addOutput (h_meff_minus_bjets_preselection_leplep);
  wk()->addOutput (h_hT_preselection_leplep);
  wk()->addOutput (h_hT_minus_bjets_preselection_leplep);
  wk()->addOutput (h_mjj_max_preselection_leplep);
  wk()->addOutput (h_mjj_min_preselection_leplep);
  wk()->addOutput (h_pTlep_MET_preselection_leplep);
  wk()->addOutput (h_pTlep_MET2_preselection_leplep);
  wk()->addOutput (h_num_jets_preselection_leplep);
  wk()->addOutput (h_num_bjets_preselection_leplep);
  wk()->addOutput (h_num_non_bjets_preselection_leplep);
  wk()->addOutput (h_METproj_preselection_leplep);
  wk()->addOutput (h_dR_b1b2_preselection_leplep);
  wk()->addOutput (h_m_lvb_max_preselection_leplep);
  wk()->addOutput (h_m_lvb_min_preselection_leplep);

  wk()->addOutput (h_lepton_pt_preselection_leptau);
  wk()->addOutput (h_MET_preselection_leptau);
  wk()->addOutput (h_bjet1_pt_preselection_leptau);
  wk()->addOutput (h_bjet2_pt_preselection_leptau);
  wk()->addOutput (h_bjet_ratio_preselection_leptau);
  wk()->addOutput (h_non_bjet1_pt_preselection_leptau);
  wk()->addOutput (h_non_bjet2_pt_preselection_leptau);
  wk()->addOutput (h_dphi_bjet_lepton_max_preselection_leptau);
  wk()->addOutput (h_dphi_bjet_lepton_min_preselection_leptau);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_preselection_leptau);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_preselection_leptau);
  wk()->addOutput (h_dphi_b1_b2_preselection_leptau);
  wk()->addOutput (h_dphi_lep_ptmiss_preselection_leptau);
  wk()->addOutput (h_mbb_preselection_leptau);
  wk()->addOutput (h_amt2_preselection_leptau);
  wk()->addOutput (h_amt2_alt_preselection_leptau);
  wk()->addOutput (h_mlb1_preselection_leptau);
  wk()->addOutput (h_mlb2_preselection_leptau);
  wk()->addOutput (h_mT_lepMET_preselection_leptau);
  wk()->addOutput (h_meff_preselection_leptau);
  wk()->addOutput (h_meff_minus_bjets_preselection_leptau);
  wk()->addOutput (h_hT_preselection_leptau);
  wk()->addOutput (h_hT_minus_bjets_preselection_leptau);
  wk()->addOutput (h_mjj_max_preselection_leptau);
  wk()->addOutput (h_mjj_min_preselection_leptau);
  wk()->addOutput (h_pTlep_MET_preselection_leptau);
  wk()->addOutput (h_pTlep_MET2_preselection_leptau);
  wk()->addOutput (h_num_jets_preselection_leptau);
  wk()->addOutput (h_num_bjets_preselection_leptau);
  wk()->addOutput (h_num_non_bjets_preselection_leptau);
  wk()->addOutput (h_METproj_preselection_leptau);
  wk()->addOutput (h_dR_b1b2_preselection_leptau);
  wk()->addOutput (h_m_lvb_max_preselection_leptau);
  wk()->addOutput (h_m_lvb_min_preselection_leptau);

  wk()->addOutput (h_lepton_pt_preselection_lephad);
  wk()->addOutput (h_MET_preselection_lephad);
  wk()->addOutput (h_bjet1_pt_preselection_lephad);
  wk()->addOutput (h_bjet2_pt_preselection_lephad);
  wk()->addOutput (h_bjet_ratio_preselection_lephad);
  wk()->addOutput (h_non_bjet1_pt_preselection_lephad);
  wk()->addOutput (h_non_bjet2_pt_preselection_lephad);
  wk()->addOutput (h_dphi_bjet_lepton_max_preselection_lephad);
  wk()->addOutput (h_dphi_bjet_lepton_min_preselection_lephad);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_preselection_lephad);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_preselection_lephad);
  wk()->addOutput (h_dphi_b1_b2_preselection_lephad);
  wk()->addOutput (h_dphi_lep_ptmiss_preselection_lephad);
  wk()->addOutput (h_mbb_preselection_lephad);
  wk()->addOutput (h_amt2_preselection_lephad);
  wk()->addOutput (h_amt2_alt_preselection_lephad);
  wk()->addOutput (h_mlb1_preselection_lephad);
  wk()->addOutput (h_mlb2_preselection_lephad);
  wk()->addOutput (h_mT_lepMET_preselection_lephad);
  wk()->addOutput (h_meff_preselection_lephad);
  wk()->addOutput (h_meff_minus_bjets_preselection_lephad);
  wk()->addOutput (h_hT_preselection_lephad);
  wk()->addOutput (h_hT_minus_bjets_preselection_lephad);
  wk()->addOutput (h_mjj_max_preselection_lephad);
  wk()->addOutput (h_mjj_min_preselection_lephad);
  wk()->addOutput (h_pTlep_MET_preselection_lephad);
  wk()->addOutput (h_pTlep_MET2_preselection_lephad);
  wk()->addOutput (h_num_jets_preselection_lephad);
  wk()->addOutput (h_num_bjets_preselection_lephad);
  wk()->addOutput (h_num_non_bjets_preselection_lephad);
  wk()->addOutput (h_METproj_preselection_lephad);
  wk()->addOutput (h_dR_b1b2_preselection_lephad);
  wk()->addOutput (h_m_lvb_max_preselection_lephad);
  wk()->addOutput (h_m_lvb_min_preselection_lephad);

  /*wk()->addOutput (h_lepton_pt_preselection_others);
  wk()->addOutput (h_MET_preselection_others);
  wk()->addOutput (h_bjet1_pt_preselection_others);
  wk()->addOutput (h_bjet2_pt_preselection_others);
  wk()->addOutput (h_non_bjet1_pt_preselection_others);
  wk()->addOutput (h_non_bjet2_pt_preselection_others);
  wk()->addOutput (h_dphi_bjet_lepton_max_preselection_others);
  wk()->addOutput (h_dphi_bjet_lepton_min_preselection_others);
  wk()->addOutput (h_dphi_bjet_ptmiss_max_preselection_others);
  wk()->addOutput (h_dphi_bjet_ptmiss_min_preselection_others);
  wk()->addOutput (h_dphi_b1_b2_preselection_others);
  wk()->addOutput (h_dphi_lep_ptmiss_preselection_others);
  wk()->addOutput (h_mbb_preselection_others);
  wk()->addOutput (h_amt2_preselection_others);
  wk()->addOutput (h_amt2_max_preselection_others);
  wk()->addOutput (h_mlb1_preselection_others);
  wk()->addOutput (h_mlb2_preselection_others);
  wk()->addOutput (h_mT_lepMET_preselection_others);
  wk()->addOutput (h_meff_preselection_others);
  wk()->addOutput (h_meff_minus_bjets_preselection_others);
  wk()->addOutput (h_hT_preselection_others);
  wk()->addOutput (h_hT_minus_bjets_preselection_others);
  wk()->addOutput (h_mjj_max_preselection_others);
  wk()->addOutput (h_mjj_min_preselection_others);
  */

  wk()->addOutput (h_theoretical_leptons);

  //wk()->addOutput (h_lepton_from_top_pt);
  //wk()->addOutput (h_lepton_from_others_pt);
  //wk()->addOutput (h_top_W_mass);
  //wk()->addOutput (h_other_W_mass);

  //wk()->addOutput (h_dR_quarks);
  //wk()->addOutput (h_dR_leptons);
  //wk()->addOutput (h_deltaPT_quarks);
  //wk()->addOutput (h_deltaPT_leptons);

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.

  //bool ptsorter( const xAOD::IParticle*, const xAOD::IParticle* );
  //bool ptsorter( const xAOD::IParticle* e1, const xAOD::IParticle* e2 )
  //{
  // return ( e1->pt() > e2->pt() );
  //}

  const char* APP_NAME = "MyxAODAnalysis";
  
  // count number of events
  m_eventCounter = 0;
  
  m_event = wk()->xaodEvent();
  
  // as a check, let's see the number of events in our xAOD
  Info("initialize()", "Number of events = %lli", m_event->getEntries() ); // print long long int

  return EL::StatusCode::SUCCESS;
}

/*const xAOD::TruthParticle* electronDecay(const xAOD::TruthParticle *electron)
{
  std::cout << "starting electronDecay" << std::endl;
  std::cout << "number children: " << electron->nChildren() << std::endl;
  for (unsigned int i = 0; i < electron->nChildren(); i++) {
    const xAOD::TruthParticle* child = electron->child(i);
    std::cout << "electron child: " << child->pdgId() << std::endl;
    if (child->absPdgId() == 11) {
      return electronDecay(child);
    }
  }
  return electron;
  }*/

EL::StatusCode MyxAODAnalysis :: execute ()
{
  const char* APP_NAME = "MyxAODAnalysis";

  //std::cout << "starting execute()" << std::endl;

  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  // print every 100 events, so we know where we are:
  //if( (m_eventCounter % 1000) ==0 ) {
  //Info("execute()", "Event number = %i", m_eventCounter );
    //}
  m_eventCounter++;
  
  //----------------------------
  // Event information
  //--------------------------- 
  const xAOD::EventInfo* eventInfo = 0;
  if( ! m_event->retrieve( eventInfo, "EventInfo").isSuccess() ){
    Error("execute()", "Failed to retrieve event info collection. Exiting." );
    return EL::StatusCode::FAILURE;
  }

  // check if the event is data or MC
  // (many tools are applied either to data or MC)
  bool isMC = false;
  // check if the event is MC
  if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION ) ){
    isMC = true; // can do something with this later
  }

  //----------------------------
  // Truth Information
  //--------------------------- 
  const xAOD::TruthEventContainer* xTruthEventContainer = NULL;
  const xAOD::TruthParticleContainer* xTruthParticleContainer = NULL;
  const xAOD::TruthVertexContainer* xTruthVertexContainer = NULL;
  const xAOD::TruthParticleContainer* xTruthTauContainer = NULL;
  const xAOD::MissingETContainer* xTruthMETContainer = NULL;
  const xAOD::TruthParticleContainer* xTruthElectronContainer = NULL;
  const xAOD::TruthParticleContainer* xTruthMuonContainer = NULL;
  const xAOD::TruthParticleContainer* xTruthNeutrinoContainer = NULL;
  const xAOD::JetContainer* xTruthJetContainer = NULL;
  const char*  xaodTruthEventContainerName = "TruthEvents";
  const char*  xaodTruthParticleContainerName = "TruthParticles";
  const char*  xaodTruthVertexContainerName = "TruthVertices";
  const char*  xaodTruthTauContainerName = "TruthTaus";
  const char*  xaodTruthMETContainerName = "MET_Truth";
  const char*  xaodTruthElectronContainerName = "TruthElectrons";
  const char*  xaodTruthMuonContainerName = "TruthMuons";
  const char*  xaodTruthNeutrinoContainerName = "TruthNeutrinos";
  const char*  xaodTruthJetContainerName = "AntiKt4TruthJets";
  CHECK( m_event->retrieve( xTruthEventContainer, xaodTruthEventContainerName));
  CHECK( m_event->retrieve( xTruthParticleContainer, xaodTruthParticleContainerName));
  CHECK( m_event->retrieve( xTruthVertexContainer, xaodTruthVertexContainerName));
  CHECK( m_event->retrieve( xTruthTauContainer, xaodTruthTauContainerName));
  CHECK( m_event->retrieve( xTruthMETContainer, xaodTruthMETContainerName));
  CHECK( m_event->retrieve( xTruthElectronContainer, xaodTruthElectronContainerName));
  CHECK( m_event->retrieve( xTruthMuonContainer, xaodTruthMuonContainerName));
  CHECK( m_event->retrieve( xTruthNeutrinoContainer, xaodTruthNeutrinoContainerName));
  CHECK( m_event->retrieve( xTruthJetContainer, xaodTruthJetContainerName));

  // This is actually number of collisions
  // Info("execute()", "Collisions=%lu", xTruthEventContainer->size());

  // Loop over collisions
  xAOD::TruthEventContainer::const_iterator itr;
  for (itr = xTruthEventContainer->begin(); itr!=xTruthEventContainer->end(); ++itr) {

    // Incoming beam particles
    std::pair<const xAOD::TruthParticle*,const xAOD::TruthParticle*> beamParticles = (*itr)->beamParticles();
 
    weight = 1;
  
    // MC event weights 
    const std::vector<float> weights = (*itr)->weights();
    if (isMC) {
      if (weights.size() > 0) {
	weight = weights[0];
	//std::cout << "weight = " << weight << std::endl;
      }
      //else std::cout << "no weights" << std::endl;
    }
	
    // Actual truth information 
    //    int nVert = (*itr)->nTruthVertices();
    //int nPart = (*itr)->nTruthParticles();
//   Info("execute()", "Vertices=%d Particles=%d", nVert, nPart);
//           
//    // loop over particles
//   for(int iPart = 0; iPart < nPart; ++iPart) {
//     std::cout << "particle" << iPart << std::endl;
//     std::cout << (*itr)->truthParticle(iPart)->pdgId() << std::endl;
//     const xAOD::TruthParticle* particle = (*itr)->truthParticle(iPart);
//     
//     if(particle->absPdgId()==15){
//	Info("execute()", "Pt=%f", particle->pt());
//	h_truthParticlePt->Fill( ( particle->pt()) * 0.001); // GeV
//     }
    
  }

  //float scale = 0.18365;      // signal
  //float scale = 0.048206;     // ttbar
  //float scale = 0.023023;     // single top
  //float scale = 0.022963;     // single tbar

  int num_leptons_total = 0;

  bool pass1lep  = false;
  bool pass1lep_or_more = false;
  bool passMET   = false;
  bool pass2bjets = false;
  bool passbjetspt = false;
  bool passamt2 = false;
  bool passcloseMETb = false;
  bool passmbb = false;
  bool passpTlep = false;
  bool pass4jets = false;
  bool passpTlepMET = false;
  bool passbjet1pt = false;
  bool passbjet2pt = false;

  //float lep_pt = 0.0;

  int tau_children = 0;

  unsigned int num_lepton_children = 0;
  unsigned int num_tau_children = 0;

  unsigned int num_truth_b = 0;

  bool leplep = false;
  bool leptau = false;
  bool lephad = false;
  bool others = false;

  //float radius = 0.0;

  lepton = new TLorentzVector(0., 0., 0., 0.);
  lep_tmp = new TLorentzVector(0., 0., 0., 0.);
  jet_tmp = new TLorentzVector(0., 0., 0., 0.);
  part_tmp = new TLorentzVector(0., 0., 0., 0.);

  int lep_id = 0;

  /*bool isolated = false;
  bool notjet = true;
  xAOD::JetContainer::const_iterator jet_itr3;
  xAOD::JetContainer::const_iterator jet_itr4;
  unsigned int num_leptons = 0;
  int label_tmp = -1;
  */
  xAOD::TruthParticleContainer::const_iterator part_itr;
  xAOD::TruthParticleContainer::const_iterator part_itr3;
  xAOD::TruthParticleContainer::const_iterator part_itr4;
  /*for (part_itr3 = xTruthParticleContainer->begin(); part_itr3!=xTruthParticleContainer->end(); ++part_itr3) {
    if ((*part_itr3)->absPdgId() == 24) { //&& (*part_itr)->parent(0)->absPdgId() == 6) {
      for (unsigned int child = 0; child < (*part_itr3)->nChildren(); child++) {
	if ((*part_itr3)->child(child)->absPdgId() == 11 || (*part_itr3)->child(child)->absPdgId() == 13) {
	  num_leptons_total += 1;
	  if ((*part_itr3)->parent(0)->absPdgId() == 6 || (*part_itr3)->parent(0)->parent(0)->absPdgId() == 6) num_lepton_children += 1;
	  h_lepton_pt_0GeV->Fill( (*part_itr3)->child(child)->pt()*0.001);
	  if ((*part_itr3)->child(child)->abseta() < 2.5) {
	    if (((*part_itr3)->child(child)->absPdgId() == 11 && (*part_itr3)->child(child)->pt()*0.001 > 7.0) || ((*part_itr3)->child(child)->absPdgId() == 13 && (*part_itr3)->child(child)->pt()*0.001 > 6.0)) {
	      lep_tmp->SetPxPyPzE( (*part_itr3)->child(child)->px()*0.001, (*part_itr3)->child(child)->py()*0.001, (*part_itr3)->child(child)->pz()*0.001, (*part_itr3)->child(child)->e()*0.001 );
	      lep_id = (*part_itr3)->child(child)->pdgId();
	      lep_type = (*part_itr3)->child(child)->auxdata< unsigned int >("classifierParticleType");
	      if (lep_type == 2 || lep_type == 6) isolated = true;
	      notjet = true;
	      for (jet_itr3 = xTruthJetContainer->begin(); jet_itr3!=xTruthJetContainer->end(); jet_itr3++) {
		jet_tmp->SetPxPyPzE( (*jet_itr3)->px()*0.001, (*jet_itr3)->py()*0.001, (*jet_itr3)->pz()*0.001, (*jet_itr3)->e()*0.001 );
		(*jet_itr3)->getAttribute("ConeTruthLabelID",label_tmp);
		radius = std::min(0.04 + 10 / jet_tmp->Pt(), 0.4);
		if (jet_tmp->Pt() > 20.0 && fabs(jet_tmp->Eta()) < 2.5) {
		  if (abs(lep_id) == 11 && jet_tmp->DeltaR(*lep_tmp) < 0.2 && label_tmp != 5) notjet = true;
		  else if (abs(lep_id) == 13 && jet_tmp->DeltaR(*lep_tmp) < 0.4 && label_tmp != 5 && lep_tmp->Pt() / jet_tmp->Pt() > 0.7) notjet = true;
		  else if (jet_tmp->DeltaR(*lep_tmp) < radius) notjet = false;
		}
	      }
	      if (isolated && notjet) {
		num_leptons += 1;
		if ((*part_itr3)->child(child)->pt()*0.001 > lep_pt) {
		  lepton->SetPxPyPzE( (*part_itr3)->child(child)->px()*0.001, (*part_itr3)->child(child)->py()*0.001, (*part_itr3)->child(child)->pz()*0.001, (*part_itr3)->child(child)->e()*0.001 );
		  lep_pt = (*part_itr3)->child(child)->pt()*0.001;
		}
		h_lepton_pt->Fill( (*part_itr3)->child(child)->pt()*0.001 );
	      }
	    }
	  }
	}
	else if ((*part_itr3)->child(child)->absPdgId() == 15) {
	  if ((*part_itr3)->parent(0)->absPdgId() == 6) num_tau_children += 1;
	  tau_children = (*part_itr3)->child(child)->nChildren();
	  for (int i=0; i < tau_children; i++) {
	    if ((*part_itr3)->child(child)->child(i)->absPdgId() == 11 || (*part_itr3)->child(child)->child(i)->absPdgId() == 13 ) {
	      num_leptons_total += 1;
	      if ((*part_itr3)->parent(0)->absPdgId() == 6 || (*part_itr3)->parent(0)->parent(0)->absPdgId() == 6) num_lepton_children += 1;
	      h_lepton_pt_0GeV->Fill( (*part_itr3)->child(child)->child(i)->pt()*0.001);
	      if ((*part_itr3)->child(child)->child(i)->abseta() < 2.5) {
		if (((*part_itr3)->child(child)->child(i)->absPdgId() == 11 && (*part_itr3)->child(child)->child(i)->pt()*0.001 > 7.0) || ((*part_itr3)->child(child)->child(i)->absPdgId() == 13 && (*part_itr3)->child(child)->child(i)->pt()*0.001 > 6.0)) {
		  lep_tmp->SetPxPyPzE( (*part_itr3)->child(child)->child(i)->px()*0.001, (*part_itr3)->child(child)->child(i)->py()*0.001, (*part_itr3)->child(child)->child(i)->pz()*0.001, (*part_itr3)->child(child)->child(i)->e()*0.001 );
		  lep_id = (*part_itr3)->child(child)->child(i)->pdgId();
		  lep_type = (*part_itr3)->child(child)->child(i)->auxdata< unsigned int >("classifierParticleType");
		  if (lep_type == 2 || lep_type == 6) isolated = true;
		  notjet = true;
		  for (jet_itr4 = xTruthJetContainer->begin(); jet_itr4!=xTruthJetContainer->end(); jet_itr4++) {
		    jet_tmp->SetPxPyPzE( (*jet_itr4)->px()*0.001, (*jet_itr4)->py()*0.001, (*jet_itr4)->pz()*0.001, (*jet_itr4)->e()*0.001 );
		    (*jet_itr4)->getAttribute("ConeTruthLabelID",label_tmp);
		    radius = std::min(0.04 + 10 / jet_tmp->Pt(), 0.4);
		    if (jet_tmp->Pt() > 20.0 && fabs(jet_tmp->Eta()) < 2.5) {
		      if (abs(lep_id) == 11 && jet_tmp->DeltaR(*lep_tmp) < 0.2 && label_tmp != 5) notjet = true;
		      else if (abs(lep_id) == 13 && jet_tmp->DeltaR(*lep_tmp) < 0.4 && label_tmp != 5 && lep_tmp->Pt() / jet_tmp->Pt() > 0.7) notjet = true;
		      else if (jet_tmp->DeltaR(*lep_tmp) < radius) notjet = false;
		    }
		  }
		  if (isolated && notjet) {
		    num_leptons += 1;
		    if ((*part_itr3)->child(child)->child(i)->pt()*0.001 > lep_pt) {
		      lepton->SetPxPyPzE( (*part_itr3)->child(child)->child(i)->px()*0.001, (*part_itr3)->child(child)->child(i)->py()*0.001, (*part_itr3)->child(child)->child(i)->pz()*0.001, (*part_itr3)->child(child)->child(i)->e()*0.001 );
		      lep_pt = (*part_itr3)->child(child)->child(i)->pt()*0.001;
		    }
		    h_lepton_pt->Fill( (*part_itr3)->child(child)->child(i)->pt()*0.001 );
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  */

  //std::vector< TLorentzVector > leptons;
  //std::vector< int > lepton_ids;
  leptons.clear();
  lepton_ids.clear();

  truthb.clear();
  b_parents.clear();

  had_child1 = new TLorentzVector(0., 0., 0., 0.);
  had_child2 = new TLorentzVector(0., 0., 0., 0.);
  had_child3 = new TLorentzVector(0., 0., 0., 0.);
  had_child4 = new TLorentzVector(0., 0., 0., 0.);

  b_tmp = new TLorentzVector(0., 0., 0., 0.);

  float lep_pt = 0.0;

  //use for everything except W+jets
  //for ttbar, single top need to change to status == 3, for signal change to status != 2
  /*for (part_itr = xTruthParticleContainer->begin(); part_itr!=xTruthParticleContainer->end(); ++part_itr) {
    if ((*part_itr)->absPdgId() == 24) {
      //if ((*part_itr)->absPdgId() == 24 && (*part_itr)->status() != 2) {
      std::cout << "W status= " << (*part_itr)->status() << std::endl;
      for (unsigned int j=0; j < (*part_itr)->nChildren(); j++) {
	h_W_children->Fill( (*part_itr)->child(j)->pdgId() );
	std::cout << "     child " << j << " id = " << (*part_itr)->child(j)->pdgId() << std::endl;
	if ((*part_itr)->child(j)->absPdgId() == 11 || (*part_itr)->child(j)->absPdgId() == 13) {
	  num_lepton_children += 1;
	  h_lepton_pt_0GeV->Fill( (*part_itr)->child(j)->pt()*0.001, weight );
	  if ( (*part_itr)->child(j)->pt()*0.001 > lep_pt ) lep_pt = (*part_itr)->child(j)->pt()*0.001;
	  if ((*part_itr)->child(j)->abseta() < 2.5) {
	    if (((*part_itr)->child(j)->absPdgId() == 11 && (*part_itr)->child(j)->pt()*0.001 > 7.0) || ((*part_itr)->child(j)->absPdgId() == 13 && (*part_itr)->child(j)->pt()*0.001 > 5.0)) {
	      lep_tmp->SetPxPyPzE( (*part_itr)->child(j)->px()*0.001, (*part_itr)->child(j)->py()*0.001, (*part_itr)->child(j)->pz()*0.001, (*part_itr)->child(j)->e()*0.001 );
	      lep_id = (*part_itr)->child(j)->pdgId();
	      leptons.push_back(*lep_tmp);
	      lepton_ids.push_back(lep_id);
	      h_lepton_pt->Fill( (*part_itr)->child(j)->pt()*0.001, weight );
	    }
	  }
	}
	else if ((*part_itr)->child(j)->absPdgId() == 15) {
	  num_tau_children += 1;
	  tau_children = (*part_itr)->child(j)->nChildren();
	  for (int i=0; i < tau_children; i++) {
	    if ((*part_itr)->child(j)->child(i)->absPdgId() == 11 || (*part_itr)->child(j)->child(i)->absPdgId() == 13 ) {
	      num_lepton_children += 1;
	      h_lepton_pt_0GeV->Fill( (*part_itr)->child(j)->child(i)->pt()*0.001, weight );
	      if ((*part_itr)->child(j)->child(i)->pt()*0.001 > lep_pt) lep_pt = (*part_itr)->child(j)->child(i)->pt()*0.001;
	      if ((*part_itr)->child(j)->child(i)->abseta() < 2.5) {
		if (((*part_itr)->child(j)->child(i)->absPdgId() == 11 && (*part_itr)->child(j)->child(i)->pt()*0.001 > 7.0) || ((*part_itr)->child(j)->child(i)->absPdgId() == 13 && (*part_itr)->child(j)->child(i)->pt()*0.001 > 5.0)) {
		  lep_tmp->SetPxPyPzE( (*part_itr)->child(j)->child(i)->px()*0.001, (*part_itr)->child(j)->child(i)->py()*0.001, (*part_itr)->child(j)->child(i)->pz()*0.001, (*part_itr)->child(j)->child(i)->e()*0.001 );
		  lep_id = (*part_itr)->child(j)->child(i)->pdgId();
		  leptons.push_back(*lep_tmp);
		  lepton_ids.push_back(lep_id);
		  h_lepton_pt->Fill( (*part_itr)->child(j)->child(i)->pt()*0.001, weight );
		}
	      }
	    }
	  }
	}
	if ((*part_itr)->child(j)->absPdgId() == 11) h_el_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 13) h_mu_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 15) h_tau_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 12) h_nuel_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 14) h_numu_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 16) h_nutau_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 1) h_down_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 2) h_up_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 3) h_strange_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 4) h_charm_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
	if ((*part_itr)->child(j)->absPdgId() == 5) h_bottom_pt->Fill((*part_itr)->child(j)->pt()*0.001, weight);
      }
    }
    }*/

  //for new samples
  //for N2toN1, change 1000024 to 1000023

  bool chargino_child = false;

  for (part_itr = xTruthParticleContainer->begin(); part_itr!=xTruthParticleContainer->end(); ++part_itr) {
    if ((*part_itr)->absPdgId() == 1000023) {
      if ((*part_itr)->nChildren() > 0) {
	if ((*part_itr)->child(0)->absPdgId() != 1000023) {
	  h_num_chargino_children->Fill( (*part_itr)->nChildren() );
	  for (unsigned int c = 0; c < (*part_itr)->nChildren(); c++) {
	    if ((*part_itr)->child(c)->absPdgId() == 1000024) chargino_child = true;
	    h_chargino_children->Fill( (*part_itr)->child(c)->pdgId() );
	    if (((*part_itr)->child(c)->absPdgId() == 11 || (*part_itr)->child(c)->absPdgId() == 13)) {
	      num_lepton_children += 1;
	      h_lepton_pt_0GeV->Fill( (*part_itr)->child(c)->pt()*0.001, weight);
	      if ((*part_itr)->child(c)->abseta() < 2.5) {
		if (((*part_itr)->child(c)->absPdgId() == 11 && (*part_itr)->child(c)->pt()*0.001 > 7.0) || ((*part_itr)->child(c)->absPdgId() == 13 && (*part_itr)->child(c)->pt()*0.001 > 5.0)) {
		  lep_tmp->SetPxPyPzE( (*part_itr)->child(c)->px()*0.001, (*part_itr)->child(c)->py()*0.001, (*part_itr)->child(c)->pz()*0.001, (*part_itr)->child(c)->e()*0.001 );
		  lep_id = (*part_itr)->child(c)->pdgId();
		  leptons.push_back(*lep_tmp);
		  lepton_ids.push_back(lep_id);
		  h_lepton_pt->Fill( (*part_itr)->child(c)->pt()*0.001, weight );
		}
	      }
	    }
	    if ((*part_itr)->child(c)->absPdgId() == 15) {
	      if ((*part_itr)->child(c)->child(0)->absPdgId() == 15) {
		for (unsigned int s = 0; s < (*part_itr)->child(c)->child(0)->nChildren(); s++) {
		  if (((*part_itr)->child(c)->child(0)->child(s)->absPdgId() == 11 || (*part_itr)->child(c)->child(0)->child(s)->absPdgId() == 13)) {
		    num_lepton_children += 1;
		    h_lepton_pt_0GeV->Fill( (*part_itr)->child(c)->child(0)->child(s)->pt()*0.001, weight);
		    if ((*part_itr)->child(c)->child(0)->child(s)->abseta() < 2.5) {
		      if (((*part_itr)->child(c)->child(0)->child(s)->absPdgId() == 11 && (*part_itr)->child(c)->child(0)->child(s)->pt()*0.001 > 7.0) || ((*part_itr)->child(c)->child(0)->child(s)->absPdgId() == 13 && (*part_itr)->child(c)->child(0)->child(s)->pt()*0.001 > 5.0)) {
			lep_tmp->SetPxPyPzE( (*part_itr)->child(c)->child(0)->child(s)->px()*0.001, (*part_itr)->child(c)->child(0)->child(s)->py()*0.001, (*part_itr)->child(c)->child(0)->child(s)->pz()*0.001, (*part_itr)->child(c)->child(0)->child(s)->e()*0.001 );
			lep_id = (*part_itr)->child(c)->child(0)->child(s)->pdgId();
			leptons.push_back(*lep_tmp);
			lepton_ids.push_back(lep_id);
			h_lepton_pt->Fill( (*part_itr)->child(c)->child(0)->child(s)->pt()*0.001, weight );
		      }
		    }
		  }
		}
	      }
	      else {
		for (unsigned int t = 0; t < (*part_itr)->child(c)->nChildren(); t++) {
		  if (((*part_itr)->child(c)->child(t)->absPdgId() == 11 || (*part_itr)->child(c)->child(t)->absPdgId() == 13)) {
		    num_lepton_children += 1;
		    h_lepton_pt_0GeV->Fill( (*part_itr)->child(c)->child(t)->pt()*0.001, weight);
		    if ((*part_itr)->child(c)->child(t)->abseta() < 2.5) {
		      if (((*part_itr)->child(c)->child(t)->absPdgId() == 11 && (*part_itr)->child(c)->child(t)->pt()*0.001 > 7.0) || ((*part_itr)->child(c)->child(t)->absPdgId() == 13 && (*part_itr)->child(c)->child(t)->pt()*0.001 > 5.0)) {
			lep_tmp->SetPxPyPzE( (*part_itr)->child(c)->child(t)->px()*0.001, (*part_itr)->child(c)->child(t)->py()*0.001, (*part_itr)->child(c)->child(t)->pz()*0.001, (*part_itr)->child(c)->child(t)->e()*0.001 );
			lep_id = (*part_itr)->child(c)->child(t)->pdgId();
			leptons.push_back(*lep_tmp);
			lepton_ids.push_back(lep_id);
			h_lepton_pt->Fill( (*part_itr)->child(c)->child(t)->pt()*0.001, weight );
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
    else {
      h_num_chargino_children->Fill(0);
    }
  }

  //std::cout << " " << " " << std::endl;

  if (lep_pt == 0.0) lep_pt = -1.0;

  //use for W->e nu and W->mu nu
  /*for (part_itr = xTruthParticleContainer->begin(); part_itr!=xTruthParticleContainer->end(); ++part_itr) {
    if (((*part_itr)->absPdgId() == 11 || (*part_itr)->absPdgId() == 13) && (*part_itr)->status() == 3) {
      num_lepton_children += 1;
      h_lepton_pt_0GeV->Fill( (*part_itr)->pt()*0.001, weight);
      if ((*part_itr)->abseta() < 2.5) {
	if (((*part_itr)->absPdgId() == 11 && (*part_itr)->pt()*0.001 > 7.0) || ((*part_itr)->absPdgId() == 13 && (*part_itr)->pt()*0.001 > 5.0)) {
	  lep_tmp->SetPxPyPzE( (*part_itr)->px()*0.001, (*part_itr)->py()*0.001, (*part_itr)->pz()*0.001, (*part_itr)->e()*0.001 );
	  lep_id = (*part_itr)->pdgId();
	  leptons.push_back(*lep_tmp);
	  lepton_ids.push_back(lep_id);
	  h_lepton_pt->Fill( (*part_itr)->pt()*0.001, weight );
	}
      }
    }
    }*/

  //use ONLY for W->tau nu
  /*for (part_itr = xTruthParticleContainer->begin(); part_itr!=xTruthParticleContainer->end(); ++part_itr) {
    if (((*part_itr)->absPdgId() == 11 || (*part_itr)->absPdgId() == 13) && (*part_itr)->status() == 1) {
      num_lepton_children += 1;
      h_lepton_pt_0GeV->Fill( (*part_itr)->pt()*0.001, weight);
      if ((*part_itr)->abseta() < 2.5) {
	if (((*part_itr)->absPdgId() == 11 && (*part_itr)->pt()*0.001 > 7.0) || ((*part_itr)->absPdgId() == 13 && (*part_itr)->pt()*0.001 > 5.0)) {
	  lep_tmp->SetPxPyPzE( (*part_itr)->px()*0.001, (*part_itr)->py()*0.001, (*part_itr)->pz()*0.001, (*part_itr)->e()*0.001 );
	  lep_id = (*part_itr)->pdgId();
	  leptons.push_back(*lep_tmp);
	  lepton_ids.push_back(lep_id);
	  h_lepton_pt->Fill( (*part_itr)->pt()*0.001, weight );
	}
      }
    }
    }*/

  if (leptons.size() == 1) {
    if (num_lepton_children == 2) leplep = true;
    else if (num_lepton_children == 1 && num_tau_children >= 1) leptau = true;
    else if (num_lepton_children == 1 && num_tau_children == 0) lephad = true;
    else {
      others = true; 
      std::cout << "other!! lepton children: " << num_lepton_children << " tau children: " << num_tau_children << std::endl;
    }
  }

  for (unsigned int n; n < leptons.size(); n++) {
    if (leptons[n].Pt() > lepton->Pt()) {
      *lepton = leptons[n];
    }
  }

  h_theoretical_leptons->SetBinContent( 1, .557*5000 );
  h_theoretical_leptons->SetBinContent( 2, .378*5000 );
  h_theoretical_leptons->SetBinContent( 3, .064*5000 );
  h_theoretical_leptons->SetBinError( 1, 0.00001 );
  h_theoretical_leptons->SetBinError( 2, 0.00001 );
  h_theoretical_leptons->SetBinError( 3, 0.00001 );
  h_theoretical_leptons->SetLineColor( kRed );
  h_theoretical_leptons->SetLineWidth( 2.5 );

  float MET_px = 0.0;
  float MET_py = 0.0;
  float MET_IntMu_px = 0.0;
  float MET_IntMu_py = 0.0;
  MET = new TLorentzVector(0., 0., 0., 0.);
  MET_IntMu = new TLorentzVector(0., 0., 0., 0.);

  xAOD::MissingETContainer::const_iterator MET_itr;
  for (MET_itr = xTruthMETContainer->begin(); MET_itr!=xTruthMETContainer->end(); ++MET_itr) {
    if( (*MET_itr)->name()=="NonInt" ) {
      MET_px += (*MET_itr)->mpx() * 0.001;
      MET_py += (*MET_itr)->mpy() * 0.001;
    }
    if( (*MET_itr)->name()=="Int" ) {
      MET_IntMu_px += (*MET_itr)->mpx() * 0.001;
      MET_IntMu_py += (*MET_itr)->mpy() * 0.001;
    }
    if( (*MET_itr)->name()=="Muons" ) {
      MET_IntMu_px += (*MET_itr)->mpx() * 0.001;
      MET_IntMu_py += (*MET_itr)->mpy() * 0.001;
    }
  }

  MET->SetPxPyPzE( MET_px, MET_py, 0., 0. );
  MET_IntMu->SetPxPyPzE( MET_IntMu_px, MET_IntMu_py, 0., 0. );

  h_MET_0GeV->Fill( MET->Pt(), weight );
  if (MET_IntMu->Pt() > 200.0) h_MET_200GeV->Fill( MET_IntMu->Pt(), weight );

  int label = 0;

  float bjet1_pt = 0.0;
  float bjet2_pt = 0.0;
  float non_bjet1_pt = 0.0;
  float non_bjet2_pt = 0.0;
  float bjet_ratio = 0.0;

  jet_tmp1 = new TLorentzVector(0., 0., 0., 0.);
  jj = new TLorentzVector(0., 0., 0., 0.);
  b1 = new TLorentzVector(0., 0., 0., 0.);
  b2 = new TLorentzVector(0., 0., 0., 0.);
  bb = new TLorentzVector(0., 0., 0., 0.);
  lb1 = new TLorentzVector(0., 0., 0., 0.);
  lb2 = new TLorentzVector(0., 0., 0., 0.);
  float jj_mass = 0.0;
  float mjj_max = 0.0;
  float mjj_min = 10000.0;

  float HT = 0.0;
  float HT_no_bjets = 0.0;
  float meff = 0.0;
  float meff_no_bjets = 0.0;

  float pTlep_MET = 100.0;
  float pTlep_MET2 = 100.0;

  xAOD::JetContainer::const_iterator jet_itr;
  xAOD::JetContainer::const_iterator jet_itr2;
  /*for (jet_itr = xTruthJetContainer->begin(); jet_itr!=xTruthJetContainer->end(); jet_itr++) {
    label = -1;
    (*jet_itr)->getAttribute("ConeTruthLabelID",label);
    jet_tmp1->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
    if ((*jet_itr)->pt()*0.001 > 20.0 && fabs((*jet_itr)->eta()) < 2.5) {
      num_jets += 1;
      if (label == 5) {
	num_bjets += 1;
	HT += (*jet_itr)->pt()*0.001;
	if ((*jet_itr)->pt()*0.001 > bjet1_pt) {
	  b2->SetPxPyPzE( b1->Px(), b1->Py(), b1->Pz(), b1->E() );
	  bjet2_pt = bjet1_pt;
	  b1->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
	  bjet1_pt = (*jet_itr)->pt()*0.001;
	}
	else if ((*jet_itr)->pt()*0.001 > bjet2_pt) {
	  b2->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
	  bjet2_pt = (*jet_itr)->pt()*0.001;
	}
      }
      else {
	HT += (*jet_itr)->pt()*0.001;
	HT_no_bjets += (*jet_itr)->pt()*0.001;
	if ((*jet_itr)->pt()*0.001 > non_bjet1_pt) {
	  jet2->SetPxPyPzE( jet1->Px(), jet1->Py(), jet1->Pz(), jet1->E() );
	  non_bjet2_pt = non_bjet1_pt;
	  jet1->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
	  non_bjet1_pt = (*jet_itr)->pt()*0.001;
	}
	else if ((*jet_itr)->pt()*0.001 > non_bjet2_pt) {
	  jet2->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
	  non_bjet2_pt = (*jet_itr)->pt()*0.001;
	}
	for (jet_itr2 = xTruthJetContainer->begin(); jet_itr2!=xTruthJetContainer->end(); jet_itr2++) {
	  label2 = -1;
	  (*jet_itr2)->getAttribute("ConeTruthLabelID", label2);
	  if ((*jet_itr2)->pt()*0.001 > 20.0 && fabs((*jet_itr2)->eta()) < 2.5) {
	    if (label2 != 5) {
	      jet_tmp2->SetPxPyPzE( (*jet_itr2)->px()*0.001, (*jet_itr2)->py()*0.001, (*jet_itr2)->pz()*0.001, (*jet_itr2)->e()*0.001 );
	      *jj = *jet_tmp1 + *jet_tmp2;
	      if (jj->M() > mjj_max) mjj_max = jj->M();
	      else if (jj->M() < mjj_min) mjj_min = jj->M();
	    }
	  }
	}
      }
    }
    }*/

  //std::vector< TLorentzVector > bjets;
  //std::vector< TLorentzVector > nonbjets;
  bjets.clear();
  nonbjets.clear();

  for (jet_itr = xTruthJetContainer->begin(); jet_itr!=xTruthJetContainer->end(); jet_itr++) {
    (*jet_itr)->getAttribute("ConeTruthLabelID",label);
    jet_tmp1->SetPxPyPzE( (*jet_itr)->px()*0.001, (*jet_itr)->py()*0.001, (*jet_itr)->pz()*0.001, (*jet_itr)->e()*0.001 );
    if ((*jet_itr)->pt()*0.001 > 20.0 && fabs((*jet_itr)->eta()) < 2.5) {
      if (label == 5) bjets.push_back(*jet_tmp1);
      else nonbjets.push_back(*jet_tmp1);
    }
  }

  /*for (unsigned int j = 0; j < nonbjets.size(); ++j) {
    bool remove = false;
    for (unsigned int i = 0; i < leptons.size(); ++i) {
      if (abs(lepton_ids[i]) == 11) {
	if (nonbjets[j].DeltaR(leptons[i]) < 0.2) remove = true;
      }
      else if (abs(lepton_ids[i]) == 13) {
	if (nonbjets[j].DeltaR(leptons[i]) < 0.4 && leptons[i].Pt() / nonbjets[j].Pt() > 0.7) remove = true;
      }
    }
    if (remove) {
      nonbjets.erase( nonbjets.begin() + j);
      j -= 1;
    }
  }

  for (unsigned int i = 0; i < leptons.size(); ++i) {
    bool remove = false;
    for (unsigned int j = 0; j < nonbjets.size(); ++j) {
      radius = std::min(0.04 + 10 / nonbjets[j].Pt(), 0.4);
      if (nonbjets[j].DeltaPhi(leptons[i]) < radius) remove = true;
    }
    for (unsigned int k = 0; k < bjets.size(); ++k) {
      radius = std::min(0.04 + 10 / bjets[k].Pt(), 0.4);
      if (bjets[k].DeltaPhi(leptons[i]) < radius) remove = true;
    }
    if (remove) {
      leptons.erase( nonbjets.begin() + i);
      i -= 1;
    }
    }*/

  h_num_leptons->Fill( leptons.size() );
  if (!chargino_child) h_num_leptons_total->Fill( num_lepton_children );

  float dphi_bjet_lepton_max = 0.0;
  float dphi_bjet_lepton_min = 100.0;
  float dphi_bjet_ptmiss_max = 0.0;
  float dphi_bjet_ptmiss_min = 100.0;
  float mlb_max = 0.0;
  float mlb_min = 1000.0;
  float mlvb_max = 0.0;
  float mlvb_min = 1000.0;

  mlb_tmp = new TLorentzVector(0., 0., 0., 0.);
  mlvb_tmp = new TLorentzVector(0., 0., 0., 0.);

  for (unsigned int b = 0; b < bjets.size(); ++b) {
    HT += bjets[b].Pt();
    meff += bjets[b].Pt();
    if (b > 1) {
      HT_no_bjets += bjets[b].Pt();
      meff_no_bjets += bjets[b].Pt();
    }
    if (bjets[b].Pt() > b1->Pt()) {
      *b2 = *b1;
      *b1 = bjets[b];
    }
    else if (bjets[b].Pt() > b2->Pt()) {
      *b2 = bjets[b];
    }
    if ( fabs(bjets[b].DeltaPhi(*lepton)) > dphi_bjet_lepton_max ) {
      dphi_bjet_lepton_max = fabs(bjets[b].DeltaPhi(*lepton));
    }
    if ( fabs(bjets[b].DeltaPhi(*lepton)) < dphi_bjet_lepton_min ) {
      dphi_bjet_lepton_min = fabs(bjets[b].DeltaPhi(*lepton));
    }
    if ( fabs(bjets[b].DeltaPhi(*MET_IntMu)) > dphi_bjet_ptmiss_max ) {
      dphi_bjet_ptmiss_max = fabs(bjets[b].DeltaPhi(*MET_IntMu));
    }
    if ( fabs(bjets[b].DeltaPhi(*MET_IntMu)) < dphi_bjet_ptmiss_min ) {
      dphi_bjet_ptmiss_min = fabs(bjets[b].DeltaPhi(*MET_IntMu));
    }
    *mlb_tmp = *lepton + bjets[b];
    if ( mlb_tmp->M() > mlb_max ) {
      mlb_max = mlb_tmp->M();
    }
    if ( mlb_tmp->M() < mlb_min ) {
      mlb_min = mlb_tmp->M();
    }
    float mT_mlvb = sqrt( 2 * mlb_tmp->Pt() * MET_IntMu->Pt() * ( 1 - cos( mlb_tmp->DeltaPhi(*MET_IntMu) ) ) );
    if ( mT_mlvb > mlvb_max ) {
      mlvb_max = mT_mlvb;
    }
    if ( mT_mlvb < mlvb_min ) {
      mlvb_min = mT_mlvb;
    }
  }

  double dR_child_jet1 = 100.0;
  double dR_child_jet2 = 100.0;
  float deltaPT_child_jet1 = 100.0;
  float deltaPT_child_jet2 = 100.0;

  double min1 = 100.0;
  double min2 = 100.0;
  double min3 = 100.0;
  double min4 = 100.0;

  /*if (had_child1->Pt() != 0.0 && had_child2->Pt() != 0.0) min1 = std::min( b1->DeltaR(*had_child1), b1->DeltaR(*had_child2) );
  if (had_child3->Pt() != 0.0 && had_child4->Pt() != 0.0) min2 = std::min( b1->DeltaR(*had_child3), b1->DeltaR(*had_child4) ); 
  dR_child_jet1 = std::min( min1, min2 );

  if (had_child1->Pt() != 0.0 && had_child2->Pt() != 0.0) min3 = std::min( b2->DeltaR(*had_child1), b2->DeltaR(*had_child2) );
  if (had_child3->Pt() != 0.0 && had_child4->Pt() != 0.0) min4 = std::min( b2->DeltaR(*had_child3), b2->DeltaR(*had_child4) );
  dR_child_jet2 = std::min( min3, min4 );

  if (dR_child_jet1 < 0.4) {
    if (dR_child_jet1 == b1->DeltaR(*had_child1) && had_child1->Pt() != 0.0) deltaPT_child_jet1 = (b1->Pt() - had_child1->Pt()) / had_child1->Pt();
    else if (dR_child_jet1 == b1->DeltaR(*had_child2) && had_child2->Pt() != 0.0) deltaPT_child_jet1 = (b1->Pt() - had_child2->Pt()) / had_child2->Pt();
    else if (dR_child_jet1 == b1->DeltaR(*had_child3) && had_child3->Pt() != 0.0) deltaPT_child_jet1 = (b1->Pt() - had_child3->Pt()) / had_child3->Pt();
    else if (dR_child_jet1 == b1->DeltaR(*had_child4) && had_child4->Pt() != 0.0) deltaPT_child_jet1 = (b1->Pt() - had_child4->Pt()) / had_child4->Pt();
  }

  if (dR_child_jet2 < 0.4) {
    if (dR_child_jet2 == b2->DeltaR(*had_child1) && had_child1->Pt() != 0.0) deltaPT_child_jet2 = (b2->Pt() - had_child1->Pt()) / had_child1->Pt();
    else if (dR_child_jet2 == b2->DeltaR(*had_child2) && had_child2->Pt() != 0.0) deltaPT_child_jet2 = (b2->Pt() - had_child2->Pt()) / had_child2->Pt();
    else if (dR_child_jet2 == b2->DeltaR(*had_child3) && had_child3->Pt() != 0.0) deltaPT_child_jet2 = (b2->Pt() - had_child3->Pt()) / had_child3->Pt();
    else if (dR_child_jet2 == b2->DeltaR(*had_child4) && had_child4->Pt() != 0.0) deltaPT_child_jet2 = (b2->Pt() - had_child4->Pt()) / had_child4->Pt();
    }*/

  for (unsigned int n = 0; n < nonbjets.size(); ++n) {
    HT += nonbjets[n].Pt();
    HT_no_bjets += nonbjets[n].Pt();
    meff += nonbjets[n].Pt();
    meff_no_bjets += nonbjets[n].Pt();
    if (nonbjets[n].Pt() > non_bjet1_pt) {
      non_bjet2_pt = non_bjet1_pt;
      non_bjet1_pt = nonbjets[n].Pt();
    }
    else if (nonbjets[n].Pt() > non_bjet2_pt) {
      non_bjet2_pt = nonbjets[n].Pt();
    }
    for (unsigned int m = 0; m < nonbjets.size(); ++m) {
      if (m != n) {
	*jj = nonbjets[n] + nonbjets[m];
	if (jj->M() > mjj_max) mjj_max = jj->M();
	else if (jj->M() < mjj_min) mjj_min = jj->M();
      }
    }
  }

  bjet1_pt = b1->Pt();
  bjet2_pt = b2->Pt();

  *bb = *b1 + *b2;
  *lb1 = *lepton + *b1;
  *lb2 = *lepton + *b2;

  float MET_projection = fabs(MET_IntMu->Vect().Dot(lepton->Vect()) / lepton->Pt());

  pTlep_MET = lepton->Pt() / MET_IntMu->Pt();
  pTlep_MET2 = lepton->Pt() / MET_projection;

  meff += lepton->Pt();
  meff_no_bjets += lepton->Pt();
  meff += MET_IntMu->Pt();
  meff_no_bjets += MET_IntMu->Pt();
  
  h_num_jets->Fill( bjets.size() + nonbjets.size(), weight );
  h_num_bjets->Fill( bjets.size(), weight );
  h_num_non_bjets->Fill( nonbjets.size(), weight );
  h_bjet1_pt->Fill( bjet1_pt, weight );
  h_bjet2_pt->Fill( bjet2_pt, weight );

  if (bjet1_pt != 0.0) bjet_ratio = bjet2_pt / bjet1_pt;

  ComputeaMT2 mt2aCalc(*lb1,*b2,*MET_IntMu,0.,80.);
  const float mt2a  = mt2aCalc.Compute();

  ComputeaMT2 mt2bCalc(*lb2,*b1,*MET_IntMu,0.,80.);
  const float  mt2b = mt2bCalc.Compute();

  const float aMT2 = std::min(mt2a,mt2b);
  const float aMT2_alt = std::max(mt2a,mt2b);

  float mT = sqrt( 2 * lepton->Pt() * MET_IntMu->Pt() * ( 1 - cos( lepton->DeltaPhi(*MET_IntMu) ) ) );

  if (leptons.size() >= 1) pass1lep_or_more = true;
  if (leptons.size() == 1) pass1lep = true;
  if( MET_IntMu->Pt() > 250.0) passMET = true;
  if (bjets.size() >= 2) pass2bjets = true;
  if (bjet1_pt > 250.0) passbjet1pt = true;
  if (bjet2_pt > 100.0) passbjet2pt = true;
  if (passbjet1pt && passbjet2pt) passbjetspt = true;
  if (aMT2 > 200.0) passamt2 = true;
  if (dphi_bjet_ptmiss_min > 1.0) passcloseMETb = true;
  if (bb->M() > 200.0) passmbb = true;
  if (lepton->Pt() < 30.0) passpTlep = true;
  if (bjets.size() + nonbjets.size() >= 4) pass4jets = true;
  if (pTlep_MET < 0.09) passpTlepMET = true;
  
  /*float x1=0.0;
  float x2=0.0;
  float den1 = lep1->Px()*lep2->Py()+MET_px*lep2->Py()-lep1->Py()*lep2->Px()-MET_py*lep2->Px();
  float den2 = lep1->Px()*lep2->Py()-MET_px*lep1->Py()-lep1->Py()*lep2->Px()+MET_py*lep1->Px();
  x1 = ( lep1->Px()*lep2->Py()-lep1->Py()*lep2->Px() ) / den1;
  x2 = ( lep1->Px()*lep2->Py()-lep1->Py()*lep2->Px() ) / den2;
  float mtautau = ll->M() / sqrt(x1*x2);*/

  total_events += 1;
  total_weighted_events += weight;
  h_entries->Fill(1, weight);
  h_num_jets_nocuts->Fill( bjets.size() + nonbjets.size(), weight );
  h_num_bjets_nocuts->Fill( bjets.size(), weight );
  h_num_non_bjets_nocuts->Fill( nonbjets.size(), weight );
  h_lepton_pt_nocuts->Fill( lepton->Pt(), weight );
  h_num_leptons_nocuts->Fill( leptons.size(), weight );
  h_MET_nocuts->Fill( MET_IntMu->Pt(), weight );
  h_bjet1_pt_nocuts->Fill( bjet1_pt, weight );
  h_bjet2_pt_nocuts->Fill( bjet2_pt, weight );
  h_non_bjet1_pt_nocuts->Fill( non_bjet1_pt, weight );
  h_non_bjet2_pt_nocuts->Fill( non_bjet2_pt, weight );
  h_jj_inv_mass_nocuts->Fill( jj_mass, weight );
  h_bjet_ratio_nocuts->Fill( bjet_ratio, weight );
  h_dphi_bjet_lepton_max_nocuts->Fill( dphi_bjet_lepton_max, weight );
  h_dphi_bjet_lepton_min_nocuts->Fill( dphi_bjet_lepton_min, weight );
  h_dphi_bjet_ptmiss_max_nocuts->Fill( dphi_bjet_ptmiss_max, weight );
  h_dphi_bjet_ptmiss_min_nocuts->Fill( dphi_bjet_ptmiss_min, weight );
  h_dphi_b1_b2_nocuts->Fill( b1->DeltaPhi(*b2), weight );
  h_mbb_nocuts->Fill( bb->M(), weight );
  h_amt2_nocuts->Fill( aMT2, weight );
  h_amt2_alt_nocuts->Fill( aMT2_alt, weight );
  h_mlb1_nocuts->Fill( mlb_max, weight );
  h_mlb2_nocuts->Fill( mlb_min, weight );
  h_hT_nocuts->Fill( HT, weight );
  h_hT_minus_bjets_nocuts->Fill( HT_no_bjets, weight );
  h_mjj_max_nocuts->Fill( mjj_max, weight );
  h_mjj_min_nocuts->Fill( mjj_min, weight );
  h_meff_nocuts->Fill( meff, weight );
  h_meff_minus_bjets_nocuts->Fill( meff_no_bjets, weight );
  h_mT_lepMET_nocuts->Fill( mT, weight );
  h_dphi_lep_ptmiss_nocuts->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
  h_pTlep_MET_nocuts->Fill( pTlep_MET, weight );
  h_pTlep_MET2_nocuts->Fill( pTlep_MET2, weight );
  h_METproj_nocuts->Fill( MET_projection, weight );
  h_dR_b1b2_nocuts->Fill( b1->DeltaR(*b2), weight );
  h_m_lvb_max_nocuts->Fill( mlvb_max, weight );
  h_m_lvb_min_nocuts->Fill( mlvb_min, weight );
  if (passMET && pass2bjets && passbjetspt && passamt2 && passcloseMETb && passmbb) {
    h_pTlep_noLepCut->Fill( lepton->Pt(), weight );
  }
  if (pass1lep && pass2bjets && passbjetspt && passamt2 && passcloseMETb && passmbb) {
    h_MET_noMETCut->Fill( MET_IntMu->Pt(), weight );
  }
  if (pass1lep && passMET && passbjet2pt && passamt2 && passcloseMETb && passmbb) {
    h_bjet1pt_nobJet1Cut->Fill( bjet1_pt, weight );
  }
  if (pass1lep && passMET && passbjet1pt && passamt2 && passcloseMETb && passmbb) {
    h_bjet2pt_nobJet2Cut->Fill( bjet2_pt, weight );
  }
  if (pass1lep && passMET && pass2bjets && passbjetspt && passcloseMETb && passmbb) {
    h_amt2_noamt2Cut->Fill( aMT2, weight );
  }
  if (pass1lep & passMET && pass2bjets && passbjetspt && passamt2 && passmbb) {
    h_dphibMET_noCloseMETbCut->Fill( dphi_bjet_ptmiss_min, weight );
  }
  if (pass1lep && passMET && pass2bjets && passbjetspt && passcloseMETb && passamt2) {
    h_mbb_nombbCut->Fill( bb->M(), weight );
  }
  if (passMET) {
    pass200MET_cut += weight;
    h_entries_200MET->Fill(1, weight);
    if (pass2bjets) {
      pass2bjet_cut += weight;
      h_entries_2bjets->Fill(1, weight);
      if (passbjetspt) {
	passbjetpt_cut += weight;
	h_entries_bjetspt->Fill(1, weight);
	h_num_jets_MET_bjets->Fill( bjets.size() + nonbjets.size(), weight );
	h_num_bjets_MET_bjets->Fill( bjets.size(), weight );
	h_num_non_bjets_MET_bjets->Fill( nonbjets.size(), weight );
	h_lepton_pt_MET_bjets->Fill( lepton->Pt(), weight );
	h_num_leptons_MET_bjets->Fill( leptons.size(), weight );
	h_MET_MET_bjets->Fill( MET_IntMu->Pt(), weight );
	h_bjet1_pt_MET_bjets->Fill( bjet1_pt, weight );
	h_bjet2_pt_MET_bjets->Fill( bjet2_pt, weight );
	h_non_bjet1_pt_MET_bjets->Fill( non_bjet1_pt, weight );
	h_non_bjet2_pt_MET_bjets->Fill( non_bjet2_pt, weight );
	h_jj_inv_mass_MET_bjets->Fill( jj_mass, weight );
	h_bjet_ratio_MET_bjets->Fill( bjet_ratio, weight );
	h_dphi_bjet_lepton_max_MET_bjets->Fill( dphi_bjet_lepton_max, weight );
	h_dphi_bjet_lepton_min_MET_bjets->Fill( dphi_bjet_lepton_min, weight );
	h_dphi_bjet_ptmiss_max_MET_bjets->Fill( dphi_bjet_ptmiss_max, weight );
	h_dphi_bjet_ptmiss_min_MET_bjets->Fill( dphi_bjet_ptmiss_min, weight );
	h_dphi_b1_b2_MET_bjets->Fill( b1->DeltaPhi(*b2), weight );
	h_mbb_MET_bjets->Fill( bb->M(), weight );
	h_amt2_MET_bjets->Fill( aMT2, weight );
	h_amt2_alt_MET_bjets->Fill( aMT2_alt, weight );
	h_mlb1_MET_bjets->Fill( mlb_max, weight );
	h_mlb2_MET_bjets->Fill( mlb_min, weight );
	h_hT_MET_bjets->Fill( HT, weight );
	h_hT_minus_bjets_MET_bjets->Fill( HT_no_bjets, weight );
	h_mjj_max_MET_bjets->Fill( mjj_max, weight );
	h_mjj_min_MET_bjets->Fill( mjj_min, weight );
	h_meff_MET_bjets->Fill( meff, weight );
	h_meff_minus_bjets_MET_bjets->Fill( meff_no_bjets, weight );
	h_mT_lepMET_MET_bjets->Fill( mT, weight );
	h_dphi_lep_ptmiss_MET_bjets->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
	h_pTlep_MET_MET_bjets->Fill( pTlep_MET, weight );
	h_pTlep_MET2_MET_bjets->Fill( pTlep_MET2, weight );
	h_METproj_MET_bjets->Fill( MET_projection, weight );
	h_dR_b1b2_MET_bjets->Fill( b1->DeltaR(*b2), weight );
	h_m_lvb_max_MET_bjets->Fill( mlvb_max, weight );
	h_m_lvb_min_MET_bjets->Fill( mlvb_min, weight );
	if (pass1lep_or_more) {
	  pass1lep_or_more_cut += weight;
	  h_entries_1lep_or_more->Fill(1, weight);
	  if (pass1lep) {
	    pass1lep_cut += weight;
	    h_entries_1lep->Fill(1, weight);
	    h_num_jets_1lep->Fill( bjets.size() + nonbjets.size(), weight );
	    h_num_bjets_1lep->Fill( bjets.size(), weight );
	    h_num_non_bjets_1lep->Fill( nonbjets.size(), weight );
	    h_lepton_pt_1lep->Fill( lepton->Pt(), weight );
	    h_num_leptons_1lep->Fill( leptons.size(), weight );
	    h_MET_1lep->Fill( MET_IntMu->Pt(), weight );
	    h_bjet1_pt_1lep->Fill( bjet1_pt, weight );
	    h_bjet2_pt_1lep->Fill( bjet2_pt, weight );
	    h_non_bjet1_pt_1lep->Fill( non_bjet1_pt, weight );
	    h_non_bjet2_pt_1lep->Fill( non_bjet2_pt, weight );
	    h_jj_inv_mass_1lep->Fill( jj_mass, weight );
	    h_bjet_ratio_1lep->Fill( bjet_ratio, weight );
	    h_dphi_bjet_lepton_max_1lep->Fill( dphi_bjet_lepton_max, weight );
	    h_dphi_bjet_lepton_min_1lep->Fill( dphi_bjet_lepton_min, weight );
	    h_dphi_bjet_ptmiss_max_1lep->Fill( dphi_bjet_ptmiss_max, weight );
	    h_dphi_bjet_ptmiss_min_1lep->Fill( dphi_bjet_ptmiss_min, weight );
	    h_dphi_b1_b2_1lep->Fill( b1->DeltaPhi(*b2), weight );
	    h_mbb_1lep->Fill( bb->M(), weight );
	    h_amt2_1lep->Fill( aMT2, weight );
	    h_amt2_alt_1lep->Fill( aMT2_alt, weight );
	    h_mlb1_1lep->Fill( mlb_max, weight );
	    h_mlb2_1lep->Fill( mlb_min, weight );
	    h_hT_1lep->Fill( HT, weight );
	    h_hT_minus_bjets_1lep->Fill( HT_no_bjets, weight );
	    h_mjj_max_1lep->Fill( mjj_max, weight );
	    h_mjj_min_1lep->Fill( mjj_min, weight );
	    h_meff_1lep->Fill( meff, weight );
	    h_meff_minus_bjets_1lep->Fill( meff_no_bjets, weight );
	    h_mT_lepMET_1lep->Fill( mT, weight );
	    h_dphi_lep_ptmiss_1lep->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
	    h_pTlep_MET_1lep->Fill( pTlep_MET, weight );
	    h_pTlep_MET2_1lep->Fill( pTlep_MET2, weight );
	    h_METproj_1lep->Fill( MET_projection, weight );
	    h_dR_b1b2_1lep->Fill( b1->DeltaR(*b2), weight );
	    h_m_lvb_max_1lep->Fill( mlvb_max, weight );
	    h_m_lvb_min_1lep->Fill( mlvb_min, weight );
	    if (passamt2) {
	      passamt2_cut += weight;
	      h_entries_amt2->Fill(1, weight);
	      if (passcloseMETb) {
		passcloseMETb_cut += weight;
		h_entries_closeMETb->Fill(1, weight);
		if (passmbb) {
		  passmbb_cut += weight;
		  h_entries_mbb->Fill(1, weight);
		  h_num_jets_mbb->Fill( bjets.size() + nonbjets.size(), weight );
		  h_num_bjets_mbb->Fill( bjets.size(), weight );
		  h_num_non_bjets_mbb->Fill( nonbjets.size(), weight );
		  h_lepton_pt_mbb->Fill( lepton->Pt(), weight );
		  h_num_leptons_mbb->Fill( leptons.size(), weight );
		  h_MET_mbb->Fill( MET_IntMu->Pt(), weight );
		  h_bjet1_pt_mbb->Fill( bjet1_pt, weight );
		  h_bjet2_pt_mbb->Fill( bjet2_pt, weight );
		  h_non_bjet1_pt_mbb->Fill( non_bjet1_pt, weight );
		  h_non_bjet2_pt_mbb->Fill( non_bjet2_pt, weight );
		  h_jj_inv_mass_mbb->Fill( jj_mass, weight );
		  h_bjet_ratio_mbb->Fill( bjet_ratio, weight );
		  h_dphi_bjet_lepton_max_mbb->Fill( dphi_bjet_lepton_max, weight );
		  h_dphi_bjet_lepton_min_mbb->Fill( dphi_bjet_lepton_min, weight );
		  h_dphi_bjet_ptmiss_max_mbb->Fill( dphi_bjet_ptmiss_max, weight );
		  h_dphi_bjet_ptmiss_min_mbb->Fill( dphi_bjet_ptmiss_min, weight );
		  h_dphi_b1_b2_mbb->Fill( b1->DeltaPhi(*b2), weight );
		  h_mbb_mbb->Fill( bb->M(), weight );
		  h_amt2_mbb->Fill( aMT2, weight );
		  h_amt2_alt_mbb->Fill( aMT2_alt, weight );
		  h_mlb1_mbb->Fill( mlb_max, weight );
		  h_mlb2_mbb->Fill( mlb_min, weight );
		  h_hT_mbb->Fill( HT, weight );
		  h_hT_minus_bjets_mbb->Fill( HT_no_bjets, weight );
		  h_mjj_max_mbb->Fill( mjj_max, weight );
		  h_mjj_min_mbb->Fill( mjj_min, weight );
		  h_meff_mbb->Fill( meff, weight );
		  h_meff_minus_bjets_mbb->Fill( meff_no_bjets, weight );
		  h_mT_lepMET_mbb->Fill( mT, weight );
		  h_dphi_lep_ptmiss_mbb->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		  h_pTlep_MET_mbb->Fill( pTlep_MET, weight );
		  h_pTlep_MET2_mbb->Fill( pTlep_MET2, weight );
		  h_METproj_mbb->Fill( MET_projection, weight );
		  h_dR_b1b2_mbb->Fill( b1->DeltaR(*b2), weight );
		  h_m_lvb_max_mbb->Fill( mlvb_max, weight );
		  h_m_lvb_min_mbb->Fill( mlvb_min, weight );
		  if (passpTlepMET) {
		    passpTlepMET_cut += weight;
		    h_entries_pTlepMET->Fill(1, weight);
		    h_num_jets_preselection->Fill( bjets.size() + nonbjets.size(), weight );
		    h_num_bjets_preselection->Fill( bjets.size(), weight );
		    h_num_non_bjets_preselection->Fill( nonbjets.size(), weight );
		    h_lepton_pt_preselection->Fill( lepton->Pt(), weight );
		    h_num_leptons_preselection->Fill( leptons.size(), weight );
		    h_MET_preselection->Fill( MET_IntMu->Pt(), weight );
		    h_bjet1_pt_preselection->Fill( bjet1_pt, weight );
		    h_bjet2_pt_preselection->Fill( bjet2_pt, weight );
		    h_non_bjet1_pt_preselection->Fill( non_bjet1_pt, weight );
		    h_non_bjet2_pt_preselection->Fill( non_bjet2_pt, weight );
		    h_jj_inv_mass_preselection->Fill( jj_mass, weight );
		    h_bjet_ratio_preselection->Fill( bjet_ratio, weight );
		    h_dphi_bjet_lepton_max_preselection->Fill( dphi_bjet_lepton_max, weight );
		    h_dphi_bjet_lepton_min_preselection->Fill( dphi_bjet_lepton_min, weight );
		    h_dphi_bjet_ptmiss_max_preselection->Fill( dphi_bjet_ptmiss_max, weight );
		    h_dphi_bjet_ptmiss_min_preselection->Fill( dphi_bjet_ptmiss_min, weight );
		    h_dphi_b1_b2_preselection->Fill( b1->DeltaPhi(*b2), weight );
		    h_mbb_preselection->Fill( bb->M(), weight );
		    h_amt2_preselection->Fill( aMT2, weight );
		    h_amt2_alt_preselection->Fill( aMT2_alt, weight );
		    h_mlb1_preselection->Fill( mlb_max, weight );
		    h_mlb2_preselection->Fill( mlb_min, weight );
		    h_hT_preselection->Fill( HT, weight );
		    h_hT_minus_bjets_preselection->Fill( HT_no_bjets, weight );
		    h_mjj_max_preselection->Fill( mjj_max, weight );
		    h_mjj_min_preselection->Fill( mjj_min, weight );
		    h_meff_preselection->Fill( meff, weight );
		    h_meff_minus_bjets_preselection->Fill( meff_no_bjets, weight );
		    h_mT_lepMET_preselection->Fill( mT, weight );
		    h_dphi_lep_ptmiss_preselection->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		    h_pTlep_MET_preselection->Fill( pTlep_MET, weight );
		    h_pTlep_MET2_preselection->Fill( pTlep_MET2, weight );
		    h_METproj_preselection->Fill( MET_projection, weight );
		    h_dR_b1b2_preselection->Fill( b1->DeltaR(*b2), weight );
		    h_m_lvb_max_preselection->Fill( mlvb_max, weight );
		    h_m_lvb_min_preselection->Fill( mlvb_min, weight );
		    if (leplep) {
		      h_num_jets_preselection_leplep->Fill( bjets.size() + nonbjets.size(), weight );
		      h_num_bjets_preselection_leplep->Fill( bjets.size(), weight );
		      h_num_non_bjets_preselection_leplep->Fill( nonbjets.size(), weight );
		      h_lepton_pt_preselection_leplep->Fill( lepton->Pt(), weight );
		      h_MET_preselection_leplep->Fill( MET_IntMu->Pt(), weight );
		      h_bjet1_pt_preselection_leplep->Fill( bjet1_pt, weight );
		      h_bjet2_pt_preselection_leplep->Fill( bjet2_pt, weight );
		      h_bjet_ratio_preselection_leplep->Fill( bjet_ratio, weight );	
		      h_non_bjet1_pt_preselection_leplep->Fill( non_bjet1_pt, weight );
		      h_non_bjet2_pt_preselection_leplep->Fill( non_bjet2_pt, weight );
		      h_dphi_bjet_lepton_max_preselection_leplep->Fill( dphi_bjet_lepton_max, weight );
		      h_dphi_bjet_lepton_min_preselection_leplep->Fill( dphi_bjet_lepton_min, weight );
		      h_dphi_bjet_ptmiss_max_preselection_leplep->Fill( dphi_bjet_ptmiss_max, weight );
		      h_dphi_bjet_ptmiss_min_preselection_leplep->Fill( dphi_bjet_ptmiss_min, weight );
		      h_dphi_b1_b2_preselection_leplep->Fill( b1->DeltaPhi(*b2), weight );
		      h_mbb_preselection_leplep->Fill( bb->M(), weight );
		      h_amt2_preselection_leplep->Fill( aMT2, weight );
		      h_amt2_alt_preselection_leplep->Fill( aMT2_alt, weight );
		      h_mlb1_preselection_leplep->Fill( mlb_max, weight );
		      h_mlb2_preselection_leplep->Fill( mlb_min, weight );
		      h_hT_preselection_leplep->Fill( HT, weight );
		      h_hT_minus_bjets_preselection_leplep->Fill( HT_no_bjets, weight );
		      h_mjj_max_preselection_leplep->Fill( mjj_max, weight );
		      h_mjj_min_preselection_leplep->Fill( mjj_min, weight );
		      h_meff_preselection_leplep->Fill( meff, weight );
		      h_meff_minus_bjets_preselection_leplep->Fill( meff_no_bjets, weight );
		      h_mT_lepMET_preselection_leplep->Fill( mT, weight );
		      h_dphi_lep_ptmiss_preselection_leplep->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		      h_pTlep_MET_preselection_leplep->Fill( pTlep_MET, weight );
		      h_pTlep_MET2_preselection_leplep->Fill( pTlep_MET2, weight );
		      h_METproj_preselection_leplep->Fill( MET_projection, weight );
		      h_dR_b1b2_preselection_leplep->Fill( b1->DeltaR(*b2), weight );
		      h_m_lvb_max_preselection_leplep->Fill( mlvb_max, weight );
		      h_m_lvb_min_preselection_leplep->Fill( mlvb_min, weight );
		    }
		    else if (leptau) {
		      h_num_jets_preselection_leptau->Fill( bjets.size() + nonbjets.size(), weight );
		      h_num_bjets_preselection_leptau->Fill( bjets.size(), weight );
		      h_num_non_bjets_preselection_leptau->Fill( nonbjets.size(), weight );
		      h_lepton_pt_preselection_leptau->Fill( lepton->Pt(), weight );
		      h_MET_preselection_leptau->Fill( MET_IntMu->Pt(), weight );
		      h_bjet1_pt_preselection_leptau->Fill( bjet1_pt, weight );
		      h_bjet2_pt_preselection_leptau->Fill( bjet2_pt, weight );
		      h_bjet_ratio_preselection_leptau->Fill( bjet_ratio, weight );	
		      h_non_bjet1_pt_preselection_leptau->Fill( non_bjet1_pt, weight );
		      h_non_bjet2_pt_preselection_leptau->Fill( non_bjet2_pt, weight );
		      h_dphi_bjet_lepton_max_preselection_leptau->Fill( dphi_bjet_lepton_max, weight );
		      h_dphi_bjet_lepton_min_preselection_leptau->Fill( dphi_bjet_lepton_min, weight );
		      h_dphi_bjet_ptmiss_max_preselection_leptau->Fill( dphi_bjet_ptmiss_max, weight );
		      h_dphi_bjet_ptmiss_min_preselection_leptau->Fill( dphi_bjet_ptmiss_min, weight );
		      h_dphi_b1_b2_preselection_leptau->Fill( b1->DeltaPhi(*b2), weight );
		      h_mbb_preselection_leptau->Fill( bb->M(), weight );
		      h_amt2_preselection_leptau->Fill( aMT2, weight );
		      h_amt2_alt_preselection_leptau->Fill( aMT2_alt, weight );
		      h_mlb1_preselection_leptau->Fill( mlb_max, weight );
		      h_mlb2_preselection_leptau->Fill( mlb_min, weight );
		      h_hT_preselection_leptau->Fill( HT, weight );
		      h_hT_minus_bjets_preselection_leptau->Fill( HT_no_bjets, weight );
		      h_mjj_max_preselection_leptau->Fill( mjj_max, weight );
		      h_mjj_min_preselection_leptau->Fill( mjj_min, weight );
		      h_meff_preselection_leptau->Fill( meff, weight );
		      h_meff_minus_bjets_preselection_leptau->Fill( meff_no_bjets, weight );
		      h_mT_lepMET_preselection_leptau->Fill( mT, weight );
		      h_dphi_lep_ptmiss_preselection_leptau->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		      h_pTlep_MET_preselection_leptau->Fill( pTlep_MET, weight );
		      h_pTlep_MET2_preselection_leptau->Fill( pTlep_MET2, weight );
		      h_METproj_preselection_leptau->Fill( MET_projection, weight );
		      h_dR_b1b2_preselection_leptau->Fill( b1->DeltaR(*b2), weight );
		      h_m_lvb_max_preselection_leptau->Fill( mlvb_max, weight );
		      h_m_lvb_min_preselection_leptau->Fill( mlvb_min, weight );
		    }
		    else if (lephad) {
		      h_num_jets_preselection_lephad->Fill( bjets.size() + nonbjets.size(), weight );
		      h_num_bjets_preselection_lephad->Fill( bjets.size(), weight );
		      h_num_non_bjets_preselection_lephad->Fill( nonbjets.size(), weight );
		      h_lepton_pt_preselection_lephad->Fill( lepton->Pt(), weight );
		      h_MET_preselection_lephad->Fill( MET_IntMu->Pt(), weight );
		      h_bjet1_pt_preselection_lephad->Fill( bjet1_pt, weight );
		      h_bjet2_pt_preselection_lephad->Fill( bjet2_pt, weight );
		      h_bjet_ratio_preselection_lephad->Fill( bjet_ratio, weight );	
		      h_non_bjet1_pt_preselection_lephad->Fill( non_bjet1_pt, weight );
		      h_non_bjet2_pt_preselection_lephad->Fill( non_bjet2_pt, weight );
		      h_dphi_bjet_lepton_max_preselection_lephad->Fill( dphi_bjet_lepton_max, weight );
		      h_dphi_bjet_lepton_min_preselection_lephad->Fill( dphi_bjet_lepton_min, weight );
		      h_dphi_bjet_ptmiss_max_preselection_lephad->Fill( dphi_bjet_ptmiss_max, weight );
		      h_dphi_bjet_ptmiss_min_preselection_lephad->Fill( dphi_bjet_ptmiss_min, weight );
		      h_dphi_b1_b2_preselection_lephad->Fill( b1->DeltaPhi(*b2), weight );
		      h_mbb_preselection_lephad->Fill( bb->M(), weight );
		      h_amt2_preselection_lephad->Fill( aMT2, weight );
		      h_amt2_alt_preselection_lephad->Fill( aMT2_alt, weight );
		      h_mlb1_preselection_lephad->Fill( mlb_max, weight );
		      h_mlb2_preselection_lephad->Fill( mlb_min, weight );
		      h_hT_preselection_lephad->Fill( HT, weight );
		      h_hT_minus_bjets_preselection_lephad->Fill( HT_no_bjets, weight );
		      h_mjj_max_preselection_lephad->Fill( mjj_max, weight );
		      h_mjj_min_preselection_lephad->Fill( mjj_min, weight );
		      h_meff_preselection_lephad->Fill( meff, weight );
		      h_meff_minus_bjets_preselection_lephad->Fill( meff_no_bjets, weight );
		      h_mT_lepMET_preselection_lephad->Fill( mT, weight );
		      h_dphi_lep_ptmiss_preselection_lephad->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		      h_pTlep_MET_preselection_lephad->Fill( pTlep_MET, weight );
		      h_pTlep_MET2_preselection_lephad->Fill( pTlep_MET2, weight );
		      h_METproj_preselection_lephad->Fill( MET_projection, weight );
		      h_dR_b1b2_preselection_lephad->Fill( b1->DeltaR(*b2), weight );
		      h_m_lvb_max_preselection_lephad->Fill( mlvb_max, weight );
		      h_m_lvb_min_preselection_lephad->Fill( mlvb_min, weight );
		    }
		    /*else if (others) {
		      h_lepton_pt_preselection_others->Fill( lepton->Pt(), weight );
		      h_MET_preselection_others->Fill( MET_IntMu->Pt(), weight );
		      h_bjet1_pt_preselection_others->Fill( bjet1_pt, weight );
		      h_bjet2_pt_preselection_others->Fill( bjet2_pt, weight );
		      h_non_bjet1_pt_preselection_others->Fill( non_bjet1_pt, weight );
		      h_non_bjet2_pt_preselection_others->Fill( non_bjet2_pt, weight );
		      h_dphi_bjet_lepton_max_preselection_others->Fill( std::max( fabs(b1->DeltaPhi(*lepton)), fabs(b2->DeltaPhi(*lepton)) ), weight );
		      h_dphi_bjet_lepton_min_preselection_others->Fill( std::min( fabs(b1->DeltaPhi(*lepton)), fabs(b2->DeltaPhi(*lepton)) ), weight );
		      h_dphi_bjet_ptmiss_max_preselection_others->Fill( std::max( fabs(b1->DeltaPhi(*MET_IntMu)), fabs(b2->DeltaPhi(*MET_IntMu)) ), weight );
		      h_dphi_bjet_ptmiss_min_preselection_others->Fill( std::min( fabs(b1->DeltaPhi(*MET_IntMu)), fabs(b2->DeltaPhi(*MET_IntMu)) ), weight );
		      h_dphi_b1_b2_preselection_others->Fill( b1->DeltaPhi(*b2), weight );
		      h_mbb_preselection_others->Fill( bb->M(), weight );
		      h_amt2_preselection_others->Fill( aMT2, weight );
		      h_amt2_alt_preselection_others->Fill( aMT2_alt, weight );
		      h_mlb1_preselection_others->Fill( lb1->M(), weight );
		      h_mlb2_preselection_others->Fill( lb2->M(), weight );
		      h_hT_preselection_others->Fill( HT, weight );
		      h_hT_minus_bjets_preselection_others->Fill( HT_no_bjets, weight );
		      h_mjj_max_preselection_others->Fill( mjj_max, weight );
		      h_mjj_min_preselection_others->Fill( mjj_min, weight );
		      h_meff_preselection_others->Fill( meff, weight );
		      h_meff_minus_bjets_preselection_others->Fill( meff_no_bjets, weight );
		      h_mT_lepMET_preselection_others->Fill( mT, weight );
		      h_dphi_lep_ptmiss_preselection_others->Fill( lepton->DeltaPhi(*MET_IntMu), weight );
		      }*/
		  }
		  if (passpTlep) {
		    passpTlep_cut += weight;
		    h_entries_pTlep->Fill(1, weight);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }

  /*
  //h_num_electrons->Scale(scale);
  //h_num_muons->Scale(scale);
  //h_num_jets->Scale(scale);
  //h_num_bjets->Scale(scale);
  //h_num_non_bjets->Scale(scale);
  h_bjet1_pt->Scale(scale);
  h_bjet2_pt->Scale(scale);
  //h_jj_inv_mass->Scale(scale);
  h_lepton_pt_0GeV->Scale(scale);
  h_lepton_pt->Scale(scale);
  //h_num_leptons->Scale(scale);
  //h_num_leptons_total->Scale(scale);
  h_MET_0GeV->Scale(scale);
  h_MET_200GeV->Scale(scale);
  //h_num_jets_1lep->Scale(scale);
  h_lepton_pt_1lep->Scale(scale);
  //h_num_leptons_1lep->Scale(scale);
  h_MET_1lep->Scale(scale);
  h_bjet1_pt_1lep->Scale(scale);
  h_bjet1_pt_1lep->Scale(scale);
  //h_num_jets_200MET->Scale(scale);
  h_lepton_pt_200MET->Scale(scale);
  //h_num_leptons_200MET->Scale(scale);
  h_MET_200MET->Scale(scale);
  h_bjet1_pt_200MET->Scale(scale);
  h_bjet2_pt_200MET->Scale(scale);
  //h_num_jets_preselection->Scale(scale);
  h_lepton_pt_preselection->Scale(scale);
  //h_num_leptons_preselection->Scale(scale);
  h_MET_preselection->Scale(scale);
  h_bjet1_pt_preselection->Scale(scale);
  h_bjet2_pt_preselection->Scale(scale);
  //h_theoretical_leptons->Scale(scale);
  */

  //std::cout << "done execute" << std::endl;

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.

  if(total_events%5000==0){
    std::cout << "total weighted event: " << total_weighted_events << std::endl;
    std::cout << "pass 200 MET cut: " << pass200MET_cut << std::endl;
    std::cout << "pass 2 b-jet cut: " << pass2bjet_cut << std::endl;
    std::cout << "pass b-jets pt cut: " << passbjetpt_cut << std::endl;
    std::cout << "pass at least 1 lepton cut: " << pass1lep_or_more_cut << std::endl;
    std::cout << "pass exactly 1 lepton cut: " << pass1lep_cut << std::endl;
    std::cout << "pass aMT2 cut: " << passamt2_cut << std::endl;
    std::cout << "pass close b-jet/MET: " << passcloseMETb_cut << std::endl;
    std::cout << "pass mbb cut: " << passmbb_cut << std::endl;
    std::cout << "pass pT_lep / MET cut: " << passpTlepMET_cut << std::endl;
    std::cout << "pass pT_lep cut: " << passpTlep_cut << std::endl;
    std::cout << " " << std::endl;
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: finalize ()
{
  const char* APP_NAME = "MyxAODAnalysis";

  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.

  return EL::StatusCode::SUCCESS;
}
