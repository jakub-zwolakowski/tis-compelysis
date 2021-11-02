# Examples
## sqrt
### Test
```
```
### gcc
```
sqrt.c: In function ‘f_noncompliant’:
sqrt.c:4:10: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   double result;
          ^~~~~~
sqrt.c: In function ‘f_compliant’:
sqrt.c:9:10: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   double result;
          ^~~~~~
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./sqrt.out
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
