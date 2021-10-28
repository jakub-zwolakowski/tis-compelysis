# Examples
## example1
### Test
```
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
```
### gcc
```
example1.c:18:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:18:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:18:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example1.out
==12345== 
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000000.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
f_compliant, x = 100000008.000000
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
