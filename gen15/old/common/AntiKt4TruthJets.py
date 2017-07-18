## Configure jet container for anti-kT R=0.4 truth jets

evgenConfig.findJets = True

## Turn off ghost association algorithms
from JetRec.JetRecFlags import jetFlags
jetFlags.truthFlavorTags = []

from JetRec.JetRecStandard import jtm
jtm.addJetFinder("AntiKt4TruthJets", "AntiKt", 0.4, "truth",
                 modifiersin="none",
                 ptmin=7000.)
