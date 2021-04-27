## Storage_Durations
### Test
```
At the beginning I was here
Ðú»ü
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
==11351== Memcheck, a memory error detector
==11351== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11351== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11351== Command: ./Storage_Durations.out
==11351== 
At the beginning I was here
Pøÿþ
==11351== 
==11351== HEAP SUMMARY:
==11351==     in use at exit: 0 bytes in 0 blocks
==11351==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==11351== 
==11351== All heap blocks were freed -- no leaks are possible
==11351== 
==11351== For counts of detected and suppressed errors, rerun with: -v
==11351== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
