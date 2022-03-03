# Examples
## example_memset_compliant
### Test
```
timeout: failed to run command ‘./example_memset_compliant.out’: No such file or directory
```
### gcc
```
/tmp/cccRwswQ.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_memset_compliant.c:28: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_memset_compliant-5738c6.o: In function `do_stuff':
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
## example_compliant
### Test
```
timeout: failed to run command ‘./example_compliant.out’: No such file or directory
```
### gcc
```
/tmp/ccUECVcr.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_compliant.c:28: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_compliant-347d92.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_compliant.c:28: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
timeout: failed to run command ‘./example_compliant.UBSan-out’: No such file or directory
```
### Valgrind
```
valgrind: ./example_compliant.out: No such file or directory
```
## example_noncompliant
### Test
```
timeout: failed to run command ‘./example_noncompliant.out’: No such file or directory
```
### gcc
```
/tmp/ccyr5vGN.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_noncompliant.c:14: undefined reference to `copy_to_user'
collect2: error: ld returned 1 exit status
```
### clang
```
/tmp/example_noncompliant-33c328.o: In function `do_stuff':
/home/qba/git/tis-compelysis/CERT_C/DCL/DCL39-C/example_noncompliant.c:14: undefined reference to `copy_to_user'
clang-12: error: linker command failed with exit code 1 (use -v to see invocation)
```
### UBSan
```
timeout: failed to run command ‘./example_noncompliant.UBSan-out’: No such file or directory
```
### Valgrind
```
valgrind: ./example_noncompliant.out: No such file or directory
```
