# Run arguments file auto-generated on Tue Jun  2 12:45:05 2015 by:
# JobTransform: Generate
# Version: unknown

# Authors: Andy Buckley <Andy.Buckley@cern.ch>
#          Borut Kersevan <Borut.Kersevan@cern.ch>

#################################################################################
from PyJobTransformsCore.runargs import RunArguments

runArgs = RunArguments()


# Maximum number of events to process
runArgs.maxEvents = 100

# List of strings separated by commas
runArgs.jobConfig = ['MC12.205048.Herwigpp_UEEE4_CTEQ6L1_sM_wA_WZ_C1_100_N1_0.py']

# number of the first event in the output data file
runArgs.firstEvent = 1

# random seed for generator
runArgs.randomSeed = 1

# Run number of data file
runArgs.runNumber = 205048

# Output file that contains generated events with min. contents check
runArgs.outputEVNTFile = 'test.EVNT.pool.root'

# Center of mass energy parameter in GeV
runArgs.ecmEnergy = 13000
