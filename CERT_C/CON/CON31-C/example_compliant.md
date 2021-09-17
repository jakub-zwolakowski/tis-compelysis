## example_compliant
### Test
```
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
```
### gcc
```
```
### clang
```
```
### UBSan
```
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
```
### Valgrind
```
==30730== Memcheck, a memory error detector
==30730== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==30730== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==30730== Command: ./example_compliant.out
==30730== 
compliant beginning
compliant 1
compliant 2
compliant 3
compliant 4
compliant 5
compliant end
==30730== 
==30730== HEAP SUMMARY:
==30730==     in use at exit: 0 bytes in 0 blocks
==30730==   total heap usage: 6 allocs, 6 frees, 5,456 bytes allocated
==30730== 
==30730== All heap blocks were freed -- no leaks are possible
==30730== 
==30730== For counts of detected and suppressed errors, rerun with: -v
==30730== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
