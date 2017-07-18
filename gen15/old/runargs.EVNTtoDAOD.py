# Run arguments file auto-generated on Tue Jun  2 12:12:30 2015 by:
# JobTransform: EVNTtoDAOD
# Version: $Id: trfExe.py 625001 2014-10-29 18:34:02Z wbreaden $
# Import runArgs class
from PyJobTransforms.trfJobOptions import RunArguments
runArgs = RunArguments()
runArgs.trfSubstepName = 'EVNTtoDAOD' 

runArgs.maxEvents = 100
runArgs.reductionConf = ['MCGN1']

# Input data
runArgs.inputEVNTFile = ['test2.EVNT.root']
runArgs.inputEVNTFileType = 'EVNT'
runArgs.inputEVNTFileNentries = 10L

# Output data
runArgs.outputDAOD_MCGN1File = 'DAOD_MCGN1.VBF.root'
runArgs.outputDAOD_MCGN1FileType = 'aod'

# Extra runargs

# Extra runtime runargs

# Literal runargs snippets
