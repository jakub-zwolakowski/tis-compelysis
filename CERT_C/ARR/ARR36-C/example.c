#include <stddef.h>

enum { SIZE = 32 };

void f_noncompliant(void) {
  int nums[SIZE];
  int end;
  int *next_num_ptr = nums;
  size_t free_elements;

  /* Increment next_num_ptr as array fills */

  free_elements = &end - next_num_ptr;
}

void f_compliant(void) {
  int nums[SIZE];
  int *next_num_ptr = nums;
  size_t free_elements;

  /* Increment next_num_ptr as array fills */

  free_elements = &(nums[SIZE]) - next_num_ptr;
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
