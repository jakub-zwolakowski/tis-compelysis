## example1
### Test
```
abc
abc
```
### gcc
```
example1.c:13:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:13:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:13:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
abc
abc`2��
```
### Valgrind
```
==10544== Memcheck, a memory error detector
==10544== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10544== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10544== Command: ./example1.out
==10544== 
abc
abc
==10544== 
==10544== HEAP SUMMARY:
==10544==     in use at exit: 0 bytes in 0 blocks
==10544==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==10544== 
==10544== All heap blocks were freed -- no leaks are possible
==10544== 
==10544== For counts of detected and suppressed errors, rerun with: -v
==10544== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
