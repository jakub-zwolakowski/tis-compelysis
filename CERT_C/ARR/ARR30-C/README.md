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
==10675== Memcheck, a memory error detector
==10675== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10675== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10675== Command: ./Pointer_Past_Flexible_Array_Member.out
==10675== 
==10675== 
==10675== HEAP SUMMARY:
==10675==     in use at exit: 8 bytes in 1 blocks
==10675==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==10675== 
==10675== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==10675==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10675==    by 0x10871C: main (Pointer_Past_Flexible_Array_Member.c:33)
==10675== 
==10675== LEAK SUMMARY:
==10675==    definitely lost: 8 bytes in 1 blocks
==10675==    indirectly lost: 0 bytes in 0 blocks
==10675==      possibly lost: 0 bytes in 0 blocks
==10675==    still reachable: 0 bytes in 0 blocks
==10675==         suppressed: 0 bytes in 0 blocks
==10675== 
==10675== For counts of detected and suppressed errors, rerun with: -v
==10675== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
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
==11217== Memcheck, a memory error detector
==11217== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11217== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11217== Command: ./Forming_Out-of-Bounds_Pointer.out
==11217== 
==11217== 
==11217== HEAP SUMMARY:
==11217==     in use at exit: 0 bytes in 0 blocks
==11217==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11217== 
==11217== All heap blocks were freed -- no leaks are possible
==11217== 
==11217== For counts of detected and suppressed errors, rerun with: -v
==11217== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==11285== Memcheck, a memory error detector
==11285== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11285== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11285== Command: ./Using_Past-the-End_Index.out
==11285== 
==11285== Invalid write of size 4
==11285==    at 0x1086C8: insert_in_table (Using_Past-the-End_Index.c:38)
==11285==    by 0x108710: main (Using_Past-the-End_Index.c:46)
==11285==  Address 0x522f050 is 0 bytes after a block of size 16 alloc'd
==11285==    at 0x4C31A3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11285==    by 0x4C33D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11285==    by 0x108695: insert_in_table (Using_Past-the-End_Index.c:16)
==11285==    by 0x1086E3: main (Using_Past-the-End_Index.c:43)
==11285== 
==11285== 
==11285== HEAP SUMMARY:
==11285==     in use at exit: 16 bytes in 1 blocks
==11285==   total heap usage: 1 allocs, 0 frees, 16 bytes allocated
==11285== 
==11285== LEAK SUMMARY:
==11285==    definitely lost: 0 bytes in 0 blocks
==11285==    indirectly lost: 0 bytes in 0 blocks
==11285==      possibly lost: 0 bytes in 0 blocks
==11285==    still reachable: 16 bytes in 1 blocks
==11285==         suppressed: 0 bytes in 0 blocks
==11285== Reachable blocks (those to which a pointer was found) are not shown.
==11285== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==11285== 
==11285== For counts of detected and suppressed errors, rerun with: -v
==11285== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
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
==11354== Memcheck, a memory error detector
==11354== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11354== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11354== Command: ./Dereferencing_Past-the-End_Pointer.out
==11354== 
*** stack smashing detected ***: <unknown> terminated
==11354== 
==11354== Process terminating with default action of signal 6 (SIGABRT)
==11354==    at 0x4E7CFB7: raise (raise.c:51)
==11354==    by 0x4E7E920: abort (abort.c:79)
==11354==    by 0x4EC7966: __libc_message (libc_fatal.c:181)
==11354==    by 0x4F72B60: __fortify_fail_abort (fortify_fail.c:33)
==11354==    by 0x4F72B21: __stack_chk_fail (stack_chk_fail.c:29)
==11354==    by 0x10872E: GetServerPath (Dereferencing_Past-the-End_Pointer.c:43)
==11354==    by 0x1087AD: _RemoteActivation (Dereferencing_Past-the-End_Pointer.c:47)
==11354==    by 0x108827: main (Dereferencing_Past-the-End_Pointer.c:58)
==11354== 
==11354== HEAP SUMMARY:
==11354==     in use at exit: 0 bytes in 0 blocks
==11354==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11354== 
==11354== All heap blocks were freed -- no leaks are possible
==11354== 
==11354== For counts of detected and suppressed errors, rerun with: -v
==11354== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
==11808== Memcheck, a memory error detector
==11808== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11808== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11808== Command: ./Apparently_Accessible_Out-of-Range_Index.out
==11808== 
==11808== 
==11808== HEAP SUMMARY:
==11808==     in use at exit: 0 bytes in 0 blocks
==11808==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==11808== 
==11808== All heap blocks were freed -- no leaks are possible
==11808== 
==11808== For counts of detected and suppressed errors, rerun with: -v
==11808== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
