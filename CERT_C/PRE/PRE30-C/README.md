# Examples
## example_compliant
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
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
## example_noncompliant
### Test
```
timeout: failed to run command ‘./example_noncompliant.out’: No such file or directory
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
```
### clang
```
example_noncompliant.c:6:10: error: incomplete universal character name; treating as '\' followed by identifier [-Werror,-Wunicode]
  assign(\u04, 01, 4);
         ^
example_noncompliant.c:6:10: error: expected expression
2 errors generated.
```
### UBSan
```
timeout: failed to run command ‘./example_noncompliant.UBSan-out’: No such file or directory
```
### Valgrind
```
```
## example
### Test
```
timeout: failed to run command ‘./example.out’: No such file or directory
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
```
### clang
```
example.c:6:23: error: incomplete universal character name; treating as '\' followed by identifier [-Werror,-Wunicode]
  assign_noncompliant(\u04, 01, 4);
                      ^
example.c:6:23: error: expected expression
2 errors generated.
```
### UBSan
```
timeout: failed to run command ‘./example.UBSan-out’: No such file or directory
```
### Valgrind
```
```
