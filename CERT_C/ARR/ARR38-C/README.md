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
==7525==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address (pc 0x000000423382 bp 0xfffd72e800001738 sp 0x7ffed76c1df8 T7525)
==7525==The signal is caused by a READ memory access.
==7525==Hint: this fault was caused by a dereference of a high value address (see register values below).  Dissassemble the provided pc to learn which register was used.
UndefinedBehaviorSanitizer:DEADLYSIGNAL
UndefinedBehaviorSanitizer: nested bug in the same thread, aborting.
```
### Valgrind
```
==7531== Memcheck, a memory error detector
==7531== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7531== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7531== Command: ./Element_Count.out
==7531== 
*** stack smashing detected ***: <unknown> terminated
==7531== 
==7531== Process terminating with default action of signal 6 (SIGABRT)
==7531==    at 0x4E7CFB7: raise (raise.c:51)
==7531==    by 0x4E7E920: abort (abort.c:79)
==7531==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==7531==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==7531==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==7531==    by 0x108757: f_noncompliant (Element_Count.c:12)
==7531==    by 0x110780100527A00: ???
==7531==    by 0x1087DF: ??? (in /home/qba/git/tis-compelysis/CERT_C/ARR/ARR38-C/Element_Count.out)
==7531==    by 0x4E5FBF6: (below main) (libc-start.c:310)
==7531== 
==7531== HEAP SUMMARY:
==7531==     in use at exit: 0 bytes in 0 blocks
==7531==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7531== 
==7531== All heap blocks were freed -- no leaks are possible
==7531== 
==7531== For counts of detected and suppressed errors, rerun with: -v
==7531== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
