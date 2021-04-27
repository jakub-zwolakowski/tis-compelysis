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
==8068==ERROR: UndefinedBehaviorSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7f775fab1aaa bp 0x7ffc5e442820 sp 0x7ffc5e4427b8 T8068)
==8068==The signal is caused by a WRITE memory access.
==8068==Hint: address points to the zero page.
    #0 0x7f775fab1aaa  /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316
    #1 0x423357 in init_block_noncompliant (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x423357)
    #2 0x423515 in main (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x423515)
    #3 0x7f775f944bf6 in __libc_start_main /build/glibc-S9d2JN/glibc-2.27/csu/../csu/libc-start.c:310
    #4 0x402a49 in _start (/home/qba/git/tis-compelysis/CERT_C/ARR/ARR30-C/Null_Pointer_Arithmetic.UBSan-out+0x402a49)

UndefinedBehaviorSanitizer can not provide additional info.
SUMMARY: UndefinedBehaviorSanitizer: SEGV /build/glibc-S9d2JN/glibc-2.27/string/../sysdeps/x86_64/multiarch/memmove-vec-unaligned-erms.S:316 
==8068==ABORTING
```
### Valgrind
```
==8075== Memcheck, a memory error detector
==8075== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8075== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8075== Command: ./Null_Pointer_Arithmetic.out
==8075== 
==8075== Invalid write of size 2
==8075==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8075==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==8075==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==8075==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==8075== 
==8075== 
==8075== Process terminating with default action of signal 11 (SIGSEGV)
==8075==  Access not within mapped region at address 0x0
==8075==    at 0x4C38753: memmove (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8075==    by 0x10873E: init_block_noncompliant (Null_Pointer_Arithmetic.c:17)
==8075==    by 0x108816: main (Null_Pointer_Arithmetic.c:39)
==8075==  If you believe this happened as a result of a stack
==8075==  overflow in your program's main thread (unlikely but
==8075==  possible), you can try to increase the size of the
==8075==  main thread stack using the --main-stacksize= flag.
==8075==  The main thread stack size used in this run was 8388608.
==8075== 
==8075== HEAP SUMMARY:
==8075==     in use at exit: 0 bytes in 0 blocks
==8075==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8075== 
==8075== All heap blocks were freed -- no leaks are possible
==8075== 
==8075== For counts of detected and suppressed errors, rerun with: -v
==8075== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
