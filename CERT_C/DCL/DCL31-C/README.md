# Examples
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
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Implicit_Return_Type.out
==12345== 
4294967295
-1
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
