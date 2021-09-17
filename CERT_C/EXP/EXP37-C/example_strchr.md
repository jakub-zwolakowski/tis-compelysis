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
==1023==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000060 (pc 0x7fc4c18ecf37 bp 0x7ffdc433e6e0 sp 0x7ffdc433e6c8 T1023)
==1023==The signal is caused by a READ memory access.
==1023==Hint: address points to the zero page.
    #0 0x7fc4c18ecf37  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76
    #1 0x4241a1 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x4241a1)
    #2 0x42422d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x42422d)
    #3 0x7fc4c1780bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a69 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x402a69)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76 
==1023==ABORTING
```
### Valgrind
```
==1032== Memcheck, a memory error detector
==1032== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1032== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1032== Command: ./example_strchr.out
==1032== 
==1032== Invalid read of size 1
==1032==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==1032==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==1032==    by 0x108708: main (example_strchr.c:24)
==1032==  Address 0x65 is not stack'd, malloc'd or (recently) free'd
==1032== 
==1032== 
==1032== Process terminating with default action of signal 11 (SIGSEGV)
==1032==  Access not within mapped region at address 0x65
==1032==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==1032==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==1032==    by 0x108708: main (example_strchr.c:24)
==1032==  If you believe this happened as a result of a stack
==1032==  overflow in your program's main thread (unlikely but
==1032==  possible), you can try to increase the size of the
==1032==  main thread stack using the --main-stacksize= flag.
==1032==  The main thread stack size used in this run was 8388608.
ello
==1032== 
==1032== HEAP SUMMARY:
==1032==     in use at exit: 0 bytes in 0 blocks
==1032==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==1032== 
==1032== All heap blocks were freed -- no leaks are possible
==1032== 
==1032== For counts of detected and suppressed errors, rerun with: -v
==1032== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
