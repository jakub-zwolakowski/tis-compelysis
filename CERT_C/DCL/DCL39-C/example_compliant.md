## example_compliant
### Test
```
/bin/sh: 1: ./example_compliant.out: not found
```
### gcc
```
/tmp/ccOZ0jAh.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_compliant.c:28: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_compliant-01e718.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_compliant.c:28: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
/bin/sh: 1: ./example_compliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_compliant.out: No such file or directory
```
