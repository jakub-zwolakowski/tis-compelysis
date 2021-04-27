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
example.c: In function ‘main’:
example.c:27:7: warning: unused variable ‘res’ [-Wunused-variable]
   int res = 13;
       ^~~
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
example.c:27:7: warning: unused variable 'res' [-Wunused-variable]
  int res = 13;
      ^
2 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==30432== Memcheck, a memory error detector
==30432== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30432== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30432== Command: ./example.out
==30432== 
==30432== Conditional jump or move depends on uninitialised value(s)
==30432==    at 0x4C37E22: bcmp (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30432==    by 0x1086DF: compare_noncompliant (example.c:11)
==30432==    by 0x1087DB: main (example.c:42)
==30432== 
==30432== Conditional jump or move depends on uninitialised value(s)
==30432==    at 0x4C37E91: bcmp (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30432==    by 0x1086DF: compare_noncompliant (example.c:11)
==30432==    by 0x1087DB: main (example.c:42)
==30432== 
==30432== 
==30432== HEAP SUMMARY:
==30432==     in use at exit: 0 bytes in 0 blocks
==30432==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==30432== 
==30432== All heap blocks were freed -- no leaks are possible
==30432== 
==30432== For counts of detected and suppressed errors, rerun with: -v
==30432== Use --track-origins=yes to see where uninitialised values come from
==30432== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
