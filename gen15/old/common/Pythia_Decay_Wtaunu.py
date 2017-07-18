## Common fragment to specify exclusive W->tau,nu decays in PYTHIA
assert hasattr(genSeq, "Pythia")
genSeq.Pythia.PythiaCommand += ["pydat3 mdme 190 1 0", # du
                                "pydat3 mdme 191 1 0", # dc
                                "pydat3 mdme 192 1 0", # dt
                                "pydat3 mdme 194 1 0", # su
                                "pydat3 mdme 195 1 0", # sc
                                "pydat3 mdme 196 1 0", # st
                                "pydat3 mdme 198 1 0", # bu
                                "pydat3 mdme 199 1 0", # bc
                                "pydat3 mdme 200 1 0", # bt
                                "pydat3 mdme 206 1 0", # e,nu
                                "pydat3 mdme 207 1 0", # mu,nu
                                "pydat3 mdme 208 1 1"] # tau,nu


