## example
### Test
```
Time: Sat Mar 25 06:42:99 1989Time: Sat Mar 25 06:42:99 1989
```
### gcc
```
example.c: In function ‘func_compliant’:
example.c:18:10: warning: unused variable ‘size’ [-Wunused-variable]
   size_t size = strftime(s, maxsize, format, time); // This is an UB too actually...
          ^~~~
```
### clang
```
example.c:18:10: warning: unused variable 'size' [-Wunused-variable]
  size_t size = strftime(s, maxsize, format, time); // This is an UB too actually...
         ^
1 warning generated.
```
### UBSan
```
Time: Sat Mar 25 06:42:99 1989Time: Sat Mar 25 06:42:99 1989
```
### Valgrind
```
==32682== Memcheck, a memory error detector
==32682== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32682== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32682== Command: ./example.out
==32682== 
Time: Sat Mar 25 06:42:99 1989Time: Sat Mar 25 06:42:99 1989
==32682== 
==32682== HEAP SUMMARY:
==32682==     in use at exit: 0 bytes in 0 blocks
==32682==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==32682== 
==32682== All heap blocks were freed -- no leaks are possible
==32682== 
==32682== For counts of detected and suppressed errors, rerun with: -v
==32682== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
