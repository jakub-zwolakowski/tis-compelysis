## example_noncompliant
### Test
```
/bin/sh: 1: ./example_noncompliant.out: not found
```
### gcc
```
/tmp/cc4LoP4w.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_noncompliant.c:14: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_noncompliant-602077.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_noncompliant.c:14: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
/bin/sh: 1: ./example_noncompliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_noncompliant.out: No such file or directory
```
