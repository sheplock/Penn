## Herwig++ config for the CTEQ6L1 UE-EE-4 tune series with an NLO ME PDF with NLO events read from an LHEF file
include("MC14JobOptions/Herwigpp_UEEE4_CTEQ6L1_CT10ME_Common.py")

from Herwigpp_i import config as hw
genSeq.Herwigpp.Commands += hw.lhef_cmds(filename="events.lhe", nlo=True).splitlines()


