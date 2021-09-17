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
==606== Memcheck, a memory error detector
==606== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==606== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==606== Command: ./Unsigned_to_Signed.out
==606== 
==606== 
==606== HEAP SUMMARY:
==606==     in use at exit: 0 bytes in 0 blocks
==606==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==606== 
==606== All heap blocks were freed -- no leaks are possible
==606== 
==606== For counts of detected and suppressed errors, rerun with: -v
==606== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
