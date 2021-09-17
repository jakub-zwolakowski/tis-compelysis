## example_noncompliant
### Test
```
Aborted (core dumped)
```
### gcc
```
```
### clang
```
```
### UBSan
```
Aborted (core dumped)
```
### Valgrind
```
==27869== Memcheck, a memory error detector
==27869== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27869== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27869== Command: ./example_noncompliant.out
==27869== 
==27869== 
==27869== Process terminating with default action of signal 6 (SIGABRT)
==27869==    at 0x4E7CFB7: raise (raise.c:51)
==27869==    by 0x4E7E920: abort (abort.c:79)
==27869==    by 0x4EC76B4: __libc_message.constprop.0 (libc_fatal.c:181)
==27869==    by 0x4EC79F9: __libc_fatal (libc_fatal.c:191)
==27869==    by 0x4EC82A6: _IO_vtable_check (vtables.c:72)
==27869==    by 0x4EBD404: IO_validate_vtable (libioP.h:876)
==27869==    by 0x4EBD404: fputs (iofputs.c:38)
==27869==    by 0x10883C: main (example_noncompliant.c:5)
==27869== 
==27869== HEAP SUMMARY:
==27869==     in use at exit: 0 bytes in 0 blocks
==27869==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==27869== 
==27869== All heap blocks were freed -- no leaks are possible
==27869== 
==27869== For counts of detected and suppressed errors, rerun with: -v
==27869== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
