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
==8181==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x0000004232e7 bp 0x7ffd164bc940 sp 0x7ffd164bc920 T8181)
==8181==The signal is caused by a READ memory access.
==8181==Hint: address points to the zero page.
    #0 0x4232e7 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4232e7)
    #1 0x4233c2 in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4233c2)
    #2 0x7fc68142fbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4232e7) in f_noncompliant
==8181==ABORTING
```
### Valgrind
```
==8188== Memcheck, a memory error detector
==8188== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8188== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8188== Command: ./custom_example.out
==8188== 
==8188== Invalid read of size 4
==8188==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==8188==    by 0x10876C: main (custom_example.c:28)
==8188==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==8188== 
==8188== 
==8188== Process terminating with default action of signal 11 (SIGSEGV)
==8188==  Access not within mapped region at address 0x0
==8188==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==8188==    by 0x10876C: main (custom_example.c:28)
==8188==  If you believe this happened as a result of a stack
==8188==  overflow in your program's main thread (unlikely but
==8188==  possible), you can try to increase the size of the
==8188==  main thread stack using the --main-stacksize= flag.
==8188==  The main thread stack size used in this run was 8388608.
==8188== 
==8188== HEAP SUMMARY:
==8188==     in use at exit: 0 bytes in 0 blocks
==8188==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8188== 
==8188== All heap blocks were freed -- no leaks are possible
==8188== 
==8188== For counts of detected and suppressed errors, rerun with: -v
==8188== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
