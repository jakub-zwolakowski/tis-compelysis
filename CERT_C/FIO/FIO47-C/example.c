#include <stdio.h>

void func_noncompliant(void) {
  const char *error_msg = "Resource not available to user.";
  int error_type = 3;
  /* ... */
  printf("Error (type %s): %d\n", error_type, error_msg);
  /* ... */
}

void func_compliant(void) {
  const char *error_msg = "Resource not available to user.";
  int error_type = 3;
  /* ... */
  printf("Error (type %d): %s\n", error_type, error_msg);

  /* ... */
}

int main(void) {
  func_compliant();
  func_noncompliant();
  return 0;
}
