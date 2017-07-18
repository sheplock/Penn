#-- start of make_header -----------------

#====================================
#  Document install_nonStandardjobOptions
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

cmt_install_nonStandardjobOptions_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_install_nonStandardjobOptions_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_install_nonStandardjobOptions

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_install_nonStandardjobOptions = $(MC15JobOptions_tag)_install_nonStandardjobOptions.make
cmt_local_tagfile_install_nonStandardjobOptions = $(bin)$(MC15JobOptions_tag)_install_nonStandardjobOptions.make

else

tags      = $(tag),$(CMTEXTRATAGS)

MC15JobOptions_tag = $(tag)

#cmt_local_tagfile_install_nonStandardjobOptions = $(MC15JobOptions_tag).make
cmt_local_tagfile_install_nonStandardjobOptions = $(bin)$(MC15JobOptions_tag).make

endif

include $(cmt_local_tagfile_install_nonStandardjobOptions)
#-include $(cmt_local_tagfile_install_nonStandardjobOptions)

ifdef cmt_install_nonStandardjobOptions_has_target_tag

cmt_final_setup_install_nonStandardjobOptions = $(bin)setup_install_nonStandardjobOptions.make
cmt_dependencies_in_install_nonStandardjobOptions = $(bin)dependencies_install_nonStandardjobOptions.in
#cmt_final_setup_install_nonStandardjobOptions = $(bin)MC15JobOptions_install_nonStandardjobOptionssetup.make
cmt_local_install_nonStandardjobOptions_makefile = $(bin)install_nonStandardjobOptions.make

else

cmt_final_setup_install_nonStandardjobOptions = $(bin)setup.make
cmt_dependencies_in_install_nonStandardjobOptions = $(bin)dependencies.in
#cmt_final_setup_install_nonStandardjobOptions = $(bin)MC15JobOptionssetup.make
cmt_local_install_nonStandardjobOptions_makefile = $(bin)install_nonStandardjobOptions.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)MC15JobOptionssetup.make

#install_nonStandardjobOptions :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'install_nonStandardjobOptions'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = install_nonStandardjobOptions/
#install_nonStandardjobOptions::
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

install_dir = ${installarea}/jobOptions/MC15JobOptions/nonStandard

install_nonStandardjobOptions :: install_nonStandardjobOptionsinstall ;

install :: install_nonStandardjobOptionsinstall ;

install_nonStandardjobOptionsclean :: install_nonStandardjobOptionsuninstall

uninstall :: install_nonStandardjobOptionsuninstall


# This is to avoid error in case there are no files to install
# Ideally, the fragment should not be used without files to install,
# and this line should be dropped then
install_nonStandardjobOptionsinstall :: ;

#-- start of cleanup_header --------------

clean :: install_nonStandardjobOptionsclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(install_nonStandardjobOptions.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

install_nonStandardjobOptionsclean ::
#-- end of cleanup_header ---------------
