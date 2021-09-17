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
==924== Memcheck, a memory error detector
==924== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==924== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==924== Command: ./example.out
==924== 
22==924== 
==924== HEAP SUMMARY:
==924==     in use at exit: 0 bytes in 0 blocks
==924==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==924== 
==924== All heap blocks were freed -- no leaks are possible
==924== 
==924== For counts of detected and suppressed errors, rerun with: -v
==924== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
