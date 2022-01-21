# Examples
## example_memset_compliant
### Test
```
/bin/sh: 1: ./example_memset_compliant.out: not found
```
### gcc
```
/tmp/cc6Q6g0N.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_compliant.c:28: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_memset_compliant-72f818.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_compliant.c:28: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
/bin/sh: 1: ./example_memset_compliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_memset_compliant.out: No such file or directory
```
## example_memset_noncompliant
### Test
```
/bin/sh: 1: ./example_memset_noncompliant.out: not found
```
### gcc
```
/tmp/cco56Bi5.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_noncompliant.c:22: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_memset_noncompliant-d9c592.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_noncompliant.c:22: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
/bin/sh: 1: ./example_memset_noncompliant.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example_memset_noncompliant.out: No such file or directory
```
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
