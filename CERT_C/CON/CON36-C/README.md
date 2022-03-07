# Examples
## example_compliant
### Test
```
Node = 42
Node = 42
Node = 42
Node = 42
Node = 42
Node = 42
```
### gcc
```
```
### clang
```
```
### UBSan
```
Node = 42
Node = 42
Node = 42
Node = 42
Node = 42
Node = 42
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
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 19 allocs, 19 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
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
example_noncompliant.c:38:38: runtime error: member access within null pointer of type 'struct node_t'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_noncompliant.c:38:38 in 
example_noncompliant.c:38:38: runtime error: load of null pointer of type 'void *'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_noncompliant.c:38:38 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x424242424242 in consume_list_element (/home/qba/git/tis-compelysis/CERT_C/CON/CON36-C/example_noncompliant.UBSan-out+0x424242424242)
    #1 0x424242424242 in start_thread /build/glibc-XXXXXX/glibc-XXXXXX.27/nptl/pthread_create.c:463
    #2 0x424242424242 in clone /build/glibc-XXXXXX/glibc-XXXXXX.27/misc/../sysdeps/unix/sysv/linux/x86_64/clone.S:95

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (/home/qba/git/tis-compelysis/CERT_C/CON/CON36-C/example_noncompliant.UBSan-out+0x424242424242) in consume_list_element
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== Parent PID: 12345
==12345== 
==12345== Thread 42:
==12345== Invalid read of size 8
==12345==    at 0x424242424242: consume_list_element (example_noncompliant.c:38)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==12345== 
==12345== 
==12345== Process terminating with default action of signal 11 (SIGSEGV)
==12345==  Access not within mapped region at address 0x0
==12345==    at 0x424242424242: consume_list_element (example_noncompliant.c:38)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345==  If you believe this happened as a result of a stack
==12345==  overflow in your program's main thread (unlikely but
==12345==  possible), you can try to increase the size of the
==12345==  main thread stack using the --main-stacksize= flag.
==12345==  The main thread stack size used in this run was 8388608.
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 123,456 bytes in 6 blocks
==12345==   total heap usage: 13 allocs, 7 frees, 123,456 bytes allocated
==12345== 
==12345== Thread 42:
==12345== 123,456 bytes in 6 blocks are possibly lost in loss record 1 of 1
==12345==    at 0x424242424242: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: allocate_dtv (dl-tls.c:286)
==12345==    by 0x424242424242: _dl_allocate_tls (dl-tls.c:530)
==12345==    by 0x424242424242: allocate_stack (allocatestack.c:627)
==12345==    by 0x424242424242: pthread_create@@GLIBC_2.2.5 (pthread_create.c:644)
==12345==    by 0x424242424242: thrd_create (c11threads.h:52)
==12345==    by 0x424242424242: main (example_noncompliant.c:85)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 0 bytes in 0 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 123,456 bytes in 6 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
