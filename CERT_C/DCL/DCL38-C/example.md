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
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 123 bytes in 2 blocks
==12345==   total heap usage: 2 allocs, 0 frees, 123 bytes allocated
==12345== 
==12345== 123 bytes in 1 blocks are definitely lost in loss record 1 of 2
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: f_compliant (example.c:37)
==12345==    by 0x424242424242: main (example.c:57)
==12345== 
==12345== 123 bytes in 1 blocks are definitely lost in loss record 2 of 2
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: f_noncompliant (example.c:10)
==12345==    by 0x424242424242: main (example.c:58)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 123 bytes in 2 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
