## Pointer_Past_Flexible_Array_Member
### Test
```
```
### gcc
```
Pointer_Past_Flexible_Array_Member.c:32:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Pointer_Past_Flexible_Array_Member.c:32:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Pointer_Past_Flexible_Array_Member.c:32:1: note: change return type to 'int'
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
==6773== Memcheck, a memory error detector
==6773== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6773== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6773== Command: ./Pointer_Past_Flexible_Array_Member.out
==6773== 
==6773== 
==6773== HEAP SUMMARY:
==6773==     in use at exit: 8 bytes in 1 blocks
==6773==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==6773== 
==6773== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==6773==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==6773==    by 0x10871C: main (Pointer_Past_Flexible_Array_Member.c:33)
==6773== 
==6773== LEAK SUMMARY:
==6773==    definitely lost: 8 bytes in 1 blocks
==6773==    indirectly lost: 0 bytes in 0 blocks
==6773==      possibly lost: 0 bytes in 0 blocks
==6773==    still reachable: 0 bytes in 0 blocks
==6773==         suppressed: 0 bytes in 0 blocks
==6773== 
==6773== For counts of detected and suppressed errors, rerun with: -v
==6773== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
