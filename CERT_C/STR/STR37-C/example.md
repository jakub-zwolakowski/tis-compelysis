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
==4715== Memcheck, a memory error detector
==4715== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4715== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4715== Command: ./example.out
==4715== 
==4715== 
==4715== HEAP SUMMARY:
==4715==     in use at exit: 0 bytes in 0 blocks
==4715==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4715== 
==4715== All heap blocks were freed -- no leaks are possible
==4715== 
==4715== For counts of detected and suppressed errors, rerun with: -v
==4715== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
