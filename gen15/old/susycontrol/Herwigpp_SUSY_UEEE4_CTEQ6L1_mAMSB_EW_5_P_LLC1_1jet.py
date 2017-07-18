## SUSY Herwig++ jobOptions for mAMSB electroweak production (long-lived chargino)

from AthenaCommon import Logging
log = Logging.logging.getLogger('Generate.mAMSB')

if not 'evgenConfig' in dir():
    raise RuntimeError('These jobOptions should be run through Generate_trf.py')

# setup Herwig++
include ( 'MC14JobOptions/Herwigpp_UEEE4_CTEQ6L1_Common.py' )

# define spectrum file name
include ( 'MC14JobOptions/SUSY_mAMSB_EW_5_P_LLC1_points.py' )
try:
      slha_file, lifetime = amsb_ew_dict[runArgs.runNumber]
except:
      raise RuntimeError('DSID %s not found in dictionary. Aborting!' % runArgs.runNumber)

# Add Herwig++ parameters for this process
include ( 'MC14JobOptions/Herwigpp_SUSYConfig.py' )
cmds = buildHerwigppCommands(['neutralinos','charginos','sleptons','staus'], slha_file, earlyCopy=True) 

# speciaConfig params
include ( 'MC14JobOptions/SUSYMetadata.py' )
(c1mass, n1mass) = mAMSB_mass_extract(slha_file, ['1000024', '1000022'])

# define metadata
evgenConfig.description = 'AMSB electroweak production, slha file: %s, lifetime: %s' % (slha_file,lifetime)
evgenConfig.keywords = ['SUSY','mAMSB','DirectGaugino','LongLivedChargino']
evgenConfig.contact  = ['shimpei.yamamoto@cern.ch']
evgenConfig.specialConfig = 'AMSBC1Mass=%s*GeV;AMSBN1Mass=%s*GeV;AMSBC1Lifetime=%s*ns;preInclude=SimulationJobOptions/preInclude.AMSB.py' % (c1mass,n1mass,lifetime)

# print checks
log.info('*** Begin Herwig++ commands ***')
log.info(cmds)
log.info('*** End Herwig++ commands ***')

# Set the command vector
genSeq.Herwigpp.Commands += cmds.splitlines() 

# Generator Filter
include("MC14JobOptions/JetFilterAkt4.py")
filtSeq.QCDTruthJetFilter.MinPt = 70*GeV
filtSeq.QCDTruthJetFilter.MaxEta = 5.0

# clean up
del cmds
