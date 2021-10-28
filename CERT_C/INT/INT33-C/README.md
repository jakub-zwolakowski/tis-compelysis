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
==12345==ERROR: UndefinedBehaviorSanitizer: FPE on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
    #0 0x42416f in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x42416f)
    #1 0x424287 in main (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x424287)
    #2 0x424242424242 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: FPE (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x42416f) in f_noncompliant
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Division.out
==12345== 
==12345== 
==12345== Process terminating with default action of signal 8 (SIGFPE)
==12345==  Integer divide by zero at address 0x1002D3BCA0
==12345==    at 0x108623: f_noncompliant (Division.c:8)
==12345==    by 0x1086C8: main (Division.c:29)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Floating point exception (core dumped)
```
