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
==11285== Memcheck, a memory error detector
==11285== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11285== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11285== Command: ./Using_Past-the-End_Index.out
==11285== 
==11285== Invalid write of size 4
==11285==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==11285==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==11285==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==11285==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11285==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11285==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==11285==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==11285== 
==11285== 
==11285== HEAP SUMMARY:
==11285==     in use at exit: 16 bytes in 1 blocks
==11285==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==11285== 
==11285== LEAK SUMMARY:
==11285==    definitely lost: 0 bytes in 0 blocks
==11285==    indirectly lost: 0 bytes in 0 blocks
==11285==      possibly lost: 0 bytes in 0 blocks
==11285==    still reachable: 16 bytes in 1 blocks
==11285==         suppressed: 0 bytes in 0 blocks
==11285== Reachable blocks (those to which a pointer was found) are not shown.
==11285== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==11285== 
==11285== For counts of detected and suppressed errors, rerun with: -v
==11285== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
