## Truth jet filter setup for anti-kT R=0.4 truth jets

include("MC14JobOptions/AntiKt4TruthJets.py")

include("MC14JobOptions/JetFilter_Fragment.py")
filtSeq.QCDTruthJetFilter.TruthJetContainer = "AntiKt4TruthJets"
