## Herwig++ job option file for Susy 2-parton -> 2-sparticle processes

## Get a handle on the top level algorithms' sequence
from AthenaCommon import Logging
log = Logging.logging.getLogger('Generate.SMModeADG')

if not 'evgenConfig' in dir():
    raise RuntimeError('These jobOptions should be run through Generate_trf.py')

## Setup Herwig++
include ( 'MC12JobOptions/Herwigpp_UEEE4_CTEQ6L1_Common.py' )

# define spectrum file name
slha_file = 'susy_simplifiedModel_wA_nosl_lepW_164301.slha'

# Add Herwig++ parameters for this process
include ( 'MC12JobOptions/Herwigpp_SUSYConfig.py' )

# Add Herwig++ parameters for this process
cmds = buildHerwigppCommands(['~chi_1+','~chi_20'],slha_file,'Exclusive')

cmds+="""
#switch off decay modes
set /Herwig/Particles/W+/W+->u,dbar;:OnOff Off
set /Herwig/Particles/W+/W+->c,sbar;:OnOff Off
set /Herwig/Particles/W+/W+->sbar,u;:OnOff Off
set /Herwig/Particles/W+/W+->c,dbar;:OnOff Off
set /Herwig/Particles/W+/W+->bbar,c;:OnOff Off

set /Herwig/Particles/W-/W-->ubar,d;:OnOff Off
set /Herwig/Particles/W-/W-->cbar,s;:OnOff Off
set /Herwig/Particles/W-/W-->s,ubar;:OnOff Off
set /Herwig/Particles/W-/W-->cbar,d;:OnOff Off
set /Herwig/Particles/W-/W-->b,cbar;:OnOff Off

set /Herwig/Particles/Z0/Z0->d,dbar;:OnOff Off
set /Herwig/Particles/Z0/Z0->s,sbar;:OnOff Off
set /Herwig/Particles/Z0/Z0->b,bbar;:OnOff Off
set /Herwig/Particles/Z0/Z0->u,ubar;:OnOff Off
set /Herwig/Particles/Z0/Z0->c,cbar;:OnOff Off
set /Herwig/Particles/Z0/Z0->nu_e,nu_ebar;:OnOff Off
set /Herwig/Particles/Z0/Z0->nu_mu,nu_mubar;:OnOff Off
set /Herwig/Particles/Z0/Z0->nu_tau,nu_taubar;:OnOff Off
"""

## Define metadata
evgenConfig.description = 'Simplified Model Mode A grid generation for direct gaugino search...'
evgenConfig.keywords    = ['SUSY','Direct Gaugino','Simplified Models','chargino','neutralino']
evgenConfig.contact     = ['alaettin.serhan.mete@cern.ch']

## Print checks
log.info('*** Begin Herwig++ commands ***')
log.info(cmds)
log.info('*** End Herwig++ commands ***')

## Set the command vector
topAlg.Herwigpp.Commands += cmds.splitlines()

## Clean up
del cmds
