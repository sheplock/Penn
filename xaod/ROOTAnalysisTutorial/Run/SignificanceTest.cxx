#include "TCanvas.h"
#include "TFile.h"
#include "TROOT.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TLorentzVector.h>

using namespace std;

void SignificanceTest() {

  TFile* f[28]; 
  f[0] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/ttbar/leplep_file.root");
  f[1] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletop/leplep_file.root");
  f[2] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletbar/leplep_file.root");
  f[3] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt0_70/hist-mc15_13TeV.361302.Sherpa_CT10_Wenu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[4] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt70_140/hist-mc15_13TeV.361305.Sherpa_CT10_Wenu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[5] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt140_280/hist-mc15_13TeV.361308.Sherpa_CT10_Wenu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[6] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt280_500/hist-mc15_13TeV.361311.Sherpa_CT10_Wenu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[7] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt500_700/hist-mc15_13TeV.361314.Sherpa_CT10_Wenu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[8] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt700_1000/hist-mc15_13TeV.361317.Sherpa_CT10_Wenu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[9] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt1000_2000/hist-mc15_13TeV.361320.Sherpa_CT10_Wenu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[10] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wenu_Pt2000/hist-mc15_13TeV.361323.Sherpa_CT10_Wenu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[11] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt0_70/hist-mc15_13TeV.361326.Sherpa_CT10_Wmunu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[12] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt70_140/hist-mc15_13TeV.361329.Sherpa_CT10_Wmunu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[13] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt140_280/hist-mc15_13TeV.361332.Sherpa_CT10_Wmunu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3651_p2375.root");
  f[14] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt280_500/hist-mc15_13TeV.361335.Sherpa_CT10_Wmunu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[15] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt500_700/hist-mc15_13TeV.361338.Sherpa_CT10_Wmunu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[16] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt700_1000/hist-mc15_13TeV.361341.Sherpa_CT10_Wmunu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[17] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt1000_2000/hist-mc15_13TeV.361344.Sherpa_CT10_Wmunu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[18] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wmunu_Pt2000/hist-mc15_13TeV.361347.Sherpa_CT10_Wmunu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[19] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt0_70/hist-mc15_13TeV.361350.Sherpa_CT10_Wtaunu_Pt0_70_BFilter.merge.DAOD_TRUTH1.e3733_p2375.root");
  f[20] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt70_140/hist-mc15_13TeV.361353.Sherpa_CT10_Wtaunu_Pt70_140_BFilter.merge.DAOD_TRUTH1.e3733_p2375.root");
  f[21] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt140_280/hist-mc15_13TeV.361356.Sherpa_CT10_Wtaunu_Pt140_280_BFilter.merge.DAOD_TRUTH1.e3733_p2375.root");
  f[22] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt280_500/hist-mc15_13TeV.361359.Sherpa_CT10_Wtaunu_Pt280_500_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[23] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt500_700/hist-mc15_13TeV.361362.Sherpa_CT10_Wtaunu_Pt500_700_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[24] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt700_1000/hist-mc15_13TeV.361365.Sherpa_CT10_Wtaunu_Pt700_1000_BFilter.merge.DAOD_TRUTH1.e3973_p2375.root");
  f[25] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt1000_2000/hist-mc15_13TeV.361368.Sherpa_CT10_Wtaunu_Pt1000_2000_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[26] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/Wtaunu_Pt2000/hist-mc15_13TeV.361371.Sherpa_CT10_Wtaunu_Pt2000_E_CMS_BFilter.merge.DAOD_TRUTH1.e3741_p2375.root");
  f[27] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/signal_650_170_150/hist-DAOD_TRUTH1.signal650.root");
    
  //histos
  TString HISTO[100];   

  int myh=0;
  
  // Lepton pt
  HISTO[myh]="h_lepton_pt_preselection"; 
  myh++;

  // leading non b-jet pt
  HISTO[myh]="h_non_bjet1_pt_preselection"; 
  myh++;

  // max lb mass
  HISTO[myh]="h_mlb1_preselection";
  myh++;

  // min lb mass
  HISTO[myh]="h_mlb2_preselection";
  myh++;

  // pTlep / MET
  HISTO[myh]="h_pTlep_MET_preselection";
  myh++;

  // pTlep / MET along lep
  HISTO[myh]="h_pTlep_MET2_preselection";
  myh++;

  // m_lvb max
  HISTO[myh]="h_m_lvb_max_preselection";
  myh++;

  // m_lvb min
  HISTO[myh]="h_m_lvb_min_preselection";
  myh++;

  int cut_low_bin = -1;
  int cut_high_bin = -1;
  double sig_integral = 0.0;
  double bkg_integral = 0.0;
  double significance = 0.0;
  double num_sig = 0.0;
  double num_bkg = 0.0;

  // loop over histograms
  for( int ih=0; ih<myh; ih++ ){

    significance = 0.0;
    
    TString histo=HISTO[ih];
    
    TObject* ob_sig = f[27]->Get(histo);
    TH1F *sig_hist = (TH1F*)ob_sig;
    int nBins = sig_hist->GetNbinsX();

    sig_hist->Scale( 0.18365 );

    TObject* ob_ttbar = f[0]->Get(histo);
    TH1F *ttbar_hist = (TH1F*)ob_ttbar;
    TObject* ob_Wt = f[1]->Get(histo);
    TH1F *Wt_hist = (TH1F*)ob_Wt;
    TObject* ob_Wtbar = f[2]->Get(histo);
    TH1F *Wtbar_hist = (TH1F*)ob_Wtbar;
    TObject* ob_W1 = f[3]->Get(histo);
    TH1F *W1_hist = (TH1F*)ob_W1;
    TObject* ob_W2 = f[4]->Get(histo);
    TH1F *W2_hist = (TH1F*)ob_W2;
    TObject* ob_W3 = f[5]->Get(histo);
    TH1F *W3_hist = (TH1F*)ob_W3;
    TObject* ob_W4 = f[6]->Get(histo);
    TH1F *W4_hist = (TH1F*)ob_W4;
    TObject* ob_W5 = f[7]->Get(histo);
    TH1F *W5_hist = (TH1F*)ob_W5;
    TObject* ob_W6 = f[8]->Get(histo);
    TH1F *W6_hist = (TH1F*)ob_W6;
    TObject* ob_W7 = f[9]->Get(histo);
    TH1F *W7_hist = (TH1F*)ob_W7;
    TObject* ob_W8 = f[10]->Get(histo);
    TH1F *W8_hist = (TH1F*)ob_W8;
    TObject* ob_W9 = f[11]->Get(histo);
    TH1F *W9_hist = (TH1F*)ob_W9;
    TObject* ob_W10 = f[12]->Get(histo);
    TH1F *W10_hist = (TH1F*)ob_W10;
    TObject* ob_W11 = f[13]->Get(histo);
    TH1F *W11_hist = (TH1F*)ob_W11;
    TObject* ob_W12 = f[14]->Get(histo);
    TH1F *W12_hist = (TH1F*)ob_W12;
    TObject* ob_W13 = f[15]->Get(histo);
    TH1F *W13_hist = (TH1F*)ob_W13;
    TObject* ob_W14 = f[16]->Get(histo);
    TH1F *W14_hist = (TH1F*)ob_W14;
    TObject* ob_W15 = f[17]->Get(histo);
    TH1F *W15_hist = (TH1F*)ob_W15;
    TObject* ob_W16 = f[18]->Get(histo);
    TH1F *W16_hist = (TH1F*)ob_W16;
    TObject* ob_W17 = f[19]->Get(histo);
    TH1F *W17_hist = (TH1F*)ob_W17;
    TObject* ob_W18 = f[20]->Get(histo);
    TH1F *W18_hist = (TH1F*)ob_W18;
    TObject* ob_W19 = f[21]->Get(histo);
    TH1F *W19_hist = (TH1F*)ob_W19;
    TObject* ob_W20 = f[22]->Get(histo);
    TH1F *W20_hist = (TH1F*)ob_W20;
    TObject* ob_W21 = f[23]->Get(histo);
    TH1F *W21_hist = (TH1F*)ob_W21;
    TObject* ob_W22 = f[24]->Get(histo);
    TH1F *W22_hist = (TH1F*)ob_W22;
    TObject* ob_W23 = f[25]->Get(histo);
    TH1F *W23_hist = (TH1F*)ob_W23;
    TObject* ob_W24 = f[26]->Get(histo);
    TH1F *W24_hist = (TH1F*)ob_W24;

    ttbar_hist->Scale( 0.048206 );
    Wt_hist->Scale( 0.023023 );
    Wtbar_hist->Scale( 0.022963 );
    W1_hist->Scale( 4.3354 );
    W2_hist->Scale( 0.34942 );
    W3_hist->Scale( 0.90138 );
    W4_hist->Scale( 0.19411 );
    W5_hist->Scale( 0.058329 );
    W6_hist->Scale( 0.040825 );
    W7_hist->Scale( 0.045325 );
    W8_hist->Scale( 0.00022171 );
    W9_hist->Scale( 5.7793 );
    W10_hist->Scale( 1.9374 );
    W11_hist->Scale( 0.96092 );
    W12_hist->Scale( 0.22574 );
    W13_hist->Scale( 0.034436 );
    W14_hist->Scale( 0.024515 );
    W15_hist->Scale( 0.077984 );
    W16_hist->Scale( 0.000019007 );
    W17_hist->Scale( 5.4372 );
    W18_hist->Scale( 1.7817 );
    W19_hist->Scale( 0.99691 );
    W20_hist->Scale( 0.30656 );
    W21_hist->Scale( 0.035354 );
    W22_hist->Scale( 0.019408 );
    W23_hist->Scale( 0.046324 );
    W24_hist->Scale( 0.0020367 );
    
    for( int high_bin=1; high_bin<=nBins+1; high_bin++ ) {
      
      for( int low_bin=0; low_bin < high_bin; low_bin++ ) {

	sig_integral=0.0;
	bkg_integral=0.0;

	sig_integral = sig_hist->Integral(low_bin, high_bin);
    
	bkg_integral += ttbar_hist->Integral(low_bin, high_bin);
	bkg_integral += Wt_hist->Integral(low_bin, high_bin);
	bkg_integral += Wtbar_hist->Integral(low_bin, high_bin);
	bkg_integral += W1_hist->Integral(low_bin, high_bin);
	bkg_integral += W2_hist->Integral(low_bin, high_bin);
	bkg_integral += W3_hist->Integral(low_bin, high_bin);
	bkg_integral += W4_hist->Integral(low_bin, high_bin);
	bkg_integral += W5_hist->Integral(low_bin, high_bin);
	bkg_integral += W6_hist->Integral(low_bin, high_bin);
	bkg_integral += W7_hist->Integral(low_bin, high_bin);
	bkg_integral += W8_hist->Integral(low_bin, high_bin);
	bkg_integral += W9_hist->Integral(low_bin, high_bin);
	bkg_integral += W10_hist->Integral(low_bin, high_bin);
	bkg_integral += W11_hist->Integral(low_bin, high_bin);
	bkg_integral += W12_hist->Integral(low_bin, high_bin);
	bkg_integral += W13_hist->Integral(low_bin, high_bin);
	bkg_integral += W14_hist->Integral(low_bin, high_bin);
	bkg_integral += W15_hist->Integral(low_bin, high_bin);
	bkg_integral += W16_hist->Integral(low_bin, high_bin);
	bkg_integral += W17_hist->Integral(low_bin, high_bin);
	bkg_integral += W18_hist->Integral(low_bin, high_bin);
	bkg_integral += W19_hist->Integral(low_bin, high_bin);
	bkg_integral += W20_hist->Integral(low_bin, high_bin);
	bkg_integral += W21_hist->Integral(low_bin, high_bin);
	bkg_integral += W22_hist->Integral(low_bin, high_bin);
	bkg_integral += W23_hist->Integral(low_bin, high_bin);
	bkg_integral += W24_hist->Integral(low_bin, high_bin);

	if (bkg_integral > 0) {
	  if (sig_integral / sqrt(bkg_integral) > significance && (high_bin == nBins+1 || low_bin == 0)) {
	    significance = sig_integral / sqrt(bkg_integral);
	    cut_low_bin = low_bin;
	    cut_high_bin = high_bin;
	    num_sig = sig_integral;
	    num_bkg = bkg_integral;
	  }
	
	}

      }

    }
    
    cout << "HISTO: " << histo << endl;
    cout << "low bin = " << cut_low_bin << " high bin= " << cut_high_bin << endl;
    cout << "S/sqrt(B) = " << significance << " number signal events = " << num_sig << " number of background events = " << num_bkg << endl;
    cout << " " << endl;

  }

}

