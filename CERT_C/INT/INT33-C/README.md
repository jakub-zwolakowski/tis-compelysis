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
==32557==ERROR: UndefinedBehaviorSanitizer: FPE on unknown address 0x00000042416f (pc 0x00000042416f bp 0x7ffc94afaff0 sp 0x7ffc94afafc0 T32557)
    #0 0x42416f in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x42416f)
    #1 0x424287 in main (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x424287)
    #2 0x7f6ecd53fbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: FPE (/home/qba/git/tis-compelysis/CERT_C/INT/INT33-C/Division.UBSan-out+0x42416f) in f_noncompliant
==32557==ABORTING
```
### Valgrind
```
==32564== Memcheck, a memory error detector
==32564== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32564== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32564== Command: ./Division.out
==32564== 
==32564== 
==32564== Process terminating with default action of signal 8 (SIGFPE)
==32564==  Integer divide by zero at address 0x1002D3BCA0
==32564==    at 0x108623: f_noncompliant (Division.c:8)
==32564==    by 0x1086C8: main (Division.c:29)
==32564== 
==32564== HEAP SUMMARY:
==32564==     in use at exit: 0 bytes in 0 blocks
==32564==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==32564== 
==32564== All heap blocks were freed -- no leaks are possible
==32564== 
==32564== For counts of detected and suppressed errors, rerun with: -v
==32564== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Floating point exception (core dumped)
```
