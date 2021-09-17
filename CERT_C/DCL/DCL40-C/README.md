# Examples
## example_main
### Test
```
```
### gcc
```
example_main.c:5:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example_main.c:5:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_main.c:5:1: note: change return type to 'int'
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
==24871== Memcheck, a memory error detector
==24871== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24871== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24871== Command: ./example_main.out
==24871== 
==24871== 
==24871== HEAP SUMMARY:
==24871==     in use at exit: 0 bytes in 0 blocks
==24871==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==24871== 
==24871== All heap blocks were freed -- no leaks are possible
==24871== 
==24871== For counts of detected and suppressed errors, rerun with: -v
==24871== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
