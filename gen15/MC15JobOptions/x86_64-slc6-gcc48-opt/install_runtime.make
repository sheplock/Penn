#-- start of make_header -----------------

#====================================
#  Document install_runtime
#
#   Generated Wed Jun 22 11:49:54 2016  by shepj
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_install_runtime_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_install_runtime_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_install_runtime

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_install_runtime = $(MC15JobOptions_tag)_install_runtime.make
cmt_local_tagfile_install_runtime = $(bin)$(MC15JobOptions_tag)_install_runtime.make

else

tags      = $(tag),$(CMTEXTRATAGS)

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_install_runtime = $(MC15JobOptions_tag).make
cmt_local_tagfile_install_runtime = $(bin)$(MC15JobOptions_tag).make

endif

include $(cmt_local_tagfile_install_runtime)
#-include $(cmt_local_tagfile_install_runtime)

ifdef cmt_install_runtime_has_target_tag

cmt_final_setup_install_runtime = $(bin)setup_install_runtime.make
cmt_dependencies_in_install_runtime = $(bin)dependencies_install_runtime.in
#cmt_final_setup_install_runtime = $(bin)MC15JobOptions_install_runtimesetup.make
cmt_local_install_runtime_makefile = $(bin)install_runtime.make

else

cmt_final_setup_install_runtime = $(bin)setup.make
cmt_dependencies_in_install_runtime = $(bin)dependencies.in
#cmt_final_setup_install_runtime = $(bin)MC15JobOptionssetup.make
cmt_local_install_runtime_makefile = $(bin)install_runtime.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)MC15JobOptionssetup.make

#install_runtime :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'install_runtime'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = install_runtime/
#install_runtime::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------


