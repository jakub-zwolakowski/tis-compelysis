## example_memset_compliant
### Test
```
timeout: failed to run command ‘./example_memset_compliant.out’: No such file or directory
```
### gcc
```
/tmp/XXX.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_compliant.c:28: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/XXX.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_compliant.c:28: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
timeout: failed to run command ‘./example_memset_compliant.UBSan-out’: No such file or directory
```
### Valgrind
```
valgrind: ./example_memset_compliant.out: No such file or directory
```
