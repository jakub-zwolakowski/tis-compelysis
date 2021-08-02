## Forming_Out-of-Bounds_Pointer
### Test
```
```
### gcc
```
Forming_Out-of-Bounds_Pointer.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Forming_Out-of-Bounds_Pointer.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Forming_Out-of-Bounds_Pointer.c:21:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Forming_Out-of-Bounds_Pointer.c:9:18: runtime error: index -1 out of bounds for type 'int [100]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Forming_Out-of-Bounds_Pointer.c:9:18 in 
```
### Valgrind
```
==11217== Memcheck, a memory error detector
==11217== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11217== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11217== Command: ./Forming_Out-of-Bounds_Pointer.out
==11217== 
==11217== 
==11217== HEAP SUMMARY:
==11217==     in use at exit: 0 bytes in 0 blocks
==11217==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11217== 
==11217== All heap blocks were freed -- no leaks are possible
==11217== 
==11217== For counts of detected and suppressed errors, rerun with: -v
==11217== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
