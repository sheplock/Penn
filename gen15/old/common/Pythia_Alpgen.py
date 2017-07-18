## Common config for Alpgen+PYTHIA
assert hasattr(genSeq, "Pythia")
genSeq.Pythia.PythiaCommand += ["pyinit user alpgen", "pypars mstp 143 1"]
evgenConfig.generators = ["Alpgen", "Pythia"]

