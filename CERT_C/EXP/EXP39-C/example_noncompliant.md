## example_noncompliant
### Test
```
float is 0.000000
```
### gcc
```
```
### clang
```
```
### UBSan
```
float is 0.000000
```
### Valgrind
```
==1894== Memcheck, a memory error detector
==1894== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1894== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1894== Command: ./example_noncompliant.out
==1894== 
float is 0.000000
==1894== 
==1894== HEAP SUMMARY:
==1894==     in use at exit: 0 bytes in 0 blocks
==1894==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==1894== 
==1894== All heap blocks were freed -- no leaks are possible
==1894== 
==1894== For counts of detected and suppressed errors, rerun with: -v
==1894== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
