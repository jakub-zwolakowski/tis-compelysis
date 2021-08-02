## example1
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example1.c: In function ‘f_compliant’:
example1.c:7:8: warning: variable ‘str’ set but not used [-Wunused-but-set-variable]
   char str[] = "string literal";
        ^~~
example1.c: At top level:
example1.c:11:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:11:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:11:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==3758==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042b89b (pc 0x00000042323f bp 0x7ffd17a34700 sp 0x7ffd17a346e0 T3758)
==3758==The signal is caused by a WRITE memory access.
    #0 0x42323f in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x42323f)
    #1 0x42330d in main (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x42330d)
    #2 0x7f7fc4964bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x42323f) in f_noncompliant
==3758==ABORTING
```
### Valgrind
```
==3765== Memcheck, a memory error detector
==3765== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3765== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3765== Command: ./example1.out
==3765== 
==3765== 
==3765== Process terminating with default action of signal 11 (SIGSEGV)
==3765==  Bad permissions for mapped region at address 0x108774
==3765==    at 0x10867D: f_noncompliant (example1.c:3)
==3765==    by 0x1086EB: main (example1.c:13)
==3765== 
==3765== HEAP SUMMARY:
==3765==     in use at exit: 0 bytes in 0 blocks
==3765==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==3765== 
==3765== All heap blocks were freed -- no leaks are possible
==3765== 
==3765== For counts of detected and suppressed errors, rerun with: -v
==3765== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
