# Examples
## example_compliant
### Test
```
example_compliant.out: example_compliant.c:10: assert_handler: Assertion `value' failed.
timeout: the monitored command dumped core
Aborted
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
timeout: the monitored command dumped core
Aborted
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
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __assert_fail_base (assert.c:92)
==12345==    by 0x424242424242: __assert_fail (assert.c:101)
==12345==    by 0x424242424242: assert_handler (example_compliant.c:10)
==12345==    by 0x424242424242: execute_handler (example_compliant.c:6)
==12345==    by 0x424242424242: func (example_compliant.c:14)
==12345==    by 0x424242424242: main (example_compliant.c:18)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 123 bytes allocated
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
example_noncompliant.c:10:19: error: incompatible function pointer types passing 'void (*)(const char *, const char *, int) __attribute__((noreturn))' to parameter of type 'handler_type' (aka 'void (*)(int)') [-Werror,-Wincompatible-function-pointer-types]
  execute_handler(&(assert), e < 0);
                  ^~~~~~~~~
example_noncompliant.c:5:35: note: passing argument to parameter 'handler' here
void execute_handler(handler_type handler, int value) {
                                  ^
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
example.c:10:19: error: incompatible function pointer types passing 'void (*)(const char *, const char *, int) __attribute__((noreturn))' to parameter of type 'handler_type' (aka 'void (*)(int)') [-Werror,-Wincompatible-function-pointer-types]
  execute_handler(&(assert), e < 0);
                  ^~~~~~~~~
example.c:5:35: note: passing argument to parameter 'handler' here
void execute_handler(handler_type handler, int value) {
                                  ^
2 errors generated.
```
### UBSan
```
timeout: failed to run command ‘./example.UBSan-out’: No such file or directory
```
### Valgrind
```
```
