## example_noncompliant
### Test
```
exit2
exit2 : some_condition
exit1
```
### gcc
```
```
### clang
```
```
### UBSan
```
exit2
exit2 : some_condition
exit1
```
### Valgrind
```
==25367== Memcheck, a memory error detector
==25367== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25367== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25367== Command: ./example_noncompliant.out
==25367== 
exit2
exit2 : some_condition
exit1
==25367== 
==25367== HEAP SUMMARY:
==25367==     in use at exit: 0 bytes in 0 blocks
==25367==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==25367== 
==25367== All heap blocks were freed -- no leaks are possible
==25367== 
==25367== For counts of detected and suppressed errors, rerun with: -v
==25367== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
