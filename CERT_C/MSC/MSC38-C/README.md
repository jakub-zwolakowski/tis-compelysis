# Examples
## example_compliant
### Test
```
example_compliant.out: example_compliant.c:10: assert_handler: Assertion `value' failed.
Aborted (core dumped)
```
### gcc
```
```
### clang
```
```
### UBSan
```
example_compliant.UBSan-out: example_compliant.c:10: void assert_handler(int): Assertion `value' failed.
Aborted (core dumped)
```
### Valgrind
```
==31537== Memcheck, a memory error detector
==31537== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31537== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31537== Command: ./example_compliant.out
==31537== 
example_compliant.out: example_compliant.c:10: assert_handler: Assertion `value' failed.
==31537== 
==31537== Process terminating with default action of signal 6 (SIGABRT)
==31537==    at 0x4E7CFB7: raise (raise.c:51)
==31537==    by 0x4E7E920: abort (abort.c:79)
==31537==    by 0x4E6E489: __assert_fail_base (assert.c:92)
==31537==    by 0x4E6E501: __assert_fail (assert.c:101)
==31537==    by 0x108696: assert_handler (example_compliant.c:10)
==31537==    by 0x108663: execute_handler (example_compliant.c:6)
==31537==    by 0x1086BB: func (example_compliant.c:14)
==31537==    by 0x1086CC: main (example_compliant.c:18)
==31537== 
==31537== HEAP SUMMARY:
==31537==     in use at exit: 0 bytes in 0 blocks
==31537==   total heap usage: 2 allocs, 2 frees, 190 bytes allocated
==31537== 
==31537== All heap blocks were freed -- no leaks are possible
==31537== 
==31537== For counts of detected and suppressed errors, rerun with: -v
==31537== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
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
## example
### Test
```
/bin/sh: 1: ./example.out: not found
```
### gcc
```
example.c: In function ‘func_noncompliant’:
example.c:10:21: error: ‘assert’ undeclared (first use in this function); did you mean ‘__assert’?
   execute_handler(&(assert), e < 0);
                     ^~~~~~
                     __assert
example.c:10:21: note: each undeclared identifier is reported only once for each function it appears in
```
### clang
```
example.c:10:21: error: use of undeclared identifier 'assert'; did you mean '__assert'?
  execute_handler(&(assert), e < 0);
                    ^~~~~~
                    __assert
/usr/include/assert.h:81:13: note: '__assert' declared here
extern void __assert (const char *__assertion, const char *__file, int __line)
            ^
example.c:10:19: warning: incompatible function pointer types passing 'void (*)(const char *, const char *, int) __attribute__((noreturn))' to parameter of type 'handler_type' (aka 'void (*)(int)') [-Wincompatible-function-pointer-types]
  execute_handler(&(assert), e < 0);
                  ^~~~~~~~~
example.c:5:35: note: passing argument to parameter 'handler' here
void execute_handler(handler_type handler, int value) {
                                  ^
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