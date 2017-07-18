## PHOTOS config for PYTHIA

## Disable native QED FSR
assert hasattr(genSeq, "Pythia")
genSeq.Pythia.PythiaCommand += ["pydat1 parj 90 20000"]

## Enable PHOTOS
include("MC14JobOptions/Photos_Fragment.py")
