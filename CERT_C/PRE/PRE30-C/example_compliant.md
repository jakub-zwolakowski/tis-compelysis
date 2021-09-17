## example_compliant
### Test
```
```
### gcc
```
example_compliant.c: In function ‘func’:
example_compliant.c:4:7: warning: variable ‘Ё’ set but not used [-Wunused-but-set-variable]
   int \u0401;
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
==31197== Memcheck, a memory error detector
==31197== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31197== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31197== Command: ./example_compliant.out
==31197== 
==31197== 
==31197== HEAP SUMMARY:
==31197==     in use at exit: 0 bytes in 0 blocks
==31197==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==31197== 
==31197== All heap blocks were freed -- no leaks are possible
==31197== 
==31197== For counts of detected and suppressed errors, rerun with: -v
==31197== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
