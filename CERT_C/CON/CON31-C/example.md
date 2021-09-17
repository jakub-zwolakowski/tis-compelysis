## example
### Test
```
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
noncompliant beginning
noncompliant 1, Worker 1
noncompliant 2, Worker 2
noncompliant 3, Worker 3
noncompliant 4, Destruction 3
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
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
noncompliant beginning
noncompliant 2, Worker 1
noncompliant 3, Worker 2
noncompliant 4, Destruction 2
noncompliant 5, Destruction 2
noncompliant 5, Destruction 2
noncompliant end
```
### Valgrind
```
==30906== Memcheck, a memory error detector
==30906== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30906== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30906== Command: ./example.out
==30906== 
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
noncompliant beginning
noncompliant 5, Destruction 0
noncompliant 5, Destruction 0
noncompliant 5, Destruction 0
noncompliant 5, Destruction 0
noncompliant 5, Destruction 0
noncompliant end
==30906== 
==30906== HEAP SUMMARY:
==30906==     in use at exit: 0 bytes in 0 blocks
==30906==   total heap usage: 7 allocs, 7 frees, 5,728 bytes allocated
==30906== 
==30906== All heap blocks were freed -- no leaks are possible
==30906== 
==30906== For counts of detected and suppressed errors, rerun with: -v
==30906== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
