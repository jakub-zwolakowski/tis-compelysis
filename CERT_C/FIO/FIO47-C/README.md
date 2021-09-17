# Examples
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
==28790==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000003 (pc 0x7f38506924e1 bp 0x7ffeb85a7e80 sp 0x7ffeb85a7908 T28790)
==28790==The signal is caused by a READ memory access.
==28790==Hint: address points to the zero page.
    #0 0x7f38506924e1  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65
    #1 0x7f38505615d2 in vfprintf /build/glibc-S9d2JN/glibc-2.27/stdio-common/vfprintf.c:1643
    #2 0x7f3850569015 in printf /build/glibc-S9d2JN/glibc-2.27/stdio-common/printf.c:33
    #3 0x424154 in func_noncompliant (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x424154)
    #4 0x4241ad in main (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x4241ad)
    #5 0x7f3850525bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #6 0x402a19 in _start (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x402a19)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65 
==28790==ABORTING
```
### Valgrind
```
==28797== Memcheck, a memory error detector
==28797== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==28797== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==28797== Command: ./example.out
==28797== 
==28797== Invalid read of size 1
==28797==    at 0x4C34CF2: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==28797==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==28797==    by 0x4EA3015: printf (printf.c:33)
==28797==    by 0x10867D: func_noncompliant (example.c:7)
==28797==    by 0x1086C5: main (example.c:22)
==28797==  Address 0x3 is not stack'd, malloc'd or (recently) free'd
==28797== 
==28797== 
==28797== Process terminating with default action of signal 11 (SIGSEGV)
==28797==  Access not within mapped region at address 0x3
==28797==    at 0x4C34CF2: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==28797==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==28797==    by 0x4EA3015: printf (printf.c:33)
==28797==    by 0x10867D: func_noncompliant (example.c:7)
==28797==    by 0x1086C5: main (example.c:22)
==28797==  If you believe this happened as a result of a stack
==28797==  overflow in your program's main thread (unlikely but
==28797==  possible), you can try to increase the size of the
==28797==  main thread stack using the --main-stacksize= flag.
==28797==  The main thread stack size used in this run was 8388608.
Error (type 3): Resource not available to user.
Error (type ==28797== 
==28797== HEAP SUMMARY:
==28797==     in use at exit: 0 bytes in 0 blocks
==28797==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==28797== 
==28797== All heap blocks were freed -- no leaks are possible
==28797== 
==28797== For counts of detected and suppressed errors, rerun with: -v
==28797== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
