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
==30495== Memcheck, a memory error detector
==30495== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30495== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30495== Command: ./example_compliant.out
==30495== 
==30495== 
==30495== HEAP SUMMARY:
==30495==     in use at exit: 272 bytes in 1 blocks
==30495==   total heap usage: 1 allocs, 0 frees, 272 bytes allocated
==30495== 
==30495== 272 bytes in 1 blocks are possibly lost in loss record 1 of 1
==30495==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30495==    by 0x4013646: allocate_dtv (dl-tls.c:286)
==30495==    by 0x4013646: _dl_allocate_tls (dl-tls.c:530)
==30495==    by 0x4E46227: allocate_stack (allocatestack.c:627)
==30495==    by 0x4E46227: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==30495==    by 0x108769: main (example_compliant.c:19)
==30495== 
==30495== LEAK SUMMARY:
==30495==    definitely lost: 0 bytes in 0 blocks
==30495==    indirectly lost: 0 bytes in 0 blocks
==30495==      possibly lost: 272 bytes in 1 blocks
==30495==    still reachable: 0 bytes in 0 blocks
==30495==         suppressed: 0 bytes in 0 blocks
==30495== 
==30495== For counts of detected and suppressed errors, rerun with: -v
==30495== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
