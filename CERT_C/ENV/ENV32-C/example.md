## example
### Test
```
exit2_compliant
exit2_compliant : some_condition
exit2_noncompliant
exit2_noncompliant : some_condition
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
exit2_compliant
exit2_compliant : some_condition
exit2_noncompliant
exit2_noncompliant : some_condition
exit1
```
### Valgrind
```
==25435== Memcheck, a memory error detector
==25435== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25435== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25435== Command: ./example.out
==25435== 
exit2_compliant
exit2_compliant : some_condition
exit2_noncompliant
exit2_noncompliant : some_condition
exit1
==25435== 
==25435== HEAP SUMMARY:
==25435==     in use at exit: 0 bytes in 0 blocks
==25435==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==25435== 
==25435== All heap blocks were freed -- no leaks are possible
==25435== 
==25435== For counts of detected and suppressed errors, rerun with: -v
==25435== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
