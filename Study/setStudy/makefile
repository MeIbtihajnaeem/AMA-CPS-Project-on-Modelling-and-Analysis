OBJS=setStudySetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libsetStudySetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libsetStudySetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libsetStudySetStudy.a: FORCE
	$(MAKE) lib TARGET=libsetStudySetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libsetStudySetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libsetStudySetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

