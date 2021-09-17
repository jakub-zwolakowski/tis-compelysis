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
==27653== Memcheck, a memory error detector
==27653== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27653== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27653== Command: ./example_compliant.out
==27653== 
==27653== 
==27653== HEAP SUMMARY:
==27653==     in use at exit: 552 bytes in 1 blocks
==27653==   total heap usage: 4 allocs, 3 frees, 9,296 bytes allocated
==27653== 
==27653== LEAK SUMMARY:
==27653==    definitely lost: 0 bytes in 0 blocks
==27653==    indirectly lost: 0 bytes in 0 blocks
==27653==      possibly lost: 0 bytes in 0 blocks
==27653==    still reachable: 552 bytes in 1 blocks
==27653==         suppressed: 0 bytes in 0 blocks
==27653== Reachable blocks (those to which a pointer was found) are not shown.
==27653== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==27653== 
==27653== For counts of detected and suppressed errors, rerun with: -v
==27653== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
