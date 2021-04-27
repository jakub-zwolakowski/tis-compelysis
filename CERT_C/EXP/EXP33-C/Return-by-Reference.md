## Return-by-Reference
### Test
```
```
### gcc
```
Return-by-Reference.c:41:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Return-by-Reference.c:41:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Return-by-Reference.c:41:1: note: change return type to 'int'
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
==32185== Memcheck, a memory error detector
==32185== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32185== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32185== Command: ./Return-by-Reference.out
==32185== 
==32185== Syscall param exit_group(status) contains uninitialised byte(s)
==32185==    at 0x4F22BD6: _Exit (_exit.c:31)
==32185==    by 0x4E81231: __run_exit_handlers (exit.c:132)
==32185==    by 0x4E81259: exit (exit.c:139)
==32185==    by 0x4E5FBFD: (below main) (libc-start.c:344)
==32185== 
==32185== 
==32185== HEAP SUMMARY:
==32185==     in use at exit: 0 bytes in 0 blocks
==32185==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==32185== 
==32185== All heap blocks were freed -- no leaks are possible
==32185== 
==32185== For counts of detected and suppressed errors, rerun with: -v
==32185== Use --track-origins=yes to see where uninitialised values come from
==32185== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
