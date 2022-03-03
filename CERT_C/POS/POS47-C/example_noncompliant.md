## example_noncompliant
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
a: 42 | b:42
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
==12345== 
==12345== Process terminating with default action of signal 15 (SIGTERM)
==12345==    at 0x424242424242: __lll_lock_wait (lowlevellock.S:135)
==12345==    by 0x424242424242: pthread_mutex_lock (pthread_mutex_lock.c:80)
==12345==    by 0x424242424242: main (example_noncompliant.c:59)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 6 allocs, 6 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
