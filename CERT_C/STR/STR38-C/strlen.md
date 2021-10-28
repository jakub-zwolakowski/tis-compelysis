## strlen
### Test
```
```
### gcc
```
strlen.c: In function ‘f_noncompliant’:
strlen.c:7:48: warning: passing argument 1 of ‘strlen’ from incompatible pointer type [-Wincompatible-pointer-types]
   wchar_t *wide_str2 = (wchar_t*)malloc(strlen(wide_str1) + 1);
                                                ^~~~~~~~~
In file included from strlen.c:2:0:
/usr/include/string.h:384:15: note: expected ‘const char *’ but argument is of type ‘wchar_t * {aka int *}’
 extern size_t strlen (const char *__s)
               ^~~~~~
strlen.c: At top level:
strlen.c:33:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
strlen.c:7:48: warning: incompatible pointer types passing 'wchar_t [11]' to parameter of type 'const char *' [-Wincompatible-pointer-types]
  wchar_t *wide_str2 = (wchar_t*)malloc(strlen(wide_str1) + 1);
                                               ^~~~~~~~~
/usr/include/string.h:384:35: note: passing argument to parameter '__s' here
extern size_t strlen (const char *__s)
                                  ^
strlen.c:33:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
strlen.c:33:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./strlen.out
==12345== 
==12345== Invalid write of size 4
==12345==    at 0x108812: f_noncompliant (strlen.c:13)
==12345==    by 0x108900: main (strlen.c:35)
==12345==  Address 0x522f0bc is 10 bytes after a block of size 2 alloc'd
==12345==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x1087F8: f_noncompliant (strlen.c:7)
==12345==    by 0x108900: main (strlen.c:35)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 46 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
