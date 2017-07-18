#include "TCanvas.h"
#include "TFile.h"
#include "TROOT.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TLorentzVector.h>

using namespace std;

void StackPlots() {


  TFile* f[28]; 
  //f[0] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/ttbar/leplep_file.root");
  //f[1] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/ttbar/leptau_file.root");
  //f[2] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/ttbar/lephad_file.root");
  //f[3] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletop/leplep_file.root");
  //f[4] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletbar/leplep_file.root");
  //f[5] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletop/leptau_file.root");
  //f[6] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletbar/leptau_file.root");
  //f[7] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletop/lephad_file.root");
  //f[8] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletbar/lephad_file.root");
  f[0] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/ttbar/hist-mc15_13TeV.407012.PowhegPythiaEvtGen_P2012CT10_ttbarMET200_hdamp172p5_nonAH.merge.DAOD_TRUTH1.e4023_p2440.root");
  f[1] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletop/hist-mc15_13TeV.407019.PowhegPythiaEvtGen_P2012CT10_Wt_inclusive_top_MET200.merge.DAOD_TRUTH1.e4024_p2613.root");
  f[2] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/singletbar/hist-mc15_13TeV.407021.PowhegPythiaEvtGen_P2012CT10_Wt_inclusive_tbar_MET200.merge.DAOD_TRUTH1.e4024_p2613.root");
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
  f[27] = new TFile("/home/shepj/xaod/ROOTAnalysisTutorial/Run/signal_650_170_150/hist-DAOD_TRUTH1.signal_650_170_150.root");
  
  Color_t ttbar_leplep_col=kBlue+3;
  Color_t ttbar_leptau_col=kBlue;
  Color_t ttbar_lephad_col=kBlue-7;
  Color_t singletop_leplep_col=kRed+3;
  Color_t singletop_leptau_col=kRed;
  Color_t singletop_lephad_col=kRed-7;
  Color_t singletbar_leplep_col=kRed+3;
  Color_t singletbar_leptau_col=kRed;
  Color_t singletbar_lephad_col=kRed-7;
  Color_t Wjets_col_e = kGreen+3;
  Color_t Wjets_col_mu = kGreen;
  Color_t Wjets_col_tau = kGreen-7;
  Color_t signal_col=kGray;

  Color_t ttbar_col = kBlue;
  Color_t singletop_col = kRed;
  Color_t Wjets_col = kGreen;

  // set the colours and line attributes here
  Color_t mylinecol[28]    = { //kBlue+3, 
			       kBlue, 
			       //kBlue-7, 
			       //kRed+3, 
			       //kRed+3, 
			       kRed, 
			       kRed, 
			       //kRed-7, 
			       //kRed-7, 
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kGreen,
			       kBlack };
  Color_t myfillcol[28]    = { //ttbar_leplep_col, 
			       ttbar_col, 
			       //ttbar_lephad_col, 
			       //singletop_leplep_col, 
			       //singletbar_leplep_col, 
			       singletop_col, 
			       singletop_col, 
			       //singletop_lephad_col, 
			       //singletbar_lephad_col, 
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       Wjets_col,
			       signal_col };
  Color_t myfillsty[28]    = { //1001,             
			       1001,             
			       //1001,             
			       //1001,               
			       //1001,              
			       1001,               
			       1001,              
			       //1001,              
			       //1001,               
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       1001,
			       0 };
  Style_t mylinestyle[28]  = { //1,
			       1,
			       //1,
			       //1,
			       //1,
			       1,
			       1,
			       //1,
			       //1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1,
			       1 };
  Width_t mylinewidth[28]  = { //2,
			       2,
			       //2,
			       //2,
			       //2,
			       2,
			       2,
			       //2,
			       //2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       2,
			       4 };
  Double_t mymarkersize[28]  = { //0,
				 0,
				 //0,
				 //0,
				 //0,
				 0,
				 0,
				 //0,
				 //0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0,
				 0 };

  TString sample[28] = { "ttbar", "single top", "wrong", "W+jets", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "wrong", "signal" };
 
  //this is used for the legend formatting
  TH1F* MyLine[28];
  for( int i=0; i<28; i++){
    TIter nextkey1( f[i]->GetListOfKeys());   TKey *key1;
    while( ( key1 = (TKey*)nextkey1() )   ){
      f[i]->cd();
      TObject *obj = key1->ReadObj();
      if (obj->IsA()->InheritsFrom("TH1")){
	TH1 *h1 = (TH1*)obj;
	h1->SetLineColor(mylinecol[i]);  h1->SetMarkerColor(mylinecol[i]);
	h1->SetLineStyle(mylinestyle[i]);  h1->SetLineWidth(mylinewidth[i]);
	h1->SetStats(kFALSE); 
      }
    }
    // this bit is useful for the legend
    MyLine[i]=new TH1F("MyLine_"+i,"",7,-0.5,6.5);  MyLine[i]->SetStats(kFALSE); 
    MyLine[i]->SetLineColor(mylinecol[i]);  MyLine[i]->SetMarkerColor(mylinecol[i]);
    MyLine[i]->SetLineStyle(mylinestyle[i]);  MyLine[i]->SetLineWidth(mylinewidth[i]);
  }
  
  cout << "looped myline" << endl;

  
  //legend->AddEntry(MyLine[9],"signal","f");
  //legend->AddEntry(MyLine[0],"ttbar leplep","f");
  //legend->AddEntry(MyLine[1],"ttbar leptau","f");
  //legend->AddEntry(MyLine[2],"ttbar lephad","f");
  //legend->AddEntry(MyLine[3],"single top leplep","f");
  //legend->AddEntry(MyLine[5],"single top leptau","f");
  //legend->AddEntry(MyLine[7],"single top lephad","f");

  //change to the cut name you have
  TString CUT[1]={"noamt2Cut"};
    
  //histos
  TString HISTO[100];   
  double c1_ymin[28][100];
  double c1_ymax[28][100];   
  double c1_xmin[28][100];
  double c1_xmax[28][100];
  for( int ic=0; ic<28; ic++ ){ 
    for( int ih=0; ih<100; ih++ ){  
      c1_ymin[ic][ih]=0.01;  // needs to be 0.1 for y on log scale
    } 
  }

  cout << "Set plot parameters" << endl;
  int myh=0;

  HISTO[myh]="h_amt2"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=10; }
  c1_ymax[0][myh]=1000;                                                                          
  c1_ymax[1][myh]=1000;
  myh++;

  /*
  // Number of Jets
  HISTO[myh]="h_num_jets"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=10; }
  c1_ymax[0][myh]=1000;                                                                          
  c1_ymax[1][myh]=1000;
  myh++;

  // Number of b-jets
  HISTO[myh]="h_num_bjets"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=10; }   
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;      
  myh++;

  // Number of non b-jets
  HISTO[myh]="h_num_non_bjets"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=10; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;    
  myh++;
  
  // Lepton pt
  HISTO[myh]="h_lepton_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=100; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;      
  myh++;

  // MET
  HISTO[myh]="h_MET"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;     
  myh++;

  // leading b-jet pt
  HISTO[myh]="h_bjet1_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;     
  myh++;

  // subleading b-jet pt
  HISTO[myh]="h_bjet2_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;   
  myh++;

  // leading non b-jet pt
  HISTO[myh]="h_non_bjet1_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;   
  myh++;

  // subleading non b-jet pt
  HISTO[myh]="h_non_bjet2_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;   
  myh++;

  // di-jet invariant mass
  //HISTO[myh]="h_jj_inv_mass"; 
  //for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=200; }
  //c1_ymax[0][myh]=1;
  //c1_ymax[1][myh]=1;   
  //myh++;

  // b-jet pt ratio
  HISTO[myh]="h_bjet_ratio";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=200; }
  c1_ymax[0][myh]=1;
  c1_ymax[1][myh]=1;
  myh++;

  // deltaPhi(b, l) max
  HISTO[myh]="h_dphi_bjet_lepton_max";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaPhi(b, l) min
  HISTO[myh]="h_dphi_bjet_lepton_min";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaPhi(b, ptmiss) max
  HISTO[myh]="h_dphi_bjet_ptmiss_max";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaPhi(b, ptmiss) min
  HISTO[myh]="h_dphi_bjet_ptmiss_min";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaPhi(b1, b2)
  HISTO[myh]="h_dphi_b1_b2";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaPhi(lep, ptmiss)
  HISTO[myh]="h_dphi_lep_ptmiss";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // bb mass
  HISTO[myh]="h_mbb";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // aMT2
  HISTO[myh]="h_amt2";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // aMT2 alt
  HISTO[myh]="h_amt2_alt";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // lb1 mass
  HISTO[myh]="h_mlb1";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // lb2 mass
  HISTO[myh]="h_mlb2";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // mT
  HISTO[myh]="h_mT_lepMET";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // m_eff
  HISTO[myh]="h_meff";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // m_eff - lead/sublead b-jets
  HISTO[myh]="h_meff_minus_bjets";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // HT
  HISTO[myh]="h_hT";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // HT - lead/sublead b-jets
  HISTO[myh]="h_hT_minus_bjets";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // jj mass max
  HISTO[myh]="h_mjj_max";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // jj mass min
  HISTO[myh]="h_mjj_min";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // pTlep / MET
  HISTO[myh]="h_pTlep_MET";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // pTlep / MET along lep
  HISTO[myh]="h_pTlep_MET2";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // MET projection along lepton
  HISTO[myh]="h_METproj";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // deltaR(b1, b2)
  HISTO[myh]="h_dR_b1b2";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // m_lvb max
  HISTO[myh]="h_m_lvb_max";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // m_lvb min
  HISTO[myh]="h_m_lvb_min";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;
  */

  /*
  // MET
  HISTO[myh]="h_MET";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;

  // lepton pT
  HISTO[myh]="h_lepton_pt";
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;
  myh++;
  

  // leading b-jet pt
  HISTO[myh]="h_bjet1_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;     
  myh++;

  // subleading b-jet pt
  HISTO[myh]="h_bjet2_pt"; 
  for(int ic=0; ic<2; ic++){ c1_xmin[ic][myh]=0; c1_xmax[ic][myh]=1000; }
  c1_ymax[0][myh]=1000;
  c1_ymax[1][myh]=1000;   
  myh++;
  */

  int entries = 0;

  // loop over cuts
  for( int ic=0; ic<1; ic++ ){
    
    // loop over histograms
    for( int ih=0; ih<myh; ih++ ){
      cout << ic << "\t" << ih << endl;
      
      TLegend *legend = new TLegend(0.70,0.60,0.80,0.90);
      legend->SetBorderSize(1);
      legend->SetTextFont(42);
      legend->SetTextSize(0.04);
      legend->SetFillColor(0);
      legend->SetLineColor(0);

      //float integral = 0.0;

     // make a canvas to plot on
      //----------------------------------------------c1---------------------------------------------------------
      TCanvas* c1 = new TCanvas("c1",HISTO[ih],800,600); 
      c1->cd();
      c1->SetLogy();
      c1->SetLineStyle(1);
      c1->SetLineWidth(1);

      TString cut=CUT[ic]; TString histo=HISTO[ih];   
      // stack the backgrounds nicely and draw
      THStack* mystack_c1; 
      mystack_c1 = new THStack("mystack_c1","");     
      cout << "made stack" << endl;

      for( int i=0; i<28; i++){ 
	//cout << "this is a test " << HISTO[ih] << "_" << CUT[ic] << endl;
	TObject* ob = f[i]->Get(HISTO[ih]+"_"+CUT[ic]);
	TH1F *stackelement=(TH1F*)ob;
	stackelement->SetFillColor(myfillcol[i]);
	stackelement->SetFillStyle(myfillsty[i]);
	stackelement->SetLineColorAlpha(mylinecol[i], 0.25);
	if (ih != 0 && ih != 1 && ih != 2) stackelement->Rebin(2);
	if( i==27 ){
	  stackelement->Scale( 0.20112 );
	  //std::cout << "background integral: " << integral << std::endl;
	  legend->AddEntry(stackelement, sample[i], "f");
	  c1->cd();
	  mystack_c1->Draw("hist");
	  stackelement->Draw("hist same");
	  mystack_c1->GetXaxis()->SetTitle(stackelement->GetXaxis()->GetTitle());
	  mystack_c1->GetYaxis()->SetTitle(stackelement->GetYaxis()->GetTitle());
	}
	else {
	  if (i==0) stackelement->Scale( 70885.33574 );
	  else if (i==1) stackelement->Scale( 681143.728 );
	  else if (i==2) stackelement->Scale( 679741.7929 );
	  else if (i==3) stackelement->Scale( 6.955729 );
	  else if (i==4) stackelement->Scale( 0.752167 );
	  else if (i==5) stackelement->Scale( 1.688973 );
	  else if (i==6) stackelement->Scale( 0.324779 );
	  else if (i==7) stackelement->Scale( 0.092724 );
	  else if (i==8) stackelement->Scale( 0.060810 );
	  else if (i==9) stackelement->Scale( 0.064964 );
	  else if (i==10) stackelement->Scale( 0.00035942 );
	  else if (i==11) stackelement->Scale( 9.324475 );
	  else if (i==12) stackelement->Scale( 4.15411 );
	  else if (i==13) stackelement->Scale( 1.79658 );
	  else if (i==14) stackelement->Scale( 0.36949 );
	  else if (i==15) stackelement->Scale( 0.051529 );
	  else if (i==16) stackelement->Scale( 0.03565883 );
	  else if (i==17) stackelement->Scale( 0.11414522 );
	  else if (i==18) stackelement->Scale( 0.000030850 );
	  else if (i==19) stackelement->Scale( 8.709668 );
	  else if (i==20) stackelement->Scale( 3.8390 );
	  else if (i==21) stackelement->Scale( 1.86490 );
	  else if (i==22) stackelement->Scale( 0.50313 );
	  else if (i==23) stackelement->Scale( 0.0555418 );
	  else if (i==24) stackelement->Scale( 0.02845238 );
	  else if (i==25) stackelement->Scale( 0.06268758 );
	  else if (i==26) stackelement->Scale( 0.00029056 );
	  mystack_c1->Add(stackelement);
	  //integral += stackelement->Integral();
	  if (i==0 || i==1 || i==3) legend->AddEntry(stackelement, sample[i], "f");
	}

	  //mystack_c1->Add(stackelement); 
	  //c1->cd();
	  //mystack_c1->Draw();
	  //	if( i==3 ){     
	  //c1->cd(); mystack_c1->Draw("nostack");
	  //mystack_c1->GetXaxis()->SetTitle(stackelement->GetXaxis()->GetTitle());
	  //mystack_c1->GetYaxis()->SetTitle(stackelement->GetYaxis()->GetTitle());
	  //}	

      }
      cout << " done stacking" << endl;
      legend->Draw();
      //update and save
      c1->cd(); c1->Update();
      c1->Print("/home/shepj/xaod/ROOTAnalysisTutorial/Run/histograms/"+HISTO[ih]+"_"+CUT[ic]+".root");
      cout << "done stacking" << endl;
    }
  }
}

