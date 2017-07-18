from AthenaCommon import Logging
log = Logging.logging.getLogger('Generate.GMSB')

if not 'evgenConfig' in dir():
    raise RuntimeError('These jobOptions should be run through Generate_tf.py')

# setup Herwig++
include ( 'MC14JobOptions/Herwigpp_UEEE4_CTEQ6L1_Common.py' )

include ( 'MC14JobOptions/SUSY_GMSB_stablestau_mc12points.py' )
try:
    Lambda, tanbeta = pointdict[runArgs.runNumber]
except:
    raise RuntimeError('DSID %s not found in grid point dictionary. Aborting!' % runArgs.runNumber)
    
# define spectrum file name
slha_file = 'susy_gmsb_stablestau_lambda_%s_tanb_%s.slha'  % (Lambda, tanbeta)

# Add Herwig++ parameters for this process
include ( 'MC14JobOptions/Herwigpp_SUSYConfig.py' )
cmds = buildHerwigppCommands(['all'], slha_file, earlyCopy=True)

# specialConfig params for simulation: stau1 = 1000015, selectronR = 2000011, assumption that smuonR is mass degenerated with selectronR
include ( 'MC14JobOptions/SUSYMetadata.py' )
(m_stau, m_slepton) = mass_extract(slha_file, ['1000015', '2000011'])

# define metadata
evgenConfig.description = "GMSB Generation for Lambda=%s, tan beta=%s" % (Lambda, tanbeta)
evgenConfig.keywords = ["SUSY", "GMSB", "longLived"]
evgenConfig.contact = ["benitez@cern.ch"]
evgenConfig.specialConfig = 'GMSBIndex=2;GMSBStau=%s*GeV;GMSBSlepton=%s*GeV;preInclude=SimulationJobOptions/preInclude.GMSB.py' % (m_stau,m_slepton)

# print checks
log.info('*** Begin Herwig++ commands ***')
log.info(cmds)
log.info('*** End Herwig++ commands ***')

# Set the command vector
genSeq.Herwigpp.Commands += cmds.splitlines()

# dump herwig++ configuration
genSeq.Herwigpp.InFileDump = 'herwigpp.config.txt'

# Clean up
del cmds, Lambda, tanbeta, m_stau, m_slepton
