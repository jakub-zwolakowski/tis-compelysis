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
abc ��
```
### Valgrind
```
==20895== Memcheck, a memory error detector
==20895== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20895== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==20895== Command: ./example1.out
==20895== 
abc
abc
==20895== 
==20895== HEAP SUMMARY:
==20895==     in use at exit: 0 bytes in 0 blocks
==20895==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==20895== 
==20895== All heap blocks were freed -- no leaks are possible
==20895== 
==20895== For counts of detected and suppressed errors, rerun with: -v
==20895== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
