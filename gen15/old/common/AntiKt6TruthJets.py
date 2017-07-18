## Configure jet container for anti-kT R=0.6 truth jets

evgenConfig.findJets = True

## Turn off ghost association algorithms
from JetRec.JetRecFlags import jetFlags
jetFlags.truthFlavorTags = []

from JetRec.JetRecStandard import jtm
jtm.addJetFinder("AntiKt6TruthJets", "AntiKt", 0.6, "truth",
                 modifiersin="none",
                 ptmin=7000.)
