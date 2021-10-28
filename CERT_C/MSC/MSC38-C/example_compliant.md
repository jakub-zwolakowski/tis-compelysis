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
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== 
example_compliant.out: example_compliant.c:10: assert_handler: Assertion `value' failed.
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x4E7CFB7: raise (raise.c:51)
==12345==    by 0x4E7E920: abort (abort.c:79)
==12345==    by 0x4E6E489: __assert_fail_base (assert.c:92)
==12345==    by 0x4E6E501: __assert_fail (assert.c:101)
==12345==    by 0x108696: assert_handler (example_compliant.c:10)
==12345==    by 0x108663: execute_handler (example_compliant.c:6)
==12345==    by 0x1086BB: func (example_compliant.c:14)
==12345==    by 0x1086CC: main (example_compliant.c:18)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 190 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
