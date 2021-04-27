## example_sizeof
### Test
```
15, 4
14, 4
```
### gcc
```
example_sizeof.c:16:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example_sizeof.c:5:17: warning: expression with side effects has no effect in an unevaluated context [-Wunevaluated-expression]
  int b = sizeof(a++);
                ^
example_sizeof.c:16:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_sizeof.c:16:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
15, 4
14, 4
```
### Valgrind
```
==30582== Memcheck, a memory error detector
==30582== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30582== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30582== Command: ./example_sizeof.out
==30582== 
15, 4
14, 4
==30582== 
==30582== HEAP SUMMARY:
==30582==     in use at exit: 0 bytes in 0 blocks
==30582==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==30582== 
==30582== All heap blocks were freed -- no leaks are possible
==30582== 
==30582== For counts of detected and suppressed errors, rerun with: -v
==30582== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
