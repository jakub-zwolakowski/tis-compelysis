## Unintentional_Assignment
### Test
```
```
### gcc
```
Unintentional_Assignment.c: In function ‘f_noncompliant’:
Unintentional_Assignment.c:2:7: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
   if (a = b) {
       ^
Unintentional_Assignment.c: At top level:
Unintentional_Assignment.c:15:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
 void main(void) {
      ^~~~
```
### clang
```
Unintentional_Assignment.c:2:9: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
  if (a = b) {
      ~~^~~
Unintentional_Assignment.c:2:9: note: place parentheses around the assignment to silence this warning
  if (a = b) {
        ^
      (    )
Unintentional_Assignment.c:2:9: note: use '==' to turn this assignment into an equality comparison
  if (a = b) {
        ^
        ==
Unintentional_Assignment.c:15:1: warning: return type of 'main' is not 'int' [-Wmain-return-type]
void main(void) {
^
Unintentional_Assignment.c:15:1: note: change return type to 'int'
void main(void) {
^~~~
int
2 warnings generated.
```
### UBSan
```
```
### Valgrind
```
==9198== Memcheck, a memory error detector
==9198== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9198== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==9198== Command: ./Unintentional_Assignment.out
==9198== 
==9198== 
==9198== HEAP SUMMARY:
==9198==     in use at exit: 0 bytes in 0 blocks
==9198==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9198== 
==9198== All heap blocks were freed -- no leaks are possible
==9198== 
==9198== For counts of detected and suppressed errors, rerun with: -v
==9198== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
