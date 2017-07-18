## Example configuration for VBFForwardJetsFilter setting up defaults

include("MC15JobOptions/AntiKt4TruthJets_pileup.py")
include("MC15JobOptions/AntiKt6TruthJets_pileup.py")
include("MC15JobOptions/JetFilter_Fragment.py")

if not hasattr( filtSeq, "VBFForwardJetsFilter" ):
    from GeneratorFilters.GeneratorFiltersConf import VBFForwardJetsFilter
    filtSeq += VBFForwardJetsFilter()
    pass

"""
VBFForwardJetsFilter = filtSeq.VBFForwardJetsFilter
VBFForwardJetsFilter.JetMinPt = 10.*Gaudi::Units::GeV
VBFForwardJetsFilter.JetMaxEta = 5.
VBFForwardJetsFilter.NJets = 2
VBFForwardJetsFilter.Jet1MinPt = 20.*Gaudi::Units::GeV
VBFForwardJetsFilter.Jet1MaxEta = 5.
VBFForwardJetsFilter.Jet2MinPt = 10.*Gaudi::Units::GeV
VBFForwardJetsFilter.Jet2MaxEta = 5.
VBFForwardJetsFilter.UseOppositeSignEtaJet1Jet2 = False
VBFForwardJetsFilter.MassJJ = 300.*Gaudi::Units::GeV
VBFForwardJetsFilter.DeltaEtaJJ = 2.0
VBFForwardJetsFilter.UseLeadingJJ = False
VBFForwardJetsFilter.TruthJetContainer = "AntiKt4TruthJets"
VBFForwardJetsFilter.LGMinPt = 10.*Gaudi::Units::GeV
VBFForwardJetsFilter.LGMaxEta = 2.5
VBFForwardJetsFilter.DeltaRJLG = 0.05
VBFForwardJetsFilter.RatioPtJLG = 0.3
"""
