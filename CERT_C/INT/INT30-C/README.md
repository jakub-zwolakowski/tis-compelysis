# Examples
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
==32418== Memcheck, a memory error detector
==32418== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32418== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32418== Command: ./Addition.out
==32418== 
==32418== 
==32418== HEAP SUMMARY:
==32418==     in use at exit: 0 bytes in 0 blocks
==32418==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==32418== 
==32418== All heap blocks were freed -- no leaks are possible
==32418== 
==32418== For counts of detected and suppressed errors, rerun with: -v
==32418== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
