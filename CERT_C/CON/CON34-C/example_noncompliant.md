## example_noncompliant
### Test
```
Result: 21854
```
### gcc
```
```
### clang
```
```
### UBSan
```
Result: 0
```
### Valgrind
```
==30018== Memcheck, a memory error detector
==30018== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30018== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30018== Command: ./example_noncompliant.out
==30018== 
Result: 0
==30018== 
==30018== HEAP SUMMARY:
==30018==     in use at exit: 0 bytes in 0 blocks
==30018==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==30018== 
==30018== All heap blocks were freed -- no leaks are possible
==30018== 
==30018== For counts of detected and suppressed errors, rerun with: -v
==30018== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
