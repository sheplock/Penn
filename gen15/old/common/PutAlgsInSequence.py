# author: Marjorie Shapiro <mdshapiro@lbl.gov>
#
#
# This JO is a total kludge
# When we have a very inefficient filter, such as the JZnW ones,
# there is no reason to run the remainder of the generator algorithms
# on events that fail.  However, for bookkeeping reasons, we want
# to run CountHepMC and TestHepMC on ALL events
# By putting all the generators into a sequence, we can
# get the desired behavior
#
# USE THIS script with care!!!

from GaudiAlg.GaudiAlgConf import Sequencer
seq = Sequencer("GeneratorFilterSequence")
for i in topSequence:
  seq.Members += [ i.getFullName() ]
  seq += i

genSeq.TopAlg = [ seq.getFullName()]

StreamEVGEN.RequireAlgs = [seq.getFullName()]
