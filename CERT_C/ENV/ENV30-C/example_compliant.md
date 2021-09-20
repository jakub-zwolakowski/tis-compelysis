## example_compliant
### Test
```
I "love" you
I _love_ you
check: I "love" you
```
### gcc
```
```
### clang
```
```
### UBSan
```
I "love" you
I _love_ you
check: I "love" you
```
### Valgrind
```
==25507== Memcheck, a memory error detector
==25507== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25507== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25507== Command: ./example_compliant.out
==25507== 
I "love" you
I _love_ you
check: I "love" you
==25507== 
==25507== HEAP SUMMARY:
==25507==     in use at exit: 0 bytes in 0 blocks
==25507==   total heap usage: 5 allocs, 5 frees, 4,843 bytes allocated
==25507== 
==25507== All heap blocks were freed -- no leaks are possible
==25507== 
==25507== For counts of detected and suppressed errors, rerun with: -v
==25507== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```