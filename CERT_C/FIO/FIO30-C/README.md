# Examples
## example_compliant
### Test
```
password 42 be authenticated.
password %d cannot be authenticated.
```
### gcc
```
```
### clang
```
```
### UBSan
```
password 42 be authenticated.
password %d cannot be authenticated.
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_compliant.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 77 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## example_noncompliant
### Test
```
password 42 be authenticated.
password 42 cannot be authenticated.
```
### gcc
```
example_noncompliant.c: In function ‘incorrect_password’:
example_noncompliant.c:23:3: error: format not a string literal and no format arguments [-Werror=format-security]
   fprintf(stderr, msg);
   ^~~~~~~
cc1: all warnings being treated as errors
```
### clang
```
example_noncompliant.c:23:19: error: format string is not a string literal (potentially insecure) [-Werror,-Wformat-security]
  fprintf(stderr, msg);
                  ^~~
example_noncompliant.c:23:19: note: treat the string as an argument to avoid this
  fprintf(stderr, msg);
                  ^
                  "%s", 
1 error generated.
```
### UBSan
```
password 42 be authenticated.
password 42 cannot be authenticated.
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_noncompliant.out
==12345== Parent PID: 12345
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 77 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
