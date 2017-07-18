## Herwig++ config for the CTEQ6L1 UE-EE-4 tune series with an NLO ME PDF
include("MC14JobOptions/Herwigpp_Base_Fragment.py")

## Construct command set
from Herwigpp_i import config as hw
cmds = hw.energy_cmds(runArgs.ecmEnergy) + hw.base_cmds() \
    + hw.nlo_pdf_cmds("CT10.LHgrid", "cteq6ll.LHpdf") \
    + hw.ue_tune_cmds("UE-EE-4-CTEQ6L1")
genSeq.Herwigpp.Commands = cmds.splitlines()
del cmds

evgenConfig.tune = "CTEQ6L1-UE-EE-4"
