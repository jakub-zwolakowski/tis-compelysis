# Examples
## example1
### Test
```
42, 142, 1```
### gcc
```
example1.c: In function ‘f_noncompliant’:
example1.c:4:17: warning: operation on ‘i’ may be undefined [-Wsequence-point]
   int a = i + b[++i];
                 ^~~
```
### clang
```
example1.c:4:17: error: unsequenced modification and access to 'i' [-Werror,-Wunsequenced]
  int a = i + b[++i];
          ~     ^
1 error generated.
```
### UBSan
```
42, 141, 1```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example1.out
==12345== 
42, 142, 1==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
