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
==31057== Memcheck, a memory error detector
==31057== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31057== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31057== Command: ./example_noncompliant.out
==31057== 
==31057== 
==31057== HEAP SUMMARY:
==31057==     in use at exit: 31 bytes in 1 blocks
==31057==   total heap usage: 1 allocs, 0 frees, 31 bytes allocated
==31057== 
==31057== 31 bytes in 1 blocks are definitely lost in loss record 1 of 1
==31057==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==31057==    by 0x108714: func (example_noncompliant.c:9)
==31057==    by 0x108743: main (example_noncompliant.c:21)
==31057== 
==31057== LEAK SUMMARY:
==31057==    definitely lost: 31 bytes in 1 blocks
==31057==    indirectly lost: 0 bytes in 0 blocks
==31057==      possibly lost: 0 bytes in 0 blocks
==31057==    still reachable: 0 bytes in 0 blocks
==31057==         suppressed: 0 bytes in 0 blocks
==31057== 
==31057== For counts of detected and suppressed errors, rerun with: -v
==31057== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
