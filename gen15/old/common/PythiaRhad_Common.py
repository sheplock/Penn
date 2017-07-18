# R-Hadron common evgen jobOption fragment
# compiled by Sascha Mehlhase (sascha.mehlhase@cern.ch)
# June 19, 2013 (by ahaas)
# based on input from Paul Jackson, Andy Haas and Jorge-Armando Benitez Garcia

import os
import sys

#evgenConfig.generators = ["PythiaRhad"]
#evgenConfig.description = "PYTHIA6 R-Hadrons"
#evgenConfig.keywords = ["SUSY", "longLived"]
#evgenConfig.contact  = ["ahaas@cern.ch", "benitez@cern.ch", "sascha.mehlhase@cern.ch"]

# import PythiaRhad package (PYTHIA 6)
from PythiaRhad_i.PythiaRhad_iConf import PythiaRhad
genSeq += PythiaRhad()

# set default tune/PDF combination (was PYTUNE_103 before)
genSeq.PythiaRhad.Tune_Name = "ATLAS_20110003"
genSeq.PythiaRhad.useAtlasPythiaTune09 = False
evgenConfig.tune = "AUET2B CTEQ6L1"

# set common PYTHIA parameters
genSeq.PythiaRhad.PythiaCommand += [
  "pyinit pylisti 12",
  "pyinit pylistf 1",
  "pystat 1 3 4 5",
  "pyinit dumpr 1 5",
  "pydat2 pmas 6 1 172.5",    # TOP mass
  "pydat2 pmas 24 1 80.399",  # PDG2010 W mass
  "pydat2 pmas 23 1 91.1876", # PDG2010 Z0 mass
]

# set some commands valid for both guino and stop/sbottom case
genSeq.PythiaRhad.PythiaCommand += [
  "pysubs ckin 3 18.",      # pT cut at 18 GeV
  "pypars mstp 81 1",       # Old shower/multiple-interaction model (new model is not compatible with R-hadron fragmentation)
  "pydat1 mstj 11 4",       # Set longitudinal fragmentation function to Pythia default
  "pymssm imss 1 1",        # General MSSM simulation
  "pymssm imss 3 1",        # Tell Pythia that rmss 3 below should be interpreted as the gluino pole mass
  "pymssm imss 5 1",        # Set stop, sbottom and stau masses and mixing by hand (26-28 for mixing not set!)
  "pymssm rmss 1 4000.0",   # Photino mass
  "pymssm rmss 2 4000.0",   # Wino/Zino mass
  "pymssm rmss 7 4000.0",   # Right slepton mass
  "pymssm rmss 8 4000.0",   # Left squark mass
  "pymssm rmss 9 4000.0",   # Right squark mass
  "pymssm rmss 10 4000.0",  # stop2 mass
  "pymssm rmss 11 4000.0",  # sbottom1 mass
  "pymssm rmss 12 4000.0",  # stop1 mass
  "pymssm rmss 4 4000.0",   # Higgsino mass parameter
  "pysubs msel 0",          # Turn off all processes
  "pypars mstp 111 0",      # Turn off master switch for fragmentation and decay
  "pyinit pylistf 3",
  "pystat 2"
]

pdg = {}
q3 = {}
apflag = {}
names = {}
antinames = {}
masses = {}

# adding gluino setups
pdg[("generic", "gluino")] = [1000993, 1009213, 1009313, 1009323, 1009113, 1009223, 1009333, 1091114, 1092114, 1092214, 1092224, 1093114, 1093214, 1093224, 1093314, 1093324, 1093334, 0, 0, 0]
q3[("generic", "gluino")] = [0, 3, 0, 3, 0, 0, 0, -3, 0, 3, 6, -3, 0, 3, -3, 0, -3, 0, 0, 0]
apflag[("generic", "gluino")] = [0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0]
names[("generic", "gluino")] = ["~g_ball", "~g_rho+", "~g_K*0", "~g_K*+", "~g_rho0", "~g_omega", "~g_phi", "~g_Dlt-", "~g_Dlt0", "~g_Dlt+", "~g_Dlt++", "~g_Sgm*-", "~g_Sgm*0", "~g_Sgm*+", "~g_Xi*-", "~g_Xi*0 ", "~g_Omg-", " ", " ", " "]
antinames[("generic", "gluino")] = [" ", "~g_rho-", "~g_K*br0", "~g_K*-", " ", " ", " ", "~g_Dltb+", "~g_Dltb0", "~g_Dltb-", "~g_Dlb--", "~g_Sgmb+", "~g_Sgmb0", "~g_Sgmb-", "~g_Xibr+", "~g_Xib0", "~g_Omgb+", " ", " ", " "]

