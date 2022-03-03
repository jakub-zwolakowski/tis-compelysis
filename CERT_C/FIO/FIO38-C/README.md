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
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== 
Hello, World!
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
timeout: the monitored command dumped core
Aborted
```
### gcc
```
```
### clang
```
```
### UBSan
```
timeout: the monitored command dumped core
Aborted
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __libc_message.constprop.0 (libc_fatal.c:181)
==12345==    by 0x424242424242: __libc_fatal (libc_fatal.c:191)
==12345==    by 0x424242424242: _IO_vtable_check (vtables.c:72)
==12345==    by 0x424242424242: IO_validate_vtable (libioP.h:876)
==12345==    by 0x424242424242: fputs (iofputs.c:38)
==12345==    by 0x424242424242: main (example_noncompliant.c:5)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
timeout: the monitored command dumped core
Aborted
```
## example
### Test
```
timeout: the monitored command dumped core
Aborted
```
### gcc
```
```
### clang
```
```
### UBSan
```
timeout: the monitored command dumped core
Aborted
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __libc_message.constprop.0 (libc_fatal.c:181)
==12345==    by 0x424242424242: __libc_fatal (libc_fatal.c:191)
==12345==    by 0x424242424242: _IO_vtable_check (vtables.c:72)
==12345==    by 0x424242424242: IO_validate_vtable (libioP.h:876)
==12345==    by 0x424242424242: fputs (iofputs.c:38)
==12345==    by 0x424242424242: main_noncompliant (example.c:14)
==12345==    by 0x424242424242: main (example.c:23)
Hello, World!
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
timeout: the monitored command dumped core
Aborted
```
