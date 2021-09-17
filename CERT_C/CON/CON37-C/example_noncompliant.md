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
```
### Valgrind
```
==30573== Memcheck, a memory error detector
==30573== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30573== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30573== Command: ./example_noncompliant.out
==30573== 
==30573== 
==30573== HEAP SUMMARY:
==30573==     in use at exit: 272 bytes in 1 blocks
==30573==   total heap usage: 1 allocs, 0 frees, 272 bytes allocated
==30573== 
==30573== 272 bytes in 1 blocks are possibly lost in loss record 1 of 1
==30573==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30573==    by 0x4013646: allocate_dtv (dl-tls.c:286)
==30573==    by 0x4013646: _dl_allocate_tls (dl-tls.c:530)
==30573==    by 0x4E46227: allocate_stack (allocatestack.c:627)
==30573==    by 0x4E46227: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==30573==    by 0x1087A6: main (example_noncompliant.c:23)
==30573== 
==30573== LEAK SUMMARY:
==30573==    definitely lost: 0 bytes in 0 blocks
==30573==    indirectly lost: 0 bytes in 0 blocks
==30573==      possibly lost: 272 bytes in 1 blocks
==30573==    still reachable: 0 bytes in 0 blocks
==30573==         suppressed: 0 bytes in 0 blocks
==30573== 
==30573== For counts of detected and suppressed errors, rerun with: -v
==30573== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
