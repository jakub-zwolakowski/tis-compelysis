## example
### Test
```
22```
### gcc
```
example.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:21:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
22```
### Valgrind
```
==29912== Memcheck, a memory error detector
==29912== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29912== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29912== Command: ./example.out
==29912== 
22==29912== 
==29912== HEAP SUMMARY:
==29912==     in use at exit: 0 bytes in 0 blocks
==29912==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==29912== 
==29912== All heap blocks were freed -- no leaks are possible
==29912== 
==29912== For counts of detected and suppressed errors, rerun with: -v
==29912== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
