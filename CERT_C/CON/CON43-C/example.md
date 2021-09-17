## example
### Test
```
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
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
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
-42
0
```
### Valgrind
```
==30401== Memcheck, a memory error detector
==30401== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30401== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30401== Command: ./example.out
==30401== 
42
84
126
84
126
168
126
84
42
0
-42
0
-42
0
-42
-84
-126
-84
-42
0
==30401== 
==30401== HEAP SUMMARY:
==30401==     in use at exit: 0 bytes in 0 blocks
==30401==   total heap usage: 17 allocs, 17 frees, 8,448 bytes allocated
==30401== 
==30401== All heap blocks were freed -- no leaks are possible
==30401== 
==30401== For counts of detected and suppressed errors, rerun with: -v
==30401== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
