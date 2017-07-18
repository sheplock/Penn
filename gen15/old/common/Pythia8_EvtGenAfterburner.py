## Common config for adding the EvtGen decayer to Pythia8
	
assert hasattr(genSeq, "Pythia8")
evgenConfig.generators += ["EvtGen"]
#
# For now, run photos inside EvtGen.  inclusive.dec does that, while inclusiveP8.dec turns
# Photos off so we can run it in afterburner mode.  The two .dec files are indentical otherwise.
#
#evgenConfig.auxfiles += ['inclusiveP8.dec', 'inclusiveP8.pdt']
evgenConfig.auxfiles += ['inclusive.dec', 'inclusiveP8.pdt']
	
# This code sets up EvtGen for inclusive decays

from EvtGen_i.EvtGen_iConf import EvtInclusiveDecay
genSeq += EvtInclusiveDecay()
genSeq.EvtInclusiveDecay.OutputLevel = INFO
genSeq.EvtInclusiveDecay.pdtFile = "inclusiveP8.pdt"
genSeq.EvtInclusiveDecay.decayFile = "inclusive.dec"

## Disable B-mixing since EvtGen will do this
genSeq.Pythia8.Commands += ["ParticleDecays:mixB = off"]
