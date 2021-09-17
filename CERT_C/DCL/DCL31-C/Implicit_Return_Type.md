## Implicit_Return_Type
### Test
```
4294967295
-1
```
### gcc
```
Implicit_Return_Type.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 foo_noncompliant(void) {
 ^~~~~~~~~~~~~~~~
Implicit_Return_Type.c:12:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Implicit_Return_Type.c:4:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
foo_noncompliant(void) {
^
Implicit_Return_Type.c:12:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Implicit_Return_Type.c:12:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
4294967295
-1
```
### Valgrind
```
==25224== Memcheck, a memory error detector
==25224== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==25224== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==25224== Command: ./Implicit_Return_Type.out
==25224== 
4294967295
-1
==25224== 
==25224== HEAP SUMMARY:
==25224==     in use at exit: 0 bytes in 0 blocks
==25224==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==25224== 
==25224== All heap blocks were freed -- no leaks are possible
==25224== 
==25224== For counts of detected and suppressed errors, rerun with: -v
==25224== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
