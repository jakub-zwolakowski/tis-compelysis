# Examples
## Division
### Test
```
Floating point exception (core dumped)
```
### gcc
```
Division.c: In function ‘f_noncompliant’:
Division.c:4:15: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   signed long result;
               ^~~~~~
Division.c: In function ‘f_compliant’:
Division.c:14:15: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   signed long result;
               ^~~~~~
Division.c: At top level:
Division.c:23:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Division.c:23:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Division.c:23:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Division.c:8:18: runtime error: division by zero
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Division.c:8:18 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==1963==ERROR: UndefinedBehaviorSanitizer: FPE on unknown address 0x000000423257 (pc 0x000000423257 bp 0x7ffe181393e0 sp 0x7ffe181393b0 T1963)
    #0 0x423257 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x423257)
    #1 0x42337d in main (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x42337d)
    #2 0x7fa3db8b9bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: FPE (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x423257) in f_noncompliant
==1963==ABORTING
```
### Valgrind
```
==1969== Memcheck, a memory error detector
==1969== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1969== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1969== Command: ./Division.out
==1969== 
==1969== 
==1969== Process terminating with default action of signal 8 (SIGFPE)
==1969==  Integer divide by zero at address 0x1002D3BCA0
==1969==    at 0x108623: f_noncompliant (Division.c:8)
==1969==    by 0x1086C8: main (Division.c:29)
==1969== 
==1969== HEAP SUMMARY:
==1969==     in use at exit: 0 bytes in 0 blocks
==1969==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==1969== 
==1969== All heap blocks were freed -- no leaks are possible
==1969== 
==1969== For counts of detected and suppressed errors, rerun with: -v
==1969== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Floating point exception (core dumped)
```
