## Configure jet container for anti-kT R=0.6 truth jets with flavour labels

## Note: this cannot be used simultaneously with a non-labelled jet container
## since jetFlags.truthFlavorTags is a global variable

evgenConfig.findJets = True

## Turn on ghost association algorithms
from JetRec.JetRecFlags import jetFlags
jetFlags.truthFlavorTags = ["BHadronsInitial", "BHadronsFinal", "BQuarksFinal",
                            "CHadronsInitial", "CHadronsFinal", "CQuarksFinal",
                            "TausFinal",
                            "Partons",
                            ]

## truthpartondr    => adds cone-based label
## partontruthlabel => adds ghost-based label
## removeconstit    => empties container of jet constituents to reduce filesize
from JetRec.JetRecStandard import jtm
jtm.addJetFinder("AntiKt6TruthJets", "AntiKt", 0.6, "truth",
                 modifiersin=[jtm.truthpartondr, jtm.partontruthlabel, jtm.removeconstit],
                 ptmin=7000.)
