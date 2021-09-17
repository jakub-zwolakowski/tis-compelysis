## example_noncompliant
### Test
```
-42
0
42
0
0
-42
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
42
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
==30283== Memcheck, a memory error detector
==30283== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30283== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30283== Command: ./example_noncompliant.out
==30283== 
-42
0
42
0
42
0
-42
0
42
0
==30283== 
==30283== HEAP SUMMARY:
==30283==     in use at exit: 0 bytes in 0 blocks
==30283==   total heap usage: 11 allocs, 11 frees, 6,816 bytes allocated
==30283== 
==30283== All heap blocks were freed -- no leaks are possible
==30283== 
==30283== For counts of detected and suppressed errors, rerun with: -v
==30283== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
