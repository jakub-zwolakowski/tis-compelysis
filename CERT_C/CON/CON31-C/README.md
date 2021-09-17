# Examples
## example_compliant
### Test
```
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
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
```
### Valgrind
```
==30730== Memcheck, a memory error detector
==30730== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30730== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30730== Command: ./example_compliant.out
==30730== 
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
==30730== 
==30730== HEAP SUMMARY:
==30730==     in use at exit: 0 bytes in 0 blocks
==30730==   total heap usage: 6 allocs, 6 frees, 5,456 bytes allocated
==30730== 
==30730== All heap blocks were freed -- no leaks are possible
==30730== 
==30730== For counts of detected and suppressed errors, rerun with: -v
==30730== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
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
==30813== Memcheck, a memory error detector
==30813== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30813== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30813== Command: ./example_noncompliant.out
==30813== 
noncompliant beginning
noncompliant 3, Worker 1
noncompliant 3, Worker 2
noncompliant 3, Worker 3
noncompliant 3, Worker 4
noncompliant 5, Destruction 4
noncompliant end
==30813== 
==30813== HEAP SUMMARY:
==30813==     in use at exit: 0 bytes in 0 blocks
==30813==   total heap usage: 6 allocs, 6 frees, 5,456 bytes allocated
==30813== 
==30813== All heap blocks were freed -- no leaks are possible
==30813== 
==30813== For counts of detected and suppressed errors, rerun with: -v
==30813== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
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
