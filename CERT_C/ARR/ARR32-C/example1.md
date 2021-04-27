## example1
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example1.c:38:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:38:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:38:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==6341==ERROR: UndefinedBehaviorSanitizer: stack-overflow on address 0x7ffcdae36688 (pc 0x0000004233c7 bp 0x7ffedae366b0 sp 0x7ffcdae36690 T6341)
    #0 0x4233c7 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4233c7)
    #1 0x4234dd in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4234dd)
    #2 0x7f37ad4d7bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x402a79 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x402a79)

SUMMARY: UndefinedBehaviorSanitizer: stack-overflow (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4233c7) in f_noncompliant
==6341==ABORTING
```
### Valgrind
```
==6363== Memcheck, a memory error detector
==6363== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6363== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6363== Command: ./example1.out
==6363== 
==6363== Warning: set address range perms: large range [0x59e43040, 0x259e4303c) (undefined)
==6363== Warning: set address range perms: large range [0x59e43028, 0x259e43054) (noaccess)
==6363== Warning: client switching stacks?  SP change: 0x1ffefff820 --> 0x1dfefff820
==6363==          to suppress, use: --max-stackframe=8589934592 or greater
==6363== Invalid write of size 8
==6363==    at 0x1087C6: f_noncompliant (example1.c:14)
==6363==  Address 0x1dfefff818 is on thread 1's stack
==6363== 
==6363== 
==6363== Process terminating with default action of signal 11 (SIGSEGV)
==6363==  Access not within mapped region at address 0x1DFEFFF818
==6363==    at 0x1087C6: f_noncompliant (example1.c:14)
==6363==  If you believe this happened as a result of a stack
==6363==  overflow in your program's main thread (unlikely but
==6363==  possible), you can try to increase the size of the
==6363==  main thread stack using the --main-stacksize= flag.
==6363==  The main thread stack size used in this run was 8388608.
==6363== Invalid write of size 8
==6363==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==6363==  Address 0x1dfefff810 is on thread 1's stack
==6363== 
==6363== 
==6363== Process terminating with default action of signal 11 (SIGSEGV)
==6363==  Access not within mapped region at address 0x1DFEFFF810
==6363==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==6363==  If you believe this happened as a result of a stack
==6363==  overflow in your program's main thread (unlikely but
==6363==  possible), you can try to increase the size of the
==6363==  main thread stack using the --main-stacksize= flag.
==6363==  The main thread stack size used in this run was 8388608.
==6363== 
==6363== HEAP SUMMARY:
==6363==     in use at exit: 0 bytes in 0 blocks
==6363==   total heap usage: 1 allocs, 1 frees, 8,589,934,588 bytes allocated
==6363== 
==6363== All heap blocks were freed -- no leaks are possible
==6363== 
==6363== For counts of detected and suppressed errors, rerun with: -v
==6363== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
