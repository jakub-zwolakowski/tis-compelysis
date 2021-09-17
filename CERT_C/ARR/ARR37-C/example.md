## example
### Test
```
/bin/sh: 1: ./example.out: not found
```
### gcc
```
example.c:48:5: error: redefinition of ‘main_noncompliant’
 int main_noncompliant(void) {
     ^~~~~~~~~~~~~~~~~
example.c:20:5: note: previous definition of ‘main_noncompliant’ was here
 int main_noncompliant(void) {
     ^~~~~~~~~~~~~~~~~
```
### clang
```
example.c:48:5: error: redefinition of 'main_noncompliant'
int main_noncompliant(void) {
    ^
example.c:20:5: note: previous definition is here
int main_noncompliant(void) {
    ^
1 error generated.
```
### UBSan
```
/bin/sh: 1: ./example.UBSan-out: not found
```
### Valgrind
```
valgrind: ./example.out: No such file or directory
```
