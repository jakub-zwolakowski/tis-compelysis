## example
### Test
```
float is 0.000000
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
float is 0.000000
```
### Valgrind
```
==1962== Memcheck, a memory error detector
==1962== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1962== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1962== Command: ./example.out
==1962== 
float is 0.000000
float is 0.000000
==1962== 
==1962== HEAP SUMMARY:
==1962==     in use at exit: 0 bytes in 0 blocks
==1962==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==1962== 
==1962== All heap blocks were freed -- no leaks are possible
==1962== 
==1962== For counts of detected and suppressed errors, rerun with: -v
==1962== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
