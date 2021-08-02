# Examples
## Element_Count
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
Element_Count.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Element_Count.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Element_Count.c:21:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==10216==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address (pc 0x000000423382 bp 0xfffd72e800001738 sp 0x7ffc5a2362a8 T10216)
==10216==The signal is caused by a READ memory access.
==10216==Hint: this fault was caused by a dereference of a high value address (see register values below).  Dissassemble the provided pc to learn which register was used.
UndefinedBehaviorSanitizer:DEADLYSIGNAL
UndefinedBehaviorSanitizer: nested bug in the same thread, aborting.
```
### Valgrind
```
==10222== Memcheck, a memory error detector
==10222== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10222== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10222== Command: ./Element_Count.out
==10222== 
*** stack smashing detected ***: <unknown> terminated
==10222== 
==10222== Process terminating with default action of signal 6 (SIGABRT)
==10222==    at 0x4E7CFB7: raise (raise.c:51)
==10222==    by 0x4E7E920: abort (abort.c:79)
==10222==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==10222==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==10222==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==10222==    by 0x108757: f_noncompliant (Element_Count.c:12)
==10222==    by 0x110780100527A00: ???
==10222==    by 0x1087DF: ??? (in /home/qba/git/tis-compelysis/CERT_C/ARR/ARR38-C/Element_Count.out)
==10222==    by 0x4E5FBF6: (below main) (libc-start.c:310)
==10222== 
==10222== HEAP SUMMARY:
==10222==     in use at exit: 0 bytes in 0 blocks
==10222==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==10222== 
==10222== All heap blocks were freed -- no leaks are possible
==10222== 
==10222== For counts of detected and suppressed errors, rerun with: -v
==10222== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
