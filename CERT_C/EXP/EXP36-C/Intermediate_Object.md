## Intermediate_Object
### Test
```
```
### gcc
```
Intermediate_Object.c:20:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Intermediate_Object.c:20:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Intermediate_Object.c:20:1: note: change return type to 'int'
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
==7567== Memcheck, a memory error detector
==7567== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7567== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7567== Command: ./Intermediate_Object.out
==7567== 
==7567== 
==7567== HEAP SUMMARY:
==7567==     in use at exit: 0 bytes in 0 blocks
==7567==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7567== 
==7567== All heap blocks were freed -- no leaks are possible
==7567== 
==7567== For counts of detected and suppressed errors, rerun with: -v
==7567== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
