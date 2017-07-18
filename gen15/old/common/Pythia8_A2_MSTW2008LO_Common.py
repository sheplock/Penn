## Config for Py8 tune A2 with MSTW2008LO
include("MC14JobOptions/Pythia8_Base_Fragment.py")
	
genSeq.Pythia8.Commands += [
    "Tune:pp = 5",
    "PDF:useLHAPDF = on",
    "PDF:LHAPDFset = MSTW2008lo68cl.LHgrid",
    "MultipartonInteractions:bProfile = 4",
    "MultipartonInteractions:a1 = 0.03",
    "MultipartonInteractions:pT0Ref = 1.90",
    "MultipartonInteractions:ecmPow = 0.30",
    "BeamRemnants:reconnectRange = 2.28",
    "SpaceShower:rapidityOrder=0"]
evgenConfig.tune = "A2 MSTW2008LO"
