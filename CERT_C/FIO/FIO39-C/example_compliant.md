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
==27127== Memcheck, a memory error detector
==27127== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27127== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27127== Command: ./example_compliant.out
==27127== 
==27127== 
==27127== HEAP SUMMARY:
==27127==     in use at exit: 552 bytes in 1 blocks
==27127==   total heap usage: 2 allocs, 1 frees, 4,648 bytes allocated
==27127== 
==27127== LEAK SUMMARY:
==27127==    definitely lost: 0 bytes in 0 blocks
==27127==    indirectly lost: 0 bytes in 0 blocks
==27127==      possibly lost: 0 bytes in 0 blocks
==27127==    still reachable: 552 bytes in 1 blocks
==27127==         suppressed: 0 bytes in 0 blocks
==27127== Reachable blocks (those to which a pointer was found) are not shown.
==27127== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==27127== 
==27127== For counts of detected and suppressed errors, rerun with: -v
==27127== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
