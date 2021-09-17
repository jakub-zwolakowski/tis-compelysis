## example
### Test
```
17
4
17
17
```
### gcc
```
example.c:35:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
example.c: In function ‘f_noncompliant’:
example.c:7:9: warning: statement will never be executed [-Wswitch-unreachable]
     int i = 4;
         ^
```
### clang
```
example.c:12:3: warning: variable 'i' is used uninitialized whenever switch default is taken [-Wsometimes-uninitialized]
  default:
  ^~~~~~~
example.c:13:20: note: uninitialized use occurs here
    printf("%d\n", i);
                   ^
example.c:7:5: note: variable 'i' is declared here
    int i = 4;
    ^
example.c:35:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
example.c:35:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
17
4
17
17
```
### Valgrind
```
==24647== Memcheck, a memory error detector
==24647== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24647== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24647== Command: ./example.out
==24647== 
==24647== Conditional jump or move depends on uninitialised value(s)
==24647==    at 0x4E9A9DA: vfprintf (vfprintf.c:1642)
==24647==    by 0x4EA3015: printf (printf.c:33)
==24647==    by 0x108682: f_noncompliant (example.c:13)
==24647==    by 0x1086F8: main (example.c:39)
==24647== 
==24647== Use of uninitialised value of size 8
==24647==    at 0x4E9696B: _itoa_word (_itoa.c:179)
==24647==    by 0x4E9A00D: vfprintf (vfprintf.c:1642)
==24647==    by 0x4EA3015: printf (printf.c:33)
==24647==    by 0x108682: f_noncompliant (example.c:13)
==24647==    by 0x1086F8: main (example.c:39)
==24647== 
==24647== Conditional jump or move depends on uninitialised value(s)
==24647==    at 0x4E96975: _itoa_word (_itoa.c:179)
==24647==    by 0x4E9A00D: vfprintf (vfprintf.c:1642)
==24647==    by 0x4EA3015: printf (printf.c:33)
==24647==    by 0x108682: f_noncompliant (example.c:13)
==24647==    by 0x1086F8: main (example.c:39)
==24647== 
==24647== Conditional jump or move depends on uninitialised value(s)
==24647==    at 0x4E9A114: vfprintf (vfprintf.c:1642)
==24647==    by 0x4EA3015: printf (printf.c:33)
==24647==    by 0x108682: f_noncompliant (example.c:13)
==24647==    by 0x1086F8: main (example.c:39)
==24647== 
==24647== Conditional jump or move depends on uninitialised value(s)
==24647==    at 0x4E9AC4C: vfprintf (vfprintf.c:1642)
==24647==    by 0x4EA3015: printf (printf.c:33)
==24647==    by 0x108682: f_noncompliant (example.c:13)
==24647==    by 0x1086F8: main (example.c:39)
==24647== 
17
4
17
17
==24647== 
==24647== HEAP SUMMARY:
==24647==     in use at exit: 0 bytes in 0 blocks
==24647==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==24647== 
==24647== All heap blocks were freed -- no leaks are possible
==24647== 
==24647== For counts of detected and suppressed errors, rerun with: -v
==24647== Use --track-origins=yes to see where uninitialised values come from
==24647== ERROR SUMMARY: 7 errors from 5 contexts (suppressed: 0 from 0)
```
