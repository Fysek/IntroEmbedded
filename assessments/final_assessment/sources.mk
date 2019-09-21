#*****************************************************************************  
# Copyright 2019 Mateusz Dyrdół
#
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
#*****************************************************************************<F9>

ifeq ($(PLATFORM),HOST)
	SOURCES  = memory.c \
		   main.c \
		   data.c \
		   stats.c \
		   memory.c \
		   course1.c \

        INCLUDES = -I../include/common
else
	SOURCES = system_msp432p401r.c \
		  startup_msp432p401r_gcc.c \
		  main.c \
		  data.c \
		  stats.c \
		  memory.c \
		  course1.c \
		  interrupts_msp432p401r_gcc.c

	INCLUDES = -I../include/common \
		   -I../include/CMSIS \
	           -I../include/msp432
endif
