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
==7961== Memcheck, a memory error detector
==7961== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7961== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7961== Command: ./Apparently_Accessible_Out-of-Range_Index.out
==7961== 
==7961== 
==7961== HEAP SUMMARY:
==7961==     in use at exit: 0 bytes in 0 blocks
==7961==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7961== 
==7961== All heap blocks were freed -- no leaks are possible
==7961== 
==7961== For counts of detected and suppressed errors, rerun with: -v
==7961== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
