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
==9848==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000100637da0 (pc 0x000000423537 bp 0x7ffef70dd520 sp 0x7ffef70dd4b0 T9848)
==9848==The signal is caused by a READ memory access.
    #0 0x423537 in first_not_in_table_noncompliant (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x423537)
    #1 0x42397b in main (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x42397b)
    #2 0x7f63adb4fbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x423537) in first_not_in_table_noncompliant
==9848==ABORTING
```
### Valgrind
```
==9855== Memcheck, a memory error detector
==9855== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9855== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9855== Command: ./example1.out
==9855== 
==9855== Invalid read of size 1
==9855==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==9855==    by 0x1087CF: main (example1.c:33)
==9855==  Address 0x100308fa0 is not stack'd, malloc'd or (recently) free'd
==9855== 
==9855== 
==9855== Process terminating with default action of signal 11 (SIGSEGV)
==9855==  Access not within mapped region at address 0x100308FA0
==9855==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==9855==    by 0x1087CF: main (example1.c:33)
==9855==  If you believe this happened as a result of a stack
==9855==  overflow in your program's main thread (unlikely but
==9855==  possible), you can try to increase the size of the
==9855==  main thread stack using the --main-stacksize= flag.
==9855==  The main thread stack size used in this run was 8388608.
==9855== 
==9855== HEAP SUMMARY:
==9855==     in use at exit: 0 bytes in 0 blocks
==9855==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9855== 
==9855== All heap blocks were freed -- no leaks are possible
==9855== 
==9855== For counts of detected and suppressed errors, rerun with: -v
==9855== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
