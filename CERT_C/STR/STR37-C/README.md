# Examples
## example
### Test
```
```
### gcc
```
example.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:22:1: note: change return type to 'int'
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
==10322== Memcheck, a memory error detector
==10322== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10322== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10322== Command: ./example.out
==10322== 
==10322== 
==10322== HEAP SUMMARY:
==10322==     in use at exit: 0 bytes in 0 blocks
==10322==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==10322== 
==10322== All heap blocks were freed -- no leaks are possible
==10322== 
==10322== For counts of detected and suppressed errors, rerun with: -v
==10322== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
