# Examples
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
==6811== Memcheck, a memory error detector
==6811== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6811== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6811== Command: ./example.out
==6811== 
22==6811== 
==6811== HEAP SUMMARY:
==6811==     in use at exit: 0 bytes in 0 blocks
==6811==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==6811== 
==6811== All heap blocks were freed -- no leaks are possible
==6811== 
==6811== For counts of detected and suppressed errors, rerun with: -v
==6811== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
