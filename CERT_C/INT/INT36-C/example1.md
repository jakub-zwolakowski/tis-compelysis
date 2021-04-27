## example1
### Test
```
```
### gcc
```
example1.c: In function ‘func_noncompliant’:
example1.c:5:25: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   unsigned int number = (unsigned int)ptr;
                         ^
example1.c:7:9: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   ptr = (char *)number;
         ^
example1.c: At top level:
example1.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
example1.c: In function ‘func_compliant’:
example1.c:18:19: warning: ‘ptr’ is used uninitialized in this function [-Wuninitialized]
   ptrflag.pointer = ptr;
   ~~~~~~~~~~~~~~~~^~~~~
```
### clang
```
example1.c:5:25: warning: cast to smaller integer type 'unsigned int' from 'char *' [-Wpointer-to-int-cast]
  unsigned int number = (unsigned int)ptr;
                        ^~~~~~~~~~~~~~~~~
example1.c:7:9: warning: cast to 'char *' from smaller integer type 'unsigned int' [-Wint-to-pointer-cast]
  ptr = (char *)number;
        ^~~~~~~~~~~~~~
example1.c:18:21: warning: variable 'ptr' is uninitialized when used here [-Wuninitialized]
  ptrflag.pointer = ptr;
                    ^~~
example1.c:16:12: note: initialize the variable 'ptr' to silence this warning
  char *ptr;
           ^
            = 0
example1.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example1.c:22:1: note: change return type to 'int'
void main(void) {
^~~~
int
4 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==1760== Memcheck, a memory error detector
==1760== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1760== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1760== Command: ./example1.out
==1760== 
==1760== 
==1760== HEAP SUMMARY:
==1760==     in use at exit: 0 bytes in 0 blocks
==1760==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==1760== 
==1760== All heap blocks were freed -- no leaks are possible
==1760== 
==1760== For counts of detected and suppressed errors, rerun with: -v
==1760== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
