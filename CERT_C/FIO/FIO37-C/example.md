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
example.c:29:3: runtime error: addition of unsigned offset to 0x424242424242 overflowed to 0x424242424242
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example.c:29:3 in 
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example.out
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 8 allocs, 8 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
