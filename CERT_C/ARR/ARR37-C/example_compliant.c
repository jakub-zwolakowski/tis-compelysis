#include <stddef.h>

struct numbers {
  short a[3];
};

int sum_numbers(const short *numb, size_t dim) {
  int total = 0;
  for (size_t i = 0; i < dim; ++i) {
    total += numb[i];
  }
 
  return total;
}

int main(void) {
  struct numbers my_numbers = { .a[0]= 1, .a[1]= 2, .a[2]= 3};
  sum_numbers(
    my_numbers.a,
    sizeof(my_numbers.a)/sizeof(my_numbers.a[0])
  );
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_ARR37-C_compliant.c
// C17: https://cigix.me/c17#6.5.6.p8
// UB: ?
