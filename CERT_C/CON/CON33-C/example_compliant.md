## example_compliant
### Test
```
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
```
### gcc
```
```
### clang
```
```
### UBSan
```
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== 
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
errnum = XX : Some error message
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 17 allocs, 17 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```