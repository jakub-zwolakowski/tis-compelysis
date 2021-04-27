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
==4338== Memcheck, a memory error detector
==4338== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4338== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4338== Command: ./example.out
==4338== 
==4338== 
==4338== HEAP SUMMARY:
==4338==     in use at exit: 32 bytes in 1 blocks
==4338==   total heap usage: 2 allocs, 1 frees, 64 bytes allocated
==4338== 
==4338== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==4338==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4338==    by 0x10869B: f_noncompliant (example.c:9)
==4338==    by 0x1086F9: main (example.c:27)
==4338== 
==4338== LEAK SUMMARY:
==4338==    definitely lost: 32 bytes in 1 blocks
==4338==    indirectly lost: 0 bytes in 0 blocks
==4338==      possibly lost: 0 bytes in 0 blocks
==4338==    still reachable: 0 bytes in 0 blocks
==4338==         suppressed: 0 bytes in 0 blocks
==4338== 
==4338== For counts of detected and suppressed errors, rerun with: -v
==4338== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
