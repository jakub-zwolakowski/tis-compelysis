## example
### Test
```
1.000000 0.500000 0.333333 
0.333333 inf inf ```
### gcc
```
example.c:62:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:62:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:62:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
1.000000 0.500000 0.333333 
0.333333 486690226827332100219682535410400193577667212198480635224754917028773099848335360.000000 inf ```
### Valgrind
```
==32200== Memcheck, a memory error detector
==32200== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32200== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32200== Command: ./example.out
==32200== 
1.000000 0.500000 0.333333 
0.333333 inf inf ==32200== 
==32200== HEAP SUMMARY:
==32200==     in use at exit: 0 bytes in 0 blocks
==32200==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==32200== 
==32200== All heap blocks were freed -- no leaks are possible
==32200== 
==32200== For counts of detected and suppressed errors, rerun with: -v
==32200== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
