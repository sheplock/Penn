## Energy-specific UE tune handling for JIMMY with the AUET2 CTEQ6L1 tune

## Calculate the energy-specific pT cutoff using the standard ansatz with tuned coeff and exponent
__ptjim = 3.224 * (runArgs.ecmEnergy/1800.)**0.231

## Set params
genSeq.Herwig.HerwigCommand += [
    # PDF
    "modpdf 10042",     # CTEQ6L1 PDF
    "autpdf HWLHAPDF",  # External PDF library
    # AUET2 (CTEQ6L1) tune settings
    "ispac 2",          # ISR-shower scheme
    "qspac 2.5",        # ISR shower cut-off (default value)
    "ptrms 1.2",        # Primordial kT
    "ptjim %f" % __ptjim, # Min pT of secondary scatters, calculated above
    "jmrad 73 2.386",   # Inverse proton radius squared
    "prsof 0",          # Soft underlying event off (HERWIG parameter)
    ]

del __ptjim

evgenConfig.tune = "AUET2 CTEQ6L1"
