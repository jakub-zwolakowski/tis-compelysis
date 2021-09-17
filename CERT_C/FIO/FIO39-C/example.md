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
==27264== Memcheck, a memory error detector
==27264== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27264== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27264== Command: ./example.out
==27264== 
==27264== 
==27264== HEAP SUMMARY:
==27264==     in use at exit: 552 bytes in 1 blocks
==27264==   total heap usage: 4 allocs, 3 frees, 9,296 bytes allocated
==27264== 
==27264== LEAK SUMMARY:
==27264==    definitely lost: 0 bytes in 0 blocks
==27264==    indirectly lost: 0 bytes in 0 blocks
==27264==      possibly lost: 0 bytes in 0 blocks
==27264==    still reachable: 552 bytes in 1 blocks
==27264==         suppressed: 0 bytes in 0 blocks
==27264== Reachable blocks (those to which a pointer was found) are not shown.
==27264== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==27264== 
==27264== For counts of detected and suppressed errors, rerun with: -v
==27264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
