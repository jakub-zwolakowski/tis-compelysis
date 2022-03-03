# Examples
## example
### Test
```
timeout: the monitored command dumped core
Segmentation fault
```
### gcc
```
example.c: In function ‘f_noncompliant’:
example.c:6:20: error: assignment from incompatible pointer type [-Wincompatible-pointer-types]
   ipp_noncompliant = &ip_noncompliant; /* Constraint violation */
                    ^
```
### clang
```
example.c:6:20: error: assigning to 'const int **' from 'int **' discards qualifiers in nested pointer types [-Werror,-Wincompatible-pointer-types-discards-qualifiers]
  ipp_noncompliant = &ip_noncompliant; /* Constraint violation */
                   ^ ~~~~~~~~~~~~~~~~
1 error generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
==12345==The signal is caused by a WRITE memory access.
    #0 0x424242424242 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424242424242)
    #1 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424242424242)
    #2 0x424242424242 in __libc_start_main /build/glibc-XXXXXX/glibc-XXXXXX.27/csu/../csu/libc-start.c:310
    #3 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424242424242)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424242424242) in f_noncompliant
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Bad permissions for mapped region at address 0x424242424242
==12345==    at 0x424242424242: f_noncompliant (example.c:8)
==12345==    by 0x424242424242: main (example.c:23)
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
Segmentation fault
```
