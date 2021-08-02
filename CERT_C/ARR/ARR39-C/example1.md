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
==11899== Memcheck, a memory error detector
==11899== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11899== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11899== Command: ./example1.out
==11899== 
==11899== 
==11899== HEAP SUMMARY:
==11899==     in use at exit: 0 bytes in 0 blocks
==11899==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11899== 
==11899== All heap blocks were freed -- no leaks are possible
==11899== 
==11899== For counts of detected and suppressed errors, rerun with: -v
==11899== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
