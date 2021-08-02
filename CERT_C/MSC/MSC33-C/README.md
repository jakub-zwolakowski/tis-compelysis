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
==5475== Memcheck, a memory error detector
==5475== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5475== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5475== Command: ./example.out
==5475== 
Time: Sat Mar 25 06:42:42 1989
==5475== 
==5475== HEAP SUMMARY:
==5475==     in use at exit: 0 bytes in 0 blocks
==5475==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==5475== 
==5475== All heap blocks were freed -- no leaks are possible
==5475== 
==5475== For counts of detected and suppressed errors, rerun with: -v
==5475== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
