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
==29654== Memcheck, a memory error detector
==29654== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29654== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29654== Command: ./example_atoi_vs_strtol.out
==29654== 
foo: not a decimal number
12345678901234567890 out of range of type long
x = 2
x = 2
x = 2
x = 2
x = 0
x = -1
==29654== 
==29654== HEAP SUMMARY:
==29654==     in use at exit: 0 bytes in 0 blocks
==29654==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==29654== 
==29654== All heap blocks were freed -- no leaks are possible
==29654== 
==29654== For counts of detected and suppressed errors, rerun with: -v
==29654== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
