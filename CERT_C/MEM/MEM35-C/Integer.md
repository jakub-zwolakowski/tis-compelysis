## Integer
### Test
```
```
### gcc
```
Integer.c:40:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Integer.c:40:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Integer.c:40:1: note: change return type to 'int'
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
==4408== Memcheck, a memory error detector
==4408== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4408== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4408== Command: ./Integer.out
==4408== 
==4408== Invalid write of size 8
==4408==    at 0x1086EA: f_noncompliant (Integer.c:17)
==4408==    by 0x1087AD: main (Integer.c:42)
==4408==  Address 0x522f278 is 0 bytes after a block of size 168 alloc'd
==4408==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4408==    by 0x1086BC: f_noncompliant (Integer.c:10)
==4408==    by 0x1087AD: main (Integer.c:42)
==4408== 
==4408== 
==4408== HEAP SUMMARY:
==4408==     in use at exit: 0 bytes in 0 blocks
==4408==   total heap usage: 2 allocs, 2 frees, 504 bytes allocated
==4408== 
==4408== All heap blocks were freed -- no leaks are possible
==4408== 
==4408== For counts of detected and suppressed errors, rerun with: -v
==4408== ERROR SUMMARY: 21 errors from 1 contexts (suppressed: 0 from 0)
```
