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
==25713==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x00000042ca55 (pc 0x000000424154 bp 0x7fffd61f0e30 sp 0x7fffd61f0e10 T25713)
==25713==The signal is caused by a WRITE memory access.
    #0 0x424154 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x424154)
    #1 0x42420d in main (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x42420d)
    #2 0x7fe4086cabf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/STR/STR30-C/example1.UBSan-out+0x424154) in f_noncompliant
==25713==ABORTING
```
### Valgrind
```
==25720== Memcheck, a memory error detector
==25720== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25720== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25720== Command: ./example1.out
==25720== 
==25720== 
==25720== Process terminating with default action of signal 11 (SIGSEGV)
==25720==  Bad permissions for mapped region at address 0x108774
==25720==    at 0x10867D: f_noncompliant (example1.c:3)
==25720==    by 0x1086EB: main (example1.c:13)
==25720== 
==25720== HEAP SUMMARY:
==25720==     in use at exit: 0 bytes in 0 blocks
==25720==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==25720== 
==25720== All heap blocks were freed -- no leaks are possible
==25720== 
==25720== For counts of detected and suppressed errors, rerun with: -v
==25720== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
