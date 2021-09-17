## example_compliant
### Test
```
Hello, World!
```
### gcc
```
```
### clang
```
```
### UBSan
```
Hello, World!
```
### Valgrind
```
==27799== Memcheck, a memory error detector
==27799== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27799== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27799== Command: ./example_compliant.out
==27799== 
Hello, World!
==27799== 
==27799== HEAP SUMMARY:
==27799==     in use at exit: 0 bytes in 0 blocks
==27799==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==27799== 
==27799== All heap blocks were freed -- no leaks are possible
==27799== 
==27799== For counts of detected and suppressed errors, rerun with: -v
==27799== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
