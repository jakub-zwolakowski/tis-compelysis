#include <stdbool.h>
#include <string.h>

struct S {
  int i;
  float f;
};

bool are_equal_noncompliant(const struct S *s1, const struct S *s2) {
  if (!s1 && !s2)
    return true;
  else if (!s1 || !s2)
    return false;
  return 0 == memcmp(s1, s2, sizeof(struct S));
}

bool are_equal_compliant(const struct S *s1, const struct S *s2) {
  if (!s1 && !s2)
    return true;
  else if (!s1 || !s2)
    return false;
  return s1->i == s2->i &&
         s1->f == s2->f;
}

int main(void) {
  struct S s1 = { .i = 42, .f = 0.0 };
  struct S s2 = { .i = 42, .f = -0.0 };
  bool are_equal;
  are_equal = are_equal_compliant(&s1, &s2);
  are_equal = are_equal_noncompliant(&s1, &s2);
  return 0;
}
