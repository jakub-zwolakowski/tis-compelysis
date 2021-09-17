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
