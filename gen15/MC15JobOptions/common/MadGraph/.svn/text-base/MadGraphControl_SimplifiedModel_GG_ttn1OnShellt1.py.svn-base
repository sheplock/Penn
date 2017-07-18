include ( 'MC15JobOptions/MadGraphControl_SimplifiedModelPreInclude.py' )

fields = runArgs.jobConfig[0].replace(".py","").split("_")

masses['1000021'] = float(fields[3])
masses['1000006'] = float(fields[4])
masses['1000022'] = float(fields[5])

gentype = fields[1]
decaytype = fields[2]

process = '''
generate p p > go go $ susysq susysq~ @1
add process p p > go go j $ susysq susysq~ @2
add process p p > go go j j $ susysq susysq~ @3
'''

njets = 2

evgenLog.info('Registered generation of Gtt on-shell grid '+str(runArgs.runNumber))

evgenConfig.contact  = ["louis.guillaume.gagnon@cern.ch"]
evgenConfig.keywords += ['simplifiedModel', 'gluino', 'stop', 'neutralino', 'SUSY', 'boosted', 'top']
evgenConfig.description = 'gluino pair production and decay to top pair and LSP via on-shell stop'

include ( 'MC15JobOptions/MadGraphControl_SimplifiedModelPostInclude.py' )

if njets>0:
    genSeq.Pythia8.Commands += ["Merging:Process = pp>{go,1000021}{go,1000021}"]
