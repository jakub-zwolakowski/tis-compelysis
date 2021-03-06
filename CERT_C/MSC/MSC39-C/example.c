#include <stdarg.h>
#include <stdio.h>

int contains_zero_noncompliant(size_t count, va_list ap) {
  for (size_t i = 1; i < count; ++i) {
    if (va_arg(ap, double) == 0.0) {
      return 1;
    }
  }
  return 0;
}

int print_reciprocals_noncompliant(size_t count, ...) {
  va_list ap;
  va_start(ap, count);

  if (contains_zero_noncompliant(count, ap)) {
    va_end(ap);
    return 1;
  }

  for (size_t i = 0; i < count; ++i) {
    printf("%f ", 1.0 / va_arg(ap, double));
  }

  va_end(ap);
  return 0;
}

int contains_zero_compliant(size_t count, va_list *ap) {
  va_list ap1;
  va_copy(ap1, *ap);
  for (size_t i = 1; i < count; ++i) {
    if (va_arg(ap1, double) == 0.0) {
      va_end(ap1);
      return 1;
    }
  }
  va_end(ap1);
  return 0;
}

int print_reciprocals_compliant(size_t count, ...) {
  int status;
  va_list ap;
  va_start(ap, count);

  if (contains_zero_compliant(count, &ap)) {
    printf("0 in arguments!\n");
    status = 1;
  } else {
    for (size_t i = 0; i < count; i++) {
      printf("%f ", 1.0 / va_arg(ap, double));
    }
    printf("\n");
    status = 0;
  }

  va_end(ap);
  return status;
}

int main(void) {
  print_reciprocals_compliant(3, (double)1, (double)2, (double)3);
  print_reciprocals_noncompliant(3, (double)1, (double)2, (double)3);
  return 0;
}
