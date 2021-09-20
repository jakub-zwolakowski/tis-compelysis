## example
### Test
```
example.out: example.c:32: main_compliant: Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
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
example.UBSan-out: example.c:32: int main_compliant(void): Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
Aborted (core dumped)
```
### Valgrind
```
==9052== Memcheck, a memory error detector
==9052== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9052== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9052== Command: ./example.out
==9052== 
example.out: example.c:32: main_compliant: Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
==9052== 
==9052== Process terminating with default action of signal 6 (SIGABRT)
==9052==    at 0x4E7CFB7: raise (raise.c:51)
==9052==    by 0x4E7E920: abort (abort.c:79)
==9052==    by 0x4E6E489: __assert_fail_base (assert.c:92)
==9052==    by 0x4E6E501: __assert_fail (assert.c:101)
==9052==    by 0x108732: main_compliant (example.c:32)
==9052==    by 0x1087C7: main (example.c:47)
==9052== 
==9052== HEAP SUMMARY:
==9052==     in use at exit: 0 bytes in 0 blocks
==9052==   total heap usage: 3 allocs, 3 frees, 518 bytes allocated
==9052== 
==9052== All heap blocks were freed -- no leaks are possible
==9052== 
==9052== For counts of detected and suppressed errors, rerun with: -v
==9052== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```