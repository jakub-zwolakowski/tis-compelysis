## example1
### Test
```
free(): double free detected in tcache 2
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
free(): double free detected in tcache 2
timeout: the monitored command dumped core
Aborted
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example1.out
==12345== 
==12345== Invalid read of size 8
==12345==    at 0x424242424242: free_list_noncompliant (example1.c:9)
==12345==    by 0x424242424242: main (example1.c:39)
==12345==  Address 0x424242424242 is 8 bytes inside a block of size 16 free'd
==12345==    at 0x424242424242: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: free_list_noncompliant (example1.c:10)
==12345==    by 0x424242424242: main (example1.c:39)
==12345==  Block was alloc'd at
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: make_list (example1.c:27)
==12345==    by 0x424242424242: main (example1.c:38)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 64 bytes in 4 blocks
==12345==   total heap usage: 6 allocs, 2 frees, 96 bytes allocated
==12345== 
==12345== 32 bytes in 2 blocks are definitely lost in loss record 1 of 2
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: make_list (example1.c:27)
==12345==    by 0x424242424242: main (example1.c:36)
==12345== 
==12345== 32 bytes in 2 blocks are definitely lost in loss record 2 of 2
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: make_list (example1.c:27)
==12345==    by 0x424242424242: main (example1.c:38)
==12345== 
==12345== LEAK SUMMARY:
==12345==    definitely lost: 64 bytes in 4 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```
