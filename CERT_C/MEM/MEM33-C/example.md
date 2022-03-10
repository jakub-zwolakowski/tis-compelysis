## example
### Test
```
*** stack smashing detected ***: <unknown> terminated
timeout: the monitored command dumped core
Aborted
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
==12345==Hint: pc points to the zero page.
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x0  (<unknown module>)
    #1 0x424242424242 in __sanitizer::HandleDeadlySignal(void*, void*, unsigned int, void (*)(__sanitizer::SignalContext const&, void const*, __sanitizer::BufferedStackTrace*), void const*) /home/qba/tis/deps/llvm/12.0.0/src/projects/compiler-rt/lib/sanitizer_common/sanitizer_symbolizer_report.cpp:246:3
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
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== Process terminating with default action of signal 6 (SIGABRT)
==12345==    at 0x424242424242: raise (raise.c:51)
==12345==    by 0x424242424242: abort (abort.c:79)
==12345==    by 0x424242424242: __libc_message (libc_fatal.c:181)
==12345==    by 0x424242424242: __fortify_fail_abort (fortify_fail.c:33)
==12345==    by 0x424242424242: __stack_chk_fail (stack_chk_fail.c:29)
==12345==    by 0x424242424242: func_noncompliant (example.c:19)
==12345==    by 0x424242424242: main (example.c:46)
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 1 allocs, 1 frees, 24 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
