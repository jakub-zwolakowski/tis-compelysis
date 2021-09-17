## example
### Test
```
```
### gcc
```
example.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:22:1: note: change return type to 'int'
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
==26818== Memcheck, a memory error detector
==26818== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26818== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26818== Command: ./example.out
==26818== 
==26818== 
==26818== HEAP SUMMARY:
==26818==     in use at exit: 0 bytes in 0 blocks
==26818==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==26818== 
==26818== All heap blocks were freed -- no leaks are possible
==26818== 
==26818== For counts of detected and suppressed errors, rerun with: -v
==26818== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
