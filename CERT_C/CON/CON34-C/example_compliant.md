## example_compliant
### Test
```
Result: 1
```
### gcc
```
```
### clang
```
```
### UBSan
```
Result: 1
```
### Valgrind
```
==29947== Memcheck, a memory error detector
==29947== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29947== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29947== Command: ./example_compliant.out
==29947== 
Result: 1
==29947== 
==29947== HEAP SUMMARY:
==29947==     in use at exit: 0 bytes in 0 blocks
==29947==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==29947== 
==29947== All heap blocks were freed -- no leaks are possible
==29947== 
==29947== For counts of detected and suppressed errors, rerun with: -v
==29947== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
