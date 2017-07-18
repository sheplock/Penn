## Job options file for Herwig++, QCD jet slice production
## Andy Buckley, April '10
## Lily Asquith, June '12
## Orel Gueta, November '12

include("MC14JobOptions/Herwigpp_UEEE5_CTEQ6L1_Common.py")

evgenConfig.description = "QCD dijet production JZ0 with PDF and UE-EE5 tune"
evgenConfig.keywords = ["QCD", "jets"]

cmds = """\
insert /Herwig/MatrixElements/SimpleQCD:MatrixElements[0] /Herwig/MatrixElements/MEMinBias
set /Herwig/Cuts/JetKtCut:MinKT 0.0*GeV
set /Herwig/Cuts/QCDCuts:MHatMin 0.0*GeV
set /Herwig/Cuts/QCDCuts:X1Min 0.01
set /Herwig/Cuts/QCDCuts:X2Min 0.01
set /Herwig/UnderlyingEvent/MPIHandler:IdenticalToUE 0
"""

genSeq.Herwigpp.Commands += cmds.splitlines()

include("MC14JobOptions/Herwigpp_SUSYConfig.py")
evgenConfig.minevents = 5000

