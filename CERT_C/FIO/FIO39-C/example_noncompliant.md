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
==27195== Memcheck, a memory error detector
==27195== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27195== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27195== Command: ./example_noncompliant.out
==27195== 
==27195== 
==27195== HEAP SUMMARY:
==27195==     in use at exit: 552 bytes in 1 blocks
==27195==   total heap usage: 2 allocs, 1 frees, 4,648 bytes allocated
==27195== 
==27195== LEAK SUMMARY:
==27195==    definitely lost: 0 bytes in 0 blocks
==27195==    indirectly lost: 0 bytes in 0 blocks
==27195==      possibly lost: 0 bytes in 0 blocks
==27195==    still reachable: 552 bytes in 1 blocks
==27195==         suppressed: 0 bytes in 0 blocks
==27195== Reachable blocks (those to which a pointer was found) are not shown.
==27195== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==27195== 
==27195== For counts of detected and suppressed errors, rerun with: -v
==27195== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
