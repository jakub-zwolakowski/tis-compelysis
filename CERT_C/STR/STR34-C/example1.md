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
==4225==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000100637da0 (pc 0x000000423537 bp 0x7ffec72ebf10 sp 0x7ffec72ebea0 T4225)
==4225==The signal is caused by a READ memory access.
    #0 0x423537 in first_not_in_table_noncompliant (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x423537)
    #1 0x42397b in main (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x42397b)
    #2 0x7f7b4c109bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x4029e9 in _start (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x4029e9)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/STR/STR34-C/example1.UBSan-out+0x423537) in first_not_in_table_noncompliant
==4225==ABORTING
```
### Valgrind
```
==4232== Memcheck, a memory error detector
==4232== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4232== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4232== Command: ./example1.out
==4232== 
==4232== Invalid read of size 1
==4232==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==4232==    by 0x1087CF: main (example1.c:33)
==4232==  Address 0x100308fa0 is not stack'd, malloc'd or (recently) free'd
==4232== 
==4232== 
==4232== Process terminating with default action of signal 11 (SIGSEGV)
==4232==  Access not within mapped region at address 0x100308FA0
==4232==    at 0x1086ED: first_not_in_table_noncompliant (example1.c:17)
==4232==    by 0x1087CF: main (example1.c:33)
==4232==  If you believe this happened as a result of a stack
==4232==  overflow in your program's main thread (unlikely but
==4232==  possible), you can try to increase the size of the
==4232==  main thread stack using the --main-stacksize= flag.
==4232==  The main thread stack size used in this run was 8388608.
==4232== 
==4232== HEAP SUMMARY:
==4232==     in use at exit: 0 bytes in 0 blocks
==4232==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4232== 
==4232== All heap blocks were freed -- no leaks are possible
==4232== 
==4232== For counts of detected and suppressed errors, rerun with: -v
==4232== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
