## example_calloc
### Test
```
```
### gcc
```
example_calloc.c:60:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example_calloc.c:60:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_calloc.c:60:1: note: change return type to 'int'
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
==851== Memcheck, a memory error detector
==851== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==851== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==851== Command: ./example_calloc.out
==851== 
==851== 
==851== HEAP SUMMARY:
==851==     in use at exit: 0 bytes in 0 blocks
==851==   total heap usage: 2 allocs, 2 frees, 2,688 bytes allocated
==851== 
==851== All heap blocks were freed -- no leaks are possible
==851== 
==851== For counts of detected and suppressed errors, rerun with: -v
==851== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
