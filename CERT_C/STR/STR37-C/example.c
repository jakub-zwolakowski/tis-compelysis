#include <ctype.h>
#include <string.h>

size_t count_preceding_whitespace_noncompliant(const char *s) {
  const char *t = s;
  size_t length = strlen(s) + 1;
  while (isspace(*t) && (t - s < length)) {
    ++t;
  }
  return t - s;
}

size_t count_preceding_whitespace_compliant(const char *s) {
  const char *t = s;
  size_t length = strlen(s) + 1;
  while (isspace((unsigned char)*t) && (t - s < length)) {
    ++t;
  }
  return t - s;
}

void main(void) {
  count_preceding_whitespace_compliant("   ÿ foo");
  count_preceding_whitespace_noncompliant("   ÿ foo");
}
