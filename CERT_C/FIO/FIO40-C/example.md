## example
### Test
```
  
```
### gcc
```
```
### clang
```
```
### UBSan
```
  
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== Parent PID: 12345
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:789)
==12345==    by 0x424242424242: putchar (putchar.c:28)
==12345==    by 0x424242424242: func_noncompliant (example.c:11)
==12345==    by 0x424242424242: main (example.c:43)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: func_noncompliant (example.c:5)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:797)
==12345==    by 0x424242424242: putchar (putchar.c:28)
==12345==    by 0x424242424242: func_noncompliant (example.c:11)
==12345==    by 0x424242424242: main (example.c:43)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: func_noncompliant (example.c:5)
==12345== 
==12345== Syscall param write(buf) points to uninitialised byte(s)
==12345==    at 0x424242424242: write (write.c:27)
==12345==    by 0x424242424242: _IO_file_write@@GLIBC_2.2.5 (fileops.c:1203)
==12345==    by 0x424242424242: new_do_write (fileops.c:457)
==12345==    by 0x424242424242: _IO_do_write@@GLIBC_2.2.5 (fileops.c:433)
==12345==    by 0x424242424242: _IO_flush_all_lockp (genops.c:769)
==12345==    by 0x424242424242: _IO_cleanup (genops.c:929)
==12345==    by 0x424242424242: __run_exit_handlers (exit.c:130)
==12345==    by 0x424242424242: exit (exit.c:139)
==12345==    by 0x424242424242: (below main) (libc-start.c:344)
==12345==  Address 0x424242424242 is 1 bytes inside a block of size 1,024 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: _IO_file_doallocate (filedoalloc.c:101)
==12345==    by 0x424242424242: _IO_doallocbuf (genops.c:365)
==12345==    by 0x424242424242: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:759)
==12345==    by 0x424242424242: putchar (putchar.c:28)
==12345==    by 0x424242424242: func_compliant (example.c:21)
==12345==    by 0x424242424242: main (example.c:34)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: func_noncompliant (example.c:5)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 7 allocs, 7 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```
