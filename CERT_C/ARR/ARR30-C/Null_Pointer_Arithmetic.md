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
==6884==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7fabd8e00aaa bp 0x7ffd1ebbe020 sp 0x7ffd1ebbdfb8 T6884)
==6884==The signal is caused by a WRITE memory access.
==6884==Hint: address points to the zero page.
    #0 0x7fabd8e00aaa  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316
    #1 0x424266 in init_block_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x424266)
    #2 0x424413 in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x424413)
    #3 0x7fabd8c93bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a39 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x402a39)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316 
==6884==ABORTING
```
### Valgrind
```
==6895== Memcheck, a memory error detector
==6895== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6895== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6895== Command: ./Null_Pointer_Arithmetic.out
==6895== 
==6895== Invalid write of size 2
==6895==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==6895==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==6895==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==6895==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==6895== 
==6895== 
==6895== Process terminating with default action of signal 11 (SIGSEGV)
==6895==  Access not within mapped region at address 0x0
==6895==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==6895==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==6895==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==6895==  If you believe this happened as a result of a stack
==6895==  overflow in your program's main thread (unlikely but
==6895==  possible), you can try to increase the size of the
==6895==  main thread stack using the --main-stacksize= flag.
==6895==  The main thread stack size used in this run was 8388608.
==6895== 
==6895== HEAP SUMMARY:
==6895==     in use at exit: 0 bytes in 0 blocks
==6895==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6895== 
==6895== All heap blocks were freed -- no leaks are possible
==6895== 
==6895== For counts of detected and suppressed errors, rerun with: -v
==6895== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
