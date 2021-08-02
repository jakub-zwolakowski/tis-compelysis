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
==10675== Memcheck, a memory error detector
==10675== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10675== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10675== Command: ./Pointer_Past_Flexible_Array_Member.out
==10675== 
==10675== 
==10675== HEAP SUMMARY:
==10675==     in use at exit: 8 bytes in 1 blocks
==10675==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==10675== 
==10675== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==10675==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10675==    by 0x10871C: main (Pointer_Past_Flexible_Array_Member.c:33)
==10675== 
==10675== LEAK SUMMARY:
==10675==    definitely lost: 8 bytes in 1 blocks
==10675==    indirectly lost: 0 bytes in 0 blocks
==10675==      possibly lost: 0 bytes in 0 blocks
==10675==    still reachable: 0 bytes in 0 blocks
==10675==         suppressed: 0 bytes in 0 blocks
==10675== 
==10675== For counts of detected and suppressed errors, rerun with: -v
==10675== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
