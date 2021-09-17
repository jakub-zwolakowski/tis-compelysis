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
==768== Memcheck, a memory error detector
==768== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==768== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==768== Command: ./example_atoi_vs_strtol.out
==768== 
foo: not a decimal number
12345678901234567890 out of range of type long
x = 2
x = 2
x = 2
x = 2
x = 0
x = -1
==768== 
==768== HEAP SUMMARY:
==768==     in use at exit: 0 bytes in 0 blocks
==768==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==768== 
==768== All heap blocks were freed -- no leaks are possible
==768== 
==768== For counts of detected and suppressed errors, rerun with: -v
==768== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
