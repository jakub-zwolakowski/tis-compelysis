# Examples
## example_compliant
### Test
```
stdout successfully closed.
```
### gcc
```
```
### clang
```
```
### UBSan
```
stdout successfully closed.
```
### Valgrind
```
==29267== Memcheck, a memory error detector
==29267== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29267== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29267== Command: ./example_compliant.out
==29267== 
stdout successfully closed.
==29267== 
==29267== HEAP SUMMARY:
==29267==     in use at exit: 0 bytes in 0 blocks
==29267==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==29267== 
==29267== All heap blocks were freed -- no leaks are possible
==29267== 
==29267== For counts of detected and suppressed errors, rerun with: -v
==29267== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==29335== Memcheck, a memory error detector
==29335== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29335== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29335== Command: ./example_noncompliant.out
==29335== 
==29335== 
==29335== HEAP SUMMARY:
==29335==     in use at exit: 0 bytes in 0 blocks
==29335==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==29335== 
==29335== All heap blocks were freed -- no leaks are possible
==29335== 
==29335== For counts of detected and suppressed errors, rerun with: -v
==29335== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example
### Test
```
compliant
compliant: stdout successfully closed.
noncompliant
```
### gcc
```
```
### clang
```
```
### UBSan
```
compliant
compliant: stdout successfully closed.
noncompliant
```
### Valgrind
```
==29404== Memcheck, a memory error detector
==29404== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29404== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29404== Command: ./example.out
==29404== 
compliant
compliant: stdout successfully closed.
==29404== 
==29404== HEAP SUMMARY:
==29404==     in use at exit: 0 bytes in 0 blocks
==29404==   total heap usage: 2 allocs, 2 frees, 8,192 bytes allocated
==29404== 
==29404== All heap blocks were freed -- no leaks are possible
==29404== 
==29404== For counts of detected and suppressed errors, rerun with: -v
==29404== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
