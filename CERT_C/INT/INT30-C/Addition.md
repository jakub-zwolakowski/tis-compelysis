## Addition
### Test
```
```
### gcc
```
Addition.c: In function ‘f_noncompliant’:
Addition.c:4:16: warning: unused variable ‘usum’ [-Wunused-variable]
   unsigned int usum = ui_a + ui_b;
                ^~~~
Addition.c: In function ‘f_compliant’:
Addition.c:9:16: warning: variable ‘usum’ set but not used [-Wunused-but-set-variable]
   unsigned int usum;
                ^~~~
Addition.c: At top level:
Addition.c:18:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
Addition.c: In function ‘main’:
Addition.c:19:22: warning: unused variable ‘c’ [-Wunused-variable]
   unsigned int a, b, c;
                      ^
```
### clang
```
Addition.c:4:16: warning: unused variable 'usum' [-Wunused-variable]
  unsigned int usum = ui_a + ui_b;
               ^
Addition.c:18:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Addition.c:18:1: note: change return type to 'int'
void main(void) {
^~~~
int
Addition.c:19:22: warning: unused variable 'c' [-Wunused-variable]
  unsigned int a, b, c;
                     ^
3 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Addition.out
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
