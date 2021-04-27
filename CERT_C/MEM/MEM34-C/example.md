## example
### Test
```
munmap_chunk(): invalid pointer
Aborted (core dumped)
```
### gcc
```
example.c:55:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
example.c: In function ‘main’:
example.c:59:18: warning: passing argument 2 of ‘f_compliant’ from incompatible pointer type [-Wincompatible-pointer-types]
   f_compliant(2, argv);
                  ^~~~
example.c:31:5: note: expected ‘const char **’ but argument is of type ‘char **’
 int f_compliant(int argc, const char *argv[]) {
     ^~~~~~~~~~~
example.c:60:18: warning: passing argument 2 of ‘f_compliant’ from incompatible pointer type [-Wincompatible-pointer-types]
   f_compliant(1, argv);
                  ^~~~
example.c:31:5: note: expected ‘const char **’ but argument is of type ‘char **’
 int f_compliant(int argc, const char *argv[]) {
     ^~~~~~~~~~~
example.c:61:21: warning: passing argument 2 of ‘f_noncompliant’ from incompatible pointer type [-Wincompatible-pointer-types]
   f_noncompliant(2, argv);
                     ^~~~
example.c:7:5: note: expected ‘const char **’ but argument is of type ‘char **’
 int f_noncompliant(int argc, const char *argv[]) {
     ^~~~~~~~~~~~~~
example.c:62:21: warning: passing argument 2 of ‘f_noncompliant’ from incompatible pointer type [-Wincompatible-pointer-types]
   f_noncompliant(1, argv);
                     ^~~~
example.c:7:5: note: expected ‘const char **’ but argument is of type ‘char **’
 int f_noncompliant(int argc, const char *argv[]) {
     ^~~~~~~~~~~~~~
```
### clang
```
example.c:55:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:55:1: note: change return type to 'int'
void main(void) {
^~~~
int
example.c:59:18: warning: passing 'char *[2]' to parameter of type 'const char **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  f_compliant(2, argv);
                 ^~~~
example.c:31:39: note: passing argument to parameter 'argv' here
int f_compliant(int argc, const char *argv[]) {
                                      ^
example.c:60:18: warning: passing 'char *[2]' to parameter of type 'const char **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  f_compliant(1, argv);
                 ^~~~
example.c:31:39: note: passing argument to parameter 'argv' here
int f_compliant(int argc, const char *argv[]) {
                                      ^
example.c:61:21: warning: passing 'char *[2]' to parameter of type 'const char **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  f_noncompliant(2, argv);
                    ^~~~
example.c:7:42: note: passing argument to parameter 'argv' here
int f_noncompliant(int argc, const char *argv[]) {
                                         ^
example.c:62:21: warning: passing 'char *[2]' to parameter of type 'const char **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
  f_noncompliant(1, argv);
                    ^~~~
example.c:7:42: note: passing argument to parameter 'argv' here
int f_noncompliant(int argc, const char *argv[]) {
                                         ^
5 warnings generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==4262==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7f09b736bcf1 bp 0xffffffffffffff88 sp 0x7ffc3d6e1c20 T4262)
==4262==The signal is caused by a READ memory access.
==4262==Hint: address points to the zero page.
    #0 0x7f09b736bcf1 in free /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133
    #1 0x423561 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x423561)
    #2 0x423965 in main (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x423965)
    #3 0x7f09b72f5bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402b49 in _start (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x402b49)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133 in free
==4262==ABORTING
```
### Valgrind
```
==4268== Memcheck, a memory error detector
==4268== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4268== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4268== Command: ./example.out
==4268== 
==4268== Invalid free() / delete / delete[] / realloc()
==4268==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4268==    by 0x10886F: f_noncompliant (example.c:27)
==4268==    by 0x10898E: main (example.c:62)
==4268==  Address 0x108a34 is in a r-x mapped file /home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.out segment
==4268== 
usage: $>a.exe [string]
usage: $>a.exe [string]
==4268== 
==4268== HEAP SUMMARY:
==4268==     in use at exit: 0 bytes in 0 blocks
==4268==   total heap usage: 3 allocs, 4 frees, 4,104 bytes allocated
==4268== 
==4268== All heap blocks were freed -- no leaks are possible
==4268== 
==4268== For counts of detected and suppressed errors, rerun with: -v
==4268== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
