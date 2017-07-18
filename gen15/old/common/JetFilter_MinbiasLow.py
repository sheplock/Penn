## Min bias truth jet filter for min bias sample preparation (low slice)

include("MC14JobOptions/AntiKt4TruthJets_pileup.py")
include("MC14JobOptions/AntiKt6TruthJets_pileup.py")

include("MC14JobOptions/JetFilter_Fragment.py")
filtSeq.QCDTruthJetFilter.MaxPt = 35.*GeV
filtSeq.QCDTruthJetFilter.TruthJetContainer = "AntiKt6TruthJets"
filtSeq.QCDTruthJetFilter.DoShape = False