pdg[("regge", "gluino")] = [1000993, 1009213, 1009113, 1009313, 1009323, 1093212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
q3[("regge", "gluino")] = [0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
apflag[("regge", "gluino")] = [0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
names[("regge", "gluino")] = ["~g_gball", "~g_rho+", "~g_rho0", "~g_K0", "~g_K+", "~g_L0", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]
antinames[("regge", "gluino")] = [" ", "~g_rho-", " ", "~g_K0bar", "~g_K-", "~g_L0bar", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]

pdg[("intermediate", "gluino")] = [1000991, 1009211, 1009111, 1009311, 1009321, 1093212, 1092212, 1092112, 1092214, 1092114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
q3[("intermediate", "gluino")] = [0, 3, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
apflag[("intermediate", "gluino")] = [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
names[("intermediate", "gluino")] = ["~g_gball", "~g_pi+", "~g_pi0", "~g_K0", "~g_K+", "~g_L0", "~g_prot", "~g_neutr", "~g_Delt+", "~g_Delt0", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]
antinames[("intermediate", "gluino")] = [" ", "~g_pi-", " ", "~g_K0bar", "~g_K-", "~g_L0bar", "~g_aprot", "~g_aneut", "~g_Dltb-", "~g_Dltb0", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]
masses[("intermediate", "gluino")] = [0.330, 0.330, 0.330, 0.460, 0.460, 0.280, 0.660, 0.660, 0.530, 0.530, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.]

#adding stop setups
pdg[("generic", "stop")] = [1000612, 1000622, 1000632, 1000642, 1000652, 1006113, 1006211, 1006213, 1006223, 1006311, 1006313, 1006321, 1006323, 1006333, 0, 0, 0, 0, 0, 0]
q3[("generic", "stop")] = [3, 0, 3, 0, 3, 0, 3, 3, 6, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0]
apflag[("generic", "stop")] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0]
names[("generic", "stop")] = ["~T+", "~T0", "~T_s+", "~T_c0", "~T_b+", "~T_dd10", "~T_ud0+", "~T_ud1+", "~T_uu1++", "~T_sd00", "~T_sd10", "~T_su0+", "~T_su1+", "~T_ss10", " ", " ", " ", " ", " ", " "]
antinames[("generic", "stop")] = ["~Tb-", "~Tb0", "~Tb_s-", "~Tb_c0", "~Tb_b-", "~Tb_dd10", "~Tb_ud0-", "~Tb_ud1-", "~Tb_uu--", "~Tb_sd00", "~Tb_sd10", "~Tb_su0-", "~Tb_su1-", "~Tb_ss10", " ", " ", " ", " ", " ", " "]

pdg[("regge", "stop")] = [1000612, 1000622, 1006211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
q3[("regge", "stop")] = [3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
apflag[("regge", "stop")] = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
names[("regge", "stop")] = ["~T+", "~T0", "~T_ud0+", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]
antinames[("regge", "stop")] = ["~Tb-", "~Tb0", "~Tb_ud-", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]

#adding sbottom setups
pdg[("regge", "sbottom")] = [1000512, 1000522, 1005211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
q3[("regge", "sbottom")] = [0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
apflag[("regge", "sbottom")] = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
names[("regge", "sbottom")] = ["~B0", "~B-", "~B_ud0", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]
antinames[("regge", "sbottom")] = ["~Bb0", "~Bb+", "~Bb_ud0", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "]

# add spectra
genSeq.PythiaRhad.RHadronPDGids = pdg[(MODEL, CASE)]
genSeq.PythiaRhad.PygiveCommand = []
for i in xrange(1, 20):
  kc = int(400 + i)
  genSeq.PythiaRhad.PygiveCommand += [
    "KCHG(%d,1)=%d" % (kc, q3[(MODEL,CASE)][i-1]),
    "KCHG(%d,2)=0"  % (kc),
    "KCHG(%d,3)=%d" % (kc, apflag[(MODEL,CASE)][i-1]),
    "KCHG(%d,4)=%d" % (kc, pdg[(MODEL,CASE)][i-1]),
    "CHAF(%d,1)=%s" % (kc, names[(MODEL,CASE)][i-1]),
    "CHAF(%d,2)=%s" % (kc, antinames[(MODEL,CASE)][i-1])
  ]
  if MODEL == 'intermediate':
    genSeq.PythiaRhad.PygiveCommand += [
      "PMAS(%d,1)=%fD0" % (kc, MASS + masses[(MODEL,CASE)][i-1]),
      "PMAS(%d,2)=%fD0" % (kc, MASS + masses[(MODEL,CASE)][i-1])
    ]

# choose different interaction models - generic (default), regge, intermediate
if MODEL == 'regge':
  genSeq.PythiaRhad.RunReggeModel = True
  genSeq.PythiaRhad.RunIntermediateModel = False
elif MODEL == 'intermediate':
  genSeq.PythiaRhad.RunReggeModel = False
  genSeq.PythiaRhad.RunIntermediateModel = True
else:
  genSeq.PythiaRhad.RunReggeModel = False
  genSeq.PythiaRhad.RunIntermediateModel = False

# remove all particles in GEANT4 in case of stopped gluinos
if 'STOPPED' in globals() and STOPPED == 'true':
  genSeq.PythiaRhad.strip_out_rh = True
else:
  genSeq.PythiaRhad.strip_out_rh = False

# choose different production processes - gluino, stop, sbottom
if CASE == 'gluino':
  genSeq.PythiaRhad.RunGluinoHadrons = True
  genSeq.PythiaRhad.RunStopHadrons = False
  genSeq.PythiaRhad.RunSbottomHadrons = False
  # checking for decaying particles
  if 'DECAY' in globals() and DECAY == 'true':
    genSeq.PythiaRhad.randomtshift = 50 # +-X ns, overrides tshift if non-zero
    genSeq.PythiaRhad.rh_decay = True
    genSeq.PythiaRhad.boost_rh_to_rest_frame = True
    genSeq.PythiaRhad.rotate_rh = True
    genSeq.PythiaRhad.translate_rh_to_stopping_position = True
    genSeq.PythiaRhad.StoppingInput = [[0, 0, 0, 0, 0, 0]]
    include("StoppingInput.txt")
    genSeq.PythiaRhad.PythiaCommand += [
      "pymssm imss 1 1",
      "pymssm imss 3 1",
      "pymssm imss 5 1",
      "pymssm rmss 3 %d.0" % (MASS),
      "pymssm rmss 1 %d.0" % (MASSX),
      "pymssm rmss 2 3000.0",
      "pymssm rmss 4 10000.0",
      "pymssm rmss 7 4000.0",
      "pymssm rmss 8 4000.0",
      "pymssm rmss 9 4000.0",
      "pymssm rmss 10 4000.0",
      "pymssm rmss 11 4000.0",
      "pymssm rmss 12 5000.0",
      # decays into gluons
      "pymssm rmss 21 %d.0e9" % (MASSX),
      "pymssm imss 11 1",                 # ok to use the Gravitino
      "pymssm rmss 29 2.0e6",             # Planck mass, controls BR(g~ -> g+Gravitino)
      "pydat3 mdcy 1000022 1 0",          # kill neutralino decays
      # "pydat1 mstj 45 6",               # allow CMshower->ttbar in gluino decays
      # "pydat1 mstj 43 1",               # z definition in CM shower
      "pysubs msel 0",
      "pysubs msub 243 1",
      "pysubs msub 244 1",
      "pypars mstp 111 0",
      "pyinit pylisti 12",                # dumps the full decay table, etc.
      # "pyinit pylistf 1",               # dumps pythia event
      "pyinit dumpr 0 100",
      # "pystat 2"
     ]
  else:
    genSeq.PythiaRhad.PythiaCommand += [
      "pymssm rmss 12 4000.0",        # stop1 mass
      "pymssm rmss 3 %d.0" % (MASS),  # gluino pole mass
    ]
    if 'PROC' in globals() and PROC == 'ffbar':
      genSeq.PythiaRhad.PythiaCommand += ["pysubs msub 243 1"] # turn on ffbar -> ~g~g
    elif 'PROC' in globals() and PROC == 'gg':
      genSeq.PythiaRhad.PythiaCommand += ["pysubs msub 244 1"] # turn on gg -> ~g~g
    else:
      genSeq.PythiaRhad.PythiaCommand += ["pysubs msub 243 1"] # turn on ffbar -> ~g~g
      genSeq.PythiaRhad.PythiaCommand += ["pysubs msub 244 1"] # turn on gg -> ~g~g
  # set glueball fraction
  if 'GBALLPROB' in globals():
    genSeq.PythiaRhad.GluinoBallProbability = GBALLPROB
elif CASE == 'stop':
  genSeq.PythiaRhad.RunGluinoHadrons = False
  genSeq.PythiaRhad.RunStopHadrons = True
  genSeq.PythiaRhad.RunSbottomHadrons = False
  genSeq.PythiaRhad.PythiaCommand += [
  	"pymssm rmss 12 %d.0" % (MASS), # stop1 mass
  	"pymssm rmss 3 4000.0",         # gluino pole mass
  	"pysubs msub 261 1",            # turn on ffbar -> stop1stop1bar
  	"pysubs msub 264 1"             # turn on gg -> stop1stop1bar
  ]
elif CASE == 'sbottom':
  genSeq.PythiaRhad.RunGluinoHadrons = False
  genSeq.PythiaRhad.RunStopHadrons = False
  genSeq.PythiaRhad.RunSbottomHadrons = True
  genSeq.PythiaRhad.PythiaCommand += [
    "pymssm rmss 11 %d.0" % (MASS), # sbottom1 mass
    "pymssm rmss 3 4000.0",         # gluino pole mass
    "pysubs msub 287 1",            # turn on ffbar -> sbottom1sbottom1bar
    "pysubs msub 289 1",            # turn on gg -> sbottom1sbottom1bar
    "pysubs msub 291 1"             # turn on bb -> sbottom1sbottom1
  ]
else:
  raise RunTimError('No sensible CASE was set!')
