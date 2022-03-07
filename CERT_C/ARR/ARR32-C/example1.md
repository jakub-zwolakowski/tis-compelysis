## example1
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
==12345==ERROR: UndefinedBehaviorSanitizer: stack-overflow on address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
    #0 0x424242424242 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242)
    #1 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR32-C/example1.UBSan-out+0x424242424242)
    #2 0x424242424242 in __libc_start_main /build/glibc-XXXXXX/glibc-XXXXXX.27/csu/../csu/libc-start.c:310
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
==12345== Parent PID: 12345
==12345== 
==12345== Warning: set address range perms: large range [0x424242424242, 0x424242424242) (undefined)
==12345== 
==12345== Process terminating with default action of signal 15 (SIGTERM)
==12345==    at 0x424242424242: do_work (example1.c:9)
==12345==    by 0x424242424242: f_compliant (example1.c:33)
==12345==    by 0x424242424242: main (example1.c:41)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 123,456 bytes in 1 blocks
==12345==   total heap usage: 1 allocs, 0 frees, 123,456 bytes allocated
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 0 bytes in 0 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 123,456 bytes in 1 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== Reachable blocks (those to which a pointer was found) are not shown.
==12345== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
