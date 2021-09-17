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
==2245==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042cac0 (pc 0x000000424185 bp 0x7ffc0897f000 sp 0x7ffc0897eff0 T2245)
==2245==The signal is caused by a WRITE memory access.
    #0 0x424185 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424185)
    #1 0x42426d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x42426d)
    #2 0x7ff4d2d66bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP40-C/example.UBSan-out+0x424185) in f_noncompliant
==2245==ABORTING
```
### Valgrind
```
==2252== Memcheck, a memory error detector
==2252== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2252== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2252== Command: ./example.out
==2252== 
==2252== 
==2252== Process terminating with default action of signal 11 (SIGSEGV)
==2252==  Bad permissions for mapped region at address 0x108704
==2252==    at 0x108624: f_noncompliant (example.c:8)
==2252==    by 0x10866D: main (example.c:23)
==2252== 
==2252== HEAP SUMMARY:
==2252==     in use at exit: 0 bytes in 0 blocks
==2252==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2252== 
==2252== All heap blocks were freed -- no leaks are possible
==2252== 
==2252== For counts of detected and suppressed errors, rerun with: -v
==2252== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
