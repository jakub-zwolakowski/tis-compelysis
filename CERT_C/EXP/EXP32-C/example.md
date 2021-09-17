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
==2034== Memcheck, a memory error detector
==2034== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2034== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2034== Command: ./example.out
==2034== 
i = 0.
i = 0.
==2034== 
==2034== HEAP SUMMARY:
==2034==     in use at exit: 0 bytes in 0 blocks
==2034==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==2034== 
==2034== All heap blocks were freed -- no leaks are possible
==2034== 
==2034== For counts of detected and suppressed errors, rerun with: -v
==2034== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
