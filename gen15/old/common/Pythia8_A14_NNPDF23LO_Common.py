## Config for Py8 tune A14 with NNPDF23LO
include("MC14JobOptions/Pythia8_Base_Fragment.py")

genSeq.Pythia8.Commands += [
    "Tune:ee = 7", 
    "Tune:pp = 14",
    "PDF:pSet = LHAPDF6:NNPDF23_lo_as_0130_qed.LHpdf",
    "SpaceShower:rapidityOrder = on",
    "SigmaProcess:alphaSvalue = 0.140",
    "SpaceShower:pT0Ref = 1.56",
    "SpaceShower:pTmaxFudge = 0.91",
    "SpaceShower:pTdampFudge = 1.05",
    "SpaceShower:alphaSvalue = 0.127",
    "TimeShower:alphaSvalue = 0.127",
    "BeamRemnants:primordialKThard = 1.88",
    "MultipartonInteractions:pT0Ref = 2.09",
    "MultipartonInteractions:alphaSvalue = 0.126",
    "ColourReconnection:mode = 0",
    "ColourReconnection:range = 1.71"]

evgenConfig.tune = "A14 NNPDF23LO"
