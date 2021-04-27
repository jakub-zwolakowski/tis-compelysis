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
==29977==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000060 (pc 0x7f62a0fccf37 bp 0x7fff3f655880 sp 0x7fff3f655868 T29977)
==29977==The signal is caused by a READ memory access.
==29977==Hint: address points to the zero page.
    #0 0x7f62a0fccf37  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76
    #1 0x423281 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x423281)
    #2 0x42330d in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x42330d)
    #3 0x7f62a0e60bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a79 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x402a79)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76 
==29977==ABORTING
```
### Valgrind
```
==29983== Memcheck, a memory error detector
==29983== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29983== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29983== Command: ./example_strchr.out
==29983== 
==29983== Invalid read of size 1
==29983==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==29983==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==29983==    by 0x108708: main (example_strchr.c:24)
==29983==  Address 0x65 is not stack'd, malloc'd or (recently) free'd
==29983== 
==29983== 
==29983== Process terminating with default action of signal 11 (SIGSEGV)
==29983==  Access not within mapped region at address 0x65
==29983==    at 0x4FCBEE0: __strchr_avx2 (strchr-avx2.S:45)
==29983==    by 0x1086A9: f_noncompliant (example_strchr.c:9)
==29983==    by 0x108708: main (example_strchr.c:24)
==29983==  If you believe this happened as a result of a stack
==29983==  overflow in your program's main thread (unlikely but
==29983==  possible), you can try to increase the size of the
==29983==  main thread stack using the --main-stacksize= flag.
==29983==  The main thread stack size used in this run was 8388608.
ello
==29983== 
==29983== HEAP SUMMARY:
==29983==     in use at exit: 0 bytes in 0 blocks
==29983==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==29983== 
==29983== All heap blocks were freed -- no leaks are possible
==29983== 
==29983== For counts of detected and suppressed errors, rerun with: -v
==29983== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
