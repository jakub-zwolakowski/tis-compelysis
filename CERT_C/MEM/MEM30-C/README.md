# Examples
## example1
### Test
```
free(): double free detected in tcache 2
Aborted (core dumped)
```
### gcc
```
example1.c:34:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example1.c:34:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:34:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
free(): double free detected in tcache 2
Aborted (core dumped)
```
### Valgrind
```
==23284== Memcheck, a memory error detector
==23284== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23284== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23284== Command: ./example1.out
==23284== 
==23284== Invalid read of size 8
==23284==    at 0x1086B0: free_list_noncompliant (example1.c:9)
==23284==    by 0x10878E: main (example1.c:39)
==23284==  Address 0x522f1d8 is 8 bytes inside a block of size 16 free'd
==23284==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==23284==    by 0x1086AB: free_list_noncompliant (example1.c:10)
==23284==    by 0x10878E: main (example1.c:39)
==23284==  Block was alloc'd at
==23284==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==23284==    by 0x108727: make_list (example1.c:27)
==23284==    by 0x10877E: main (example1.c:38)
==23284== 
==23284== 
==23284== HEAP SUMMARY:
==23284==     in use at exit: 64 bytes in 4 blocks
==23284==   total heap usage: 6 allocs, 2 frees, 96 bytes allocated
==23284== 
==23284== 32 bytes in 2 blocks are definitely lost in loss record 1 of 2
==23284==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==23284==    by 0x108727: make_list (example1.c:27)
==23284==    by 0x108764: main (example1.c:36)
==23284== 
==23284== 32 bytes in 2 blocks are definitely lost in loss record 2 of 2
==23284==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==23284==    by 0x108727: make_list (example1.c:27)
==23284==    by 0x10877E: main (example1.c:38)
==23284== 
==23284== LEAK SUMMARY:
==23284==    definitely lost: 64 bytes in 4 blocks
==23284==    indirectly lost: 0 bytes in 0 blocks
==23284==      possibly lost: 0 bytes in 0 blocks
==23284==    still reachable: 0 bytes in 0 blocks
==23284==         suppressed: 0 bytes in 0 blocks
==23284== 
==23284== For counts of detected and suppressed errors, rerun with: -v
==23284== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```
