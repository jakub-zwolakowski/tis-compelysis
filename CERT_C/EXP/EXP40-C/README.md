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
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042cac0 (pc 0x000000424185 bp 0x7ffc0897f000 sp 0x7ffc0897eff0 T2245)
==12345==The signal is caused by a WRITE memory access.
    #0 0x424185 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424185)
    #1 0x42426d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42426d)
    #2 0x7ff4d2d66bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424185) in f_noncompliant
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
==12345==  Bad permissions for mapped region at address 0x108704
==12345==    at 0x108624: f_noncompliant (example.c:8)
==12345==    by 0x10866D: main (example.c:23)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
