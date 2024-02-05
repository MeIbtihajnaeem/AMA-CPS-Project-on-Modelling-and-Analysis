OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lgenMain
MAINLIB_debug=-lgenMain_debug
SIMLIB=gen
SIMLIB_debug=gen_debug
SIMLIB_trace=gen_trace
PROJECTLIBS=-lsetStudySetStudy -lRewardCalcPV -lAtomicModelSAN 
PROJECTLIBS_debug=-lsetStudySetStudy_debug -lRewardCalcPV_debug -lAtomicModelSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
ssgGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=ssgGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
ssgGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=ssgGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
ssgGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=ssgGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/AtomicModel/ && $(MAKE) clean
	cd ../../Reward/RewardCalc/ && $(MAKE) clean
	cd ../../Study/setStudy/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[AtomicModel]"
	cd ../../Atomic/AtomicModel/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[RewardCalc]"
	cd ../../Reward/RewardCalc/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[setStudy]"
	cd ../../Study/setStudy/ && $(MAKE) $(@F)


