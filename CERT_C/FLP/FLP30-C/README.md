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
==9524== Memcheck, a memory error detector
==9524== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9524== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9524== Command: ./example1.out
==9524== 
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
==9524== 
==9524== HEAP SUMMARY:
==9524==     in use at exit: 0 bytes in 0 blocks
==9524==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==9524== 
==9524== All heap blocks were freed -- no leaks are possible
==9524== 
==9524== For counts of detected and suppressed errors, rerun with: -v
==9524== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
