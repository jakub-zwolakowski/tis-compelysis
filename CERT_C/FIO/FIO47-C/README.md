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
```
### clang
```
example.c:7:35: error: format specifies type 'char *' but the argument has type 'int' [-Werror,-Wformat]
  printf("Error (type %s): %d\n", error_type, error_msg);
                      ~~          ^~~~~~~~~~
                      %d
example.c:7:47: error: format specifies type 'int' but the argument has type 'const char *' [-Werror,-Wformat]
  printf("Error (type %s): %d\n", error_type, error_msg);
                           ~~                 ^~~~~~~~~
                           %s
2 errors generated.
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x424242424242  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65
    #1 0x424242424242 in vfprintf /build/glibc-S9d2JN/glibc-2.27/stdio-common/vfprintf.c:1643
    #2 0x424242424242 in printf /build/glibc-S9d2JN/glibc-2.27/stdio-common/printf.c:33
    #3 0x424242424242 in func_noncompliant (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x424242424242)
    #4 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x424242424242)
    #5 0x424242424242 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #6 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/FIO/FIO47-C/example.UBSan-out+0x424242424242)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/strlen-avx2.S:65 
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: func_noncompliant (example.c:7)
==12345==    by 0x424242424242: main (example.c:22)
==12345==  Address 0x3 is not stack'd, malloc'd or (recently) free'd
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x3
==12345==    at 0x424242424242: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1643)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: func_noncompliant (example.c:7)
==12345==    by 0x424242424242: main (example.c:22)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
Error (type 3): Resource not available to user.
Error (type ==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
