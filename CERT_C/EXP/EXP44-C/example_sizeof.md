## example_sizeof
### Test
```
15, 4
14, 4
```
### gcc
```
```
### clang
```
example_sizeof.c:5:17: error: expression with side effects has no effect in an unevaluated context [-Werror,-Wunevaluated-expression]
  int b = sizeof(a++);
                ^
1 error generated.
```
### UBSan
```
15, 4
14, 4
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_sizeof.out
==12345== 
15, 4
14, 4
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
