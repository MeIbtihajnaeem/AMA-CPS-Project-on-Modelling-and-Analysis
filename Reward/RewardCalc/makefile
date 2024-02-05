OBJS=RewardCalcPVNodes.o RewardCalcPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRewardCalcPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRewardCalcPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRewardCalcPV.a: FORCE
	$(MAKE) lib TARGET=libRewardCalcPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRewardCalcPV_debug.a: FORCE
	$(MAKE) lib TARGET=libRewardCalcPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

