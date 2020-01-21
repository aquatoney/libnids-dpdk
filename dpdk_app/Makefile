SHELL := /bin/bash


### TARGET ###
APP = procpkts

### GCC ###
GCC = gcc
GCC_OPT = -m64 # -Wall -DNEWEV -Werror

#DBG_OPT = -DDBGMSG -DDBGFUNC -DSTREAM -DSTATE -DTSTAT -DAPP -DEPOLL
#DBG_OPT = -DDBGMSG -DDBGFUNC -DSTREAM -DSTATE
#DBG_OPT += -DPKTDUMP
#DBG_OPT += -DDUMP_STREAM
#GCC_OPT += -g -DNETSTAT -DINFO -DDBGERR -DDBGCERR
GCC_OPT += -DNDEBUG -O3 -DNETSTAT -DINFO -DDBGERR -DDBGCERR
GCC_OPT += $(DBG_OPT)

### LIBRARIES AND INCLUDES ###
INC_DIR = ../src
INC= -I$(INC_DIR)

### SOURCE FILES ###
SRCS = dpdk_main.c callback.c ../src/libnids.a

ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif
# DPDK LIBRARY and HEADER
RTE_TARGET ?= x86_64-native-linuxapp-gcc
DPDK_INC=$(RTE_SDK)/$(RTE_TARGET)/include
DPDK_LIB=$(RTE_SDK)/$(RTE_TARGET)/lib/
include $(RTE_SDK)/mk/rte.vars.mk

DPDK_MACHINE_FLAGS=$(MACHINE_CFLAGS)
DPDK_LIB_FLAGS = -ldpdk -ldl -lnuma -lpthread -lnids -lgthread-2.0 -lnsl -lpcap -lnet

INC += ${DPDK_MACHINE_FLAGS} -I${DPDK_INC} -include $(DPDK_INC)/rte_config.h
LIBS += -L$(DPDK_LIB) -L$(INC_DIR)
LIB_FLAGS += $(DPDK_LIB_FLAGS)


### GOALS ###
all: $(APP)

$(APP): $(SRCS)
	$(GCC) $(GCC_OPT) -o $@ $^ $(INC) $(LIBS) $(LIB_FLAGS)

../src/libnids.a:
	cd .. & ./configure --disable-libglib & $(MAKE) -C ..

clean:
	-$(RM) procpkts
	$(MAKE) -C .. clean

distclean: clean
	$(MAKE) -C .. distclean

.PHONY: all clean
