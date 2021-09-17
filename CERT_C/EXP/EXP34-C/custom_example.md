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
==3057==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x0000004241eb bp 0x7fff1c0c7d30 sp 0x7fff1c0c7d10 T3057)
==3057==The signal is caused by a READ memory access.
==3057==Hint: address points to the zero page.
    #0 0x4241eb in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4241eb)
    #1 0x4242b5 in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4242b5)
    #2 0x7f4869b68bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP34-C/custom_example.UBSan-out+0x4241eb) in f_noncompliant
==3057==ABORTING
```
### Valgrind
```
==3064== Memcheck, a memory error detector
==3064== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3064== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3064== Command: ./custom_example.out
==3064== 
==3064== Invalid read of size 4
==3064==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==3064==    by 0x10876C: main (custom_example.c:28)
==3064==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==3064== 
==3064== 
==3064== Process terminating with default action of signal 11 (SIGSEGV)
==3064==  Access not within mapped region at address 0x0
==3064==    at 0x1086C8: f_noncompliant (custom_example.c:12)
==3064==    by 0x10876C: main (custom_example.c:28)
==3064==  If you believe this happened as a result of a stack
==3064==  overflow in your program's main thread (unlikely but
==3064==  possible), you can try to increase the size of the
==3064==  main thread stack using the --main-stacksize= flag.
==3064==  The main thread stack size used in this run was 8388608.
==3064== 
==3064== HEAP SUMMARY:
==3064==     in use at exit: 0 bytes in 0 blocks
==3064==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==3064== 
==3064== All heap blocks were freed -- no leaks are possible
==3064== 
==3064== For counts of detected and suppressed errors, rerun with: -v
==3064== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
