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
==8602== Memcheck, a memory error detector
==8602== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8602== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8602== Command: ./Using_Past-the-End_Index.out
==8602== 
==8602== Invalid write of size 4
==8602==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==8602==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==8602==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==8602==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8602==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8602==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==8602==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==8602== 
==8602== 
==8602== HEAP SUMMARY:
==8602==     in use at exit: 16 bytes in 1 blocks
==8602==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==8602== 
==8602== LEAK SUMMARY:
==8602==    definitely lost: 0 bytes in 0 blocks
==8602==    indirectly lost: 0 bytes in 0 blocks
==8602==      possibly lost: 0 bytes in 0 blocks
==8602==    still reachable: 16 bytes in 1 blocks
==8602==         suppressed: 0 bytes in 0 blocks
==8602== Reachable blocks (those to which a pointer was found) are not shown.
==8602== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==8602== 
==8602== For counts of detected and suppressed errors, rerun with: -v
==8602== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
