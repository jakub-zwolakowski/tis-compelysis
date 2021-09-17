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
==25016== Memcheck, a memory error detector
==25016== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25016== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25016== Command: ./example_compliant.out
==25016== 
==25016== 
==25016== HEAP SUMMARY:
==25016==     in use at exit: 0 bytes in 0 blocks
==25016==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==25016== 
==25016== All heap blocks were freed -- no leaks are possible
==25016== 
==25016== For counts of detected and suppressed errors, rerun with: -v
==25016== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==25084== Memcheck, a memory error detector
==25084== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25084== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25084== Command: ./example_noncompliant.out
==25084== 
==25084== 
==25084== HEAP SUMMARY:
==25084==     in use at exit: 0 bytes in 0 blocks
==25084==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==25084== 
==25084== All heap blocks were freed -- no leaks are possible
==25084== 
==25084== For counts of detected and suppressed errors, rerun with: -v
==25084== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==25152== Memcheck, a memory error detector
==25152== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25152== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25152== Command: ./example.out
==25152== 
==25152== 
==25152== HEAP SUMMARY:
==25152==     in use at exit: 0 bytes in 0 blocks
==25152==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==25152== 
==25152== All heap blocks were freed -- no leaks are possible
==25152== 
==25152== For counts of detected and suppressed errors, rerun with: -v
==25152== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
