#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

enum { NTHREADS = 5 };

static atomic_bool flag = ATOMIC_VAR_INIT(false);
  
void init_flag(void) {
  atomic_init(&flag, false);
}
   
void toggle_flag(void) {
  bool old_flag = atomic_load(&flag);
  bool new_flag;
  do {
    new_flag = !old_flag;
  } while (!atomic_compare_exchange_weak(&flag, &old_flag, new_flag));
}
     
bool get_flag(void) {
  return atomic_load(&flag);
}

int my_thread(void *arg) {
  toggle_flag();
  return 0;
}

int main(void) {
  thrd_t threads[NTHREADS];
  for (size_t i = 0; i < NTHREADS; i++) {
    thrd_create(&threads[i], my_thread, NULL);
  }
  for (size_t i = 0; i < NTHREADS; i++) {
    thrd_join(threads[i], NULL);
  }
  bool loaded_flag = atomic_load(&flag);
  printf("flag = %s\n", loaded_flag ? "true" : "false");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_compliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
