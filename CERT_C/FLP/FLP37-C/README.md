# Examples
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
==11972== Memcheck, a memory error detector
==11972== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11972== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11972== Command: ./example.out
==11972== 
==11972== 
==11972== HEAP SUMMARY:
==11972==     in use at exit: 0 bytes in 0 blocks
==11972==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11972== 
==11972== All heap blocks were freed -- no leaks are possible
==11972== 
==11972== For counts of detected and suppressed errors, rerun with: -v
==11972== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
