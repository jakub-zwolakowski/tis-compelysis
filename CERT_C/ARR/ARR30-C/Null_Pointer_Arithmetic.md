## Null_Pointer_Arithmetic
### Test
```
Segmentation fault (core dumped)
```
### gcc
```
Null_Pointer_Arithmetic.c:36:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
Null_Pointer_Arithmetic.c: In function ‘main’:
Null_Pointer_Arithmetic.c:39:9: warning: unused variable ‘block2’ [-Wunused-variable]
   char *block2 = init_block_noncompliant(7, 0, data, sizeof (data));
         ^~~~~~
Null_Pointer_Arithmetic.c:38:9: warning: unused variable ‘block1’ [-Wunused-variable]
   char *block1 = init_block_compliant(7, 0, data, sizeof (data));
         ^~~~~~
```
### clang
```
Null_Pointer_Arithmetic.c:36:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Null_Pointer_Arithmetic.c:36:1: note: change return type to 'int'
void main(void) {
^~~~
int
Null_Pointer_Arithmetic.c:38:9: warning: unused variable 'block1' [-Wunused-variable]
  char *block1 = init_block_compliant(7, 0, data, sizeof (data));
        ^
Null_Pointer_Arithmetic.c:39:9: warning: unused variable 'block2' [-Wunused-variable]
  char *block2 = init_block_noncompliant(7, 0, data, sizeof (data));
        ^
3 warnings generated.
```
### UBSan
```
Null_Pointer_Arithmetic.c:17:17: runtime error: applying zero offset to null pointer
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Null_Pointer_Arithmetic.c:17:17 in 
Null_Pointer_Arithmetic.c:17:10: runtime error: null pointer passed as argument 1, which is declared to never be null
/usr/include/string.h:43:28: note: nonnull attribute specified here
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Null_Pointer_Arithmetic.c:17:10 in 
UndefinedBehaviorSanitizer:DEADLYSIGNAL
==10749==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7f54c902caaa bp 0x7ffcda8de0a0 sp 0x7ffcda8de038 T10749)
==10749==The signal is caused by a WRITE memory access.
==10749==Hint: address points to the zero page.
    #0 0x7f54c902caaa  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316
    #1 0x423357 in init_block_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x423357)
    #2 0x423515 in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x423515)
    #3 0x7f54c8ebfbf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a49 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x402a49)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316 
==10749==ABORTING
```
### Valgrind
```
==10756== Memcheck, a memory error detector
==10756== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10756== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10756== Command: ./Null_Pointer_Arithmetic.out
==10756== 
==10756== Invalid write of size 2
==10756==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10756==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==10756==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==10756==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==10756== 
==10756== 
==10756== Process terminating with default action of signal 11 (SIGSEGV)
==10756==  Access not within mapped region at address 0x0
==10756==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10756==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==10756==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==10756==  If you believe this happened as a result of a stack
==10756==  overflow in your program's main thread (unlikely but
==10756==  possible), you can try to increase the size of the
==10756==  main thread stack using the --main-stacksize= flag.
==10756==  The main thread stack size used in this run was 8388608.
==10756== 
==10756== HEAP SUMMARY:
==10756==     in use at exit: 0 bytes in 0 blocks
==10756==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==10756== 
==10756== All heap blocks were freed -- no leaks are possible
==10756== 
==10756== For counts of detected and suppressed errors, rerun with: -v
==10756== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
