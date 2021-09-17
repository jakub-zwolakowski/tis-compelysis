# Examples
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
==4499==ERROR: UndefinedBehaviorSanitizer: stack-overflow on address 0x7ffdb2e4d8f8 (pc 0x0000004242c4 bp 0x7fffb2e4d920 sp 0x7ffdb2e4d900 T4499)
    #0 0x4242c4 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4242c4)
    #1 0x4243dd in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4243dd)
    #2 0x7f3aca556bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x402a69 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x402a69)

SUMMARY: UndefinedBehaviorSanitizer: stack-overflow (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4242c4) in f_noncompliant
==4499==ABORTING
```
### Valgrind
```
==4598== Memcheck, a memory error detector
==4598== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4598== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4598== Command: ./example1.out
==4598== 
==4598== Warning: set address range perms: large range [0x59e43040, 0x259e4303c) (undefined)
==4598== Warning: set address range perms: large range [0x59e43028, 0x259e43054) (noaccess)
==4598== Warning: client switching stacks?  SP change: 0x1ffefff820 --> 0x1dfefff820
==4598==          to suppress, use: --max-stackframe=8589934592 or greater
==4598== Invalid write of size 8
==4598==    at 0x1087C6: f_noncompliant (example1.c:14)
==4598==  Address 0x1dfefff818 is on thread 1's stack
==4598== 
==4598== 
==4598== Process terminating with default action of signal 11 (SIGSEGV)
==4598==  Access not within mapped region at address 0x1DFEFFF818
==4598==    at 0x1087C6: f_noncompliant (example1.c:14)
==4598==  If you believe this happened as a result of a stack
==4598==  overflow in your program's main thread (unlikely but
==4598==  possible), you can try to increase the size of the
==4598==  main thread stack using the --main-stacksize= flag.
==4598==  The main thread stack size used in this run was 8388608.
==4598== Invalid write of size 8
==4598==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==4598==  Address 0x1dfefff810 is on thread 1's stack
==4598== 
==4598== 
==4598== Process terminating with default action of signal 11 (SIGSEGV)
==4598==  Access not within mapped region at address 0x1DFEFFF810
==4598==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==4598==  If you believe this happened as a result of a stack
==4598==  overflow in your program's main thread (unlikely but
==4598==  possible), you can try to increase the size of the
==4598==  main thread stack using the --main-stacksize= flag.
==4598==  The main thread stack size used in this run was 8388608.
==4598== 
==4598== HEAP SUMMARY:
==4598==     in use at exit: 0 bytes in 0 blocks
==4598==   total heap usage: 1 allocs, 1 frees, 8,589,934,588 bytes allocated
==4598== 
==4598== All heap blocks were freed -- no leaks are possible
==4598== 
==4598== For counts of detected and suppressed errors, rerun with: -v
==4598== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
