## example_compliant
### Test
```
fread in opener: ******************************************
```
### gcc
```
```
### clang
```
```
### UBSan
```
fread in opener: ******************************************
```
### Valgrind
```
==26370== Memcheck, a memory error detector
==26370== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26370== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26370== Command: ./example_compliant.out
==26370== 
fread in opener: ******************************************
==26370== 
==26370== HEAP SUMMARY:
==26370==     in use at exit: 0 bytes in 0 blocks
==26370==   total heap usage: 5 allocs, 5 frees, 13,392 bytes allocated
==26370== 
==26370== All heap blocks were freed -- no leaks are possible
==26370== 
==26370== For counts of detected and suppressed errors, rerun with: -v
==26370== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
