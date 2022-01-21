#include <stdlib.h>
  
#include <stdlib.h>
#include <string.h>
  
void func(void) {
  size_t resize = 1024;
  size_t alignment = 1 << 12;
  int *ptr;
  int *ptr1;
 
  if (NULL == (ptr = (int *)aligned_alloc(alignment,
                                          sizeof(int)))) {
    /* Handle error */
    return;
  }
 
  if (NULL == (ptr1 = (int *)aligned_alloc(alignment,
                                           resize))) {
    /* Handle error */
    return;
  }
   
  if (NULL == memcpy(ptr1, ptr, sizeof(int))) {
    /* Handle error */
    return;
  }
   
  free(ptr);
}

int main(void) {
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val example_compliant.c -val-continue-on-pointer-library-function
// C17: NOPE
// UB: ?
