## Storage_Durations
### Test
```
At the beginning I was here
`
```
### gcc
```
Storage_Durations.c: In function ‘this_is_OK’:
Storage_Durations.c:12:15: warning: unused variable ‘p’ [-Wunused-variable]
   const char *p = c_str;
               ^
Storage_Durations.c: At top level:
Storage_Durations.c:20:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Storage_Durations.c:12:15: warning: unused variable 'p' [-Wunused-variable]
  const char *p = c_str;
              ^
Storage_Durations.c:20:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Storage_Durations.c:20:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
At the beginning I was here
This will change
```
### Valgrind
```
==3462== Memcheck, a memory error detector
==3462== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3462== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3462== Command: ./Storage_Durations.out
==3462== 
At the beginning I was here
@���
==3462== 
==3462== HEAP SUMMARY:
==3462==     in use at exit: 0 bytes in 0 blocks
==3462==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==3462== 
==3462== All heap blocks were freed -- no leaks are possible
==3462== 
==3462== For counts of detected and suppressed errors, rerun with: -v
==3462== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
