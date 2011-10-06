# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS
# INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O)

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
  ../threads/system.h ../threads/thread.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../filesys/filesys.h
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
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/system.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/list.h ../threads/system.h \
  ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/synch.h ../threads/thread.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../filesys/filesys.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../machine/translate.h ../threads/switch.h \
  ../threads/synch.h ../threads/list.h ../threads/system.h \
  ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h
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
  ../threads/system.h ../threads/thread.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../filesys/filesys.h
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
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h
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
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../filesys/filesys.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../machine/translate.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h \
  ../userprog/addrspace.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
  ../userprog/bitmap.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../filesys/openfile.h ../threads/copyright.h ../threads/utility.h
process.o: ../userprog/process.cc /usr/include/g++/iostream \
  /usr/include/g++/bits/c++config.h /usr/include/g++/bits/os_defines.h \
  /usr/include/g++/bits/cpu_defines.h /usr/include/g++/ostream \
  /usr/include/g++/ios /usr/include/g++/iosfwd \
  /usr/include/g++/bits/c++locale.h /usr/include/g++/clocale \
  /usr/include/locale.h /usr/include/sys/null.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/g++/cstring /usr/include/g++/cstddef /usr/include/stddef.h \
  /usr/include/sys/featuretest.h /usr/include/machine/ansi.h \
  /usr/include/machine/int_types.h /usr/include/string.h \
  /usr/include/strings.h /usr/include/g++/cstdio /usr/include/stdio.h \
  /usr/include/sys/ansi.h /usr/include/g++/bits/c++io.h \
  /usr/include/g++/bits/gthr.h /usr/include/g++/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/time.h /usr/include/sys/time.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/machine/endian.h /usr/include/sys/endian.h \
  /usr/include/machine/endian_machdep.h /usr/include/machine/bswap.h \
  /usr/include/machine/byte_swap.h /usr/include/sys/bswap.h \
  /usr/include/sys/fd_set.h /usr/include/pthread_types.h \
  /usr/include/sys/select.h /usr/include/sys/sigtypes.h \
  /usr/include/sched.h /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/g++/cctype /usr/include/ctype.h \
  /usr/include/g++/bits/stringfwd.h /usr/include/g++/bits/postypes.h \
  /usr/include/g++/cwchar /usr/include/g++/ctime /usr/include/wchar.h \
  /usr/include/machine/wchar_limits.h /usr/include/stdint.h \
  /usr/include/machine/int_mwgwtypes.h \
  /usr/include/g++/bits/functexcept.h \
  /usr/include/g++/exception_defines.h /usr/include/g++/exception \
  /usr/include/g++/bits/char_traits.h \
  /usr/include/g++/bits/stl_algobase.h /usr/include/g++/climits \
  /usr/include/limits.h /usr/include/machine/limits.h \
  /usr/include/sys/syslimits.h /usr/include/g++/cstdlib \
  /usr/include/stdlib.h /usr/include/g++/bits/stl_pair.h \
  /usr/include/g++/bits/cpp_type_traits.h \
  /usr/include/g++/bits/stl_iterator_base_types.h \
  /usr/include/g++/bits/stl_iterator_base_funcs.h \
  /usr/include/g++/bits/concept_check.h \
  /usr/include/g++/bits/stl_iterator.h /usr/include/g++/debug/debug.h \
  /usr/include/g++/bits/localefwd.h /usr/include/g++/bits/ios_base.h \
  /usr/include/g++/bits/atomicity.h /usr/include/g++/bits/atomic_word.h \
  /usr/include/g++/bits/locale_classes.h /usr/include/g++/string \
  /usr/include/g++/memory /usr/include/g++/bits/allocator.h \
  /usr/include/g++/bits/c++allocator.h \
  /usr/include/g++/ext/new_allocator.h /usr/include/g++/new \
  /usr/include/g++/bits/stl_construct.h \
  /usr/include/g++/bits/stl_uninitialized.h \
  /usr/include/g++/bits/stl_raw_storage_iter.h /usr/include/g++/limits \
  /usr/include/g++/bits/stl_function.h \
  /usr/include/g++/bits/basic_string.h /usr/include/g++/algorithm \
  /usr/include/g++/bits/stl_algo.h /usr/include/g++/bits/stl_heap.h \
  /usr/include/g++/bits/stl_tempbuf.h \
  /usr/include/g++/bits/basic_string.tcc /usr/include/g++/streambuf \
  /usr/include/g++/bits/streambuf.tcc /usr/include/g++/bits/basic_ios.h \
  /usr/include/g++/bits/streambuf_iterator.h \
  /usr/include/g++/bits/locale_facets.h /usr/include/g++/cwctype \
  /usr/include/wctype.h /usr/include/g++/bits/ctype_base.h \
  /usr/include/g++/bits/ctype_inline.h /usr/include/g++/bits/codecvt.h \
  /usr/include/g++/bits/time_members.h \
  /usr/include/g++/bits/messages_members.h \
  /usr/include/g++/bits/basic_ios.tcc /usr/include/g++/bits/ostream.tcc \
  /usr/include/g++/locale /usr/include/g++/bits/locale_facets.tcc \
  /usr/include/g++/typeinfo /usr/include/g++/istream \
  /usr/include/g++/bits/istream.tcc ../userprog/process.h \
  ../threads/copyright.h ../threads/thread.h ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../machine/translate.h ../threads/system.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../filesys/filesys.h ../userprog/addrspace.h \
  ../threads/list.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/g++/iostream \
  /usr/include/g++/bits/c++config.h /usr/include/g++/bits/os_defines.h \
  /usr/include/g++/bits/cpu_defines.h /usr/include/g++/ostream \
  /usr/include/g++/ios /usr/include/g++/iosfwd \
  /usr/include/g++/bits/c++locale.h /usr/include/g++/clocale \
  /usr/include/locale.h /usr/include/sys/null.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/g++/cstring /usr/include/g++/cstddef /usr/include/stddef.h \
  /usr/include/sys/featuretest.h /usr/include/machine/ansi.h \
  /usr/include/machine/int_types.h /usr/include/string.h \
  /usr/include/strings.h /usr/include/g++/cstdio /usr/include/stdio.h \
  /usr/include/sys/ansi.h /usr/include/g++/bits/c++io.h \
  /usr/include/g++/bits/gthr.h /usr/include/g++/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/time.h /usr/include/sys/time.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/machine/endian.h /usr/include/sys/endian.h \
  /usr/include/machine/endian_machdep.h /usr/include/machine/bswap.h \
  /usr/include/machine/byte_swap.h /usr/include/sys/bswap.h \
  /usr/include/sys/fd_set.h /usr/include/pthread_types.h \
  /usr/include/sys/select.h /usr/include/sys/sigtypes.h \
  /usr/include/sched.h /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/g++/cctype /usr/include/ctype.h \
  /usr/include/g++/bits/stringfwd.h /usr/include/g++/bits/postypes.h \
  /usr/include/g++/cwchar /usr/include/g++/ctime /usr/include/wchar.h \
  /usr/include/machine/wchar_limits.h /usr/include/stdint.h \
  /usr/include/machine/int_mwgwtypes.h \
  /usr/include/g++/bits/functexcept.h \
  /usr/include/g++/exception_defines.h /usr/include/g++/exception \
  /usr/include/g++/bits/char_traits.h \
  /usr/include/g++/bits/stl_algobase.h /usr/include/g++/climits \
  /usr/include/limits.h /usr/include/machine/limits.h \
  /usr/include/sys/syslimits.h /usr/include/g++/cstdlib \
  /usr/include/stdlib.h /usr/include/g++/bits/stl_pair.h \
  /usr/include/g++/bits/cpp_type_traits.h \
  /usr/include/g++/bits/stl_iterator_base_types.h \
  /usr/include/g++/bits/stl_iterator_base_funcs.h \
  /usr/include/g++/bits/concept_check.h \
  /usr/include/g++/bits/stl_iterator.h /usr/include/g++/debug/debug.h \
  /usr/include/g++/bits/localefwd.h /usr/include/g++/bits/ios_base.h \
  /usr/include/g++/bits/atomicity.h /usr/include/g++/bits/atomic_word.h \
  /usr/include/g++/bits/locale_classes.h /usr/include/g++/string \
  /usr/include/g++/memory /usr/include/g++/bits/allocator.h \
  /usr/include/g++/bits/c++allocator.h \
  /usr/include/g++/ext/new_allocator.h /usr/include/g++/new \
  /usr/include/g++/bits/stl_construct.h \
  /usr/include/g++/bits/stl_uninitialized.h \
  /usr/include/g++/bits/stl_raw_storage_iter.h /usr/include/g++/limits \
  /usr/include/g++/bits/stl_function.h \
  /usr/include/g++/bits/basic_string.h /usr/include/g++/algorithm \
  /usr/include/g++/bits/stl_algo.h /usr/include/g++/bits/stl_heap.h \
  /usr/include/g++/bits/stl_tempbuf.h \
  /usr/include/g++/bits/basic_string.tcc /usr/include/g++/streambuf \
  /usr/include/g++/bits/streambuf.tcc /usr/include/g++/bits/basic_ios.h \
  /usr/include/g++/bits/streambuf_iterator.h \
  /usr/include/g++/bits/locale_facets.h /usr/include/g++/cwctype \
  /usr/include/wctype.h /usr/include/g++/bits/ctype_base.h \
  /usr/include/g++/bits/ctype_inline.h /usr/include/g++/bits/codecvt.h \
  /usr/include/g++/bits/time_members.h \
  /usr/include/g++/bits/messages_members.h \
  /usr/include/g++/bits/basic_ios.tcc /usr/include/g++/bits/ostream.tcc \
  /usr/include/g++/locale /usr/include/g++/bits/locale_facets.tcc \
  /usr/include/g++/typeinfo /usr/include/g++/istream \
  /usr/include/g++/bits/istream.tcc ../threads/copyright.h \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../machine/translate.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../filesys/filesys.h \
  ../threads/list.h ../userprog/syscall.h ../userprog/process.h \
  ../threads/thread.h ../userprog/addrspace.h ../filesys/openfile.h \
  ../userprog/syncconsole.h ../machine/console.h ../threads/synch.h
