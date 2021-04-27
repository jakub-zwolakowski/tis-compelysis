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
==30651== Memcheck, a memory error detector
==30651== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30651== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30651== Command: ./Intermediate_Object.out
==30651== 
==30651== 
==30651== HEAP SUMMARY:
==30651==     in use at exit: 0 bytes in 0 blocks
==30651==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==30651== 
==30651== All heap blocks were freed -- no leaks are possible
==30651== 
==30651== For counts of detected and suppressed errors, rerun with: -v
==30651== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
