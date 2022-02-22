#include <stdlib.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include "../c11threads.h"
#include "tis_builtin.h"
#else
#include <thread.h>
#endif
 
/* Global key to the thread-specific storage */
tss_t key;
enum { MAX_THREADS = 3 };
 
int *get_data(void) {
  int *arr = (int *)malloc(2 * sizeof(int));
  if (arr == NULL) {
    return arr;  /* Report error  */
  }
  arr[0] = 10;
  arr[1] = 42;
  return arr;
}
 
int add_data(void) {
  int *data = get_data();
  if (data == NULL) {
    return -1;  /* Report error */
  }
 
  if (thrd_success != tss_set(key, (void *)data)) {
    /* Handle error */
    return -1;
  }
  return 0;
}
 
void print_data(void) {
  /* Get this thread's global data from key */
  int *data = tss_get(key);
 
  if (data != NULL) {
    /* Print data */
  }
}
 
int function(void *dummy) {
  if (add_data() != 0) {
    return -1;  /* Report error */
  }
  print_data();
  return 0;
}
 
void destructor(void *data) {
  free(data);
}
  
int main(void) {
  thrd_t thread_id[MAX_THREADS];
 
  /* Create the key before creating the threads */
  if (thrd_success != tss_create(&key, destructor)) {
    /* Handle error */
    return -1;
  }
 
  /* Create threads that would store specific storage */
  for (size_t i = 0; i < MAX_THREADS; i++) {
    if (thrd_success != thrd_create(&thread_id[i], function, NULL)) {
      /* Handle error */
      return -1;
    }
  }
 
  for (size_t i = 0; i < MAX_THREADS; i++) {
    if (thrd_success != thrd_join(thread_id[i], NULL)) {
      /* Handle error */
      return -1;
    }
  }
 
  tss_delete(key);

#ifdef __TRUSTINSOFT_ANALYZER__
  /* Check for memory leaks before exitting the program. */
  tis_check_leak();
#endif

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread example_compliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
