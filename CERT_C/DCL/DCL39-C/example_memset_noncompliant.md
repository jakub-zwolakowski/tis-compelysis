## example_memset_noncompliant
### Test
```
timeout: failed to run command ‘./example_memset_noncompliant.out’: No such file or directory
```
### gcc
```
/tmp/ccmpXd89.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_noncompliant.c:22: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_memset_noncompliant-34ceaf.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_noncompliant.c:22: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
timeout: failed to run command ‘./example_memset_noncompliant.UBSan-out’: No such file or directory
```
### Valgrind
```
valgrind: ./example_memset_noncompliant.out: No such file or directory
```
