evgenConfig.description = "High-pT inelastic minimum bias events for pile-up, with the A2 MSTW2008LO tune"
evgenConfig.keywords = ["QCD", "minBias"]

include("MC14JobOptions/Pythia8_A2_MSTW2008LO_Common.py")
#include("MC12JobOptions/Pythia8_Photos.py")

genSeq.Pythia8.Commands += \
    ["SoftQCD:nonDiffractive = on",
     "SoftQCD:singleDiffractive = on",
     "SoftQCD:doubleDiffractive = on"]

include("MC14JobOptions/JetFilter_MinbiasHigh.py")
evgenConfig.minevents = 2000
