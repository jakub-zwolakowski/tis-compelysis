# Examples
## example_compliant
### Test
```
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
```
### gcc
```
```
### clang
```
```
### UBSan
```
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
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
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 11 allocs, 11 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
```
### gcc
```
```
### clang
```
```
### UBSan
```
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
account_balance = XXX
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 11 allocs, 11 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example
### Test
```
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
```
### gcc
```
```
### clang
```
```
### UBSan
```
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 17 allocs, 17 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
