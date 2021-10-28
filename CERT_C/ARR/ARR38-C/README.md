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
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address (pc 0x424242424242 bp 0x4242424242421788 sp 0x424242424242 T4242)
==12345==The signal is caused by a READ memory access.
==12345==Hint: this fault was caused by a dereference of a high value address (see register values below).  Disassemble the provided pc to learn which register was used.
UndefinedBehaviorSanitizer:DEADLYSIGNAL
UndefinedBehaviorSanitizer: nested bug in the same thread, aborting.
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Element_Count.out
==12345== 
*** stack smashing detected ***: <unknown> terminated
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __libc_message (libc_fatal.c:181)
==12345==    by 0x424242424242: __fortify_fail_abort (fortify_fail.c:33)
==12345==    by 0x424242424242: __stack_chk_fail (stack_chk_fail.c:29)
==12345==    by 0x424242424242: f_noncompliant (Element_Count.c:12)
==12345==    by 0x424242424242A00: ???
==12345==    by 0x424242424242: ??? (in /home/qba/git/tis-compelysis/CERT_C/ARR/ARR38-C/Element_Count.out)
==12345==    by 0x424242424242: (below main) (libc-start.c:310)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
