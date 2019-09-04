#*****************************************************************************
# Copyright 2019 Mateusz Dyrdół
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction,including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# *****************************************************************************

#------------------------------------------------------------------------------
# Simple make file to compile c source files for two targets. Supports host machine and
# the msp432 plaform based on the platform overrides.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	%.i - Generates the preprocessed .i file from ite corresounding c file . Eg make main.i PLATFORM=MSP432
# 	$.o - Generates the object file from the corresponding c file. Eg make main.o PLATFORM=MSP432
# 	%.asm - Genrates the assembly listing of an object file using objdump. Eg make main.asm PLATFORM=MSP432
# 	compile-all -  Compiles all c files to objects files without linking. Eg make compile-all PLATFORM=MSP432
# 	build - Compiles and links all the c files to form the final executable file. Eg make build PLATFORM=MSP432
#
# Platform Overrides:
# 	PLATFORM=HOST   - Compiles for the host machine.( Default value )
# 	PLATFORM=MSP432 - Crosscompiles for the MSP432 target.
#
#------------------------------------------------------------------------------

# Platform Overrides
# By default compile for host. ie native compilation
PLATFORM = HOST

TARGET = c1m2

include sources.mk

LINKER_FILE = ../msp432p401r.lds

# General FLags
CCGF = -Wall -Werror -g -O0 -std=c99
DFLAG = -MM

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST) # Native Compilation
        CC = gcc
        LD = ld
        OBJDUMP = objdump
        LDFLAGS = 
        CFLAGS  = $(INCLUDES) 
        CPPFLAGS = -D$(PLATFORM)
        SIZE    = size
else ifeq ($(PLATFORM),MSP432) # Cross Compilation
        CPU   = cortex-m4
        IS    = -mthumb
        ARCH  = -march=armv7e-m
        FLOAT = -mfloat-abi=hard
        FPU   = -mfpu=fpv4-sp-d16
        SPECS = nosys.specs
        CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        OBJDUMP = arm-none-eabi-objdump
        LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
        CFLAGS  = -mcpu=$(CPU) $(ARCH) $(FLOAT) $(FPU) $(IS) --specs=$(SPECS) -Wall -D$(PLATFORM) $(INCLUDES)
        CPPFLAGS = -D$(PLATFORM)
        SIZE   = arm-none-eabi-size
else
        $(error Unsupported Platform specified. Supported are PLATFORM=HOST or PLATFORM=MSP432. Given PLATFORM=$(PLATFORM))
endif

OBJS = $(SOURCES:.c=.o)

.PHONY: clean compile-all build size

%.i: %.c
	$(CC) $(CCGF) $(CFLAGS) $(CPPFLAGS) -E -o $@ -c $<

%.o: %.c
	$(CC) $(CCGF) $(CFLAGS) $(CPPFLAGS)  -o $@ -c $<
	$(CC) $(CCGF) $(CFLAGS) $(CPPFLAGS) $(DFLAG) -o $*.d $<

%.asm: %.o
	$(OBJDUMP) -S $< > $*.asm

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -S $< > $@

compile-all: $(OBJS)

build: $(TARGET).out size

size: $(TARGET).out
	$(SIZE) $<

$(TARGET).out: $(OBJS)
	$(CC) $(CCGF) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $@ 
	
clean:
	rm -f *.i *.o *.d *.out *.map *.asm
