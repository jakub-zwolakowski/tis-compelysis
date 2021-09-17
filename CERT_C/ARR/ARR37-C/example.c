#include <stddef.h>

struct numbers_noncompliant {
  short num_a, num_b, num_c;
};

int sum_numbers_noncompliant(const struct numbers_noncompliant *numb){
  int total = 0;
  const short *numb_ptr;
 
  for (numb_ptr = &numb->num_a;
       numb_ptr <= &numb->num_c;
       numb_ptr++) {
    total += *(numb_ptr);
  }
 
  return total;
}

int main_noncompliant(void) {
  struct numbers_noncompliant my_numbers = { 1, 2, 3 };
  sum_numbers_noncompliant(&my_numbers);
  return 0;
}

struct numbers_compliant {
  short a[3];
};

int sum_numbers_compliant(const short *numb, size_t dim) {
  int total = 0;
  for (size_t i = 0; i < dim; ++i) {
    total += numb[i];
  }
 
  return total;
}

int main_compliant(void) {
  struct numbers_compliant my_numbers = { .a[0]= 1, .a[1]= 2, .a[2]= 3};
  sum_numbers_compliant(
    my_numbers.a,
    sizeof(my_numbers.a)/sizeof(my_numbers.a[0])
  );
  return 0;
}

int main_noncompliant(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_ARR37-C.c
// C17: https://cigix.me/c17#6.5.6.p8
// UB: ?
