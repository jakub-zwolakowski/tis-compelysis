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
valgrind: ./example_noncompliant.out: No such file or directory
```
