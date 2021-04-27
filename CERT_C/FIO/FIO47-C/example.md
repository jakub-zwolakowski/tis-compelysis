## example
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
example.c: In function ‘func_noncompliant’:
example.c:7:24: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
   printf("Error (type %s): %d\n", error_type, error_msg);
                       ~^
                       %d
example.c:7:29: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘const char *’ [-Wformat=]
   printf("Error (type %s): %d\n", error_type, error_msg);
                            ~^
                            %s
example.c: At top level:
example.c:20:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
example.c:7:35: warning: format specifies type 'char *' but the argument has type 'int' [-Wformat]
  printf("Error (type %s): %d\n", error_type, error_msg);
                      ~~          ^~~~~~~~~~
                      %d
example.c:7:47: warning: format specifies type 'int' but the argument has type 'const char *' [-Wformat]
  printf("Error (type %s): %d\n", error_type, error_msg);
                           ~~                 ^~~~~~~~~
                           %s
example.c:20:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:20:1: note: change return type to 'int'
void main(void) {
^~~~
int
3 warnings generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==32409==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000003 (pc 0x7f80f01dc4e1 bp 0x7ffd3fe57360 sp 0x7ffd3fe56de8 T32409)
==32409==The signal is caused by a READ memory access.
==32409==Hint: address points to the zero page.
    #0 0x7f80f01dc4e1  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65
    #1 0x7f80f00ab5d2 in vfprintf /build/glibc-S9d2JN/glibc-2.27/stdio-common/vfprintf.c:1643
    #2 0x7f80f00b3015 in printf /build/glibc-S9d2JN/glibc-2.27/stdio-common/printf.c:33
    #3 0x423234 in func_noncompliant (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x423234)
    #4 0x42328d in main (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x42328d)
    #5 0x7f80f006fbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #6 0x402a29 in _start (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x402a29)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65 
==32409==ABORTING
```
### Valgrind
```
==32415== Memcheck, a memory error detector
==32415== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32415== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32415== Command: ./example.out
==32415== 
==32415== Invalid read of size 1
==32415==    at 0x4C34CF2: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==32415==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==32415==    by 0x4EA3015: printf (printf.c:33)
==32415==    by 0x10867D: func_noncompliant (example.c:7)
==32415==    by 0x1086C5: main (example.c:22)
==32415==  Address 0x3 is not stack'd, malloc'd or (recently) free'd
==32415== 
==32415== 
==32415== Process terminating with default action of signal 11 (SIGSEGV)
==32415==  Access not within mapped region at address 0x3
==32415==    at 0x4C34CF2: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==32415==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==32415==    by 0x4EA3015: printf (printf.c:33)
==32415==    by 0x10867D: func_noncompliant (example.c:7)
==32415==    by 0x1086C5: main (example.c:22)
==32415==  If you believe this happened as a result of a stack
==32415==  overflow in your program's main thread (unlikely but
==32415==  possible), you can try to increase the size of the
==32415==  main thread stack using the --main-stacksize= flag.
==32415==  The main thread stack size used in this run was 8388608.
Error (type 3): Resource not available to user.
Error (type ==32415== 
==32415== HEAP SUMMARY:
==32415==     in use at exit: 0 bytes in 0 blocks
==32415==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==32415== 
==32415== All heap blocks were freed -- no leaks are possible
==32415== 
==32415== For counts of detected and suppressed errors, rerun with: -v
==32415== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
