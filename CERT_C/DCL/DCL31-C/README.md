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
==29584== Memcheck, a memory error detector
==29584== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29584== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29584== Command: ./Implicit_Return_Type.out
==29584== 
4294967295
-1
==29584== 
==29584== HEAP SUMMARY:
==29584==     in use at exit: 0 bytes in 0 blocks
==29584==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==29584== 
==29584== All heap blocks were freed -- no leaks are possible
==29584== 
==29584== For counts of detected and suppressed errors, rerun with: -v
==29584== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
