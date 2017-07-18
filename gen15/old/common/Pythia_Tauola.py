## TAUOLA config for PYTHIA

## Disable native tau decays
assert hasattr(genSeq, "Pythia")
genSeq.Pythia.PythiaCommand += ["pydat3 mdcy 15 1 0"]

## Enable TAUOLA
include("MC14JobOptions/Tauola_Fragment.py")
