# Examples
## example1
### Test
```
abc
abc
```
### gcc
```
example1.c:13:6: warning: return type of â€˜mainâ€™ is not â€˜intâ€™ [-Wmain]
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
abcÐÀ³ÿ
```
### Valgrind
```
==4932== Memcheck, a memory error detector
==4932== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4932== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4932== Command: ./example1.out
==4932== 
abc
abc
==4932== 
==4932== HEAP SUMMARY:
==4932==     in use at exit: 0 bytes in 0 blocks
==4932==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==4932== 
==4932== All heap blocks were freed -- no leaks are possible
==4932== 
==4932== For counts of detected and suppressed errors, rerun with: -v
==4932== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
