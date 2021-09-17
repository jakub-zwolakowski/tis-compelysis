## example_compliant
### Test
```
42
0
-42
-84
-126
-84
-42
0
-42
0
```
### gcc
```
```
### clang
```
```
### UBSan
```
-42
-84
-126
-84
-42
0
-42
0
-42
0
```
### Valgrind
```
==30185== Memcheck, a memory error detector
==30185== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30185== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30185== Command: ./example_compliant.out
==30185== 
42
0
-42
0
42
0
-42
0
42
0
==30185== 
==30185== HEAP SUMMARY:
==30185==     in use at exit: 0 bytes in 0 blocks
==30185==   total heap usage: 11 allocs, 11 frees, 6,816 bytes allocated
==30185== 
==30185== All heap blocks were freed -- no leaks are possible
==30185== 
==30185== For counts of detected and suppressed errors, rerun with: -v
==30185== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
