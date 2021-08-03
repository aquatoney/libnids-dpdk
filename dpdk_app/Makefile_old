SHELL := /bin/bash


### TARGET ###
BUILD_DIR = ./build/
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


### SOURCE FILES ###

ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif
NIDS_DIR = $(PWD)/../src
# SRCS = main.c callback.c $(NIDS_DIR)/libnids.a
SRCS =  main.c callback.c
# SRCS += $(NIDS_DIR)/libnids.a
SRCS += $(NIDS_DIR)/allpromisc.c $(NIDS_DIR)/hash.c $(NIDS_DIR)/ip_options.c \
				$(NIDS_DIR)/checksum.c $(NIDS_DIR)/tcp.c $(NIDS_DIR)/libnids.c \
				$(NIDS_DIR)/ip_fragment.c $(NIDS_DIR)/killtcp.c $(NIDS_DIR)/scan.c \
				$(NIDS_DIR)/util.c 
# DPDK LIBRARY and HEADER
RTE_TARGET ?= x86_64-native-linuxapp-gcc
DPDK_INC = -I$(NIDS_DIR)
# DPDK_INC=$(RTE_SDK)/$(RTE_TARGET)/include
# DPDK_LIB=$(RTE_SDK)/$(RTE_TARGET)/lib/
include $(RTE_SDK)/mk/rte.vars.mk

CFLAGS += -O3
CFLAGS += $(DPDK_INC)
CFLAGS += -DXL710

CFLAGS += -D_BSD_SOURCE -DLIBNET_VER=-1 -DHAVE_ICMPHDR=1 -DHAVE_TCP_STATES=1 -DHAVE_BSD_UDPHDR=1

SRCS-y := $(SRCS)
include $(RTE_SDK)/mk/rte.extapp.mk

# $(NIDS_DIR)/libnids.a:
# 	cd $(NIDS_DIR)/.. && ./configure --disable-libglib --disable-libnet && $(MAKE) -C .
