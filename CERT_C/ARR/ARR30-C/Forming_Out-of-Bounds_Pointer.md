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
==7366== Memcheck, a memory error detector
==7366== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7366== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7366== Command: ./Forming_Out-of-Bounds_Pointer.out
==7366== 
==7366== 
==7366== HEAP SUMMARY:
==7366==     in use at exit: 0 bytes in 0 blocks
==7366==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7366== 
==7366== All heap blocks were freed -- no leaks are possible
==7366== 
==7366== For counts of detected and suppressed errors, rerun with: -v
==7366== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
