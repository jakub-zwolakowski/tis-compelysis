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
