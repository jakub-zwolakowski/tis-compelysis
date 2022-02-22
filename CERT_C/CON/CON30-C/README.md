# Examples
## example_compliant
### Test
```
/bin/sh: 1: ./example_compliant.out: not found
```
### gcc
```
example_compliant.c:6:10: fatal error: thread.h: No such file or directory
 #include <thread.h>
          ^~~~~~~~~~
compilation terminated.
```
### clang
```
example_compliant.c:6:10: fatal error: 'thread.h' file not found
#include <thread.h>
         ^~~~~~~~~~
1 error generated.
```
### UBSan
```
/bin/sh: 1: ./example_compliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_compliant.out: No such file or directory
```
## example_noncompliant
### Test
```
/bin/sh: 1: ./example_noncompliant.out: not found
```
### gcc
```
example_noncompliant.c:7:10: fatal error: thread.h: No such file or directory
 #include <thread.h>
          ^~~~~~~~~~
compilation terminated.
```
### clang
```
In file included from example_noncompliant.c:1:
./../c11threads.h:266:27: error: no newline at end of file [-Werror,-Wnewline-eof]
#endif  /* C11THREADS_H_ */
                           ^
example_noncompliant.c:7:10: fatal error: 'thread.h' file not found
#include <thread.h>
         ^~~~~~~~~~
2 errors generated.
```
### UBSan
```
/bin/sh: 1: ./example_noncompliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_noncompliant.out: No such file or directory
```
