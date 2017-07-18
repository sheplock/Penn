## Base config for Sherpa
from Sherpa_i.Sherpa_iConf import Sherpa_i
genSeq += Sherpa_i()
evgenConfig.generators = ["Sherpa"]
evgenConfig.auxfiles = []

## Tell Sherpa to write logs into a separate file
## (need for production, looping job detection, Wolfgang Ehrenfeld)
genSeq.Sherpa_i.Parameters += ["LOG_FILE=sherpa.log"]

## General ATLAS parameters
genSeq.Sherpa_i.Parameters += [
    "MASS[6]=172.5",
    "MASS[23]=91.1876",
    "MASS[24]=80.399",
    "WIDTH[23]=2.4952",
    "WIDTH[24]=2.085",
    "SIN2THETAW=0.23113",
    "MAX_PROPER_LIFETIME=10.0"
    ]

## Set the Sherpa run card
if not "sherpaRunCard" in dir() or not sherpaRunCard:
    logging.error("You have to specify the sherpaRunCard variable before including the Sherpa JO base fragment.")
    exit(1)
try:
    f = open("Run.dat", "w")
    f.write(sherpaRunCard)
    f.close()
except:
    logging.error("Failed to write out to Run.dat.")
    exit(1)
