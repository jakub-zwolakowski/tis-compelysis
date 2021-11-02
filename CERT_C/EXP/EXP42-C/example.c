#include <string.h>

struct s {
  char c;
  int i;
  char buffer[13];
};

void compare_noncompliant(const struct s *left, const struct s *right) {
  if ((left && right) &&
      (0 == memcmp(left, right, sizeof(struct s)))) {
    /* ... */
  }
}

void compare_compliant(const struct s *left, const struct s *right) {
  if ((left && right) &&
      (left->c == right->c) &&
      (left->i == right->i) &&
      (0 == memcmp(left->buffer, right->buffer, 13))) {
    /* ... */
  }
}

int main(void) {
  int j;
  int res = 13;
  struct s left, right;

  left.c = 'a';
  left.i = 42;
  for (j = 0; j < 13; ++j) {
      left.buffer[j] = 'x';
  }
  right.c = 'a';
  right.i = 42;
  for (j = 0; j < 13; ++j) {
      right.buffer[j] = 'x';
  }

  compare_compliant(&left, &right);
  compare_noncompliant(&left, &right);
  
  return 0;
}
