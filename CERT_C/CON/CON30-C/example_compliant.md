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
