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
