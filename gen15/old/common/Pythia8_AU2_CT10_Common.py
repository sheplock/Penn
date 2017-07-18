## Config for Py8 tune AU2 with CT10
include("MC14JobOptions/Pythia8_Base_Fragment.py")

genSeq.Pythia8.Commands += [
       "Tune:pp = 5",
       "PDF:useLHAPDF = on",
       "PDF:LHAPDFset = CT10.LHgrid",
       "MultipartonInteractions:bProfile = 4",
       "MultipartonInteractions:a1 = 0.10",
       "MultipartonInteractions:pT0Ref = 1.70",
       "MultipartonInteractions:ecmPow = 0.16",
       "BeamRemnants:reconnectRange = 4.67",
       "SpaceShower:rapidityOrder=0"]
evgenConfig.tune = "AU2 CT10"
