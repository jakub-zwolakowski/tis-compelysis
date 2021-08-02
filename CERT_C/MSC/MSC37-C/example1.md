## example1
### Test
```
Success!
Success
```
### gcc
```
example1.c:29:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
example1.c: In function ‘main’:
example1.c:31:8: warning: unused variable ‘not_a_pass’ [-Wunused-variable]
   char not_a_pass[] = "Doom... Doom. Doooooom!!!";
        ^~~~~~~~~~
example1.c: In function ‘checkpass_noncompliant’:
example1.c:8:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
```
### clang
```
example1.c:8:1: warning: non-void function does not return a value in all control paths [-Wreturn-type]
}
^
example1.c:29:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:29:1: note: change return type to 'int'
void main(void) {
^~~~
int
example1.c:31:8: warning: unused variable 'not_a_pass' [-Wunused-variable]
  char not_a_pass[] = "Doom... Doom. Doooooom!!!";
       ^
3 warnings generated.
```
### UBSan
```
Success!
Success
```
### Valgrind
```
==5547== Memcheck, a memory error detector
==5547== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5547== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5547== Command: ./example1.out
==5547== 
Success!
Success
==5547== 
==5547== HEAP SUMMARY:
==5547==     in use at exit: 0 bytes in 0 blocks
==5547==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==5547== 
==5547== All heap blocks were freed -- no leaks are possible
==5547== 
==5547== For counts of detected and suppressed errors, rerun with: -v
==5547== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
