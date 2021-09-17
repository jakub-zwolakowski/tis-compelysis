## example_noncompliant
### Test
```
/bin/sh: 1: ./example_noncompliant.out: not found
```
### gcc
```
example_noncompliant.c: In function ‘func’:
example_noncompliant.c:10:21: error: ‘assert’ undeclared (first use in this function); did you mean ‘__assert’?
   execute_handler(&(assert), e < 0);
                     ^~~~~~
                     __assert
example_noncompliant.c:10:21: note: each undeclared identifier is reported only once for each function it appears in
```
### clang
```
example_noncompliant.c:10:21: error: use of undeclared identifier 'assert'; did you mean '__assert'?
  execute_handler(&(assert), e < 0);
                    ^~~~~~
                    __assert
/usr/include/assert.h:81:13: note: '__assert' declared here
extern void __assert (const char *__assertion, const char *__file, int __line)
            ^
example_noncompliant.c:10:19: warning: incompatible function pointer types passing 'void (*)(const char *, const char *, int) __attribute__((noreturn))' to parameter of type 'handler_type' (aka 'void (*)(int)') [-Wincompatible-function-pointer-types]
  execute_handler(&(assert), e < 0);
                  ^~~~~~~~~
example_noncompliant.c:5:35: note: passing argument to parameter 'handler' here
void execute_handler(handler_type handler, int value) {
                                  ^
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
