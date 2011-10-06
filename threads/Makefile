# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the threads assignment.  The threads assignment must
#  be done first!
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DTHREADS
INCPATH = -I../threads -I../machine
HFILES = $(THREAD_H)
CFILES = $(THREAD_C)
C_OFILES = $(THREAD_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/system.h ../threads/thread.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../threads/utility.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
  ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/thread.h ../threads/system.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../threads/list.h \
  ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/synch.h ../threads/thread.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../threads/utility.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/switch.h ../threads/synch.h ../threads/list.h \
  ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  /usr/include/stdarg.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
  ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/system.h ../threads/thread.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h ../threads/utility.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  /usr/include/signal.h /usr/include/sys/types.h \
  /usr/include/machine/types.h /usr/include/machine/endian.h \
  /usr/include/sys/endian.h /usr/include/machine/endian_machdep.h \
  /usr/include/machine/bswap.h /usr/include/machine/byte_swap.h \
  /usr/include/sys/bswap.h /usr/include/sys/fd_set.h \
  /usr/include/pthread_types.h /usr/include/sys/signal.h \
  /usr/include/sys/sigtypes.h /usr/include/sys/siginfo.h \
  /usr/include/machine/signal.h /usr/include/machine/trap.h \
  /usr/include/x86/trap.h /usr/include/sys/ucontext.h \
  /usr/include/machine/mcontext.h /usr/include/sys/time.h \
  /usr/include/sys/select.h /usr/include/time.h /usr/include/sys/socket.h \
  /usr/include/sys/uio.h /usr/include/sys/file.h /usr/include/sys/fcntl.h \
  /usr/include/sys/stat.h /usr/include/sys/unistd.h /usr/include/sys/un.h \
  /usr/include/sys/mman.h /usr/include/unistd.h /usr/include/stdlib.h \
  /usr/include/errno.h /usr/include/sys/errno.h ../machine/interrupt.h \
  ../threads/list.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/system.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
  ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/system.h ../threads/utility.h ../threads/thread.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
