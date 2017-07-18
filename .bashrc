# .bashrc
source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.20/x86_64-slc6-gcc47-opt/root/bin/thisroot.sh
export LD_LIBRARY_PATH="/home/shepj/lib"
export AtlasSetup="/afs/cern.ch/atlas/software/dist/AtlasSetup"
alias asetup="source $AtlasSetup/scripts/asetup.sh"
export LD_LIBRARY_PATH="/home/shepj/Herwig++-2.7.1/Contrib/rootsimple2"

asetup 17.5.0,opt --testarea=/home/shepj/
