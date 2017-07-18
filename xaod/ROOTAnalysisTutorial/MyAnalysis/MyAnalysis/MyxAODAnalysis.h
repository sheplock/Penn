#ifndef MyAnalysis_MyxAODAnalysis_H
#define MyAnalysis_MyxAODAnalysis_H

// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"

#include <EventLoop/Algorithm.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TLorentzVector.h>

class MyxAODAnalysis : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:

  // Tree *myTree; //!
  TH1 *myHist; //!
  TH1 *h_truthParticlePt; //!
  TH1 *h_truthTauPt; //!
  TH1 *h_truthTauTauPt; //!
  TH1 *h_truth_dPhiTauTau; //!
  TH1 *h_truth_dPhiTauTauMET; //!

  TH1 *h_deltaR_bjet; //!
  TH1 *h_deltaR_jets; //!

  TH1 *h_numtauparents; //!
  TH1 *h_numtauparents_METcut; //!
  TH1 *h_numtauparents_jetcut; //!
  TH1 *h_numtauparents_bveto; //!
  TH1 *h_numtauparents_lepcut; //!
  TH1 *h_numtauparents_mttcut; //!
  TH1 *h_numtauparents_mllcut; //!
  TH1 *h_numtauparents_PTllMETcut; //!

  TH1 *h_leptontypes; //!
  TH1 *h_leptontypes_METcut; //!
  TH1 *h_leptontypes_jetcut; //!
  TH1 *h_leptontypes_bveto; //!
  TH1 *h_leptontypes_lepcut; //!
  TH1 *h_leptontypes_mttcut; //!
  TH1 *h_leptontypes_mllcut; //!
  TH1 *h_leptontypes_PTllMETcut; //!
  
  TH1 *h_truthLep1_pt; //!
  TH1 *h_truthLep2_pt; //!
  TH1 *h_truthMET; //!
  TH1 *h_truthNumJets; //!
  TH1 *h_truthJet_pt; //!
  TH1 *h_truth_Mll; //!
  TH1 *h_truth_PTll; //!
  TH1 *h_truth_dPhi_ll; //!
  TH1 *h_truth_dPhi_llMET; //!
  TH1 *h_truth_mTauTau; //!
  TH1 *h_truth_PTllMET; //!
  TH1 *h_truth_NumBJets; //!
  TH1 *h_truth_NumBJets_alt; //!
  TH2 *h_b_PtEta; //!
  TH1 *h_b_parent; //!
  TH1* h_truth_METplusPTll; //!

  TH1 *h_truthLep1_pt_METcut; //!
  TH1 *h_truthLep2_pt_METcut; //!
  TH1 *h_truthMET_METcut; //!
  TH1 *h_truthNumJets_METcut; //!
  TH1 *h_truthJet_pt_METcut; //!
  TH1 *h_truth_Mll_METcut; //!
  TH1 *h_truth_PTll_METcut; //!
  TH1 *h_truth_dPhi_ll_METcut; //!
  TH1 *h_truth_dPhi_llMET_METcut; //!
  TH1 *h_truth_mTauTau_METcut; //!
  TH1 *h_truth_PTllMET_METcut; //!
  TH1 *h_truth_NumBJets_METcut; //!
  TH1 *h_truth_NumBJets_alt_METcut; //!
  TH2 *h_b_PtEta_METcut; //!
  TH1 *h_b_parent_METcut; //!
  TH1* h_truth_METplusPTll_METcut; //!

  TH1 *h_truthLep1_pt_jetcut; //!
  TH1 *h_truthLep2_pt_jetcut; //!
  TH1 *h_truthMET_jetcut; //!
  TH1 *h_truthNumJets_jetcut; //!
  TH1 *h_truthJet_pt_jetcut; //!
  TH1 *h_truth_Mll_jetcut; //!
  TH1 *h_truth_PTll_jetcut; //!
  TH1 *h_truth_dPhi_ll_jetcut; //!
  TH1 *h_truth_dPhi_llMET_jetcut; //!
  TH1 *h_truth_mTauTau_jetcut; //!
  TH1 *h_truth_PTllMET_jetcut; //!
  TH1 *h_truth_NumBJets_jetcut; //!
  TH1 *h_truth_NumBJets_alt_jetcut; //!
  TH2 *h_b_PtEta_jetcut; //!
  TH1 *h_b_parent_jetcut; //!
  TH1* h_truth_METplusPTll_jetcut; //!

  TH1 *h_truthLep1_pt_bveto; //!
  TH1 *h_truthLep2_pt_bveto; //!
  TH1 *h_truthMET_bveto; //!
  TH1 *h_truthNumJets_bveto; //!
  TH1 *h_truthJet_pt_bveto; //!
  TH1 *h_truth_Mll_bveto; //!
  TH1 *h_truth_PTll_bveto; //!
  TH1 *h_truth_dPhi_ll_bveto; //!
  TH1 *h_truth_dPhi_llMET_bveto; //!
  TH1 *h_truth_mTauTau_bveto; //!
  TH1 *h_truth_PTllMET_bveto; //!
  TH1 *h_truth_NumBJets_bveto; //!
  TH1 *h_truth_NumBJets_alt_bveto; //!
  TH2 *h_b_PtEta_bveto; //!
  TH1 *h_b_parent_bveto; //!
  TH1* h_truth_METplusPTll_bveto; //!

  TH1 *h_truthLep1_pt_lepcut; //!
  TH1 *h_truthLep2_pt_lepcut; //!
  TH1 *h_truthMET_lepcut; //!
  TH1 *h_truthNumJets_lepcut; //!
  TH1 *h_truthJet_pt_lepcut; //!
  TH1 *h_truth_Mll_lepcut; //!
  TH1 *h_truth_PTll_lepcut; //!
  TH1 *h_truth_dPhi_ll_lepcut; //!
  TH1 *h_truth_dPhi_llMET_lepcut; //!
  TH1 *h_truth_mTauTau_lepcut; //!
  TH1 *h_truth_PTllMET_lepcut; //!
  TH1 *h_truth_NumBJets_lepcut; //!
  TH1 *h_truth_NumBJets_alt_lepcut; //!
  TH2 *h_b_PtEta_lepcut; //!
  TH1 *h_b_parent_lepcut; //!
  TH1* h_truth_METplusPTll_lepcut; //!

  TH1 *h_truthLep1_pt_mttcut; //!
  TH1 *h_truthLep2_pt_mttcut; //!
  TH1 *h_truthMET_mttcut; //!
  TH1 *h_truthNumJets_mttcut; //!
  TH1 *h_truthJet_pt_mttcut; //!
  TH1 *h_truth_Mll_mttcut; //!
  TH1 *h_truth_PTll_mttcut; //!
  TH1 *h_truth_dPhi_ll_mttcut; //!
  TH1 *h_truth_dPhi_llMET_mttcut; //!
  TH1 *h_truth_mTauTau_mttcut; //!
  TH1 *h_truth_PTllMET_mttcut; //!
  TH1 *h_truth_NumBJets_mttcut; //!
  TH1 *h_truth_NumBJets_alt_mttcut; //!
  TH2 *h_b_PtEta_mttcut; //!
  TH1 *h_b_parent_mttcut; //!
  TH1* h_truth_METplusPTll_mttcut; //!

  TH1 *h_truthLep1_pt_mllcut; //!
  TH1 *h_truthLep2_pt_mllcut; //!
  TH1 *h_truthMET_mllcut; //!
  TH1 *h_truthNumJets_mllcut; //!
  TH1 *h_truthJet_pt_mllcut; //!
  TH1 *h_truth_Mll_mllcut; //!
  TH1 *h_truth_PTll_mllcut; //!
  TH1 *h_truth_dPhi_ll_mllcut; //!
  TH1 *h_truth_dPhi_llMET_mllcut; //!
  TH1 *h_truth_mTauTau_mllcut; //!
  TH1 *h_truth_PTllMET_mllcut; //!
  TH1 *h_truth_NumBJets_mllcut; //!
  TH1 *h_truth_NumBJets_alt_mllcut; //!
  TH2 *h_b_PtEta_mllcut; //!
  TH1 *h_b_parent_mllcut; //!
  TH1* h_truth_METplusPTll_mllcut; //!

  TH1 *h_truthLep1_pt_PTllMETcut; //!
  TH1 *h_truthLep2_pt_PTllMETcut; //!
  TH1 *h_truthMET_PTllMETcut; //!
  TH1 *h_truthNumJets_PTllMETcut; //!
  TH1 *h_truthJet_pt_PTllMETcut; //!
  TH1 *h_truth_Mll_PTllMETcut; //!
  TH1 *h_truth_PTll_PTllMETcut; //!
  TH1 *h_truth_dPhi_ll_PTllMETcut; //!
  TH1 *h_truth_dPhi_llMET_PTllMETcut; //!
  TH1 *h_truth_mTauTau_PTllMETcut; //!
  TH1 *h_truth_PTllMET_PTllMETcut; //!
  TH1 *h_truth_NumBJets_PTllMETcut; //!
  TH1 *h_truth_NumBJets_alt_PTllMETcut; //!
  TH2 *h_b_PtEta_PTllMETcut; //!
  TH1 *h_b_parent_PTllMETcut; //!
  TH1* h_truth_METplusPTll_PTllMETcut; //!

  TLorentzVector *MET; //!
  TLorentzVector *jet; //!
  TLorentzVector *jet_tmp1; //!
  TLorentzVector *jet_tmp2; //!
  TLorentzVector *tau1; //!
  TLorentzVector *tau2; //!
  TLorentzVector *tautau; //!
  //TLorentzVector *child1; //!
  //TLorentzVector *child2; //!
  TLorentzVector *ll; //!
  TLorentzVector *reco_Z; //!
  TLorentzVector *lep1; //!
  TLorentzVector *lep2; //!
  TLorentzVector *electron1; //!
  TLorentzVector *electron2; //!
  TLorentzVector *muon1; //!
  TLorentzVector *muon2; //!
  TLorentzVector *e_tmp1; //!
  TLorentzVector *e_tmp2; //!
  TLorentzVector *mu_tmp1; //!
  TLorentzVector *mu_tmp2; //!
  TLorentzVector *b_tmp; //!
  TLorentzVector *part_tmp; //!
  TLorentzVector *lepcone1; //!
  TLorentzVector *lepcone2; //!

  //int leptons = 0;
  int both_leptons = 0;

  int one_together = 0;
  int two_together = 0;
  int three_together = 0;

  int small_mll = 0;
  int small_drll = 0;

  int decay1 = 0;
  int decay2 = 0;
  int decay3 = 0;
  int decay4 = 0;
  int decay5 = 0;
  int decay6 = 0;
  int decay7 = 0;
  int decay8 = 0;
  int decay_other = 0;

  int has_bjet = 0;
  int fail_bjet = 0;
  int pass_bjet = 0;

  int PtEta_fail = 0;
  int Pt_fail = 0;
  int Eta_fail = 0;
  int no_fail = 0;
  int total_fail = 0;

  int PtEta_fail_jet = 0;
  int Pt_fail_jet = 0;
  int Eta_fail_jet = 0;
  int no_fail_jet = 0;
  int total_fail_jet = 0;

  int PtEta_fail_bveto = 0;
  int Pt_fail_bveto = 0;
  int Eta_fail_bveto = 0;
  int no_fail_bveto = 0;
  int total_fail_bveto = 0;

  int total_events = 0;
  float total_weighted_events = 0;
  
  int after_METCut = 0;
  int after_JetCut = 0;
  int after_bVeto  = 0;
  int after_LepCut = 0;
  int after_MttCut = 0;
  int after_MllCut = 0;
  int after_PTllMETCut = 0;

  int after_bVeto_2 = 0;
  int after_onejet_2 = 0;
  int after_jetcut_2 = 0;
  int after_METcut_2 = 0;
  int after_lepcut_2_truth = 0;
  int after_lepcut_2_donut = 0;


  // - - - - - - - - - - -  //


  TH1 *h_num_leptons; //!
  TH1 *h_num_electrons; //!
  TH1 *h_num_muons; //!
  TH1 *h_num_bjets; //!
  TH1 *h_num_non_bjets; //!

  TH1 *h_bjet1_pt; //!
  TH1 *h_bjet2_pt; //!

  TH1 *h_num_jets; //!
  TH1 *h_lepton_pt_0GeV; //!
  TH1 *h_lepton_pt_MET_b_cuts; //!
  TH1 *h_lepton_pt; //!
  TH1 *h_MET_0GeV; //!
  TH1 *h_MET_200GeV; //!

  TH1 *h_num_jets_200MET; //!
  TH1 *h_lepton_pt_200MET; //!
  TH1 *h_num_leptons_200MET; //!
  TH1 *h_MET_200MET; //!
  TH1 *h_bjet1_pt_200MET; //!
  TH1 *h_bjet2_pt_200MET; //!

  TH1 *h_num_jets_2b; //!
  TH1 *h_lepton_pt_2b; //!
  TH1 *h_num_leptons_2b; //!
  TH1 *h_MET_2b; //!
  TH1 *h_bjet1_pt_2b; //!
  TH1 *h_bjet2_pt_2b; //!

  TH1 *h_num_jets_nocuts; //!
  TH1 *h_num_bjets_nocuts; //!
  TH1 *h_num_non_bjets_nocuts; //!
  TH1 *h_lepton_pt_nocuts; //!
  TH1 *h_num_leptons_nocuts; //!
  TH1 *h_MET_nocuts; //!
  TH1 *h_bjet1_pt_nocuts; //!
  TH1 *h_bjet2_pt_nocuts; //!
  TH1 *h_non_bjet1_pt_nocuts; //!
  TH1 *h_non_bjet2_pt_nocuts; //!
  TH1 *h_jj_inv_mass_nocuts; //!
  TH1 *h_bjet_ratio_nocuts; //!
  TH1 *h_dphi_bjet_lepton_max_nocuts; //!
  TH1 *h_dphi_bjet_lepton_min_nocuts; //!
  TH1 *h_dphi_bjet_ptmiss_max_nocuts; //!
  TH1 *h_dphi_bjet_ptmiss_min_nocuts; //!
  TH1 *h_dphi_b1_b2_nocuts; //!
  TH1 *h_mbb_nocuts; //!
  TH1 *h_amt2_nocuts; //!
  TH1 *h_amt2_alt_nocuts; //!
  TH1 *h_mlb1_nocuts; //!
  TH1 *h_mlb2_nocuts; //!
  TH1 *h_hT_nocuts; //!
  TH1 *h_hT_minus_bjets_nocuts; //!
  TH1 *h_mjj_max_nocuts; //!
  TH1 *h_mjj_min_nocuts; //!
  TH1 *h_meff_nocuts; //!
  TH1 *h_meff_minus_bjets_nocuts; //!
  TH1 *h_mT_lepMET_nocuts; //!
  TH1 *h_dphi_lep_ptmiss_nocuts; //!
  TH1 *h_pTlep_MET_nocuts; //!
  TH1 *h_pTlep_MET2_nocuts; //!
  TH1 *h_METproj_nocuts; //!
  TH1 *h_dR_b1b2_nocuts; //!
  TH1 *h_m_lvb_max_nocuts; //!
  TH1 *h_m_lvb_min_nocuts; //!

  TH1 *h_num_jets_1lep; //!
  TH1 *h_num_bjets_1lep; //!
  TH1 *h_num_non_bjets_1lep; //!
  TH1 *h_lepton_pt_1lep; //!
  TH1 *h_num_leptons_1lep; //!
  TH1 *h_MET_1lep; //!
  TH1 *h_bjet1_pt_1lep; //!
  TH1 *h_bjet2_pt_1lep; //!
  TH1 *h_non_bjet1_pt_1lep; //!
  TH1 *h_non_bjet2_pt_1lep; //!
  TH1 *h_jj_inv_mass_1lep; //!
  TH1 *h_bjet_ratio_1lep; //!
  TH1 *h_dphi_bjet_lepton_max_1lep; //!
  TH1 *h_dphi_bjet_lepton_min_1lep; //!
  TH1 *h_dphi_bjet_ptmiss_max_1lep; //!
  TH1 *h_dphi_bjet_ptmiss_min_1lep; //!
  TH1 *h_dphi_b1_b2_1lep; //!
  TH1 *h_mbb_1lep; //!
  TH1 *h_amt2_1lep; //!
  TH1 *h_amt2_alt_1lep; //!
  TH1 *h_mlb1_1lep; //!
  TH1 *h_mlb2_1lep; //!
  TH1 *h_hT_1lep; //!
  TH1 *h_hT_minus_bjets_1lep; //!
  TH1 *h_mjj_max_1lep; //!
  TH1 *h_mjj_min_1lep; //!
  TH1 *h_meff_1lep; //!
  TH1 *h_meff_minus_bjets_1lep; //!
  TH1 *h_mT_lepMET_1lep; //!
  TH1 *h_dphi_lep_ptmiss_1lep; //!
  TH1 *h_pTlep_MET_1lep; //!
  TH1 *h_pTlep_MET2_1lep; //!
  TH1 *h_METproj_1lep; //!
  TH1 *h_dR_b1b2_1lep; //!
  TH1 *h_m_lvb_max_1lep; //!
  TH1 *h_m_lvb_min_1lep; //!

  TH1 *h_num_jets_MET_bjets; //!
  TH1 *h_num_bjets_MET_bjets; //!
  TH1 *h_num_non_bjets_MET_bjets; //!
  TH1 *h_lepton_pt_MET_bjets; //!
  TH1 *h_num_leptons_MET_bjets; //!
  TH1 *h_MET_MET_bjets; //!
  TH1 *h_bjet1_pt_MET_bjets; //!
  TH1 *h_bjet2_pt_MET_bjets; //!
  TH1 *h_non_bjet1_pt_MET_bjets; //!
  TH1 *h_non_bjet2_pt_MET_bjets; //!
  TH1 *h_jj_inv_mass_MET_bjets; //!
  TH1 *h_bjet_ratio_MET_bjets; //!
  TH1 *h_dphi_bjet_lepton_max_MET_bjets; //!
  TH1 *h_dphi_bjet_lepton_min_MET_bjets; //!
  TH1 *h_dphi_bjet_ptmiss_max_MET_bjets; //!
  TH1 *h_dphi_bjet_ptmiss_min_MET_bjets; //!
  TH1 *h_dphi_b1_b2_MET_bjets; //!
  TH1 *h_mbb_MET_bjets; //!
  TH1 *h_amt2_MET_bjets; //!
  TH1 *h_amt2_alt_MET_bjets; //!
  TH1 *h_mlb1_MET_bjets; //!
  TH1 *h_mlb2_MET_bjets; //!
  TH1 *h_hT_MET_bjets; //!
  TH1 *h_hT_minus_bjets_MET_bjets; //!
  TH1 *h_mjj_max_MET_bjets; //!
  TH1 *h_mjj_min_MET_bjets; //!
  TH1 *h_meff_MET_bjets; //!
  TH1 *h_meff_minus_bjets_MET_bjets; //!
  TH1 *h_mT_lepMET_MET_bjets; //!
  TH1 *h_dphi_lep_ptmiss_MET_bjets; //!
  TH1 *h_pTlep_MET_MET_bjets; //!
  TH1 *h_pTlep_MET2_MET_bjets; //!
  TH1 *h_METproj_MET_bjets; //!
  TH1 *h_dR_b1b2_MET_bjets; //!
  TH1 *h_m_lvb_max_MET_bjets; //!
  TH1 *h_m_lvb_min_MET_bjets; //!

  TH1 *h_num_jets_mbb; //!
  TH1 *h_num_bjets_mbb; //!
  TH1 *h_num_non_bjets_mbb; //!
  TH1 *h_lepton_pt_mbb; //!
  TH1 *h_num_leptons_mbb; //!
  TH1 *h_MET_mbb; //!
  TH1 *h_bjet1_pt_mbb; //!
  TH1 *h_bjet2_pt_mbb; //!
  TH1 *h_non_bjet1_pt_mbb; //!
  TH1 *h_non_bjet2_pt_mbb; //!
  TH1 *h_jj_inv_mass_mbb; //!
  TH1 *h_bjet_ratio_mbb; //!
  TH1 *h_dphi_bjet_lepton_max_mbb; //!
  TH1 *h_dphi_bjet_lepton_min_mbb; //!
  TH1 *h_dphi_bjet_ptmiss_max_mbb; //!
  TH1 *h_dphi_bjet_ptmiss_min_mbb; //!
  TH1 *h_dphi_b1_b2_mbb; //!
  TH1 *h_mbb_mbb; //!
  TH1 *h_amt2_mbb; //!
  TH1 *h_amt2_alt_mbb; //!
  TH1 *h_mlb1_mbb; //!
  TH1 *h_mlb2_mbb; //!
  TH1 *h_hT_mbb; //!
  TH1 *h_hT_minus_bjets_mbb; //!
  TH1 *h_mjj_max_mbb; //!
  TH1 *h_mjj_min_mbb; //!
  TH1 *h_meff_mbb; //!
  TH1 *h_meff_minus_bjets_mbb; //!
  TH1 *h_mT_lepMET_mbb; //!
  TH1 *h_dphi_lep_ptmiss_mbb; //!
  TH1 *h_pTlep_MET_mbb; //!
  TH1 *h_pTlep_MET2_mbb; //!
  TH1 *h_METproj_mbb; //!
  TH1 *h_dR_b1b2_mbb; //!
  TH1 *h_m_lvb_max_mbb; //!
  TH1 *h_m_lvb_min_mbb; //!

  TH1 *h_num_jets_preselection; //!
  TH1 *h_num_bjets_preselection; //!
  TH1 *h_num_non_bjets_preselection; //!
  TH1 *h_lepton_pt_preselection_unscaled; //!
  TH1 *h_lepton_pt_preselection; //!
  TH1 *h_num_leptons_preselection; //!
  TH1 *h_MET_preselection_unscaled; //!
  TH1 *h_MET_preselection; //!
  TH1 *h_bjet1_pt_preselection_unscaled; //!
  TH1 *h_bjet1_pt_preselection; //!
  TH1 *h_bjet2_pt_preselection_unscaled; //!
  TH1 *h_bjet2_pt_preselection; //!
  TH1 *h_non_bjet1_pt_preselection_unscaled; //!
  TH1 *h_non_bjet1_pt_preselection; //!
  TH1 *h_non_bjet2_pt_preselection_unscaled; //!
  TH1 *h_non_bjet2_pt_preselection; //!
  TH1 *h_jj_inv_mass_preselection_unscaled; //!
  TH1 *h_jj_inv_mass_preselection; //!
  TH1 *h_bjet_ratio_preselection_unscaled; //!
  TH1 *h_bjet_ratio_preselection; //!
  
  TH1 *h_dphi_bjet_lepton_max_preselection_unscaled; //!
  TH1 *h_dphi_bjet_lepton_max_preselection; //!
  TH1 *h_dphi_bjet_lepton_min_preselection_unscaled; //!
  TH1 *h_dphi_bjet_lepton_min_preselection; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection_unscaled; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection_unscaled; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection; //!
  TH1 *h_dphi_b1_b2_preselection_unscaled; //!
  TH1 *h_dphi_b1_b2_preselection; //!
  TH1 *h_mbb_preselection_unscaled; //!
  TH1 *h_mbb_preselection; //!
  TH1 *h_amt2_preselection_unscaled; //!
  TH1 *h_amt2_preselection; //!
  TH1 *h_amt2_alt_preselection_unscaled; //!
  TH1 *h_amt2_alt_preselection; //!
  TH1 *h_mlb1_preselection_unscaled; //!
  TH1 *h_mlb1_preselection; //!
  TH1 *h_mlb2_preselection_unscaled; //!
  TH1 *h_mlb2_preselection; //!
  TH1 *h_hT_preselection_unscaled; //!
  TH1 *h_hT_preselection; //!
  TH1 *h_hT_minus_bjets_preselection_unscaled; //!
  TH1 *h_hT_minus_bjets_preselection; //!
  TH1 *h_mjj_max_preselection_unscaled; //!
  TH1 *h_mjj_max_preselection; //!
  TH1 *h_mjj_min_preselection_unscaled; //!
  TH1 *h_mjj_min_preselection; //!
  TH1 *h_meff_preselection; //!
  TH1 *h_meff_minus_bjets_preselection; //!
  TH1 *h_mT_lepMET_preselection; //!
  TH1 *h_dphi_lep_ptmiss_preselection; //!

  TH1 *h_num_jets_preselection_leplep; //!
  TH1 *h_num_bjets_preselection_leplep; //!
  TH1 *h_num_non_bjets_preselection_leplep; //!
  TH1 *h_lepton_pt_preselection_leplep; //!
  TH1 *h_MET_preselection_leplep; //!
  TH1 *h_bjet1_pt_preselection_leplep; //!
  TH1 *h_bjet2_pt_preselection_leplep; //!
  TH1 *h_non_bjet1_pt_preselection_leplep; //!
  TH1 *h_non_bjet2_pt_preselection_leplep; //!
  TH1 *h_dphi_bjet_lepton_max_preselection_leplep; //!
  TH1 *h_dphi_bjet_lepton_min_preselection_leplep; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection_leplep; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection_leplep; //!
  TH1 *h_dphi_b1_b2_preselection_leplep; //!
  TH1 *h_mbb_preselection_leplep; //!
  TH1 *h_amt2_preselection_leplep; //!
  TH1 *h_amt2_alt_preselection_leplep; //!
  TH1 *h_mlb1_preselection_leplep; //!
  TH1 *h_mlb2_preselection_leplep; //!
  TH1 *h_hT_preselection_leplep; //!
  TH1 *h_hT_minus_bjets_preselection_leplep; //!
  TH1 *h_mjj_max_preselection_leplep; //!
  TH1 *h_mjj_min_preselection_leplep; //!
  TH1 *h_meff_preselection_leplep; //!
  TH1 *h_meff_minus_bjets_preselection_leplep; //!
  TH1 *h_mT_lepMET_preselection_leplep; //!
  TH1 *h_dphi_lep_ptmiss_preselection_leplep; //!
  TH1 *h_bjet_ratio_preselection_leplep; //!

  TH1 *h_num_jets_preselection_leptau; //!
  TH1 *h_num_bjets_preselection_leptau; //!
  TH1 *h_num_non_bjets_preselection_leptau; //!
  TH1 *h_lepton_pt_preselection_leptau; //!
  TH1 *h_MET_preselection_leptau; //!
  TH1 *h_bjet1_pt_preselection_leptau; //!
  TH1 *h_bjet2_pt_preselection_leptau; //!
  TH1 *h_non_bjet1_pt_preselection_leptau; //!
  TH1 *h_non_bjet2_pt_preselection_leptau; //!
  TH1 *h_dphi_bjet_lepton_max_preselection_leptau; //!
  TH1 *h_dphi_bjet_lepton_min_preselection_leptau; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection_leptau; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection_leptau; //!
  TH1 *h_dphi_b1_b2_preselection_leptau; //!
  TH1 *h_mbb_preselection_leptau; //!
  TH1 *h_amt2_preselection_leptau; //!
  TH1 *h_amt2_alt_preselection_leptau; //!
  TH1 *h_mlb1_preselection_leptau; //!
  TH1 *h_mlb2_preselection_leptau; //!
  TH1 *h_hT_preselection_leptau; //!
  TH1 *h_hT_minus_bjets_preselection_leptau; //!
  TH1 *h_mjj_max_preselection_leptau; //!
  TH1 *h_mjj_min_preselection_leptau; //!
  TH1 *h_meff_preselection_leptau; //!
  TH1 *h_meff_minus_bjets_preselection_leptau; //!
  TH1 *h_mT_lepMET_preselection_leptau; //!
  TH1 *h_dphi_lep_ptmiss_preselection_leptau; //!
  TH1 *h_bjet_ratio_preselection_leptau; //!

  TH1 *h_num_jets_preselection_lephad; //!
  TH1 *h_num_bjets_preselection_lephad; //!
  TH1 *h_num_non_bjets_preselection_lephad; //!
  TH1 *h_lepton_pt_preselection_lephad; //!
  TH1 *h_MET_preselection_lephad; //!
  TH1 *h_bjet1_pt_preselection_lephad; //!
  TH1 *h_bjet2_pt_preselection_lephad; //!
  TH1 *h_non_bjet1_pt_preselection_lephad; //!
  TH1 *h_non_bjet2_pt_preselection_lephad; //!
  TH1 *h_dphi_bjet_lepton_max_preselection_lephad; //!
  TH1 *h_dphi_bjet_lepton_min_preselection_lephad; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection_lephad; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection_lephad; //!
  TH1 *h_dphi_b1_b2_preselection_lephad; //!
  TH1 *h_mbb_preselection_lephad; //!
  TH1 *h_amt2_preselection_lephad; //!
  TH1 *h_amt2_alt_preselection_lephad; //!
  TH1 *h_mlb1_preselection_lephad; //!
  TH1 *h_mlb2_preselection_lephad; //!
  TH1 *h_hT_preselection_lephad; //!
  TH1 *h_hT_minus_bjets_preselection_lephad; //!
  TH1 *h_mjj_max_preselection_lephad; //!
  TH1 *h_mjj_min_preselection_lephad; //!
  TH1 *h_meff_preselection_lephad; //!
  TH1 *h_meff_minus_bjets_preselection_lephad; //!
  TH1 *h_mT_lepMET_preselection_lephad; //!
  TH1 *h_dphi_lep_ptmiss_preselection_lephad; //!
  TH1 *h_bjet_ratio_preselection_lephad; //!

  TH1 *h_num_jets_preselection_others; //!
  TH1 *h_num_bjets_preselection_others; //!
  TH1 *h_num_non_bjets_preselection_others; //!
  TH1 *h_lepton_pt_preselection_others; //!
  TH1 *h_MET_preselection_others; //!
  TH1 *h_bjet1_pt_preselection_others; //!
  TH1 *h_bjet2_pt_preselection_others; //!
  TH1 *h_non_bjet1_pt_preselection_others; //!
  TH1 *h_non_bjet2_pt_preselection_others; //!
  TH1 *h_dphi_bjet_lepton_max_preselection_others; //!
  TH1 *h_dphi_bjet_lepton_min_preselection_others; //!
  TH1 *h_dphi_bjet_ptmiss_max_preselection_others; //!
  TH1 *h_dphi_bjet_ptmiss_min_preselection_others; //!
  TH1 *h_dphi_b1_b2_preselection_others; //!
  TH1 *h_mbb_preselection_others; //!
  TH1 *h_amt2_preselection_others; //!
  TH1 *h_amt2_alt_preselection_others; //!
  TH1 *h_mlb1_preselection_others; //!
  TH1 *h_mlb2_preselection_others; //!
  TH1 *h_hT_preselection_others; //!
  TH1 *h_hT_minus_bjets_preselection_others; //!
  TH1 *h_mjj_max_preselection_others; //!
  TH1 *h_mjj_min_preselection_others; //!
  TH1 *h_meff_preselection_others; //!
  TH1 *h_meff_minus_bjets_preselection_others; //!
  TH1 *h_mT_lepMET_preselection_others; //!
  TH1 *h_dphi_lep_ptmiss_preselection_others; //!

  TH1 *h_pTlep_MET_preselection; //!
  TH1 *h_pTlep_MET2_preselection; //!
  TH1 *h_pTlep_MET_preselection_leplep; //!
  TH1 *h_pTlep_MET2_preselection_leplep; //!
  TH1 *h_pTlep_MET_preselection_leptau; //!
  TH1 *h_pTlep_MET2_preselection_leptau; //!
  TH1 *h_pTlep_MET_preselection_lephad; //!
  TH1 *h_pTlep_MET2_preselection_lephad; //!
  TH1 *h_pTlep_MET_preselection_others; //!
  TH1 *h_pTlep_MET2_preselection_others; //!

  TH1 *h_entries; //!
  TH1 *h_entries_1lep; //!
  TH1 *h_entries_1lep_or_more; //!
  TH1 *h_entries_200MET; //!
  TH1 *h_entries_2bjets; //!
  TH1 *h_entries_bjetspt; //!
  TH1 *h_entries_amt2; //!
  TH1 *h_entries_closeMETb; //!
  TH1 *h_entries_mbb; //!
  TH1 *h_entries_analysis; //!
  TH1 *h_entries_pTlepMET; //!
  TH1 *h_entries_pTlep; //!

  TH1 *h_num_leptons_total; //!
  TH1 *h_theoretical_leptons; //!

  TH1 *h_jj_inv_mass; //!
  TH1 *h_W_mass; //!
  TH1 *h_W_children; //!

  TH1 *h_lepton_from_top_pt; //!
  TH1 *h_lepton_from_others_pt; //!
  TH1 *h_top_W_mass; //!
  TH1 *h_other_W_mass; //!

  TH1 *h_chargino_children; //!
  TH1 *h_num_chargino_children; //!

  int difference = 0;
  int zero_lep_events = 0;
  int one_lep_events = 0;
  int two_lep_events = 0;

  int zero_one_bjet_events = 0;
  int miss_b_pt = 0;
  int miss_b_eta = 0;
  int miss_b_both = 0;
  int miss_b_error = 0;

  int pass1lep_high = 0;
  int pass1lep_low = 0;

  float weight = 0;

  float pass1lep_cut = 0;
  float pass1lep_or_more_cut = 0;
  float pass200MET_cut = 0;
  float pass2bjet_cut = 0;
  float passbjetpt_cut = 0;
  float passamt2_cut = 0;
  float passcloseMETb_cut = 0;
  float passmbb_cut = 0;
  float passAnalysis_cut = 0;
  float passpTlepMET_cut = 0;
  float passpTlep_cut = 0;

  int onelep_fromtop = 0;
  int onelep_fromothers = 0;

  TLorentzVector *jj; //!
  TLorentzVector *lepton; //!
  TLorentzVector *b1; //!
  TLorentzVector *b2; //!
  TLorentzVector *bb; //!
  TLorentzVector *jet1; //!
  TLorentzVector *jet2; //!
  TLorentzVector *lb1; //!
  TLorentzVector *lb2; //!
  TLorentzVector *MET_IntMu; //!
  TLorentzVector *lep_tmp; //!
  TLorentzVector *jet_tmp; //!

  TH1 *h_dR_quarks; //!
  TH1 *h_dR_leptons; //!
  TH1 *h_deltaPT_quarks; //!
  TH1 *h_deltaPT_leptons; //!
  TH1 *h_dR_child_jet; //!
  TH1 *h_deltaPT_child_jet; //!

  TH1 *h_num_truthb; //!
  TH1 *h_dR_btruth_bjet; //!
  TH1 *h_truthb_parent; //!
  TH1 *h_dR_bb; //!

  TH1 *h_METproj_preselection; //!
  TH1 *h_dR_b1b2_preselection; //!
  TH1 *h_m_lvb_max_preselection; //!
  TH1 *h_m_lvb_min_preselection; //!
  TH1 *h_METproj_preselection_leplep; //!
  TH1 *h_dR_b1b2_preselection_leplep; //!
  TH1 *h_m_lvb_max_preselection_leplep; //!
  TH1 *h_m_lvb_min_preselection_leplep; //!
  TH1 *h_METproj_preselection_leptau; //!
  TH1 *h_dR_b1b2_preselection_leptau; //!
  TH1 *h_m_lvb_max_preselection_leptau; //!
  TH1 *h_m_lvb_min_preselection_leptau; //!
  TH1 *h_METproj_preselection_lephad; //!
  TH1 *h_dR_b1b2_preselection_lephad; //!
  TH1 *h_m_lvb_max_preselection_lephad; //!
  TH1 *h_m_lvb_min_preselection_lephad; //!

  TH1 *h_pTlep_noLepCut; //!
  TH1 *h_MET_noMETCut; //!
  TH1 *h_bjet1pt_nobJet1Cut; //!
  TH1 *h_bjet2pt_nobJet2Cut; //!
  TH1 *h_amt2_noamt2Cut; //!
  TH1 *h_dphibMET_noCloseMETbCut; //!
  TH1 *h_mbb_nombbCut; //!

  TH1 *h_el_pt; //!
  TH1 *h_mu_pt; //!
  TH1 *h_tau_pt; //!
  TH1 *h_nuel_pt; //!
  TH1 *h_numu_pt; //!
  TH1 *h_nutau_pt; //!
  TH1 *h_up_pt; //!
  TH1 *h_down_pt; //!
  TH1 *h_charm_pt; //!
  TH1 *h_strange_pt; //!
  TH1 *h_bottom_pt; //!

  TLorentzVector *child1; //!
  TLorentzVector *child2; //!
  TLorentzVector *child3; //!
  TLorentzVector *child4; //!
  TLorentzVector *out_tmp; //!
  TLorentzVector *had_child1; //!
  TLorentzVector *had_child2; //!
  TLorentzVector *had_child3; //!
  TLorentzVector *had_child4; //!

  TLorentzVector *mlb_tmp; //!
  TLorentzVector *mlvb_tmp; //!

  std::vector< TLorentzVector > leptons;
  std::vector< int > lepton_ids;
  std::vector< TLorentzVector > bjets;
  std::vector< TLorentzVector > nonbjets;
  std::vector< TLorentzVector > truthb;
  std::vector< int > b_parents;
  std::vector< double > bjet_btruth_dR;
  
  xAOD::TEvent *m_event;  //!
  int m_eventCounter; //!

  // this is a standard constructor
  MyxAODAnalysis ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(MyxAODAnalysis, 1);
};

#endif
