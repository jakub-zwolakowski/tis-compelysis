# Examples
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
==3245== Memcheck, a memory error detector
==3245== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3245== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3245== Command: ./Integer.out
==3245== 
==3245== Invalid write of size 8
==3245==    at 0x1086EA: f_noncompliant (Integer.c:17)
==3245==    by 0x1087AD: main (Integer.c:42)
==3245==  Address 0x522f278 is 0 bytes after a block of size 168 alloc'd
==3245==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==3245==    by 0x1086BC: f_noncompliant (Integer.c:10)
==3245==    by 0x1087AD: main (Integer.c:42)
==3245== 
==3245== 
==3245== HEAP SUMMARY:
==3245==     in use at exit: 0 bytes in 0 blocks
==3245==   total heap usage: 2 allocs, 2 frees, 504 bytes allocated
==3245== 
==3245== All heap blocks were freed -- no leaks are possible
==3245== 
==3245== For counts of detected and suppressed errors, rerun with: -v
==3245== ERROR SUMMARY: 21 errors from 1 contexts (suppressed: 0 from 0)
```