progtest.o: ../userprog/progtest.cc ../machine/console.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h ../machine/machine.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/list.h
syncconsole.o: ../userprog/syncconsole.cc ../userprog/syncconsole.h \
  ../machine/console.h ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/sys/cdefs.h \
  /usr/include/machine/cdefs.h /usr/include/sys/cdefs_elf.h \
  /usr/include/sys/featuretest.h /usr/include/sys/ansi.h \
  /usr/include/machine/int_types.h /usr/include/machine/ansi.h \
  /usr/include/sys/null.h /usr/include/string.h /usr/include/strings.h \
  ../threads/synch.h ../threads/thread.h ../threads/utility.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/list.h
console.o: ../machine/console.cc ../threads/copyright.h \
  ../machine/console.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../filesys/filesys.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../machine/translate.h \
  ../machine/disk.h ../threads/system.h ../threads/utility.h \
  ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../filesys/filesys.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../machine/translate.h \
  ../machine/disk.h ../machine/mipssim.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../machine/translate.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../filesys/filesys.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/machine/cdefs.h \
  /usr/include/sys/cdefs_elf.h /usr/include/sys/featuretest.h \
  /usr/include/sys/ansi.h /usr/include/machine/int_types.h \
  /usr/include/machine/ansi.h /usr/include/sys/null.h \
  /usr/include/string.h /usr/include/strings.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../machine/translate.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../userprog/addrspace.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../filesys/filesys.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
