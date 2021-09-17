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
==6773== Memcheck, a memory error detector
==6773== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6773== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6773== Command: ./Pointer_Past_Flexible_Array_Member.out
==6773== 
==6773== 
==6773== HEAP SUMMARY:
==6773==     in use at exit: 8 bytes in 1 blocks
==6773==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==6773== 
==6773== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==6773==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==6773==    by 0x10871C: main (Pointer_Past_Flexible_Array_Member.c:33)
==6773== 
==6773== LEAK SUMMARY:
==6773==    definitely lost: 8 bytes in 1 blocks
==6773==    indirectly lost: 0 bytes in 0 blocks
==6773==      possibly lost: 0 bytes in 0 blocks
==6773==    still reachable: 0 bytes in 0 blocks
==6773==         suppressed: 0 bytes in 0 blocks
==6773== 
==6773== For counts of detected and suppressed errors, rerun with: -v
==6773== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
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
==7366== Memcheck, a memory error detector
==7366== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7366== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7366== Command: ./Forming_Out-of-Bounds_Pointer.out
==7366== 
==7366== 
==7366== HEAP SUMMARY:
==7366==     in use at exit: 0 bytes in 0 blocks
==7366==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7366== 
==7366== All heap blocks were freed -- no leaks are possible
==7366== 
==7366== For counts of detected and suppressed errors, rerun with: -v
==7366== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==7435== Memcheck, a memory error detector
==7435== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7435== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7435== Command: ./Using_Past-the-End_Index.out
==7435== 
==7435== Invalid write of size 4
==7435==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==7435==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==7435==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==7435==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7435==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7435==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==7435==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==7435== 
==7435== 
==7435== HEAP SUMMARY:
==7435==     in use at exit: 16 bytes in 1 blocks
==7435==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==7435== 
==7435== LEAK SUMMARY:
==7435==    definitely lost: 0 bytes in 0 blocks
==7435==    indirectly lost: 0 bytes in 0 blocks
==7435==      possibly lost: 0 bytes in 0 blocks
==7435==    still reachable: 16 bytes in 1 blocks
==7435==         suppressed: 0 bytes in 0 blocks
==7435== Reachable blocks (those to which a pointer was found) are not shown.
==7435== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==7435== 
==7435== For counts of detected and suppressed errors, rerun with: -v
==7435== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
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
==7504== Memcheck, a memory error detector
==7504== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7504== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7504== Command: ./Dereferencing_Past-the-End_Pointer.out
==7504== 
*** stack smashing detected ***: <unknown> terminated
==7504== 
==7504== Process terminating with default action of signal 6 (SIGABRT)
==7504==    at 0x4E7CFB7: raise (raise.c:51)
==7504==    by 0x4E7E920: abort (abort.c:79)
==7504==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==7504==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==7504==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==7504==    by 0x10872E: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==7504==    by 0x1087AD: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==7504==    by 0x108827: main (Dereferencing_Past-the-End_Pointer.c:58)
==7504== 
==7504== HEAP SUMMARY:
==7504==     in use at exit: 0 bytes in 0 blocks
==7504==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7504== 
==7504== All heap blocks were freed -- no leaks are possible
==7504== 
==7504== For counts of detected and suppressed errors, rerun with: -v
==7504== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==7961== Memcheck, a memory error detector
==7961== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7961== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7961== Command: ./Apparently_Accessible_Out-of-Range_Index.out
==7961== 
==7961== 
==7961== HEAP SUMMARY:
==7961==     in use at exit: 0 bytes in 0 blocks
==7961==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7961== 
==7961== All heap blocks were freed -- no leaks are possible
==7961== 
==7961== For counts of detected and suppressed errors, rerun with: -v
==7961== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
