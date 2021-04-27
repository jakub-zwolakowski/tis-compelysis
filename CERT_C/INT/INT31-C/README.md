# Examples
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
==2430== Memcheck, a memory error detector
==2430== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2430== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2430== Command: ./Unsigned_to_Signed.out
==2430== 
==2430== 
==2430== HEAP SUMMARY:
==2430==     in use at exit: 0 bytes in 0 blocks
==2430==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2430== 
==2430== All heap blocks were freed -- no leaks are possible
==2430== 
==2430== For counts of detected and suppressed errors, rerun with: -v
==2430== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
