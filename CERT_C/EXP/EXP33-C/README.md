# Examples
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
==4235== Memcheck, a memory error detector
==4235== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4235== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4235== Command: ./Return-by-Reference.out
==4235== 
==4235== Syscall param exit_group(status) contains uninitialised byte(s)
==4235==    at 0x4F22BD6: _Exit (_exit.c:31)
==4235==    by 0x4E81231: __run_exit_handlers (exit.c:132)
==4235==    by 0x4E81259: exit (exit.c:139)
==4235==    by 0x4E5FBFD: (below main) (libc-start.c:344)
==4235== 
==4235== 
==4235== HEAP SUMMARY:
==4235==     in use at exit: 0 bytes in 0 blocks
==4235==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4235== 
==4235== All heap blocks were freed -- no leaks are possible
==4235== 
==4235== For counts of detected and suppressed errors, rerun with: -v
==4235== Use --track-origins=yes to see where uninitialised values come from
==4235== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
