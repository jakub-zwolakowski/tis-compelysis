# Examples
## example_atoi_vs_strtol
### Test
```
foo: not a decimal number
12345678901234567890 out of range of type long
x = 2
x = 2
x = 2
x = 2
x = 0
x = -1
```
### gcc
```
example_atoi_vs_strtol.c:45:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example_atoi_vs_strtol.c:45:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_atoi_vs_strtol.c:45:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
foo: not a decimal number
12345678901234567890 out of range of type long
x = 2
x = 2
x = 2
x = 2
x = 0
x = -1
```
### Valgrind
```
==6666== Memcheck, a memory error detector
==6666== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6666== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6666== Command: ./example_atoi_vs_strtol.out
==6666== 
foo: not a decimal number
12345678901234567890 out of range of type long
x = 2
x = 2
x = 2
x = 2
x = 0
x = -1
==6666== 
==6666== HEAP SUMMARY:
==6666==     in use at exit: 0 bytes in 0 blocks
==6666==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==6666== 
==6666== All heap blocks were freed -- no leaks are possible
==6666== 
==6666== For counts of detected and suppressed errors, rerun with: -v
==6666== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
