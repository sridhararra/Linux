# Makefile, Ch 2
#--------------------------------------------------------------
# This program is part of the source code released for the book
#  "Hands-on System Programming with Linux"
#  (c) Author: Kaiwan N Billimoria
#  Publisher:  Packt
#
# From: Ch 2 : Virtual Memory
#----------------------------------------------------------------------
ALL :=  mem_app1buggy mem_app1buggy_dbg \
	stacker stacker_dbg

CC=gcc
CFLAGS=-Wall
CFLAGS_DBG=-g -ggdb -gdwarf-4 -O0 -Wall -Wextra

all: ${ALL}
CB_FILES := *.[ch]

mem_app1buggy: mem_app1buggy.o
	gcc ${CFLAGS} -o mem_app1buggy mem_app1buggy.c
mem_app1buggy_dbg.o: mem_app1buggy.c
	gcc ${CFLAGS_DBG} -c mem_app1buggy.c -o mem_app1buggy_dbg.o
mem_app1buggy_dbg: mem_app1buggy_dbg.o
	gcc -o mem_app1buggy_dbg mem_app1buggy_dbg.o

stacker: stacker.o
	${CC} ${CFLAGS} -o stacker stacker.c
stacker_dbg.o: stacker.c
	${CC} ${CFLAGS_DBG} -c stacker.c -o stacker_dbg.o
stacker_dbg: stacker_dbg.o
	${CC} -o stacker_dbg stacker_dbg.o

# indent- "beautifies" C code into the "Linux kernel style".
# (cb = C Beautifier :) )
# Note! original source file(s) is overwritten, so we back it up.
cb: ${CB_FILES}
	mkdir bkp 2> /dev/null; cp -f ${CB_FILES} bkp/
	indent -linux ${CB_FILES}

clean:
	rm -vf ${ALL} core* vgcore* *.o *~
