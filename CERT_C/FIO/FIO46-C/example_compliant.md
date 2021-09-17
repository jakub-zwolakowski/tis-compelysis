## example_compliant
### Test
```
stdout successfully closed.
```
### gcc
```
```
### clang
```
```
### UBSan
```
stdout successfully closed.
```
### Valgrind
```
==29267== Memcheck, a memory error detector
==29267== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29267== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29267== Command: ./example_compliant.out
==29267== 
stdout successfully closed.
==29267== 
==29267== HEAP SUMMARY:
==29267==     in use at exit: 0 bytes in 0 blocks
==29267==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==29267== 
==29267== All heap blocks were freed -- no leaks are possible
==29267== 
==29267== For counts of detected and suppressed errors, rerun with: -v
==29267== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
