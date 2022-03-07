# Examples
## example
### Test
```
```
### gcc
```
```
### clang
```
```
### UBSan
```
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== Parent PID: 12345
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: bcmp (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: compare_noncompliant (example.c:11)
==12345==    by 0x424242424242: main (example.c:42)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: main (example.c:25)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: bcmp (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: compare_noncompliant (example.c:11)
==12345==    by 0x424242424242: main (example.c:42)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x424242424242: main (example.c:25)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
