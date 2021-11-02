# Examples
## example1
### Test
```
Segmentation fault (core dumped)
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
==12345==ERROR: UndefinedBehaviorSanitizer: stack-overflow on address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
    #0 0x424242424242 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242)
    #1 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242)
    #2 0x424242424242 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #3 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242)

SUMMARY: UndefinedBehaviorSanitizer: stack-overflow (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242) in f_noncompliant
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example1.out
==12345== 
==12345== Warning: set address range perms: large range [0x424242424242, 0x424242424242) (undefined)
==12345== Warning: set address range perms: large range [0x424242424242, 0x424242424242) (noaccess)
==12345== Warning: client switching stacks?  SP change: 0x424242424242 --> 0x424242424242
==12345==          to suppress, use: --max-stackframe=8589934592 or greater
==12345== Invalid write of size 8
==12345==    at 0x424242424242: f_noncompliant (example1.c:14)
==12345==  Address 0x424242424242 is on thread 1's stack
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x424242424242
==12345==    at 0x424242424242: f_noncompliant (example1.c:14)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
==12345== Invalid write of size 8
==12345==    at 0x424242424242: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==12345==  Address 0x424242424242 is on thread 1's stack
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x424242424242
==12345==    at 0x424242424242: _vgnU_freeres (in /usr/lib/valgrind/vgpreload_core-amd64-linux.so)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
