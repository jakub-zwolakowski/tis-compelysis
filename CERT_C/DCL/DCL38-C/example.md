## example
### Test
```
```
### gcc
```
example.c:56:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:56:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:56:1: note: change return type to 'int'
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
==29515== Memcheck, a memory error detector
==29515== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29515== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29515== Command: ./example.out
==29515== 
==29515== 
==29515== HEAP SUMMARY:
==29515==     in use at exit: 344 bytes in 2 blocks
==29515==   total heap usage: 2 allocs, 0 frees, 344 bytes allocated
==29515== 
==29515== 172 bytes in 1 blocks are definitely lost in loss record 1 of 2
==29515==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29515==    by 0x1086CE: f_compliant (example.c:37)
==29515==    by 0x108718: main (example.c:57)
==29515== 
==29515== 172 bytes in 1 blocks are definitely lost in loss record 2 of 2
==29515==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29515==    by 0x108669: f_noncompliant (example.c:10)
==29515==    by 0x108722: main (example.c:58)
==29515== 
==29515== LEAK SUMMARY:
==29515==    definitely lost: 344 bytes in 2 blocks
==29515==    indirectly lost: 0 bytes in 0 blocks
==29515==      possibly lost: 0 bytes in 0 blocks
==29515==    still reachable: 0 bytes in 0 blocks
==29515==         suppressed: 0 bytes in 0 blocks
==29515== 
==29515== For counts of detected and suppressed errors, rerun with: -v
==29515== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
