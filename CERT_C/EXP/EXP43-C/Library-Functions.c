#include <string.h>
  
void func_noncompliant(void) {
  char c_str[]= "test string";
  char *ptr1 = c_str;
  char *ptr2;
 
  ptr2 = ptr1 + 3;
  /* Undefined behavior because of overlapping objects */
  memcpy(ptr2, ptr1, 6); 
  /* ... */
}
 
void func_compliant(void) {
  char c_str[]= "test string";
  char *ptr1 = c_str;
  char *ptr2;
 
  ptr2 = ptr1 + 3;
  memmove(ptr2, ptr1, 6);  /* Replace call to memcpy() */
  /* ... */
}

int main(void) {
  func_compliant();
  func_noncompliant();
  return 0;
}
