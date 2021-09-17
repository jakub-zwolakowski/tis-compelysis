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
==31125== Memcheck, a memory error detector
==31125== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31125== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31125== Command: ./example.out
==31125== 
==31125== 
==31125== HEAP SUMMARY:
==31125==     in use at exit: 62 bytes in 2 blocks
==31125==   total heap usage: 2 allocs, 0 frees, 62 bytes allocated
==31125== 
==31125== 31 bytes in 1 blocks are definitely lost in loss record 1 of 2
==31125==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==31125==    by 0x10875E: func_compliant (example.c:25)
==31125==    by 0x10878D: main (example.c:35)
==31125== 
==31125== 31 bytes in 1 blocks are definitely lost in loss record 2 of 2
==31125==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==31125==    by 0x108714: func_noncompliant (example.c:9)
==31125==    by 0x108799: main (example.c:36)
==31125== 
==31125== LEAK SUMMARY:
==31125==    definitely lost: 62 bytes in 2 blocks
==31125==    indirectly lost: 0 bytes in 0 blocks
==31125==      possibly lost: 0 bytes in 0 blocks
==31125==    still reachable: 0 bytes in 0 blocks
==31125==         suppressed: 0 bytes in 0 blocks
==31125== 
==31125== For counts of detected and suppressed errors, rerun with: -v
==31125== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
