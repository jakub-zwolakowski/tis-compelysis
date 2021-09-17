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
