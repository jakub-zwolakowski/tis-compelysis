# Examples
## example_compliant
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==8111== Memcheck, a memory error detector
==8111== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8111== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8111== Command: ./example_compliant.out
==8111== 
==8111== 
==8111== HEAP SUMMARY:
==8111==     in use at exit: 0 bytes in 0 blocks
==8111==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8111== 
==8111== All heap blocks were freed -- no leaks are possible
==8111== 
==8111== For counts of detected and suppressed errors, rerun with: -v
==8111== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==8181== Memcheck, a memory error detector
==8181== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8181== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8181== Command: ./example_noncompliant.out
==8181== 
==8181== 
==8181== HEAP SUMMARY:
==8181==     in use at exit: 0 bytes in 0 blocks
==8181==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8181== 
==8181== All heap blocks were freed -- no leaks are possible
==8181== 
==8181== For counts of detected and suppressed errors, rerun with: -v
==8181== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example
### Test
```
/bin/sh: 1: ./example.out: not found
```
### gcc
```
example.c:48:5: error: redefinition of ‘main_noncompliant’
 int main_noncompliant(void) {
     ^~~~~~~~~~~~~~~~~
example.c:20:5: note: previous definition of ‘main_noncompliant’ was here
 int main_noncompliant(void) {
     ^~~~~~~~~~~~~~~~~
```
### clang
```
example.c:48:5: error: redefinition of 'main_noncompliant'
int main_noncompliant(void) {
    ^
example.c:20:5: note: previous definition is here
int main_noncompliant(void) {
    ^
1 error generated.
```
### UBSan
```
/bin/sh: 1: ./example.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example.out: No such file or directory
```
