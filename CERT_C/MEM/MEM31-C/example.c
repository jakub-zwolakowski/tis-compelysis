#include <stdlib.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

enum { BUFFER_SIZE = 32 };

int f_noncompliant(void) {
  char *text_buffer_noncompliant = (char *)malloc(BUFFER_SIZE);
  if (text_buffer_noncompliant == NULL) {
    return -1;
  }
  return 0;
}

int f_compliant(void) {
  char *text_buffer_compliant = (char *)malloc(BUFFER_SIZE);
  if (text_buffer_compliant == NULL) {
    return -1;
  }
  free(text_buffer_compliant);
  return 0;
}

int main(void) {
  f_compliant();
  f_noncompliant();
#ifdef __TRUSTINSOFT_ANALYZER__
  tis_check_leak();
#endif
  return 0;
}
