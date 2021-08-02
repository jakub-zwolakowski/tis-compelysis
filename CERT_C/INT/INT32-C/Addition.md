## Addition
### Test
```
```
### gcc
```
Addition.c: In function ‘f_noncompliant’:
Addition.c:4:14: warning: unused variable ‘sum’ [-Wunused-variable]
   signed int sum = si_a + si_b;
              ^~~
Addition.c: In function ‘f_compliant’:
Addition.c:9:14: warning: variable ‘sum’ set but not used [-Wunused-but-set-variable]
   signed int sum;
              ^~~
Addition.c: At top level:
Addition.c:19:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Addition.c:4:14: warning: unused variable 'sum' [-Wunused-variable]
  signed int sum = si_a + si_b;
             ^
Addition.c:19:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Addition.c:19:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
Addition.c:4:25: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Addition.c:4:25 in 
```
### Valgrind
```
==5766== Memcheck, a memory error detector
==5766== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5766== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5766== Command: ./Addition.out
==5766== 
==5766== 
==5766== HEAP SUMMARY:
==5766==     in use at exit: 0 bytes in 0 blocks
==5766==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5766== 
==5766== All heap blocks were freed -- no leaks are possible
==5766== 
==5766== For counts of detected and suppressed errors, rerun with: -v
==5766== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
