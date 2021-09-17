## example_compliant
### Test
```
example_compliant.out: example_compliant.c:32: main: Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
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
example_compliant.UBSan-out: example_compliant.c:32: int main(void): Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
Aborted (core dumped)
```
### Valgrind
```
==8462== Memcheck, a memory error detector
==8462== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8462== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8462== Command: ./example_compliant.out
==8462== 
example_compliant.out: example_compliant.c:32: main: Assertion `PRECISION(LONG_MAX) <= DBL_MANT_DIG * log2(FLT_RADIX)' failed.
==8462== 
==8462== Process terminating with default action of signal 6 (SIGABRT)
==8462==    at 0x4E7CFB7: raise (raise.c:51)
==8462==    by 0x4E7E920: abort (abort.c:79)
==8462==    by 0x4E6E489: __assert_fail_base (assert.c:92)
==8462==    by 0x4E6E501: __assert_fail (assert.c:101)
==8462==    by 0x108732: main (example_compliant.c:32)
==8462== 
==8462== HEAP SUMMARY:
==8462==     in use at exit: 0 bytes in 0 blocks
==8462==   total heap usage: 3 allocs, 3 frees, 528 bytes allocated
==8462== 
==8462== All heap blocks were freed -- no leaks are possible
==8462== 
==8462== For counts of detected and suppressed errors, rerun with: -v
==8462== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
