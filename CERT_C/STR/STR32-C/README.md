# Examples
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
abc��
```
### Valgrind
```
==27054== Memcheck, a memory error detector
==27054== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27054== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27054== Command: ./example1.out
==27054== 
abc
abc
==27054== 
==27054== HEAP SUMMARY:
==27054==     in use at exit: 0 bytes in 0 blocks
==27054==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==27054== 
==27054== All heap blocks were freed -- no leaks are possible
==27054== 
==27054== For counts of detected and suppressed errors, rerun with: -v
==27054== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
