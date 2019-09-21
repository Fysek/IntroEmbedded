#******************************************************************************
# Copyright (C) 2017 by Mateusz Dyrdol
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk



TARGET = c1m4

ifeq ($(PLATFORM),MSP432)
SOURCES := $(SOURCES) \
    src/interrupts_msp432p401r_gcc.c \
    src/startup_msp432p401r_gcc.c \
    src/system_msp432p401r.c 

CC = arm-none-eabi-gcc
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH=thumb
MARCH =armv7e-m
FLOAT_ABI = hard
FPU = fpv4-sp-d16
LD = arm-none-eabi-ld
SPECS = nosys.specs
 
# Compiler Flags and Defines
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CPPFLAGS = -MD -MP
ARCHFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) --specs=$(SPECS) -DMSP432
CFLAGS = $(ARCHFLAGS)-std=c99  -Wall -g 
OBJDUMP = arm-none-eabi-objdump
endif

ifeq ($(PLATFORM), HOST)
  CC = gcc
  LD = ld
  CFLAGS = -std=c99 -Wall -g -MD -DHOST
  LDFLAGS = -Wl,-O0,-Map=$(TARGET).map
  OBJDUMP = objdump
endif

OBJS = $(SRCS:.c=.o)
DEPS = $(SOURCES:.c=.d)


%.o : %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@
	
%.i :%.c
	$(CC) -E $^ $(CFLAGS) $(INCLUDES) -o $@
	
%.asm: %.c compile-all
	$(CC) -S $< $(CFLAGS) $(INCLUDES) -o $@; $(OBJDUMP) -x $(basename $<).o




.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $^ $(CFLAGS) $(INCLUDES)

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $^ > $*.d; $(OBJDUMP) -x $@ > $(basename $@).asm

	
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(TARGET).asm $(TARGET).o $(TARGET).i $(TARGET).d

