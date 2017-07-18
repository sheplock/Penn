## Enable MadGraph LHEF reading in Pythia8
include("MC14JobOptions/Pythia8_LHEF.py")
evgenConfig.generators = ["MadGraph", "Pythia8"]
