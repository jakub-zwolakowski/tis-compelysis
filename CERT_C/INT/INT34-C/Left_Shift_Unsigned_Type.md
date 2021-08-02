## Left_Shift_Unsigned_Type
### Test
```
```
### gcc
```
Left_Shift_Unsigned_Type.c: In function ‘f_noncompliant’:
Left_Shift_Unsigned_Type.c:20:16: warning: unused variable ‘uresult’ [-Wunused-variable]
   unsigned int uresult = ui_a << ui_b;
                ^~~~~~~
Left_Shift_Unsigned_Type.c: In function ‘f_compliant’:
Left_Shift_Unsigned_Type.c:25:16: warning: variable ‘uresult’ set but not used [-Wunused-but-set-variable]
   unsigned int uresult = 0;
                ^~~~~~~
Left_Shift_Unsigned_Type.c: At top level:
Left_Shift_Unsigned_Type.c:34:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Left_Shift_Unsigned_Type.c:20:16: warning: unused variable 'uresult' [-Wunused-variable]
  unsigned int uresult = ui_a << ui_b;
               ^
Left_Shift_Unsigned_Type.c:34:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Left_Shift_Unsigned_Type.c:34:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
Left_Shift_Unsigned_Type.c:20:31: runtime error: shift exponent 42 is too large for 32-bit type 'unsigned int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Left_Shift_Unsigned_Type.c:20:31 in 
```
### Valgrind
```
==5983== Memcheck, a memory error detector
==5983== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5983== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5983== Command: ./Left_Shift_Unsigned_Type.out
==5983== 
==5983== 
==5983== HEAP SUMMARY:
==5983==     in use at exit: 0 bytes in 0 blocks
==5983==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5983== 
==5983== All heap blocks were freed -- no leaks are possible
==5983== 
==5983== For counts of detected and suppressed errors, rerun with: -v
==5983== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
