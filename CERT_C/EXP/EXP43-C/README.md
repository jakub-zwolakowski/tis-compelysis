# Examples
## example_compliant
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==4006== Memcheck, a memory error detector
==4006== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4006== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4006== Command: ./example_compliant.out
==4006== 
==4006== 
==4006== HEAP SUMMARY:
==4006==     in use at exit: 0 bytes in 0 blocks
==4006==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4006== 
==4006== All heap blocks were freed -- no leaks are possible
==4006== 
==4006== For counts of detected and suppressed errors, rerun with: -v
==4006== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==4074== Memcheck, a memory error detector
==4074== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4074== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4074== Command: ./example_noncompliant.out
==4074== 
==4074== 
==4074== HEAP SUMMARY:
==4074==     in use at exit: 0 bytes in 0 blocks
==4074==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4074== 
==4074== All heap blocks were freed -- no leaks are possible
==4074== 
==4074== For counts of detected and suppressed errors, rerun with: -v
==4074== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==4145== Memcheck, a memory error detector
==4145== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4145== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4145== Command: ./example.out
==4145== 
==4145== 
==4145== HEAP SUMMARY:
==4145==     in use at exit: 0 bytes in 0 blocks
==4145==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4145== 
==4145== All heap blocks were freed -- no leaks are possible
==4145== 
==4145== For counts of detected and suppressed errors, rerun with: -v
==4145== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
