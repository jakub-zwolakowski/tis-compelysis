## example_noncompliant
### Test
```
Terminated
```
### gcc
```
```
### clang
```
```
### UBSan
```
Terminated
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== Process terminating with default action of signal 15 (SIGTERM)
==12345==    at 0x424242424242: nanosleep (nanosleep.c:28)
==12345==    by 0x424242424242: sleep (sleep.c:55)
==12345==    by 0x424242424242: func (example_noncompliant.c:8)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 123 bytes in 1 blocks
==12345==   total heap usage: 1 allocs, 0 frees, 123 bytes allocated
==12345== 
==12345== 123 bytes in 1 blocks are possibly lost in loss record 1 of 1
==12345==    at 0x424242424242: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: allocate_dtv (dl-tls.c:286)
==12345==    by 0x424242424242: _dl_allocate_tls (dl-tls.c:530)
==12345==    by 0x424242424242: allocate_stack (allocatestack.c:627)
==12345==    by 0x424242424242: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==12345==    by 0x424242424242: main (example_noncompliant.c:17)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 0 bytes in 0 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 123 bytes in 1 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
