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
example.c:29:3: runtime error: index 18446744073709551615 out of bounds for type 'char [1024]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example.c:29:3 in 
example.c:29:3: runtime error: addition of unsigned offset to 0x7fff9015cf40 overflowed to 0x7fff9015cf3f
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example.c:29:3 in 
```
### Valgrind
```
==27727== Memcheck, a memory error detector
==27727== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27727== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27727== Command: ./example.out
==27727== 
==27727== 
==27727== HEAP SUMMARY:
==27727==     in use at exit: 0 bytes in 0 blocks
==27727==   total heap usage: 8 allocs, 8 frees, 18,592 bytes allocated
==27727== 
==27727== All heap blocks were freed -- no leaks are possible
==27727== 
==27727== For counts of detected and suppressed errors, rerun with: -v
==27727== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
