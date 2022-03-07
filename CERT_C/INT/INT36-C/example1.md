## example1
### Test
```
```
### gcc
```
example1.c: In function ‘func_noncompliant’:
example1.c:5:25: error: cast from pointer to integer of different size [-Werror=pointer-to-int-cast]
   unsigned int number = (unsigned int)ptr;
                         ^
example1.c:7:9: error: cast to pointer from integer of different size [-Werror=int-to-pointer-cast]
   ptr = (char *)number;
         ^
cc1: all warnings being treated as errors
```
### clang
```
example1.c:5:25: error: cast to smaller integer type 'unsigned int' from 'char *' [-Werror,-Wpointer-to-int-cast]
  unsigned int number = (unsigned int)ptr;
                        ^~~~~~~~~~~~~~~~~
example1.c:7:9: error: cast to 'char *' from smaller integer type 'unsigned int' [-Werror,-Wint-to-pointer-cast]
  ptr = (char *)number;
        ^~~~~~~~~~~~~~
2 errors generated.
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example1.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
