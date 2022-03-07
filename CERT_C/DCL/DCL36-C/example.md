## example
### Test
```
timeout: failed to run command ‘./example.out’: No such file or directory
```
### gcc
```
example.c:3:12: error: ‘i3’ initialized and declared ‘extern’ [-Werror]
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
cc1: all warnings being treated as errors
```
### clang
```
example.c:3:12: error: 'extern' variable has an initializer [-Werror,-Wextern-initializer]
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
3 errors generated.
```
### UBSan
```
timeout: failed to run command ‘./example.UBSan-out’: No such file or directory
```
### Valgrind
```
```
