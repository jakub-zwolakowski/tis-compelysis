## example_compliant
### Test
```
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
==12345== Command: ./example_compliant.out
==12345== Parent PID: 12345
==12345== 
==12345== Syscall param execve(envp) contains uninitialised byte(s)
==12345==    at 0x424242424242: execve (syscall-template.S:78)
==12345==    by 0x424242424242: func (example_compliant.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:41)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: func (example_compliant.c:7)
==12345== 
==12345== Syscall param execve(envp[i]) points to unaddressable byte(s)
==12345==    at 0x424242424242: execve (syscall-template.S:78)
==12345==    by 0x424242424242: func (example_compliant.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:41)
==12345==  Address 0x4242424242428348 is not stack'd, malloc'd or (recently) free'd
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 27 errors from 2 contexts (suppressed: 0 from 0)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
