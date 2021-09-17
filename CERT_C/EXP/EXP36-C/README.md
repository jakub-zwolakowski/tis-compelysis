# Examples
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
==2178== Memcheck, a memory error detector
==2178== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2178== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2178== Command: ./Intermediate_Object.out
==2178== 
==2178== 
==2178== HEAP SUMMARY:
==2178==     in use at exit: 0 bytes in 0 blocks
==2178==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2178== 
==2178== All heap blocks were freed -- no leaks are possible
==2178== 
==2178== For counts of detected and suppressed errors, rerun with: -v
==2178== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
