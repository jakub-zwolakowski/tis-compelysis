## example_noncompliant
### Test
```
Time: Sat Mar 25 06:42:99 1989
```
### gcc
```
```
### clang
```
```
### UBSan
```
Time: Sat Mar 25 06:42:99 1989
```
### Valgrind
```
==32608== Memcheck, a memory error detector
==32608== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32608== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32608== Command: ./example_noncompliant.out
==32608== 
Time: Sat Mar 25 06:42:99 1989
==32608== 
==32608== HEAP SUMMARY:
==32608==     in use at exit: 0 bytes in 0 blocks
==32608==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==32608== 
==32608== All heap blocks were freed -- no leaks are possible
==32608== 
==32608== For counts of detected and suppressed errors, rerun with: -v
==32608== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
