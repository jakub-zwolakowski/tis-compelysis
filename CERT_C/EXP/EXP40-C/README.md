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
==30716==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042b900 (pc 0x00000042327d bp 0x7ffc09cd0010 sp 0x7ffc09cd0000 T30716)
==30716==The signal is caused by a WRITE memory access.
    #0 0x42327d in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42327d)
    #1 0x42336d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42336d)
    #2 0x7f621be2ebf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42327d) in f_noncompliant
==30716==ABORTING
```
### Valgrind
```
==30722== Memcheck, a memory error detector
==30722== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30722== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30722== Command: ./example.out
==30722== 
==30722== 
==30722== Process terminating with default action of signal 11 (SIGSEGV)
==30722==  Bad permissions for mapped region at address 0x108704
==30722==    at 0x108624: f_noncompliant (example.c:8)
==30722==    by 0x10866D: main (example.c:23)
==30722== 
==30722== HEAP SUMMARY:
==30722==     in use at exit: 0 bytes in 0 blocks
==30722==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==30722== 
==30722== All heap blocks were freed -- no leaks are possible
==30722== 
==30722== For counts of detected and suppressed errors, rerun with: -v
==30722== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
