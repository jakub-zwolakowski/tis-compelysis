## example_noncompliant
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
example_noncompliant.c: In function ‘func’:
example_noncompliant.c:10:28: warning: variable ‘flex_struct’ set but not used [-Wunused-but-set-variable]
   struct flex_array_struct flex_struct;
                            ^~~~~~~~~~~
```
### clang
```
```
### UBSan
```
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==23566==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x000000000000 bp 0x000000000000 sp 0x7ffe10a5f890 T23566)
==23566==Hint: pc points to the zero page.
==23566==The signal is caused by a READ memory access.
==23566==Hint: address points to the zero page.
    #0 0x0  (<unknown module>)
    #1 0x41d33a in __sanitizer::HandleDeadlySignal(void*, void*, unsigned int, void (*)(__sanitizer::SignalContext const&, void const*, __sanitizer::BufferedStackTrace*), void const*) /home/qba/tis/deps/llvm/12.0.0/src/projects/compiler-rt/lib/sanitizer_common/sanitizer_symbolizer_report.cpp:246:3
    #2 0x7fd8f73c497f  (/lib/x86_64-linux-gnu/libpthread.so.0+0x1297f)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV (<unknown module>) 
==23566==ABORTING
```
### Valgrind
```
==23573== Memcheck, a memory error detector
==23573== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23573== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23573== Command: ./example_noncompliant.out
==23573== 
*** stack smashing detected ***: <unknown> terminated
==23573== 
==23573== Process terminating with default action of signal 6 (SIGABRT)
==23573==    at 0x4E7CFB7: raise (raise.c:51)
==23573==    by 0x4E7E920: abort (abort.c:79)
==23573==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==23573==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==23573==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==23573==    by 0x1086CA: func (example_noncompliant.c:19)
==23573==    by 0x1086D5: main (example_noncompliant.c:21)
==23573== 
==23573== HEAP SUMMARY:
==23573==     in use at exit: 0 bytes in 0 blocks
==23573==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==23573== 
==23573== All heap blocks were freed -- no leaks are possible
==23573== 
==23573== For counts of detected and suppressed errors, rerun with: -v
==23573== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
