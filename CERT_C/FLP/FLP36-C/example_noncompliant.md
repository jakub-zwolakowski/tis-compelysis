## example_noncompliant
### Test
```
-46
```
### gcc
```
```
### clang
```
```
### UBSan
```
-46
```
### Valgrind
```
==8981== Memcheck, a memory error detector
==8981== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8981== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8981== Command: ./example_noncompliant.out
==8981== 
-46
==8981== 
==8981== HEAP SUMMARY:
==8981==     in use at exit: 0 bytes in 0 blocks
==8981==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==8981== 
==8981== All heap blocks were freed -- no leaks are possible
==8981== 
==8981== For counts of detected and suppressed errors, rerun with: -v
==8981== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
