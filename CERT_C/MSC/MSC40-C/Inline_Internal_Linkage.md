## Inline_Internal_Linkage
### Test
```
```
### gcc
```
```
### clang
```
Inline_Internal_Linkage.c:3:15: error: static variable 'I_noncompliant' is used in an inline function with external linkage [-Werror,-Wstatic-in-inline]
  int b = a * I_noncompliant;
              ^
Inline_Internal_Linkage.c:1:12: note: 'I_noncompliant' declared here
static int I_noncompliant = 12;
           ^
1 error generated.
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Inline_Internal_Linkage.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
