# Examples
## example
### Test
```
munmap_chunk(): invalid pointer
Aborted (core dumped)
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
==12345==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x424242424242 (pc 0x424242424242 bp 0x424242424242ff90 sp 0x424242424242 T4242)
==12345==The signal is caused by a READ memory access.
==12345==Hint: address points to the zero page.
    #0 0x424242424242 in free /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133
    #1 0x424242424242 in f_noncompliant (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x424242424242)
    #2 0x424242424242 in main (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x424242424242)
    #3 0x424242424242 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x424242424242 in _start (/home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.UBSan-out+0x424242424242)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/malloc/malloc.c:3133 in free
==12345==ABORTING
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== Invalid free() / delete / delete[] / realloc()
==12345==    at 0x424242424242: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x424242424242: f_noncompliant (example.c:27)
==12345==    by 0x424242424242: main (example.c:62)
==12345==  Address 0x424242424242 is in a r-x mapped file /home/qba/git/tis-compelysis/CERT_C/MEM/MEM34-C/example.out segment
==12345== 
usage: $>a.exe [string]
usage: $>a.exe [string]
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 3 allocs, 4 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
