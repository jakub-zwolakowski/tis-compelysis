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
==9266==ERROR: UndefinedBehaviorSanitizer: stack-overflow on address 0x7ffca702f678 (pc 0x0000004233c7 bp 0x7ffea702f6a0 sp 0x7ffca702f680 T9266)
    #0 0x4233c7 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4233c7)
    #1 0x4234dd in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4234dd)
    #2 0x7fbf5174cbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x402a79 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x402a79)

SUMMARY: UndefinedBehaviorSanitizer: stack-overflow (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x4233c7) in f_noncompliant
==9266==ABORTING
```
### Valgrind
```
==9292== Memcheck, a memory error detector
==9292== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9292== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9292== Command: ./example1.out
==9292== 
==9292== Warning: set address range perms: large range [0x59e43040, 0x259e4303c) (undefined)
==9292== Warning: set address range perms: large range [0x59e43028, 0x259e43054) (noaccess)
==9292== Warning: client switching stacks?  SP change: 0x1ffefff810 --> 0x1dfefff810
==9292==          to suppress, use: --max-stackframe=8589934592 or greater
==9292== Invalid write of size 8
==9292==    at 0x1087C6: f_noncompliant (example1.c:14)
==9292==  Address 0x1dfefff808 is on thread 1's stack
==9292== 
==9292== 
==9292== Process terminating with default action of signal 11 (SIGSEGV)
==9292==  Access not within mapped region at address 0x1DFEFFF808
==9292==    at 0x1087C6: f_noncompliant (example1.c:14)
==9292==  If you believe this happened as a result of a stack
==9292==  overflow in your program's main thread (unlikely but
==9292==  possible), you can try to increase the size of the
==9292==  main thread stack using the --main-stacksize= flag.
==9292==  The main thread stack size used in this run was 8388608.
==9292== Invalid write of size 8
==9292==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==9292==  Address 0x1dfefff800 is on thread 1's stack
==9292== 
==9292== 
==9292== Process terminating with default action of signal 11 (SIGSEGV)
==9292==  Access not within mapped region at address 0x1DFEFFF800
==9292==    at 0x4A2C650: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==9292==  If you believe this happened as a result of a stack
==9292==  overflow in your program's main thread (unlikely but
==9292==  possible), you can try to increase the size of the
==9292==  main thread stack using the --main-stacksize= flag.
==9292==  The main thread stack size used in this run was 8388608.
==9292== 
==9292== HEAP SUMMARY:
==9292==     in use at exit: 0 bytes in 0 blocks
==9292==   total heap usage: 1 allocs, 1 frees, 8,589,934,588 bytes allocated
==9292== 
==9292== All heap blocks were freed -- no leaks are possible
==9292== 
==9292== For counts of detected and suppressed errors, rerun with: -v
==9292== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
