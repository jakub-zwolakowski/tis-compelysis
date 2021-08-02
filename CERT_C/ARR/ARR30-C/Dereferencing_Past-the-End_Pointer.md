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
==11354== Memcheck, a memory error detector
==11354== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11354== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11354== Command: ./Dereferencing_Past-the-End_Pointer.out
==11354== 
*** stack smashing detected ***: <unknown> terminated
==11354== 
==11354== Process terminating with default action of signal 6 (SIGABRT)
==11354==    at 0x4E7CFB7: raise (raise.c:51)
==11354==    by 0x4E7E920: abort (abort.c:79)
==11354==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==11354==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==11354==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==11354==    by 0x10872E: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==11354==    by 0x1087AD: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==11354==    by 0x108827: main (Dereferencing_Past-the-End_Pointer.c:58)
==11354== 
==11354== HEAP SUMMARY:
==11354==     in use at exit: 0 bytes in 0 blocks
==11354==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11354== 
==11354== All heap blocks were freed -- no leaks are possible
==11354== 
==11354== For counts of detected and suppressed errors, rerun with: -v
==11354== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
