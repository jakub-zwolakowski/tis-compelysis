# Examples
## example_compliant
### Test
```
```
### gcc
```
example_compliant.c: In function ‘func’:
example_compliant.c:4:7: warning: variable ‘Ё’ set but not used [-Wunused-but-set-variable]
   int \u0401;
       ^~~~~~
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==31197== Memcheck, a memory error detector
==31197== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31197== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31197== Command: ./example_compliant.out
==31197== 
==31197== 
==31197== HEAP SUMMARY:
==31197==     in use at exit: 0 bytes in 0 blocks
==31197==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==31197== 
==31197== All heap blocks were freed -- no leaks are possible
==31197== 
==31197== For counts of detected and suppressed errors, rerun with: -v
==31197== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
/bin/sh: 1: ./example_noncompliant.out: not found
```
### gcc
```
example_noncompliant.c: In function ‘func’:
example_noncompliant.c:6:10: error: stray ‘\’ in program
   assign(\u04, 01, 4);
          ^
example_noncompliant.c:1:31: note: in definition of macro ‘assign’
 #define assign(uc1, uc2, val) uc1##uc2 = val
                               ^~~
example_noncompliant.c:6:11: error: ‘u0401’ undeclared (first use in this function)
   assign(\u04, 01, 4);
           ^
example_noncompliant.c:1:31: note: in definition of macro ‘assign’
 #define assign(uc1, uc2, val) uc1##uc2 = val
                               ^~~
example_noncompliant.c:6:11: note: each undeclared identifier is reported only once for each function it appears in
   assign(\u04, 01, 4);
           ^
example_noncompliant.c:1:31: note: in definition of macro ‘assign’
 #define assign(uc1, uc2, val) uc1##uc2 = val
                               ^~~
example_noncompliant.c:4:7: warning: unused variable ‘Ё’ [-Wunused-variable]
   int \u0401;
       ^~~~~~
```
### clang
```
example_noncompliant.c:6:10: warning: incomplete universal character name; treating as '\' followed by identifier [-Wunicode]
  assign(\u04, 01, 4);
         ^
example_noncompliant.c:6:10: error: expected expression
1 warning and 1 error generated.
```
### UBSan
```
/bin/sh: 1: ./example_noncompliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_noncompliant.out: No such file or directory
```
## example
### Test
```
/bin/sh: 1: ./example.out: not found
```
### gcc
```
example.c: In function ‘func_noncompliant’:
example.c:6:23: error: stray ‘\’ in program
   assign_noncompliant(\u04, 01, 4);
                       ^
example.c:1:44: note: in definition of macro ‘assign_noncompliant’
 #define assign_noncompliant(uc1, uc2, val) uc1##uc2 = val
                                            ^~~
example.c:6:24: error: ‘u0401’ undeclared (first use in this function)
   assign_noncompliant(\u04, 01, 4);
                        ^
example.c:1:44: note: in definition of macro ‘assign_noncompliant’
 #define assign_noncompliant(uc1, uc2, val) uc1##uc2 = val
                                            ^~~
example.c:6:24: note: each undeclared identifier is reported only once for each function it appears in
   assign_noncompliant(\u04, 01, 4);
                        ^
example.c:1:44: note: in definition of macro ‘assign_noncompliant’
 #define assign_noncompliant(uc1, uc2, val) uc1##uc2 = val
                                            ^~~
example.c:4:7: warning: unused variable ‘Ё’ [-Wunused-variable]
   int \u0401;
       ^~~~~~
example.c: In function ‘func_compliant’:
example.c:13:7: warning: variable ‘Ё’ set but not used [-Wunused-but-set-variable]
   int \u0401;
       ^~~~~~
```
### clang
```
example.c:6:23: warning: incomplete universal character name; treating as '\' followed by identifier [-Wunicode]
  assign_noncompliant(\u04, 01, 4);
                      ^
example.c:6:23: error: expected expression
1 warning and 1 error generated.
```
### UBSan
```
/bin/sh: 1: ./example.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example.out: No such file or directory
```
