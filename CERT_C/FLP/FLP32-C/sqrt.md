## sqrt
### Test
```
```
### gcc
```
sqrt.c: In function ‘f_noncompliant’:
sqrt.c:4:10: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   double result;
          ^~~~~~
sqrt.c: In function ‘f_compliant’:
sqrt.c:9:10: warning: variable ‘result’ set but not used [-Wunused-but-set-variable]
   double result;
          ^~~~~~
sqrt.c: At top level:
sqrt.c:19:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
sqrt.c:19:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
sqrt.c:19:1: note: change return type to 'int'
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
==6013== Memcheck, a memory error detector
==6013== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6013== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6013== Command: ./sqrt.out
==6013== 
==6013== 
==6013== HEAP SUMMARY:
==6013==     in use at exit: 0 bytes in 0 blocks
==6013==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6013== 
==6013== All heap blocks were freed -- no leaks are possible
==6013== 
==6013== For counts of detected and suppressed errors, rerun with: -v
==6013== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
