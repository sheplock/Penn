from TruthIO.TruthIOConf import HepMCReadFromFile
genSeq += HepMCReadFromFile()
genSeq.HepMCReadFromFile.AsciiFile = "events.hepmc"
evgenConfig.generators += ["HepMCAscii"]
