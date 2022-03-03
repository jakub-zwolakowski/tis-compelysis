# Examples
## example_compliant
### Test
```
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
```
### gcc
```
```
### clang
```
```
### UBSan
```
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== 
==12345== Thread 42:
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: reorganize_data_structure (example_compliant.c:28)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: reorganize_data_structure (example_compliant.c:31)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== Thread 42:
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:48)
==12345== 
==12345== Use of uninitialised value of size 8
==12345==    at 0x424242424242: _itoa_word (_itoa.c:179)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:48)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: _itoa_word (_itoa.c:179)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:48)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:48)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_compliant.c:48)
==12345== 
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 6 allocs, 6 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== Use --track-origins=yes to see where uninitialised values come from
==12345== ERROR SUMMARY: 35 errors from 7 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
```
### gcc
```
```
### clang
```
```
### UBSan
```
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== 
==12345== Thread 42:
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: reorganize_data_structure (example_noncompliant.c:28)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: reorganize_data_structure (example_noncompliant.c:30)
==12345==    by 0x424242424242: start_thread (pthread_create.c:463)
==12345==    by 0x424242424242: clone (clone.S:95)
==12345== 
==12345== Thread 42:
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_noncompliant.c:47)
==12345== 
==12345== Use of uninitialised value of size 8
==12345==    at 0x424242424242: _itoa_word (_itoa.c:179)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_noncompliant.c:47)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: _itoa_word (_itoa.c:179)
==12345==    by 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_noncompliant.c:47)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_noncompliant.c:47)
==12345== 
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x424242424242: vfprintf (vfprintf.c:1642)
==12345==    by 0x424242424242: printf (printf.c:33)
==12345==    by 0x424242424242: main (example_noncompliant.c:47)
==12345== 
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
Thread X something something...
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 6 allocs, 6 frees, 123,456 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== Use --track-origins=yes to see where uninitialised values come from
==12345== ERROR SUMMARY: 35 errors from 7 contexts (suppressed: 0 from 0)
```
