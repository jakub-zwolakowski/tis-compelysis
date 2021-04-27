## example
### Test
```
```
### gcc
```
example.c:26:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
example.c: In function ‘main’:
example.c:29:8: warning: variable ‘are_equal’ set but not used [-Wunused-but-set-variable]
   bool are_equal;
        ^~~~~~~~~
```
### clang
```
example.c:26:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:26:1: note: change return type to 'int'
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
==5941== Memcheck, a memory error detector
==5941== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5941== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5941== Command: ./example.out
==5941== 
==5941== 
==5941== HEAP SUMMARY:
==5941==     in use at exit: 0 bytes in 0 blocks
==5941==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5941== 
==5941== All heap blocks were freed -- no leaks are possible
==5941== 
==5941== For counts of detected and suppressed errors, rerun with: -v
==5941== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
