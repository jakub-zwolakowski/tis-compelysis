# Examples
## Pointer_Past_Flexible_Array_Member
### Test
```
```
### gcc
```
Pointer_Past_Flexible_Array_Member.c:32:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Pointer_Past_Flexible_Array_Member.c:32:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Pointer_Past_Flexible_Array_Member.c:32:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==7988== Memcheck, a memory error detector
==7988== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7988== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7988== Command: ./Pointer_Past_Flexible_Array_Member.out
==7988== 
==7988== 
==7988== HEAP SUMMARY:
==7988==     in use at exit: 8 bytes in 1 blocks
==7988==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==7988== 
==7988== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==7988==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7988==    by 0x10871C: main (Pointer_Past_Flexible_Array_Member.c:33)
==7988== 
==7988== LEAK SUMMARY:
==7988==    definitely lost: 8 bytes in 1 blocks
==7988==    indirectly lost: 0 bytes in 0 blocks
==7988==      possibly lost: 0 bytes in 0 blocks
==7988==    still reachable: 0 bytes in 0 blocks
==7988==         suppressed: 0 bytes in 0 blocks
==7988== 
==7988== For counts of detected and suppressed errors, rerun with: -v
==7988== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
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
## Forming_Out-of-Bounds_Pointer
### Test
```
```
### gcc
```
Forming_Out-of-Bounds_Pointer.c:21:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Forming_Out-of-Bounds_Pointer.c:21:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Forming_Out-of-Bounds_Pointer.c:21:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Forming_Out-of-Bounds_Pointer.c:9:18: runtime error: index -1 out of bounds for type 'int [100]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Forming_Out-of-Bounds_Pointer.c:9:18 in 
```
### Valgrind
```
==8530== Memcheck, a memory error detector
==8530== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8530== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8530== Command: ./Forming_Out-of-Bounds_Pointer.out
==8530== 
==8530== 
==8530== HEAP SUMMARY:
==8530==     in use at exit: 0 bytes in 0 blocks
==8530==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8530== 
==8530== All heap blocks were freed -- no leaks are possible
==8530== 
==8530== For counts of detected and suppressed errors, rerun with: -v
==8530== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## Using_Past-the-End_Index
### Test
```
```
### gcc
```
Using_Past-the-End_Index.c:42:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Using_Past-the-End_Index.c:42:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Using_Past-the-End_Index.c:42:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==8602== Memcheck, a memory error detector
==8602== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8602== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8602== Command: ./Using_Past-the-End_Index.out
==8602== 
==8602== Invalid write of size 4
==8602==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==8602==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==8602==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==8602==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8602==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8602==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==8602==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==8602== 
==8602== 
==8602== HEAP SUMMARY:
==8602==     in use at exit: 16 bytes in 1 blocks
==8602==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==8602== 
==8602== LEAK SUMMARY:
==8602==    definitely lost: 0 bytes in 0 blocks
==8602==    indirectly lost: 0 bytes in 0 blocks
==8602==      possibly lost: 0 bytes in 0 blocks
==8602==    still reachable: 16 bytes in 1 blocks
==8602==         suppressed: 0 bytes in 0 blocks
==8602== Reachable blocks (those to which a pointer was found) are not shown.
==8602== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==8602== 
==8602== For counts of detected and suppressed errors, rerun with: -v
==8602== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
## Dereferencing_Past-the-End_Pointer
### Test
```
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)
```
### gcc
```
Dereferencing_Past-the-End_Pointer.c:52:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Dereferencing_Past-the-End_Pointer.c:52:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Dereferencing_Past-the-End_Pointer.c:52:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
```
### Valgrind
```
==8672== Memcheck, a memory error detector
==8672== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8672== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8672== Command: ./Dereferencing_Past-the-End_Pointer.out
==8672== 
*** stack smashing detected ***: <unknown> terminated
==8672== 
==8672== Process terminating with default action of signal 6 (SIGABRT)
==8672==    at 0x4E7CFB7: raise (raise.c:51)
==8672==    by 0x4E7E920: abort (abort.c:79)
==8672==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==8672==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==8672==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==8672==    by 0x10872E: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==8672==    by 0x1087AD: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==8672==    by 0x108827: main (Dereferencing_Past-the-End_Pointer.c:58)
==8672== 
==8672== HEAP SUMMARY:
==8672==     in use at exit: 0 bytes in 0 blocks
==8672==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==8672== 
==8672== All heap blocks were freed -- no leaks are possible
==8672== 
==8672== For counts of detected and suppressed errors, rerun with: -v
==8672== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Aborted (core dumped)
```
## Apparently_Accessible_Out-of-Range_Index
### Test
```
```
### gcc
```
Apparently_Accessible_Out-of-Range_Index.c:22:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Apparently_Accessible_Out-of-Range_Index.c:22:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Apparently_Accessible_Out-of-Range_Index.c:22:1: note: change return type to 'int'
void main(void) {
^~~~
int
1 warning generated.
```
### UBSan
```
Apparently_Accessible_Out-of-Range_Index.c:9:7: runtime error: index 5 out of bounds for type 'int [5]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior Apparently_Accessible_Out-of-Range_Index.c:9:7 in 
```
### Valgrind
```
==9146== Memcheck, a memory error detector
==9146== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9146== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9146== Command: ./Apparently_Accessible_Out-of-Range_Index.out
==9146== 
==9146== 
==9146== HEAP SUMMARY:
==9146==     in use at exit: 0 bytes in 0 blocks
==9146==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9146== 
==9146== All heap blocks were freed -- no leaks are possible
==9146== 
==9146== For counts of detected and suppressed errors, rerun with: -v
==9146== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
