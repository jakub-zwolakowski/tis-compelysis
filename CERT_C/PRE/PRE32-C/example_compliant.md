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
==30989== Memcheck, a memory error detector
==30989== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30989== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30989== Command: ./example_compliant.out
==30989== 
==30989== 
==30989== HEAP SUMMARY:
==30989==     in use at exit: 31 bytes in 1 blocks
==30989==   total heap usage: 1 allocs, 0 frees, 31 bytes allocated
==30989== 
==30989== 31 bytes in 1 blocks are definitely lost in loss record 1 of 1
==30989==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30989==    by 0x108714: func (example_compliant.c:9)
==30989==    by 0x108743: main (example_compliant.c:19)
==30989== 
==30989== LEAK SUMMARY:
==30989==    definitely lost: 31 bytes in 1 blocks
==30989==    indirectly lost: 0 bytes in 0 blocks
==30989==      possibly lost: 0 bytes in 0 blocks
==30989==    still reachable: 0 bytes in 0 blocks
==30989==         suppressed: 0 bytes in 0 blocks
==30989== 
==30989== For counts of detected and suppressed errors, rerun with: -v
==30989== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
