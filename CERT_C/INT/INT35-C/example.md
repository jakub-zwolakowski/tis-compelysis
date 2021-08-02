## example
### Test
```
```
### gcc
```
example.c:34:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:34:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:34:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==6593== Memcheck, a memory error detector
==6593== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6593== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6593== Command: ./example.out
==6593== 
==6593== 
==6593== HEAP SUMMARY:
==6593==     in use at exit: 0 bytes in 0 blocks
==6593==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6593== 
==6593== All heap blocks were freed -- no leaks are possible
==6593== 
==6593== For counts of detected and suppressed errors, rerun with: -v
==6593== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
