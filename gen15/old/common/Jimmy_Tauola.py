## TAUOLA config for PYTHIA

## Disable native tau decays
genSeq.Herwig.HerwigCommand += ["taudec TAUOLA"]

## Enable TAUOLA
include("MC14JobOptions/Tauola_Fragment.py")
