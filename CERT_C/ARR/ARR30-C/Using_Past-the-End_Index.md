## Using_Past-the-End_Index
### Test
```
```
### gcc
```
Using_Past-the-End_Index.c:42:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Using_Past-the-End_Index.c:42:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Using_Past-the-End_Index.c:42:1: note: change return type to 'int'
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
==7435== Memcheck, a memory error detector
==7435== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7435== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7435== Command: ./Using_Past-the-End_Index.out
==7435== 
==7435== Invalid write of size 4
==7435==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==7435==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==7435==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==7435==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7435==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7435==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==7435==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==7435== 
==7435== 
==7435== HEAP SUMMARY:
==7435==     in use at exit: 16 bytes in 1 blocks
==7435==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==7435== 
==7435== LEAK SUMMARY:
==7435==    definitely lost: 0 bytes in 0 blocks
==7435==    indirectly lost: 0 bytes in 0 blocks
==7435==      possibly lost: 0 bytes in 0 blocks
==7435==    still reachable: 16 bytes in 1 blocks
==7435==         suppressed: 0 bytes in 0 blocks
==7435== Reachable blocks (those to which a pointer was found) are not shown.
==7435== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==7435== 
==7435== For counts of detected and suppressed errors, rerun with: -v
==7435== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
