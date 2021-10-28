## example_strchr
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example_strchr.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example_strchr.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_strchr.c:22:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000060 (pc 0x7fc4c18ecf37 bp 0x7ffdc433e6e0 sp 0x7ffdc433e6c8 T1023)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x7fc4c18ecf37  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76
    #1 0x4241a1 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x4241a1)
    #2 0x42422d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x42422d)
    #3 0x7fc4c1780bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a69 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x402a69)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76 
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_strchr.out
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==12345==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==12345==    by 0x108708: main (example_strchr.c:24)
==12345==  Address 0x65 is not stack'd, malloc'd or (recently) free'd
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x65
==12345==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==12345==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==12345==    by 0x108708: main (example_strchr.c:24)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
ello
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
