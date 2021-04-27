## Off-by-One_Error
### Test
```
```
### gcc
```
Off-by-One_Error.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Off-by-One_Error.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Off-by-One_Error.c:21:1: note: change return type to 'int'
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
==10466== Memcheck, a memory error detector
==10466== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10466== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10466== Command: ./Off-by-One_Error.out
==10466== 
==10466== 
==10466== HEAP SUMMARY:
==10466==     in use at exit: 0 bytes in 0 blocks
==10466==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==10466== 
==10466== All heap blocks were freed -- no leaks are possible
==10466== 
==10466== For counts of detected and suppressed errors, rerun with: -v
==10466== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