ifeq ($(INSTALLAREA),)
installarea = $(CMTINSTALLAREA)
else
ifeq ($(findstring `,$(INSTALLAREA)),`)
installarea = $(shell $(subst `,, $(INSTALLAREA)))
else
installarea = $(INSTALLAREA)
endif
endif

install_dir = ${installarea}/share

install_runtime :: install_runtimeinstall ;

install :: install_runtimeinstall ;

install_runtimeclean :: install_runtimeuninstall

uninstall :: install_runtimeuninstall


# This is to avoid error in case there are no files to install
# Ideally, the fragment should not be used without files to install,
# and this line should be dropped then
install_runtimeinstall :: ;

param_card.SM.BB.direct_dat_dependencies = ../susycontrol/param_card.SM.BB.direct.dat
param_card.SM.BB.onestepN2_dat_dependencies = ../susycontrol/param_card.SM.BB.onestepN2.dat
param_card.SM.GG.ttn1OnShellt1_dat_dependencies = ../susycontrol/param_card.SM.GG.ttn1OnShellt1.dat
param_card.SM.GG.bbn1_dat_dependencies = ../susycontrol/param_card.SM.GG.bbn1.dat
param_card.SM.GG.directGtc_dat_dependencies = ../susycontrol/param_card.SM.GG.directGtc.dat
param_card.SM.TT.mixedBT_dat_dependencies = ../susycontrol/param_card.SM.TT.mixedBT.dat
param_card.SM.GG.direct_dat_dependencies = ../susycontrol/param_card.SM.GG.direct.dat
param_card.SM.TT.onestepBB_dat_dependencies = ../susycontrol/param_card.SM.TT.onestepBB.dat
param_card.SM.GG.ttn1_dat_dependencies = ../susycontrol/param_card.SM.GG.ttn1.dat
param_card.SM.C1N2.Slep_dat_dependencies = ../susycontrol/param_card.SM.C1N2.Slep.dat
param_card.HeavyScalar_dat_dependencies = ../susycontrol/param_card.HeavyScalar.dat
param_card.SM.C1N2.WZ_original_dat_dependencies = ../susycontrol/param_card.SM.C1N2.WZ_original.dat
param_card.SM.SS.direct_dat_dependencies = ../susycontrol/param_card.SM.SS.direct.dat
param_card.SM.GG.2stepWZ_dat_dependencies = ../susycontrol/param_card.SM.GG.2stepWZ.dat
param_card.SM.GG.onestepN2_dat_dependencies = ../susycontrol/param_card.SM.GG.onestepN2.dat
param_card.SM.TT.directTT_dat_dependencies = ../susycontrol/param_card.SM.TT.directTT.dat
param_card.SM.C1N2.Stau_dat_dependencies = ../susycontrol/param_card.SM.C1N2.Stau.dat
param_card.SM.GG.onestepbbN2_dat_dependencies = ../susycontrol/param_card.SM.GG.onestepbbN2.dat
param_card.SM.GG.onestepCC_dat_dependencies = ../susycontrol/param_card.SM.GG.onestepCC.dat
param_card.SM.SS.onestepN2_dat_dependencies = ../susycontrol/param_card.SM.SS.onestepN2.dat
param_card.SM.C1N2.WZ_dat_dependencies = ../susycontrol/param_card.SM.C1N2.WZ.dat


install_runtimeinstall :: ${install_dir}/param_card.SM.BB.direct.dat ;

${install_dir}/param_card.SM.BB.direct.dat :: ../susycontrol/param_card.SM.BB.direct.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.BB.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.BB.direct.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.BB.direct.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.BB.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.BB.direct.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.BB.onestepN2.dat ;

${install_dir}/param_card.SM.BB.onestepN2.dat :: ../susycontrol/param_card.SM.BB.onestepN2.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.BB.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.BB.onestepN2.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.BB.onestepN2.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.BB.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.BB.onestepN2.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.ttn1OnShellt1.dat ;

${install_dir}/param_card.SM.GG.ttn1OnShellt1.dat :: ../susycontrol/param_card.SM.GG.ttn1OnShellt1.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.ttn1OnShellt1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.ttn1OnShellt1.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.ttn1OnShellt1.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.ttn1OnShellt1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.ttn1OnShellt1.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.bbn1.dat ;

${install_dir}/param_card.SM.GG.bbn1.dat :: ../susycontrol/param_card.SM.GG.bbn1.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.bbn1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.bbn1.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.bbn1.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.bbn1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.bbn1.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.directGtc.dat ;

${install_dir}/param_card.SM.GG.directGtc.dat :: ../susycontrol/param_card.SM.GG.directGtc.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.directGtc.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.directGtc.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.directGtc.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.directGtc.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.directGtc.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.TT.mixedBT.dat ;

${install_dir}/param_card.SM.TT.mixedBT.dat :: ../susycontrol/param_card.SM.TT.mixedBT.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.mixedBT.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.TT.mixedBT.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.TT.mixedBT.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.mixedBT.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.TT.mixedBT.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.direct.dat ;

${install_dir}/param_card.SM.GG.direct.dat :: ../susycontrol/param_card.SM.GG.direct.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.direct.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.direct.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.direct.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.TT.onestepBB.dat ;

${install_dir}/param_card.SM.TT.onestepBB.dat :: ../susycontrol/param_card.SM.TT.onestepBB.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.onestepBB.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.TT.onestepBB.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.TT.onestepBB.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.onestepBB.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.TT.onestepBB.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.ttn1.dat ;

${install_dir}/param_card.SM.GG.ttn1.dat :: ../susycontrol/param_card.SM.GG.ttn1.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.ttn1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.ttn1.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.ttn1.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.ttn1.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.ttn1.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.C1N2.Slep.dat ;

${install_dir}/param_card.SM.C1N2.Slep.dat :: ../susycontrol/param_card.SM.C1N2.Slep.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.Slep.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.C1N2.Slep.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.C1N2.Slep.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.Slep.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.C1N2.Slep.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.HeavyScalar.dat ;

${install_dir}/param_card.HeavyScalar.dat :: ../susycontrol/param_card.HeavyScalar.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.HeavyScalar.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.HeavyScalar.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.HeavyScalar.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.HeavyScalar.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.HeavyScalar.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.C1N2.WZ_original.dat ;

${install_dir}/param_card.SM.C1N2.WZ_original.dat :: ../susycontrol/param_card.SM.C1N2.WZ_original.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.WZ_original.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.C1N2.WZ_original.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.C1N2.WZ_original.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.WZ_original.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.C1N2.WZ_original.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.SS.direct.dat ;

${install_dir}/param_card.SM.SS.direct.dat :: ../susycontrol/param_card.SM.SS.direct.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.SS.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.SS.direct.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.SS.direct.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.SS.direct.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.SS.direct.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.2stepWZ.dat ;

${install_dir}/param_card.SM.GG.2stepWZ.dat :: ../susycontrol/param_card.SM.GG.2stepWZ.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.2stepWZ.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.2stepWZ.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.2stepWZ.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.2stepWZ.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.2stepWZ.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.onestepN2.dat ;

${install_dir}/param_card.SM.GG.onestepN2.dat :: ../susycontrol/param_card.SM.GG.onestepN2.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.onestepN2.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.onestepN2.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.onestepN2.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.TT.directTT.dat ;

${install_dir}/param_card.SM.TT.directTT.dat :: ../susycontrol/param_card.SM.TT.directTT.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.directTT.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.TT.directTT.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.TT.directTT.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.TT.directTT.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.TT.directTT.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.C1N2.Stau.dat ;

${install_dir}/param_card.SM.C1N2.Stau.dat :: ../susycontrol/param_card.SM.C1N2.Stau.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.Stau.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.C1N2.Stau.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.C1N2.Stau.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.Stau.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.C1N2.Stau.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.onestepbbN2.dat ;

${install_dir}/param_card.SM.GG.onestepbbN2.dat :: ../susycontrol/param_card.SM.GG.onestepbbN2.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepbbN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.onestepbbN2.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.onestepbbN2.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepbbN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.onestepbbN2.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.GG.onestepCC.dat ;

${install_dir}/param_card.SM.GG.onestepCC.dat :: ../susycontrol/param_card.SM.GG.onestepCC.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepCC.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.GG.onestepCC.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.GG.onestepCC.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.GG.onestepCC.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.GG.onestepCC.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.SS.onestepN2.dat ;

${install_dir}/param_card.SM.SS.onestepN2.dat :: ../susycontrol/param_card.SM.SS.onestepN2.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.SS.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.SS.onestepN2.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.SS.onestepN2.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.SS.onestepN2.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.SS.onestepN2.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi


install_runtimeinstall :: ${install_dir}/param_card.SM.C1N2.WZ.dat ;

${install_dir}/param_card.SM.C1N2.WZ.dat :: ../susycontrol/param_card.SM.C1N2.WZ.dat
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.WZ.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_install_action) "$${d}" "param_card.SM.C1N2.WZ.dat" "$(install_dir)" "/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/src/symlink.sh" "$($(package)_cmtpath)"; \
	fi

../susycontrol/param_card.SM.C1N2.WZ.dat : ;

install_runtimeuninstall ::
	@if test ! "${installarea}" = ""; then \
	  d=`dirname ../susycontrol/param_card.SM.C1N2.WZ.dat`; \
	  d=`(cd $${d}; pwd)`; \
	  CMTINSTALLAREA=${CMTINSTALLAREA}; export CMTINSTALLAREA; \
	  $(cmt_uninstall_action) "$${d}" "param_card.SM.C1N2.WZ.dat" "$(install_dir)" "$($(package)_cmtpath)"; \
	fi
#-- start of cleanup_header --------------

clean :: install_runtimeclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(install_runtime.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

install_runtimeclean ::
#-- end of cleanup_header ---------------
