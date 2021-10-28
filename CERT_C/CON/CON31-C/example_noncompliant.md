## example_noncompliant
### Test
```
noncompliant beginning
noncompliant 1, Worker 1
noncompliant 2, Worker 2
noncompliant 3, Worker 3
noncompliant 5, Destruction 3
noncompliant 5, Destruction 3
noncompliant end
```
### gcc
```
```
### clang
```
```
### UBSan
```
noncompliant beginning
noncompliant 2, Worker 1
noncompliant 3, Worker 2
noncompliant 3, Worker 3
noncompliant 4, Destruction 3
noncompliant 5, Destruction 3
noncompliant end
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
noncompliant beginning
noncompliant 3, Worker 1
noncompliant 3, Worker 2
noncompliant 3, Worker 3
noncompliant 3, Worker 4
noncompliant 5, Destruction 4
noncompliant end
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 6 allocs, 6 frees, 5,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
