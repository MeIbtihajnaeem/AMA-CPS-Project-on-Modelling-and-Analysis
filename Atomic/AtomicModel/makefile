OBJS=AtomicModelSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAtomicModelSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAtomicModelSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAtomicModelSAN.a: FORCE
	$(MAKE) lib TARGET=libAtomicModelSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAtomicModelSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libAtomicModelSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

