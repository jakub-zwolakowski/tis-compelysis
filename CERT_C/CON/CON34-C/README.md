# Examples
## example_compliant
### Test
```
Result: 1
```
### gcc
```
```
### clang
```
```
### UBSan
```
Result: 1
```
### Valgrind
```
==29947== Memcheck, a memory error detector
==29947== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29947== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29947== Command: ./example_compliant.out
==29947== 
Result: 1
==29947== 
==29947== HEAP SUMMARY:
==29947==     in use at exit: 0 bytes in 0 blocks
==29947==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==29947== 
==29947== All heap blocks were freed -- no leaks are possible
==29947== 
==29947== For counts of detected and suppressed errors, rerun with: -v
==29947== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
Result: 21854
```
### gcc
```
```
### clang
```
```
### UBSan
```
Result: 0
```
### Valgrind
```
==30018== Memcheck, a memory error detector
==30018== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30018== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30018== Command: ./example_noncompliant.out
==30018== 
Result: 0
==30018== 
==30018== HEAP SUMMARY:
==30018==     in use at exit: 0 bytes in 0 blocks
==30018==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==30018== 
==30018== All heap blocks were freed -- no leaks are possible
==30018== 
==30018== For counts of detected and suppressed errors, rerun with: -v
==30018== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example
### Test
```
Result: 1
Result: 22088
```
### gcc
```
```
### clang
```
```
### UBSan
```
Result: 1
Result: 0
```
### Valgrind
```
==30091== Memcheck, a memory error detector
==30091== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30091== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30091== Command: ./example.out
==30091== 
Result: 1
Result: 0
==30091== 
==30091== HEAP SUMMARY:
==30091==     in use at exit: 0 bytes in 0 blocks
==30091==   total heap usage: 2 allocs, 2 frees, 4,368 bytes allocated
==30091== 
==30091== All heap blocks were freed -- no leaks are possible
==30091== 
==30091== For counts of detected and suppressed errors, rerun with: -v
==30091== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
