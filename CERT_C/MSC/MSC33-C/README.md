# Examples
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
==31390== Memcheck, a memory error detector
==31390== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31390== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31390== Command: ./example.out
==31390== 
Time: Sat Mar 25 06:42:42 1989
==31390== 
==31390== HEAP SUMMARY:
==31390==     in use at exit: 0 bytes in 0 blocks
==31390==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==31390== 
==31390== All heap blocks were freed -- no leaks are possible
==31390== 
==31390== For counts of detected and suppressed errors, rerun with: -v
==31390== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
