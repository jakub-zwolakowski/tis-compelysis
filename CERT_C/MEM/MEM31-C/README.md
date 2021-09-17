# Examples
## example
### Test
```
```
### gcc
```
example.c:25:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:25:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:25:1: note: change return type to 'int'
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
==24501== Memcheck, a memory error detector
==24501== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24501== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24501== Command: ./example.out
==24501== 
==24501== 
==24501== HEAP SUMMARY:
==24501==     in use at exit: 32 bytes in 1 blocks
==24501==   total heap usage: 2 allocs, 1 frees, 64 bytes allocated
==24501== 
==24501== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==24501==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==24501==    by 0x10869B: f_noncompliant (example.c:9)
==24501==    by 0x1086F9: main (example.c:27)
==24501== 
==24501== LEAK SUMMARY:
==24501==    definitely lost: 32 bytes in 1 blocks
==24501==    indirectly lost: 0 bytes in 0 blocks
==24501==      possibly lost: 0 bytes in 0 blocks
==24501==    still reachable: 0 bytes in 0 blocks
==24501==         suppressed: 0 bytes in 0 blocks
==24501== 
==24501== For counts of detected and suppressed errors, rerun with: -v
==24501== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
