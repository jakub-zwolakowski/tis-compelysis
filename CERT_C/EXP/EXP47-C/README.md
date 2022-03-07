# Examples
## example
### Test
```
timeout: the monitored command dumped core
Illegal instruction
```
### gcc
```
In file included from example.c:1:0:
example.c: In function ‘func_noncompliant’:
example.c:8:34: error: ‘unsigned char’ is promoted to ‘int’ when passed through ‘...’ [-Werror]
     unsigned char c = va_arg(ap, unsigned char);
                                  ^
example.c:8:34: note: (so you should pass ‘int’ not ‘unsigned char’ to ‘va_arg’)
example.c:8:34: note: if this code is reached, the program will abort
cc1: all warnings being treated as errors
```
### clang
```
example.c:8:34: error: second argument to 'va_arg' is of promotable type 'unsigned char'; this va_arg has undefined behavior because arguments will be promoted to 'int' [-Werror,-Wvarargs]
    unsigned char c = va_arg(ap, unsigned char);
                                 ^~~~~~~~~~~~~
/home/qba/tis/deps/llvm/12.0.0/build/lib/clang/12.0.0/include/stdarg.h:19:50: note: expanded from macro 'va_arg'
#define va_arg(ap, type)    __builtin_va_arg(ap, type)
                                                 ^~~~
1 error generated.
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== Parent PID: 12345
==12345== 
==12345== valgrind: Unrecognised instruction at address 0x424242424242.
==12345==    at 0x424242424242: func_noncompliant (example.c:8)
==12345==    by 0x424242424242: f_noncompliant (example.c:16)
==12345==    by 0x424242424242: main (example.c:36)
==12345== Your program just tried to execute an instruction that Valgrind
==12345== did not recognise.  There are two possible reasons for this.
==12345== 1. Your program has a bug and erroneously jumped to a non-code
==12345==    location.  If you are running Memcheck and you just saw a
==12345==    warning about a bad jump, it's probably your program's fault.
==12345== 2. The instruction is legitimate but Valgrind doesn't handle it,
==12345==    i.e. it's Valgrind's fault.  If you think this is the case or
==12345==    you are not sure, please let us know and we'll try to fix it.
==12345== Either way, Valgrind will now raise a SIGILL signal which will
==12345== probably kill your program.
==12345== 
==12345== Process terminating with default action of signal 4 (SIGILL)
==12345==  Illegal opcode at address 0x424242424242
==12345==    at 0x424242424242: func_noncompliant (example.c:8)
==12345==    by 0x424242424242: f_noncompliant (example.c:16)
==12345==    by 0x424242424242: main (example.c:36)
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
