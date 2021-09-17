## example
### Test
```
I "love" you
I _love_ you
check: I "love" you
I "love" you
I _love_ you
check: I _love_ you
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
I "love" you
I _love_ you
check: I _love_ you
```
### Valgrind
```
==25645== Memcheck, a memory error detector
==25645== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25645== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25645== Command: ./example.out
==25645== 
I "love" you
I _love_ you
check: I "love" you
I "love" you
I _love_ you
check: I _love_ you
==25645== 
==25645== HEAP SUMMARY:
==25645==     in use at exit: 0 bytes in 0 blocks
==25645==   total heap usage: 5 allocs, 5 frees, 4,843 bytes allocated
==25645== 
==25645== All heap blocks were freed -- no leaks are possible
==25645== 
==25645== For counts of detected and suppressed errors, rerun with: -v
==25645== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
