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
==29479== Memcheck, a memory error detector
==29479== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29479== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29479== Command: ./example_compliant.out
==29479== 
==29479== 
==29479== HEAP SUMMARY:
==29479==     in use at exit: 0 bytes in 0 blocks
==29479==   total heap usage: 1 allocs, 1 frees, 272 bytes allocated
==29479== 
==29479== All heap blocks were freed -- no leaks are possible
==29479== 
==29479== For counts of detected and suppressed errors, rerun with: -v
==29479== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==29550== Memcheck, a memory error detector
==29550== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29550== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29550== Command: ./example_noncompliant.out
==29550== 
==29550== 
==29550== HEAP SUMMARY:
==29550==     in use at exit: 0 bytes in 0 blocks
==29550==   total heap usage: 1 allocs, 1 frees, 272 bytes allocated
==29550== 
==29550== All heap blocks were freed -- no leaks are possible
==29550== 
==29550== For counts of detected and suppressed errors, rerun with: -v
==29550== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==29629== Memcheck, a memory error detector
==29629== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29629== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29629== Command: ./example.out
==29629== 
==29629== 
==29629== HEAP SUMMARY:
==29629==     in use at exit: 0 bytes in 0 blocks
==29629==   total heap usage: 1 allocs, 1 frees, 272 bytes allocated
==29629== 
==29629== All heap blocks were freed -- no leaks are possible
==29629== 
==29629== For counts of detected and suppressed errors, rerun with: -v
==29629== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
