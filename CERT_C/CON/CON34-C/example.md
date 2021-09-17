## example
### Test
```
Result: 1
Result: 22088
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
Result: 0
```
### Valgrind
```
==30091== Memcheck, a memory error detector
==30091== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30091== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30091== Command: ./example.out
==30091== 
Result: 1
Result: 0
==30091== 
==30091== HEAP SUMMARY:
==30091==     in use at exit: 0 bytes in 0 blocks
==30091==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==30091== 
==30091== All heap blocks were freed -- no leaks are possible
==30091== 
==30091== For counts of detected and suppressed errors, rerun with: -v
==30091== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
