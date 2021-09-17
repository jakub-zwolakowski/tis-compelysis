## example_compliant
### Test
```
exit2
exit2 : some_condition
exit1
```
### gcc
```
```
### clang
```
```
### UBSan
```
exit2
exit2 : some_condition
exit1
```
### Valgrind
```
==25298== Memcheck, a memory error detector
==25298== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25298== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25298== Command: ./example_compliant.out
==25298== 
exit2
exit2 : some_condition
exit1
==25298== 
==25298== HEAP SUMMARY:
==25298==     in use at exit: 0 bytes in 0 blocks
==25298==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==25298== 
==25298== All heap blocks were freed -- no leaks are possible
==25298== 
==25298== For counts of detected and suppressed errors, rerun with: -v
==25298== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
