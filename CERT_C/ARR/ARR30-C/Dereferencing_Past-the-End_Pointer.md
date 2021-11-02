## Dereferencing_Past-the-End_Pointer
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Dereferencing_Past-the-End_Pointer.out
==12345== 
*** stack smashing detected ***: <unknown> terminated
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __libc_message (libc_fatal.c:181)
==12345==    by 0x424242424242: __fortify_fail_abort (fortify_fail.c:33)
==12345==    by 0x424242424242: __stack_chk_fail (stack_chk_fail.c:29)
==12345==    by 0x424242424242: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==12345==    by 0x424242424242: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==12345==    by 0x424242424242: main (Dereferencing_Past-the-End_Pointer.c:58)
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
