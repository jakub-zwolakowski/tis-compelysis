## example_compliant
### Test
```
timeout: the monitored command dumped core
Floating point exception
```
### gcc
```
```
### clang
```
```
### UBSan
```
example_compliant.c:20:21: runtime error: division by zero
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_compliant.c:20:21 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: FPE on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
    #0 0x424242424242 in f (/home/qba/git/tis-compelysis/CERT_C/SIG/SIG35-C/example_compliant.UBSan-out+0x424242424242)
    #1 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/SIG/SIG35-C/example_compliant.UBSan-out+0x424242424242)
    #2 0x424242424242 in __libc_start_main /build/glibc-XXXXXX/glibc-XXXXXX.27/csu/../csu/libc-start.c:310
    #3 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/SIG/SIG35-C/example_compliant.UBSan-out+0x424242424242)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: FPE (/home/qba/git/tis-compelysis/CERT_C/SIG/SIG35-C/example_compliant.UBSan-out+0x424242424242) in f
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== Process terminating with default action of signal 8 (SIGFPE)
==12345==  Integer divide by zero at address 0x424242424242
==12345==    at 0x424242424242: f (example_compliant.c:20)
==12345==    by 0x424242424242: main (example_compliant.c:32)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
