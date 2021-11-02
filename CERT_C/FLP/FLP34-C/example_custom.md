## example_custom
### Test
```
```
### gcc
```
example_custom.c: In function ‘f_noncompliant’:
example_custom.c:8:7: warning: unused variable ‘j’ [-Wunused-variable]
   int j = g;
       ^
example_custom.c:6:7: warning: unused variable ‘i’ [-Wunused-variable]
   int i = f;
       ^
example_custom.c: In function ‘f_compliant’:
example_custom.c:17:7: warning: variable ‘j’ set but not used [-Wunused-but-set-variable]
   int j = 0;
       ^
example_custom.c:13:7: warning: variable ‘i’ set but not used [-Wunused-but-set-variable]
   int i = 0;
       ^
```
### clang
```
example_custom.c:7:13: error: implicit conversion from 'long' to 'float' changes value from -21474836490 to -21474836480 [-Werror,-Wimplicit-const-int-float-conversion]
  float g = -21474836490;
        ~   ^~~~~~~~~~~~
example_custom.c:14:11: error: implicit conversion from 'int' to 'float' changes value from 2147483647 to 2147483648 [-Werror,-Wimplicit-const-int-float-conversion]
  if (f < INT_MAX)
        ~ ^~~~~~~
/home/qba/tis/deps/llvm/12.0.0/build/lib/clang/12.0.0/include/limits.h:46:19: note: expanded from macro 'INT_MAX'
#define INT_MAX   __INT_MAX__
                  ^~~~~~~~~~~
<built-in>:37:21: note: expanded from here
#define __INT_MAX__ 2147483647
                    ^~~~~~~~~~
example_custom.c:16:13: error: implicit conversion from 'long' to 'float' changes value from -21474836490 to -21474836480 [-Werror,-Wimplicit-const-int-float-conversion]
  float g = -21474836490;
        ~   ^~~~~~~~~~~~
3 errors generated.
```
### UBSan
```
example_custom.c:6:11: runtime error: 3.40282e+38 is outside the range of representable values of type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_custom.c:6:11 in 
example_custom.c:8:11: runtime error: -2.14748e+10 is outside the range of representable values of type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior example_custom.c:8:11 in 
```
### Valgrind
```
==12345== Memcheck, a memory error detector
==12345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12345== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12345== Command: ./example_custom.out
==12345== 
==12345== 
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
==12345== 
==12345== For counts of detected and suppressed errors, rerun with: -v
==12345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
