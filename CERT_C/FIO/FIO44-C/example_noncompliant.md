## example_noncompliant
### Test
```
fread in opener: ******************************************
```
### gcc
```
```
### clang
```
```
### UBSan
```
fread in opener: ******************************************
```
### Valgrind
```
==26438== Memcheck, a memory error detector
==26438== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26438== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26438== Command: ./example_noncompliant.out
==26438== 
fread in opener: ******************************************
==26438== 
==26438== HEAP SUMMARY:
==26438==     in use at exit: 0 bytes in 0 blocks
==26438==   total heap usage: 5 allocs, 5 frees, 13,392 bytes allocated
==26438== 
==26438== All heap blocks were freed -- no leaks are possible
==26438== 
==26438== For counts of detected and suppressed errors, rerun with: -v
==26438== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
