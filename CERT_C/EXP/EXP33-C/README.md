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
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./Return-by-Reference.out
==12345== 
==12345== Syscall param exit_group(status) contains uninitialised byte(s)
==12345==    at 0x4F22BD6: _Exit (_exit.c:31)
==12345==    by 0x4E81231: __run_exit_handlers (exit.c:132)
==12345==    by 0x4E81259: exit (exit.c:139)
==12345==    by 0x4E5FBFD: (below main) (libc-start.c:344)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== Use --track-origins=yes to see where uninitialised values come from
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
