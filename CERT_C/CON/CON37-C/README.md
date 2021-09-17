# Examples
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
## example
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
==30646== Memcheck, a memory error detector
==30646== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30646== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30646== Command: ./example.out
==30646== 
==30646== 
==30646== HEAP SUMMARY:
==30646==     in use at exit: 544 bytes in 2 blocks
==30646==   total heap usage: 2 allocs, 0 frees, 544 bytes allocated
==30646== 
==30646== 272 bytes in 1 blocks are possibly lost in loss record 1 of 2
==30646==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30646==    by 0x4013646: allocate_dtv (dl-tls.c:286)
==30646==    by 0x4013646: _dl_allocate_tls (dl-tls.c:530)
==30646==    by 0x4E46227: allocate_stack (allocatestack.c:627)
==30646==    by 0x4E46227: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==30646==    by 0x10884C: main_compliant (example.c:46)
==30646==    by 0x10888F: main (example.c:58)
==30646== 
==30646== 272 bytes in 1 blocks are possibly lost in loss record 2 of 2
==30646==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30646==    by 0x4013646: allocate_dtv (dl-tls.c:286)
==30646==    by 0x4013646: _dl_allocate_tls (dl-tls.c:530)
==30646==    by 0x4E46227: allocate_stack (allocatestack.c:627)
==30646==    by 0x4E46227: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==30646==    by 0x1087A6: main_noncompliant (example.c:23)
==30646==    by 0x108894: main (example.c:59)
==30646== 
==30646== LEAK SUMMARY:
==30646==    definitely lost: 0 bytes in 0 blocks
==30646==    indirectly lost: 0 bytes in 0 blocks
==30646==      possibly lost: 544 bytes in 2 blocks
==30646==    still reachable: 0 bytes in 0 blocks
==30646==         suppressed: 0 bytes in 0 blocks
==30646== 
==30646== For counts of detected and suppressed errors, rerun with: -v
==30646== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
