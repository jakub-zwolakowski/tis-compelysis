## example
### Test
```
fread in opener_compliant: ******************************************
fread in opener_noncompliant: ******************************************
```
### gcc
```
```
### clang
```
```
### UBSan
```
fread in opener_compliant: ******************************************
fread in opener_noncompliant: ******************************************
```
### Valgrind
```
==26507== Memcheck, a memory error detector
==26507== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26507== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26507== Command: ./example.out
==26507== 
fread in opener_compliant: ******************************************
fread in opener_noncompliant: ******************************************
==26507== 
==26507== HEAP SUMMARY:
==26507==     in use at exit: 0 bytes in 0 blocks
==26507==   total heap usage: 9 allocs, 9 frees, 22,688 bytes allocated
==26507== 
==26507== All heap blocks were freed -- no leaks are possible
==26507== 
==26507== For counts of detected and suppressed errors, rerun with: -v
==26507== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
