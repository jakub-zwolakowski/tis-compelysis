## Storage_Durations
### Test
```
At the beginning I was here
0³Ÿ¹ü
```
### gcc
```
Storage_Durations.c: In function â€˜this_is_OKâ€™:
Storage_Durations.c:12:15: warning: unused variable â€˜pâ€™ [-Wunused-variable]
   const char *p = c_str;
               ^
Storage_Durations.c: At top level:
Storage_Durations.c:20:6: warning: return type of â€˜mainâ€™ is not â€˜intâ€™ [-Wmain]
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
==24784== Memcheck, a memory error detector
==24784== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24784== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24784== Command: ./Storage_Durations.out
==24784== 
At the beginning I was here
Pøÿþ
==24784== 
==24784== HEAP SUMMARY:
==24784==     in use at exit: 0 bytes in 0 blocks
==24784==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==24784== 
==24784== All heap blocks were freed -- no leaks are possible
==24784== 
==24784== For counts of detected and suppressed errors, rerun with: -v
==24784== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
