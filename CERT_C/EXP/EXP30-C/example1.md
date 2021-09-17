## example1
### Test
```
42, 142, 1```
### gcc
```
example1.c: In function ‘f_noncompliant’:
example1.c:4:17: warning: operation on ‘i’ may be undefined [-Wsequence-point]
   int a = i + b[++i];
                 ^~~
example1.c: At top level:
example1.c:15:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:4:17: warning: unsequenced modification and access to 'i' [-Wunsequenced]
  int a = i + b[++i];
          ~     ^
example1.c:15:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:15:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
42, 141, 1```
### Valgrind
```
==2990== Memcheck, a memory error detector
==2990== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2990== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2990== Command: ./example1.out
==2990== 
42, 142, 1==2990== 
==2990== HEAP SUMMARY:
==2990==     in use at exit: 0 bytes in 0 blocks
==2990==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==2990== 
==2990== All heap blocks were freed -- no leaks are possible
==2990== 
==2990== For counts of detected and suppressed errors, rerun with: -v
==2990== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
