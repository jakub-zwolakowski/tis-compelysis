## Integer
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
==12345== Command: ./Integer.out
==12345== Parent PID: 12345
==12345== 
==12345== Invalid write of size 8
==12345==    at 0x424242424242: f_noncompliant (Integer.c:17)
==12345==    by 0x424242424242: main (Integer.c:42)
==12345==  Address 0x424242424242 is 0 bytes after a block of size 168 alloc'd
==12345==    at 0x424242424242: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: f_noncompliant (Integer.c:10)
==12345==    by 0x424242424242: main (Integer.c:42)
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 123 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 21 errors from 1 contexts (suppressed: 0 from 0)
```
