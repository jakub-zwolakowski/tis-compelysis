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
example_noncompliant.c:14:3: runtime error: index 18446744073709551615 out of bounds for type 'char [1024]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_noncompliant.c:14:3 in 
example_noncompliant.c:14:3: runtime error: addition of unsigned offset to 0x7ffe489f9f20 overflowed to 0x7ffe489f9f1f
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_noncompliant.c:14:3 in 
```
### Valgrind
```
==27575== Memcheck, a memory error detector
==27575== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27575== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27575== Command: ./example_noncompliant.out
==27575== 
==27575== 
==27575== HEAP SUMMARY:
==27575==     in use at exit: 552 bytes in 1 blocks
==27575==   total heap usage: 4 allocs, 3 frees, 9,296 bytes allocated
==27575== 
==27575== LEAK SUMMARY:
==27575==    definitely lost: 0 bytes in 0 blocks
==27575==    indirectly lost: 0 bytes in 0 blocks
==27575==      possibly lost: 0 bytes in 0 blocks
==27575==    still reachable: 552 bytes in 1 blocks
==27575==         suppressed: 0 bytes in 0 blocks
==27575== Reachable blocks (those to which a pointer was found) are not shown.
==27575== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==27575== 
==27575== For counts of detected and suppressed errors, rerun with: -v
==27575== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
