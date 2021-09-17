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
==6339==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address (pc 0x00000042429c bp 0xfffd611800001788 sp 0x7ffcea75b668 T6339)
==6339==The signal is caused by a READ memory access.
==6339==Hint: this fault was caused by a dereference of a high value address (see register values below).  Disassemble the provided pc to learn which register was used.
UndefinedBehaviorSanitizer:DEADLYSIGNAL
UndefinedBehaviorSanitizer: nested bug in the same thread, aborting.
```
### Valgrind
```
==6345== Memcheck, a memory error detector
==6345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6345== Command: ./Element_Count.out
==6345== 
*** stack smashing detected ***: <unknown> terminated
==6345== 
==6345== Process terminating with default action of signal 6 (SIGABRT)
==6345==    at 0x4E7CFB7: raise (raise.c:51)
==6345==    by 0x4E7E920: abort (abort.c:79)
==6345==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==6345==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==6345==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==6345==    by 0x108757: f_noncompliant (Element_Count.c:12)
==6345==    by 0x110780100527A00: ???
==6345==    by 0x1087DF: ??? (in /home/qba/git/tis-compelysis/CERT_C/ARR/ARR38-C/Element_Count.out)
==6345==    by 0x4E5FBF6: (below main) (libc-start.c:310)
==6345== 
==6345== HEAP SUMMARY:
==6345==     in use at exit: 0 bytes in 0 blocks
==6345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6345== 
==6345== All heap blocks were freed -- no leaks are possible
==6345== 
==6345== For counts of detected and suppressed errors, rerun with: -v
==6345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
