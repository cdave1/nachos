# use normal make for this Makefile
#
# Makefile for building user programs to run on top of Nachos
#
# Several things to be aware of:
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#

# if you are cross-compiling, you need to point to the right executables
# and change the flags to ld and the build procedure for as
GCCDIR = /vol/nachos/i386-NetBSD/xcomp/decstation-ultrix/bin/
LDFLAGS = -T script -N
# ASFLAGS = -mips
CPPFLAGS = $(INCDIR)


# if you aren't cross-compiling:
#GCCDIR =
#LDFLAGS = -N -T 0
ASFLAGS =
#CPPFLAGS = -P $(INCDIR)


CC = $(GCCDIR)gcc
AS = $(GCCDIR)as
LD = $(GCCDIR)ld

CPP = /usr/bin/cpp
INCDIR =-I../userprog -I../threads
CFLAGS = -G 0 -c $(INCDIR)

all: halt helloworld copyconsole catfile forktest exittest fail

start.o: start.s ../userprog/syscall.h
	$(CPP) $(CPPFLAGS) start.s > strt.s
	$(AS) $(ASFLAGS) -o start.o strt.s
	rm strt.s

halt.o: halt.c
	$(CC) $(CFLAGS) -c halt.c
halt: halt.o start.o
	$(LD) $(LDFLAGS) start.o halt.o -o halt.coff
	../bin/coff2noff halt.coff halt

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c helloworld.c
helloworld:  helloworld.o start.o
	$(LD) $(LDFLAGS) start.o helloworld.o -o helloworld.coff
	../bin/coff2noff helloworld.coff helloworld

copyconsole.o: copyconsole.c
	$(CC) $(CFLAGS) -c copyconsole.c
copyconsole: copyconsole.o start.o
	$(LD) $(LDFLAGS) start.o  copyconsole.o -o copyconsole.coff
	../bin/coff2noff copyconsole.coff copyconsole

catfile.o: catfile.c
	$(CC) $(CFLAGS) -c catfile.c
catfile: catfile.o start.o
	$(LD) $(LDFLAGS) start.o catfile.o -o catfile.coff
	../bin/coff2noff catfile.coff catfile

writefile.o: writefile.c
	$(CC) $(CFLAGS) -c writefile.c
writefile: writefile.o start.o
	$(LD) $(LDFLAGS) start.o writefile.o -o writefile.coff
	../bin/coff2noff writefile.coff writefile

forktest.o: forktest.c
	$(CC) $(CFLAGS) -c forktest.c
forktest: forktest.o start.o
	$(LD) $(LDFLAGS) start.o forktest.o -o forktest.coff
	../bin/coff2noff forktest.coff forktest

exittest.o: exittest.c
	$(CC) $(CFLAGS) -c exittest.c
exittest: exittest.o start.o
	$(LD) $(LDFLAGS) start.o exittest.o -o exittest.coff
	../bin/coff2noff exittest.coff exittest

fail.o: fail.c
	$(CC) $(CFLAGS) -c fail.c
fail: fail.o start.o
	$(LD) $(LDFLAGS) start.o fail.o -o fail.coff
	../bin/coff2noff fail.coff fail