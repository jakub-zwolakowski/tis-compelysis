## Dereferencing_Past-the-End_Pointer
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
Dereferencing_Past-the-End_Pointer.c:52:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Dereferencing_Past-the-End_Pointer.c:52:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Dereferencing_Past-the-End_Pointer.c:52:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==8672== Memcheck, a memory error detector
==8672== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8672== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8672== Command: ./Dereferencing_Past-the-End_Pointer.out
==8672== 
*** stack smashing detected ***: <unknown> terminated
==8672== 
==8672== Process terminating with default action of signal 6 (SIGABRT)
==8672==    at 0x4E7CFB7: raise (raise.c:51)
==8672==    by 0x4E7E920: abort (abort.c:79)
==8672==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==8672==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==8672==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==8672==    by 0x10872E: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==8672==    by 0x1087AD: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==8672==    by 0x108827: main (Dereferencing_Past-the-End_Pointer.c:58)
==8672== 
==8672== HEAP SUMMARY:
==8672==     in use at exit: 0 bytes in 0 blocks
==8672==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8672== 
==8672== All heap blocks were freed -- no leaks are possible
==8672== 
==8672== For counts of detected and suppressed errors, rerun with: -v
==8672== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
