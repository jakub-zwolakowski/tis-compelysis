# Examples
## example
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example.c: In function ‘f_noncompliant’:
example.c:6:20: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
   ipp_noncompliant = &ip_noncompliant; /* Constraint violation */
                    ^
example.c: At top level:
example.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:6:20: warning: assigning to 'const int **' from 'int **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  ipp_noncompliant = &ip_noncompliant; /* Constraint violation */
                   ^ ~~~~~~~~~~~~~~~~
example.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:21:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==7635==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042b900 (pc 0x00000042327d bp 0x7ffe41221e80 sp 0x7ffe41221e70 T7635)
==7635==The signal is caused by a WRITE memory access.
    #0 0x42327d in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42327d)
    #1 0x42336d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42336d)
    #2 0x7f8ccd417bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42327d) in f_noncompliant
==7635==ABORTING
```
### Valgrind
```
==7642== Memcheck, a memory error detector
==7642== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7642== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7642== Command: ./example.out
==7642== 
==7642== 
==7642== Process terminating with default action of signal 11 (SIGSEGV)
==7642==  Bad permissions for mapped region at address 0x108704
==7642==    at 0x108624: f_noncompliant (example.c:8)
==7642==    by 0x10866D: main (example.c:23)
==7642== 
==7642== HEAP SUMMARY:
==7642==     in use at exit: 0 bytes in 0 blocks
==7642==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7642== 
==7642== All heap blocks were freed -- no leaks are possible
==7642== 
==7642== For counts of detected and suppressed errors, rerun with: -v
==7642== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
