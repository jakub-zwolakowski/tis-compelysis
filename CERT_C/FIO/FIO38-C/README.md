# Examples
## example_compliant
### Test
```
Hello, World!
```
### gcc
```
```
### clang
```
```
### UBSan
```
Hello, World!
```
### Valgrind
```
==27799== Memcheck, a memory error detector
==27799== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27799== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27799== Command: ./example_compliant.out
==27799== 
Hello, World!
==27799== 
==27799== HEAP SUMMARY:
==27799==     in use at exit: 0 bytes in 0 blocks
==27799==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==27799== 
==27799== All heap blocks were freed -- no leaks are possible
==27799== 
==27799== For counts of detected and suppressed errors, rerun with: -v
==27799== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
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
## example
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
==28334== Memcheck, a memory error detector
==28334== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==28334== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==28334== Command: ./example.out
==28334== 
==28334== 
==28334== Process terminating with default action of signal 6 (SIGABRT)
==28334==    at 0x4E7CFB7: raise (raise.c:51)
==28334==    by 0x4E7E920: abort (abort.c:79)
==28334==    by 0x4EC76B4: __libc_message.constprop.0 (libc_fatal.c:181)
==28334==    by 0x4EC79F9: __libc_fatal (libc_fatal.c:191)
==28334==    by 0x4EC82A6: _IO_vtable_check (vtables.c:72)
==28334==    by 0x4EBD404: IO_validate_vtable (libioP.h:876)
==28334==    by 0x4EBD404: fputs (iofputs.c:38)
==28334==    by 0x108875: main_noncompliant (example.c:14)
==28334==    by 0x1088AA: main (example.c:23)
Hello, World!
==28334== 
==28334== HEAP SUMMARY:
==28334==     in use at exit: 0 bytes in 0 blocks
==28334==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==28334== 
==28334== All heap blocks were freed -- no leaks are possible
==28334== 
==28334== For counts of detected and suppressed errors, rerun with: -v
==28334== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
