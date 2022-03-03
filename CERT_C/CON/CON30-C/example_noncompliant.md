## example_noncompliant
### Test
```
Data = 10
Data = 10
Data = 10
```
### gcc
```
```
### clang
```
example_noncompliant.c:99:26: error: no newline at end of file [-Werror,-Wnewline-eof]
// COMPILE: gcc -lpthread
                         ^
1 error generated.
```
### UBSan
```
Data = 10
Data = 10
Data = 10
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
Data = 10
Data = 10
Data = 10
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 24 bytes in 3 blocks
==12345==   total heap usage: 7 allocs, 4 frees, 123,456 bytes allocated
==12345== 
==12345== 24 bytes in 3 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: get_data (example_noncompliant.c:19)
==12345==    by 0x424242424242: add_data (example_noncompliant.c:29)
==12345==    by 0x424242424242: function (example_noncompliant.c:54)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 24 bytes in 3 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
