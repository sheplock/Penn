from MadGraphControl.MadGraphUtils import *

fcard = open('proc_card_mg5.dat','w')
fcard.write("""
import model EffDM -modelname

generate p p > chi chi~ a QED=1 D1=0 D2=0 D3=0 D4=0 D5=1 D6=0 D7=0 D8=0 D9=0 D10=0 D11=0 D12=0 D13=0 D14=0

output -f
""")
fcard.close()

beamEnergy=-999
if hasattr(runArgs,'ecmEnergy'):
    beamEnergy = runArgs.ecmEnergy / 2.
else: 
    raise RuntimeError("No center of mass energy found.")

#Fetch default LO run_card.dat and set parameters
extras = {'lhe_version':'2.0', 
          'cut_decays' :'F', 
          'pdlabel'    : "'lhapdf'",
          'lhaid'      : 247000,
	  'xpta'       : 130 }
build_run_card(run_card_old=get_default_runcard(),run_card_new='run_card.dat',
               nevts=runArgs.maxEvents*2,rand_seed=runArgs.randomSeed,beamEnergy=beamEnergy,extras=extras)

    
print_cards()

paramcard = subprocess.Popen(['get_files','-data','MadGraph_param_card_EffDM.dat'])
paramcard.wait()
if not os.access('MadGraph_param_card_EffDM.dat',os.R_OK):
    print 'ERROR: Could not get param card'
elif os.access('param_card.dat',os.R_OK):
    print 'ERROR: Old param card in the current directory.  Dont want to clobber it.  Please move it first.'
else:
    oldcard = open('MadGraph_param_card_EffDM.dat','r')
    newcard = open('param_card.dat','w')
    for line in oldcard:
        if 'mDM' in line:
            newcard.write('  1000022 %e # mDM\n'%(mDM))
        elif 'Mstar' in line:
            newcard.write('    1 %e # Mstar\n'%(Mstar))
        else:
            newcard.write(line)
    oldcard.close()
    newcard.close()

process_dir = new_process()

runName='run_01'

generate(run_card_loc='run_card.dat',param_card_loc='param_card.dat',mode=0,njobs=1,run_name=runName,proc_dir=process_dir)

arrange_output(run_name=runName,proc_dir=process_dir,outputDS=runName+'._00001.events.tar.gz')                                                                          
                                                                                                                                                                        
#### Shower                                                                                                                                                             
evgenConfig.description = "Wimp pair monophoton with EFT, D5, pta>130 GeV"
evgenConfig.keywords = ["monophoton","exotic","BSM","WIMP"]
evgenConfig.process = "pp>chichi~a"
evgenConfig.inputfilecheck = runName                                                                                                                                    
runArgs.inputGeneratorFile=runName+'._00001.events.tar.gz'                                                                                                              
evgenConfig.contact = ["Marie-Helene Genest <mgenest@cern.ch>"]

include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_MadGraph.py")

#particle data = name antiname spin=2s+1 3xcharge colour mass width (left out, so set to 0: mMin mMax tau0)
genSeq.Pythia8.Commands += ["1000022:all = chid chid~ 2 0 0 %d 0" %(mDM),
                            "1000022:isVisible = false"]
