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
==9126== Memcheck, a memory error detector
==9126== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9126== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9126== Command: ./Return-by-Reference.out
==9126== 
==9126== Syscall param exit_group(status) contains uninitialised byte(s)
==9126==    at 0x4F22BD6: _Exit (_exit.c:31)
==9126==    by 0x4E81231: __run_exit_handlers (exit.c:132)
==9126==    by 0x4E81259: exit (exit.c:139)
==9126==    by 0x4E5FBFD: (below main) (libc-start.c:344)
==9126== 
==9126== 
==9126== HEAP SUMMARY:
==9126==     in use at exit: 0 bytes in 0 blocks
==9126==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9126== 
==9126== All heap blocks were freed -- no leaks are possible
==9126== 
==9126== For counts of detected and suppressed errors, rerun with: -v
==9126== Use --track-origins=yes to see where uninitialised values come from
==9126== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
