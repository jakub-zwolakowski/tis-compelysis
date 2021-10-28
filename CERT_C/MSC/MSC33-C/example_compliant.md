## example_compliant
### Test
```
Time: Sat Mar 25 06:42:99 1989```
### gcc
```
example_compliant.c: In function ‘func’:
example_compliant.c:11:10: warning: unused variable ‘size’ [-Wunused-variable]
   size_t size = strftime(s, maxsize, format, time); // This is an UB too actually...
          ^~~~
```
### clang
```
example_compliant.c:11:10: warning: unused variable 'size' [-Wunused-variable]
  size_t size = strftime(s, maxsize, format, time); // This is an UB too actually...
         ^
1 warning generated.
```
### UBSan
```
Time: Sat Mar 25 06:42:99 1989```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== 
Time: Sat Mar 25 06:42:99 1989==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
