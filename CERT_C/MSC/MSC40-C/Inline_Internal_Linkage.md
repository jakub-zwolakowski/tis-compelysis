## Inline_Internal_Linkage
### Test
```
```
### gcc
```
Inline_Internal_Linkage.c: In function ‘func_noncompliant’:
Inline_Internal_Linkage.c:3:7: warning: unused variable ‘b’ [-Wunused-variable]
   int b = a * I_noncompliant;
       ^
Inline_Internal_Linkage.c: In function ‘func_compliant’:
Inline_Internal_Linkage.c:9:7: warning: unused variable ‘b’ [-Wunused-variable]
   int b = a * I_compliant;
       ^
Inline_Internal_Linkage.c: At top level:
Inline_Internal_Linkage.c:13:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Inline_Internal_Linkage.c:3:15: warning: static variable 'I_noncompliant' is used in an inline function with external linkage [-Wstatic-in-inline]
  int b = a * I_noncompliant;
              ^
Inline_Internal_Linkage.c:1:12: note: 'I_noncompliant' declared here
static int I_noncompliant = 12;
           ^
Inline_Internal_Linkage.c:3:7: warning: unused variable 'b' [-Wunused-variable]
  int b = a * I_noncompliant;
      ^
Inline_Internal_Linkage.c:9:7: warning: unused variable 'b' [-Wunused-variable]
  int b = a * I_compliant;
      ^
Inline_Internal_Linkage.c:13:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Inline_Internal_Linkage.c:13:1: note: change return type to 'int'
void main(void) {
^~~~
int
4 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==5619== Memcheck, a memory error detector
==5619== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5619== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5619== Command: ./Inline_Internal_Linkage.out
==5619== 
==5619== 
==5619== HEAP SUMMARY:
==5619==     in use at exit: 0 bytes in 0 blocks
==5619==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5619== 
==5619== All heap blocks were freed -- no leaks are possible
==5619== 
==5619== For counts of detected and suppressed errors, rerun with: -v
==5619== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
