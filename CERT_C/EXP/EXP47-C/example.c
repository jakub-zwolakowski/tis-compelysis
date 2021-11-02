#include <stdarg.h>
#include <stddef.h>

void func_noncompliant(size_t num_vargs, ...) {
  va_list ap;
  va_start(ap, num_vargs);
  if (num_vargs > 0) {
    unsigned char c = va_arg(ap, unsigned char);
    // ...
  }
  va_end(ap);
}

void f_noncompliant(void) {
  unsigned char c = 0x12;
  func_noncompliant(1, c);
}

void func_compliant(size_t num_vargs, ...) {
  va_list ap;
  va_start(ap, num_vargs);
  if (num_vargs > 0) {
    unsigned char c = (unsigned char) va_arg(ap, int);
    // ...
  }
  va_end(ap);
}

void f_compliant(void) {
  unsigned char c = 0x12;
  func_compliant(1, c);
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
