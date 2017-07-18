## Common fragment to specify exclusive Z->ee decays in PYTHIA
assert hasattr(genSeq, "Pythia")
genSeq.Pythia.PythiaCommand += ["pydat3 mdme 174 1 0",
                                "pydat3 mdme 175 1 0",
                                "pydat3 mdme 176 1 0",
                                "pydat3 mdme 177 1 0",
                                "pydat3 mdme 178 1 0",
                                "pydat3 mdme 179 1 0",
                                "pydat3 mdme 182 1 1",
                                "pydat3 mdme 183 1 0",
                                "pydat3 mdme 184 1 0",
                                "pydat3 mdme 185 1 0",
                                "pydat3 mdme 186 1 0",
                                "pydat3 mdme 187 1 0"]



