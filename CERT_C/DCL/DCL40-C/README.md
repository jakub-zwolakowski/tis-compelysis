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
==26715== Memcheck, a memory error detector
==26715== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26715== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26715== Command: ./example_main.out
==26715== 
==26715== 
==26715== HEAP SUMMARY:
==26715==     in use at exit: 0 bytes in 0 blocks
==26715==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==26715== 
==26715== All heap blocks were freed -- no leaks are possible
==26715== 
==26715== For counts of detected and suppressed errors, rerun with: -v
==26715== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
