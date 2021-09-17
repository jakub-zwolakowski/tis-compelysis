## example1
### Test
```
```
### gcc
```
example1.c:25:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:25:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:25:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
example1.c:12:25: runtime error: index 320 out of bounds for type 'int [80]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example1.c:12:25 in 
```
### Valgrind
```
==8034== Memcheck, a memory error detector
==8034== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8034== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8034== Command: ./example1.out
==8034== 
==8034== 
==8034== HEAP SUMMARY:
==8034==     in use at exit: 0 bytes in 0 blocks
==8034==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8034== 
==8034== All heap blocks were freed -- no leaks are possible
==8034== 
==8034== For counts of detected and suppressed errors, rerun with: -v
==8034== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
