## example_main
### Test
```
```
### gcc
```
example_main.c:5:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
/tmp/ccilGZfq.o: In function `main':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL40-C/example_main.c:6: undefined reference to `f_compliant'
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL40-C/example_main.c:7: undefined reference to `f_noncompliant'
collect2: error: ld returned 1 exit status
```
### clang
```
example_main.c:5:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example_main.c:5:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
/tmp/example_main-738b5b.o: In function `main':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL40-C/example_main.c:6: undefined reference to `f_compliant'
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL40-C/example_main.c:7: undefined reference to `f_noncompliant'
clang-11: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
```
### Valgrind
```
==29446== Memcheck, a memory error detector
==29446== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29446== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29446== Command: ./example_main.out
==29446== 
==29446== 
==29446== HEAP SUMMARY:
==29446==     in use at exit: 0 bytes in 0 blocks
==29446==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==29446== 
==29446== All heap blocks were freed -- no leaks are possible
==29446== 
==29446== For counts of detected and suppressed errors, rerun with: -v
==29446== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
