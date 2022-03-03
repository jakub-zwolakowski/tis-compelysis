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
valgrind: ./example.out: No such file or directory
```
