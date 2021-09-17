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
==23463== Memcheck, a memory error detector
==23463== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23463== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23463== Command: ./example_compliant.out
==23463== 
==23463== 
==23463== HEAP SUMMARY:
==23463==     in use at exit: 24 bytes in 1 blocks
==23463==   total heap usage: 1 allocs, 0 frees, 24 bytes allocated
==23463== 
==23463== 24 bytes in 1 blocks are definitely lost in loss record 1 of 1
==23463==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==23463==    by 0x10866D: func (example_compliant.c:14)
==23463==    by 0x1086BA: main (example_compliant.c:31)
==23463== 
==23463== LEAK SUMMARY:
==23463==    definitely lost: 24 bytes in 1 blocks
==23463==    indirectly lost: 0 bytes in 0 blocks
==23463==      possibly lost: 0 bytes in 0 blocks
==23463==    still reachable: 0 bytes in 0 blocks
==23463==         suppressed: 0 bytes in 0 blocks
==23463== 
==23463== For counts of detected and suppressed errors, rerun with: -v
==23463== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
