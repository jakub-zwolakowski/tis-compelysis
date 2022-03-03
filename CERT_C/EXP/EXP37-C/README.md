# Examples
## example_strchr
### Test
```
timeout: the monitored command dumped core
Segmentation fault
```
### gcc
```
```
### clang
```
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x424242424242  /build/glibc-XXXXXX/glibc-XXXXXX.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76
    #1 0x424242424242 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x424242424242)
    #2 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x424242424242)
    #3 0x424242424242 in __libc_start_main /build/glibc-XXXXXX/glibc-XXXXXX.27/csu/../csu/libc-start.c:310
    #4 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/EXP/EXP37-C/example_strchr.UBSan-out+0x424242424242)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-XXXXXX/glibc-XXXXXX.27/string/../sysdeps/x86_64/multiarch/strchr-avx2.S:76 
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_strchr.out
==12345== 
==12345== Invalid read of size 1
==12345==    at 0x424242424242: __strchr_avx2 (strchr-avx2.S:45)
==12345==    by 0x424242424242: f_noncompliant (example_strchr.c:9)
==12345==    by 0x424242424242: main (example_strchr.c:24)
==12345==  Address 0x65 is not stack'd, malloc'd or (recently) free'd
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x65
==12345==    at 0x424242424242: __strchr_avx2 (strchr-avx2.S:45)
==12345==    by 0x424242424242: f_noncompliant (example_strchr.c:9)
==12345==    by 0x424242424242: main (example_strchr.c:24)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
ello
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
timeout: the monitored command dumped core
Segmentation fault
```
