#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

struct multi_threaded_flags {
  unsigned int flag1 : 2;
  unsigned int flag2 : 2;
};
 
struct multi_threaded_flags flags;

int thread1(void *arg) {
  flags.flag1 = 1;
  return 0;
}
 
int thread2(void *arg) {
  flags.flag2 = 2;
  return 0;
}

int main(void) {
  thrd_t threads[2];
  thrd_create(&threads[0], thread1, NULL);
  thrd_create(&threads[1], thread2, NULL);
  thrd_join(threads[0], NULL);
  thrd_join(threads[1], NULL);
  return 0;
}

// NOT DETECTED
// Why: the Analyzer thinks that bit-field accesses are separate.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_bit-field_noncompliant.c
// C17: https://cigix.me/c17#3.14.p3
// UB: ?
// COMPILE: gcc -lpthread
