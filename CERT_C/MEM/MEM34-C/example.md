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
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7f3c4bb31cf1 bp 0xffffffffffffff90 sp 0x7fffadf3ad30 T23383)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x7f3c4bb31cf1 in free /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133
    #1 0x424458 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x424458)
    #2 0x4247fc in main (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x4247fc)
    #3 0x7f3c4babbbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402b39 in _start (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x402b39)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133 in free
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== Invalid free() / delete / delete[] / realloc()
==12345==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x10886F: f_noncompliant (example.c:27)
==12345==    by 0x10898E: main (example.c:62)
==12345==  Address 0x108a34 is in a r-x mapped file /home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.out segment
==12345== 
usage: $>a.exe [string]
usage: $>a.exe [string]
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 3 allocs, 4 frees, 4,104 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
