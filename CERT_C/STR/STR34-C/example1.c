#include <limits.h>
#include <stddef.h>

static char table[UCHAR_MAX + 1] = { 'a' /* ... */ };

ptrdiff_t first_not_in_table_compliant(const char *c_str) {
  for (const char *s = c_str; *s; ++s) {
    if (table[(unsigned char)*s] != *s) {
      return s - c_str;
    }
  }
  return -1;
}

ptrdiff_t first_not_in_table_noncompliant(const char *c_str) {
  for (const char *s = c_str; *s; ++s) {
    if (table[(unsigned int)*s] != *s) {
      return s - c_str;
    }
  }
  return -1;
}

void main(void) {
  for(int i = 0; i < UCHAR_MAX + 1; i++) {
    table[i] = (unsigned char)i;
  }
  char c_str[UCHAR_MAX + 1];
  for(int i = 0; i < UCHAR_MAX + 1; i++) {
    c_str[i] = 'a' + (unsigned char)i;
  }
  first_not_in_table_compliant(c_str);
  first_not_in_table_noncompliant(c_str);
}
