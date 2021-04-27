# Examples
## custom_example
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
custom_example.c:24:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
custom_example.c:24:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
custom_example.c:24:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
custom_example.c:12:10: runtime error: load of null pointer of type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior custom_example.c:12:10 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==31248==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x0000004232e7 bp 0x7ffc8d545f90 sp 0x7ffc8d545f70 T31248)
==31248==The signal is caused by a READ memory access.
==31248==Hint: address points to the zero page.
    #0 0x4232e7 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4232e7)
    #1 0x4233c2 in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4233c2)
    #2 0x7fe05d578bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4232e7) in f_noncompliant
==31248==ABORTING
```
### Valgrind
```
==31254== Memcheck, a memory error detector
==31254== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31254== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31254== Command: ./custom_example.out
==31254== 
==31254== Invalid read of size 4
==31254==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==31254==    by 0x10876C: main (custom_example.c:28)
==31254==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==31254== 
==31254== 
==31254== Process terminating with default action of signal 11 (SIGSEGV)
==31254==  Access not within mapped region at address 0x0
==31254==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==31254==    by 0x10876C: main (custom_example.c:28)
==31254==  If you believe this happened as a result of a stack
==31254==  overflow in your program's main thread (unlikely but
==31254==  possible), you can try to increase the size of the
==31254==  main thread stack using the --main-stacksize= flag.
==31254==  The main thread stack size used in this run was 8388608.
==31254== 
==31254== HEAP SUMMARY:
==31254==     in use at exit: 0 bytes in 0 blocks
==31254==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==31254== 
==31254== All heap blocks were freed -- no leaks are possible
==31254== 
==31254== For counts of detected and suppressed errors, rerun with: -v
==31254== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
