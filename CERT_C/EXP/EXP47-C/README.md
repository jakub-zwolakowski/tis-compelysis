# Examples
## example
### Test
```
Illegal instruction (core dumped)
```
### gcc
```
example.c: In function ‘func_noncompliant’:
example.c:8:19: warning: unused variable ‘c’ [-Wunused-variable]
     unsigned char c = va_arg(ap, unsigned char);
                   ^
example.c: In function ‘func_compliant’:
example.c:23:19: warning: unused variable ‘c’ [-Wunused-variable]
     unsigned char c = (unsigned char) va_arg(ap, int);
                   ^
example.c: At top level:
example.c:34:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
In file included from example.c:1:0:
example.c: In function ‘func_noncompliant’:
example.c:8:34: warning: ‘unsigned char’ is promoted to ‘int’ when passed through ‘...’
     unsigned char c = va_arg(ap, unsigned char);
                                  ^
example.c:8:34: note: (so you should pass ‘int’ not ‘unsigned char’ to ‘va_arg’)
example.c:8:34: note: if this code is reached, the program will abort
```
### clang
```
example.c:8:19: warning: unused variable 'c' [-Wunused-variable]
    unsigned char c = va_arg(ap, unsigned char);
                  ^
example.c:8:34: warning: second argument to 'va_arg' is of promotable type 'unsigned char'; this va_arg has undefined behavior because arguments will be promoted to 'int' [-Wvarargs]
    unsigned char c = va_arg(ap, unsigned char);
                                 ^~~~~~~~~~~~~
/home/qba/tis/installs/default/lib/clang/11.0.0/include/stdarg.h:19:50: note: expanded from macro 'va_arg'
#define va_arg(ap, type)    __builtin_va_arg(ap, type)
                                                 ^~~~
example.c:23:19: warning: unused variable 'c' [-Wunused-variable]
    unsigned char c = (unsigned char) va_arg(ap, int);
                  ^
example.c:34:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:34:1: note: change return type to 'int'
void main(void) {
^~~~
int
4 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==8652== Memcheck, a memory error detector
==8652== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8652== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8652== Command: ./example.out
==8652== 
==8652== valgrind: Unrecognised instruction at address 0x10870c.
==8652==    at 0x10870C: func_noncompliant (example.c:8)
==8652==    by 0x108748: f_noncompliant (example.c:16)
==8652==    by 0x108881: main (example.c:36)
==8652== Your program just tried to execute an instruction that Valgrind
==8652== did not recognise.  There are two possible reasons for this.
==8652== 1. Your program has a bug and erroneously jumped to a non-code
==8652==    location.  If you are running Memcheck and you just saw a
==8652==    warning about a bad jump, it's probably your program's fault.
==8652== 2. The instruction is legitimate but Valgrind doesn't handle it,
==8652==    i.e. it's Valgrind's fault.  If you think this is the case or
==8652==    you are not sure, please let us know and we'll try to fix it.
==8652== Either way, Valgrind will now raise a SIGILL signal which will
==8652== probably kill your program.
==8652== 
==8652== Process terminating with default action of signal 4 (SIGILL)
==8652==  Illegal opcode at address 0x10870C
==8652==    at 0x10870C: func_noncompliant (example.c:8)
==8652==    by 0x108748: f_noncompliant (example.c:16)
==8652==    by 0x108881: main (example.c:36)
==8652== 
==8652== HEAP SUMMARY:
==8652==     in use at exit: 0 bytes in 0 blocks
==8652==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8652== 
==8652== All heap blocks were freed -- no leaks are possible
==8652== 
==8652== For counts of detected and suppressed errors, rerun with: -v
==8652== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Illegal instruction (core dumped)
```
