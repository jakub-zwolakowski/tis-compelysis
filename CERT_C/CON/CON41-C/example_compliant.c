#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

struct data {
  struct data *next;
  /* ... */
};

void cleanup_data_structure(struct data *head) {
  head->next = NULL;
}
 
int reorganize_data_structure(void *thread_arg) {
  struct data *_Atomic *ptr_to_head = thread_arg;
  struct data *old_head = atomic_load(ptr_to_head);
  struct data *new_head;
  bool success;
 
  /* ... Reorganize the data structure ... */
 
  success = atomic_compare_exchange_strong(
    ptr_to_head, &old_head, new_head
  );
  if (!success) {
    cleanup_data_structure(new_head);
  }
  return success; /* Exit the thread */
}

enum { NTHREADS = 5 };

int main(void) {
  struct data my_data[NTHREADS];
  thrd_t threads[NTHREADS];
  for (size_t i = 0; i < NTHREADS; i++) {
    thrd_create(&threads[i], reorganize_data_structure, &my_data[i]);
  }
  for (size_t i = 0; i < NTHREADS; i++) {
    int result = -1;
    thrd_join(threads[i], &result);
    printf("Thread %lu result %d\n", i, result);
  }
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_compliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
