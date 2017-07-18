## Base config for HERWIG 6.5 + Jimmy 4.31 using the AUET2 CTEQ6L1 tune
from Herwig_i.Herwig_iConf import Herwig
genSeq += Herwig()
evgenConfig.generators += ["Herwig"]

include("MC14JobOptions/Jimmy_Base_Fragment.py")
include("MC14JobOptions/Jimmy_AUET2_CTEQ6L1_Fragment.py")
