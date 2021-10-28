## example
### Test
```
i = 0.
i = 0.
```
### gcc
```
example.c: In function ‘f_noncompliant’:
example.c:10:7: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
   ipp = &ip; /* May produce a warning diagnostic */
       ^
example.c:11:7: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
   ipp = (int**) &ip; /* Constraint violation; may produce a warning diagnostic */
       ^
example.c: At top level:
example.c:36:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:10:7: warning: assigning to 'volatile int **' from 'int **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  ipp = &ip; /* May produce a warning diagnostic */
      ^ ~~~
example.c:11:7: warning: assigning to 'volatile int **' from 'int **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  ipp = (int**) &ip; /* Constraint violation; may produce a warning diagnostic */
      ^ ~~~~~~~~~~~
example.c:36:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:36:1: note: change return type to 'int'
void main(void) {
^~~~
int
3 warnings generated.
```
### UBSan
```
i = 0.
i = 0.
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
i = 0.
i = 0.
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
