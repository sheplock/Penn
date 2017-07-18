from MadGraphControl.MadGraphUtils import *

fcard = open('proc_card_mg5.dat','w')

ickkw=1
xqcut = 20
qcut = 30

if not hasattr(runArgs,'runNumber'): 
  raise RunTimeError("No run number found.")

#--------------------------------------------------------------
# MG5 Proc card
#--------------------------------------------------------------
if (runArgs.runNumber==158813 or runArgs.runNumber==158814):
    fcard.write("""
    import model sm
    define p = g u c d s u~ c~ d~ s~
    define j = g u c d s b u~ c~ d~ s~ b~
    define l+ = e+ mu+ ta+
    define l- = e- mu- ta-
    define vl = ve vm vt
    define vl~ = ve~ vm~ vt~
    generate p p > t t~ w+ w- @1
    output -f
    """)
    fcard.close()
    iexcfile=0
    name="ttbarWW"
else:
  raise RunTimeError("Invalid run number. Use 158813 or 158814")

#--------------------------------------------------------------
# Beam energy
#--------------------------------------------------------------
### As suggested by MC generator experts
beamEnergy=4000
if hasattr(runArgs,'ecmEnergy'): 
  beamEnergy = runArgs.ecmEnergy / 2.
else:
  raise RunTimeError("No center of mass energy found.")



#Default Scales
isFixedRenScale="F"
isFixedFacScale="F"

scale=91.1880

renScale =scale
facScale1=scale
facScale2=scale


#--------------------------------------------------------------
# Choice of PDF set 
#--------------------------------------------------------------
doMSTW08PDFSet = None
if runArgs.runNumber==158814:
  doMSTW08PDFSet = True
if runArgs.runNumber==158813:
  doMSTW08PDFSet = False

pdfSet ='lhapdf' #default set to 'cteq6l1'
pdfNumber =21000 # for lhaid 

#--------------------------------------------------------------
# MG5 + Pythia8 setup and process (lhe) generation
#--------------------------------------------------------------
# Grab the run card and move it into place
runcard = subprocess.Popen(['get_files','-data','run_card.SM.dat'])
runcard.wait()
if not os.access('run_card.SM.dat',os.R_OK):
    print 'ERROR: Could not get run card'
elif os.access('run_card.dat',os.R_OK):
    print 'ERROR: Old run card in the current directory.  Dont want to clobber it.  Please move it first.'
else:
    oldcard = open('run_card.SM.dat','r')
    newcard = open('run_card.dat','w')
    for line in oldcard:
        if ' = xqcut ' in line:
            newcard.write('%f   = xqcut   ! minimum kt jet measure between partons \n'%(xqcut))
        elif ' = nevents ' in line:
            newcard.write('  %i       = nevents ! Number of unweighted events requested \n'%(20000))
        elif ' = iseed ' in line:
            newcard.write('   %i      = iseed   ! rnd seed (0=assigned automatically=default)) \n'%(runArgs.randomSeed))
        elif ' = xptj ' in line:
            newcard.write('   %f      = xptj ! minimum pt for at least one jet \n'%(xqcut))
        elif ' = ebeam1 ' in line:
            newcard.write('   %i      = ebeam1  ! beam 1 energy in GeV \n'%(int(beamEnergy)))
        elif ' = ickkw' in line:
            newcard.write('  %i         = ickkw   ! 0 no matching, 1 MLM, 2 CKKW matching \n'%(0))
        elif ' = xqcut' in line:
            newcard.write('  %.1f       = xqcut   ! minimum kt jet measure between partons \n'%(0.))
        elif ' auto_ptj_mjj' in line:
            line=line.replace("T","F")+'\n'
            newcard.write(line)
        elif ' cut_decays' in line:
            line=line.replace("T","F")+'\n'
            newcard.write(line)
        elif ' pdfwgt' in line:
            line=line.replace("T","F")+'\n'
            newcard.write(line)
        elif ' = iseed' in line:
            newcard.write('   %i      = iseed   ! rnd seed (0=assigned automatically=default)) \n'%(runArgs.randomSeed))        
        elif ' = pdlabel ' in line:
            if doMSTW08PDFSet:
                newcard.write('   \'%s\'      = pdlabel ! PDF set\n   %d      = lhaid       ! PDF number used ONLY for LHAPDF\n' \
                    % (str(pdfSet), int(pdfNumber)))
            else:
              newcard.write(line)
        elif ' = ebeam2 ' in line:
            newcard.write('   %i      = ebeam2  ! beam 2 energy in GeV \n'%(int(beamEnergy)))
        else:
            newcard.write(line)
    oldcard.close()
    newcard.close()

#print "proc card:"
#print fcard
##MD print "Modified run_card.dat:"
##MD rcard = open('run_card.dat','r')
##MD print rcard.read()
##MD rcard.close()


process_dir = new_process()

generate(run_card_loc='run_card.dat',param_card_loc=None,mode=0,njobs=1,run_name='Test',proc_dir=process_dir)

stringy = 'madgraph.'+str(runArgs.runNumber)+'.MadGraph_'+str(name)

skip_events=0
if hasattr(runArgs,'skipEvents'): skip_events=runArgs.skipEvents
arrange_output(run_name='Test',proc_dir=process_dir,outputDS=stringy+'._00001.events.tar.gz',skip_events=skip_events)


#--------------------------------------------------------------
# MC12 metadata --> MC14 metadata ?? 
#--------------------------------------------------------------

evgenConfig.description = 'MadGraph_'+str(name)
#evgenConfig.keywords = ["SM","ttbarWW", "SameSignDileptonBkg"]
evgenConfig.keywords = ["SM"]
evgenConfig.contact  = [ "venkat.kaushik@cern.ch" ]
evgenConfig.inputfilecheck = stringy
runArgs.inputGeneratorFile=stringy+'._00001.events.tar.gz'

#--------------------------------------------------------------
# General MC12 configuration
#--------------------------------------------------------------
if doMSTW08PDFSet:
  include("MC14JobOptions/Pythia8_AU2_MSTW2008LO_Common.py")
else:
  include("MC14JobOptions/Pythia8_AU2_CTEQ6L1_Common.py")

include ("MC14JobOptions/Pythia8_MadGraph.py")

genSeq.Pythia8.Commands += ["Init:showAllParticleData = on",
                            "Next:numberShowLHA = 10",
                            "Next:numberShowEvent = 10"]

