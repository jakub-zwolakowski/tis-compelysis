## example_noncompliant
### Test
```
sh: 1: any_cmd: not found
attacker
```
### gcc
```
```
### clang
```
```
### UBSan
```
sh: 1: any_cmd: not found
attacker
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: /bin/sh -c any_cmd\ 'happy';\ echo\ 'attacker'
==12345== Parent ==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 still reachable: 123,456 bytes in 87 blocks
==12345==         suppressed: 0 bytes in 0 blocks
==12345== Reachable blocks (those to which a pointer was found) are not shown.
==12345== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
