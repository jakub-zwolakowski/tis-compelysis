# Examples
## example1
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example1.c:24:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:24:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:24:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
example1.c:17:9: runtime error: index 4294967168 out of bounds for type 'char [256]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example1.c:17:9 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==26314==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000100639da0 (pc 0x000000424426 bp 0x7ffdf8bd8980 sp 0x7ffdf8bd8910 T26314)
==26314==The signal is caused by a READ memory access.
    #0 0x424426 in first_not_in_table_noncompliant (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x424426)
    #1 0x424810 in main (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x424810)
    #2 0x7f8d7e4b6bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029d9 in _start (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x4029d9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x424426) in first_not_in_table_noncompliant
==26314==ABORTING
```
### Valgrind
```
==26321== Memcheck, a memory error detector
==26321== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26321== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26321== Command: ./example1.out
==26321== 
==26321== Invalid read of size 1
==26321==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==26321==    by 0x1087CF: main (example1.c:33)
==26321==  Address 0x100308fa0 is not stack'd, malloc'd or (recently) free'd
==26321== 
==26321== 
==26321== Process terminating with default action of signal 11 (SIGSEGV)
==26321==  Access not within mapped region at address 0x100308FA0
==26321==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==26321==    by 0x1087CF: main (example1.c:33)
==26321==  If you believe this happened as a result of a stack
==26321==  overflow in your program's main thread (unlikely but
==26321==  possible), you can try to increase the size of the
==26321==  main thread stack using the --main-stacksize= flag.
==26321==  The main thread stack size used in this run was 8388608.
==26321== 
==26321== HEAP SUMMARY:
==26321==     in use at exit: 0 bytes in 0 blocks
==26321==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==26321== 
==26321== All heap blocks were freed -- no leaks are possible
==26321== 
==26321== For counts of detected and suppressed errors, rerun with: -v
==26321== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
