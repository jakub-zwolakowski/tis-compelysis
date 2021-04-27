#include <stddef.h>

void set_flag_noncompliant(int number, int *sign_flag) {
  if (NULL == sign_flag) {
    return;
  }

  if (number > 0) {
    *sign_flag = 1;
  } else if (number < 0) {
    *sign_flag = -1;
  }
}

int is_negative_noncompliant(int number) {
  int sign;
  set_flag_noncompliant(number, &sign);
  return sign < 0;
}


void set_flag_compliant(int number, int *sign_flag) {
  if (NULL == sign_flag) {
    return;
  }

  /* Account for number being 0 */
  if (number >= 0) {
    *sign_flag = 1;
  } else {
    *sign_flag = -1;
  }
}

int is_negative_compliant(int number) {
  int sign = 0; /* Initialize for defense-in-depth */
  set_flag_compliant(number, &sign);
  return sign < 0;
}

void main(void) {
  is_negative_compliant(42);
  is_negative_compliant(-42);
  is_negative_compliant(0);
  is_negative_noncompliant(42);
  is_negative_noncompliant(-42);
  is_negative_noncompliant(0);
}
