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
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 552 bytes in 1 blocks
==12345==   total heap usage: 1 allocs, 0 frees, 552 bytes allocated
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 0 bytes in 0 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 552 bytes in 1 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== Reachable blocks (those to which a pointer was found) are not shown.
==12345== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```