## example
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
example.c: In function ‘func_noncompliant’:
example.c:10:28: warning: variable ‘flex_struct’ set but not used [-Wunused-but-set-variable]
   struct flex_array_struct flex_struct;
                            ^~~~~~~~~~~
```
### clang
```
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242 sp 0x424242424242 T4242)
==12345==Hint: pc points to the zero page.
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x0  (<unknown module>)
    #1 0x41d37a in __sanitizer::HandleDeadlySignal(void*, void*, unsigned int, void (*)(__sanitizer::SignalContext const&, void const*, __sanitizer::BufferedStackTrace*), void const*) /home/qba/tis/deps/llvm/12.0.0/src/projects/compiler-rt/lib/sanitizer_common/sanitizer_symbolizer_report.cpp:246:3
    #2 0x424242424242  (/lib/x86_64-linux-gnu/libpthread.so.0+0x1297f)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (<unknown module>) 
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
*** stack smashing detected ***: <unknown> terminated
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x4E7CFB7: raise (raise.c:51)
==12345==    by 0x4E7E920: abort (abort.c:79)
==12345==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==12345==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==12345==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==12345==    by 0x10870A: func_noncompliant (example.c:19)
==12345==    by 0x108782: main (example.c:44)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 24 bytes in 1 blocks
==12345==   total heap usage: 1 allocs, 0 frees, 24 bytes allocated
==12345== 
==12345== 24 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x108730: func_compliant (example.c:26)
==12345==    by 0x10877D: main (example.c:43)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 24 bytes in 1 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
