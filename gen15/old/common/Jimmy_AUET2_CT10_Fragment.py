## Energy-specific UE tune handling for JIMMY with the AUET2 CT10 tune

## Calculate the energy-specific pT cutoff using the standard ansatz with tuned coeff and exponent
__ptjim = 2.642 * (runArgs.ecmEnergy/1800.)**0.214

## Set params
genSeq.Herwig.HerwigCommand += [
    # PDF
    "modpdf 10800",     # CT10 (NLO) PDF
    "autpdf HWLHAPDF",  # External PDF library
    # AUET2 (CT10) tune settings
    "ispac 2",          # ISR-shower scheme
    "qspac 2.5",        # ISR shower cut-off (default value)
    "ptrms 1.2",        # Primordial kT
    "ptjim %f" % __ptjim, # Min pT of secondary scatters, calculated above
    "jmrad 73 2.432",   # Inverse proton radius squared
    "prsof 0",          # Soft underlying event off (HERWIG parameter)
    ]

del __ptjim

evgenConfig.tune = "AUET2 CT10"
