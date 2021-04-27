## Apparently_Accessible_Out-of-Range_Index
### Test
```
```
### gcc
```
Apparently_Accessible_Out-of-Range_Index.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Apparently_Accessible_Out-of-Range_Index.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Apparently_Accessible_Out-of-Range_Index.c:22:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Apparently_Accessible_Out-of-Range_Index.c:9:7: runtime error: index 5 out of bounds for type 'int [5]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Apparently_Accessible_Out-of-Range_Index.c:9:7 in 
```
### Valgrind
```
==9146== Memcheck, a memory error detector
==9146== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9146== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9146== Command: ./Apparently_Accessible_Out-of-Range_Index.out
==9146== 
==9146== 
==9146== HEAP SUMMARY:
==9146==     in use at exit: 0 bytes in 0 blocks
==9146==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9146== 
==9146== All heap blocks were freed -- no leaks are possible
==9146== 
==9146== For counts of detected and suppressed errors, rerun with: -v
==9146== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
