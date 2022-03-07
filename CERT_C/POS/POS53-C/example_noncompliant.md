## example_noncompliant
### Test
```
signaling
count2 = 1
signaling
count1 = 1
signaling
count2 = 2
signaling
count1 = 2
signaling
count2 = 3
signaling
count1 = 3
signaling
count2 = 4
signaling
count1 = 4
signaling
count2 = 5
signaling
count1 = 5
signaling
```
### gcc
```
```
### clang
```
```
### UBSan
```
signaling
count1 = 1
signaling
count2 = 1
signaling
count1 = 2
signaling
count2 = 2
signaling
count1 = 3
signaling
count2 = 3
signaling
count1 = 4
signaling
count2 = 4
signaling
count1 = 5
signaling
count2 = 5
signaling
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
==12345==   total heap usage: 4 allocs, 4 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
