# Examples
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
==684== Memcheck, a memory error detector
==684== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==684== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==684== Command: ./example.out
==684== 
==684== 
==684== HEAP SUMMARY:
==684==     in use at exit: 0 bytes in 0 blocks
==684==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==684== 
==684== All heap blocks were freed -- no leaks are possible
==684== 
==684== For counts of detected and suppressed errors, rerun with: -v
==684== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
