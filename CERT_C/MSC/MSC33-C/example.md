## example
### Test
```
Time: Sat Mar 25 06:42:42 1989
```
### gcc
```
example.c:11:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:11:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:11:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Time: Sat Mar 25 06:42:42 1989
```
### Valgrind
```
==4522== Memcheck, a memory error detector
==4522== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4522== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4522== Command: ./example.out
==4522== 
Time: Sat Mar 25 06:42:42 1989
==4522== 
==4522== HEAP SUMMARY:
==4522==     in use at exit: 0 bytes in 0 blocks
==4522==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==4522== 
==4522== All heap blocks were freed -- no leaks are possible
==4522== 
==4522== For counts of detected and suppressed errors, rerun with: -v
==4522== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
