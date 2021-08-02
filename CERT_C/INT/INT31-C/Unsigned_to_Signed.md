## Unsigned_to_Signed
### Test
```
```
### gcc
```
Unsigned_to_Signed.c: In function ‘f_noncompliant’:
Unsigned_to_Signed.c:5:15: warning: variable ‘sc’ set but not used [-Wunused-but-set-variable]
   signed char sc;
               ^~
Unsigned_to_Signed.c: In function ‘f_compliant’:
Unsigned_to_Signed.c:12:15: warning: variable ‘sc’ set but not used [-Wunused-but-set-variable]
   signed char sc;
               ^~
Unsigned_to_Signed.c: At top level:
Unsigned_to_Signed.c:20:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Unsigned_to_Signed.c:20:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Unsigned_to_Signed.c:20:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==6521== Memcheck, a memory error detector
==6521== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6521== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6521== Command: ./Unsigned_to_Signed.out
==6521== 
==6521== 
==6521== HEAP SUMMARY:
==6521==     in use at exit: 0 bytes in 0 blocks
==6521==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6521== 
==6521== All heap blocks were freed -- no leaks are possible
==6521== 
==6521== For counts of detected and suppressed errors, rerun with: -v
==6521== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
