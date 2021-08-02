# Examples
## example
### Test
```
```
### gcc
```
example.c: In function ‘f_noncompliant’:
example.c:9:10: warning: variable ‘free_elements’ set but not used [-Wunused-but-set-variable]
   size_t free_elements;
          ^~~~~~~~~~~~~
example.c: In function ‘f_compliant’:
example.c:19:10: warning: variable ‘free_elements’ set but not used [-Wunused-but-set-variable]
   size_t free_elements;
          ^~~~~~~~~~~~~
example.c: At top level:
example.c:26:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:26:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:26:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==10147== Memcheck, a memory error detector
==10147== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10147== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10147== Command: ./example.out
==10147== 
==10147== 
==10147== HEAP SUMMARY:
==10147==     in use at exit: 0 bytes in 0 blocks
==10147==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==10147== 
==10147== All heap blocks were freed -- no leaks are possible
==10147== 
==10147== For counts of detected and suppressed errors, rerun with: -v
==10147== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
