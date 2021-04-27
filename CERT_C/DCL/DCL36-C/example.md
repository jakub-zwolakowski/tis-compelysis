## example
### Test
```
/bin/sh: 1: ./example.out: not found
```
### gcc
```
example.c:3:12: warning: ‘i3’ initialized and declared ‘extern’
 extern int i3 = 30;  /* Definition, external linkage */
            ^~
example.c:8:5: error: non-static declaration of ‘i2’ follows static declaration
 int i2;  /* Undefined, linkage disagreement with previous */
     ^~
example.c:2:12: note: previous definition of ‘i2’ was here
 static int i2 = 20;  /* Definition, internal linkage */
            ^~
example.c:11:5: error: non-static declaration of ‘i5’ follows static declaration
 int i5;  /* Undefined, linkage disagreement with previous */
     ^~
example.c:5:12: note: previous declaration of ‘i5’ was here
 static int i5;       /* Tentative definition, internal linkage */
            ^~
example.c:5:12: warning: ‘i5’ defined but not used [-Wunused-variable]
example.c:2:12: warning: ‘i2’ defined but not used [-Wunused-variable]
 static int i2 = 20;  /* Definition, internal linkage */
            ^~
```
### clang
```
example.c:3:12: warning: 'extern' variable has an initializer [-Wextern-initializer]
extern int i3 = 30;  /* Definition, external linkage */
           ^
example.c:8:5: error: non-static declaration of 'i2' follows static declaration
int i2;  /* Undefined, linkage disagreement with previous */
    ^
example.c:2:12: note: previous definition is here
static int i2 = 20;  /* Definition, internal linkage */
           ^
example.c:11:5: error: non-static declaration of 'i5' follows static declaration
int i5;  /* Undefined, linkage disagreement with previous */
    ^
example.c:5:12: note: previous definition is here
static int i5;       /* Tentative definition, internal linkage */
           ^
1 warning and 2 errors generated.
```
### UBSan
```
/bin/sh: 1: ./example.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example.out: No such file or directory
```
