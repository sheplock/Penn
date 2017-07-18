#-- start of make_header -----------------

#====================================
#  Document check_install_nonStandardjobOptions
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

cmt_check_install_nonStandardjobOptions_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_check_install_nonStandardjobOptions_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_check_install_nonStandardjobOptions

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_check_install_nonStandardjobOptions = $(MC15JobOptions_tag)_check_install_nonStandardjobOptions.make
cmt_local_tagfile_check_install_nonStandardjobOptions = $(bin)$(MC15JobOptions_tag)_check_install_nonStandardjobOptions.make

else

tags      = $(tag),$(CMTEXTRATAGS)

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_check_install_nonStandardjobOptions = $(MC15JobOptions_tag).make
cmt_local_tagfile_check_install_nonStandardjobOptions = $(bin)$(MC15JobOptions_tag).make

endif

include $(cmt_local_tagfile_check_install_nonStandardjobOptions)
#-include $(cmt_local_tagfile_check_install_nonStandardjobOptions)

ifdef cmt_check_install_nonStandardjobOptions_has_target_tag

cmt_final_setup_check_install_nonStandardjobOptions = $(bin)setup_check_install_nonStandardjobOptions.make
cmt_dependencies_in_check_install_nonStandardjobOptions = $(bin)dependencies_check_install_nonStandardjobOptions.in
#cmt_final_setup_check_install_nonStandardjobOptions = $(bin)MC15JobOptions_check_install_nonStandardjobOptionssetup.make
cmt_local_check_install_nonStandardjobOptions_makefile = $(bin)check_install_nonStandardjobOptions.make

else

cmt_final_setup_check_install_nonStandardjobOptions = $(bin)setup.make
cmt_dependencies_in_check_install_nonStandardjobOptions = $(bin)dependencies.in
#cmt_final_setup_check_install_nonStandardjobOptions = $(bin)MC15JobOptionssetup.make
cmt_local_check_install_nonStandardjobOptions_makefile = $(bin)check_install_nonStandardjobOptions.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)MC15JobOptionssetup.make

#check_install_nonStandardjobOptions :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'check_install_nonStandardjobOptions'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = check_install_nonStandardjobOptions/
#check_install_nonStandardjobOptions::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of cmt_action_runner_header ---------------

ifdef ONCE
check_install_nonStandardjobOptions_once = 1
endif

ifdef check_install_nonStandardjobOptions_once

check_install_nonStandardjobOptionsactionstamp = $(bin)check_install_nonStandardjobOptions.actionstamp
#check_install_nonStandardjobOptionsactionstamp = check_install_nonStandardjobOptions.actionstamp

check_install_nonStandardjobOptions :: $(check_install_nonStandardjobOptionsactionstamp)
	$(echo) "check_install_nonStandardjobOptions ok"
#	@echo check_install_nonStandardjobOptions ok

#$(check_install_nonStandardjobOptionsactionstamp) :: $(check_install_nonStandardjobOptions_dependencies)
$(check_install_nonStandardjobOptionsactionstamp) ::
	$(silent) /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/cmt/atlas_check_installations.sh -files=' ../nonStandard/Pythia8/*.py ../nonStandard/Photos/*.py ../nonStandard/Herwigpp/*.py ../nonStandard/Pythia/*.py ../nonStandard/Sherpa/*.py ' -installdir=/home/shepj/InstallArea/jobOptions/MC15JobOptions/nonStandard -level=warning
	$(silent) cat /dev/null > $(check_install_nonStandardjobOptionsactionstamp)
#	@echo ok > $(check_install_nonStandardjobOptionsactionstamp)

check_install_nonStandardjobOptionsclean ::
	$(cleanup_silent) /bin/rm -f $(check_install_nonStandardjobOptionsactionstamp)

else

#check_install_nonStandardjobOptions :: $(check_install_nonStandardjobOptions_dependencies)
check_install_nonStandardjobOptions ::
	$(silent) /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.5/AtlasCore/20.1.5/External/ExternalPolicy/cmt/atlas_check_installations.sh -files=' ../nonStandard/Pythia8/*.py ../nonStandard/Photos/*.py ../nonStandard/Herwigpp/*.py ../nonStandard/Pythia/*.py ../nonStandard/Sherpa/*.py ' -installdir=/home/shepj/InstallArea/jobOptions/MC15JobOptions/nonStandard -level=warning

endif

install ::
uninstall ::

#-- end of cmt_action_runner_header -----------------
#-- start of cleanup_header --------------

clean :: check_install_nonStandardjobOptionsclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(check_install_nonStandardjobOptions.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

check_install_nonStandardjobOptionsclean ::
#-- end of cleanup_header ---------------
