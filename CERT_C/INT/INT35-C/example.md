## example
### Test
```
```
### gcc
```
example.c:34:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:34:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:34:1: note: change return type to 'int'
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
==2499== Memcheck, a memory error detector
==2499== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2499== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2499== Command: ./example.out
==2499== 
==2499== 
==2499== HEAP SUMMARY:
==2499==     in use at exit: 0 bytes in 0 blocks
==2499==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2499== 
==2499== All heap blocks were freed -- no leaks are possible
==2499== 
==2499== For counts of detected and suppressed errors, rerun with: -v
==2499== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
