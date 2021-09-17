#include <pthread.h>
#include <stdio.h>

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
  pthread_t my_thread_1, my_thread_2;
  pthread_create(&my_thread_1, NULL, thread1, NULL);
  pthread_create(&my_thread_2, NULL, thread2, NULL);
  pthread_join(my_thread_1, 0);
  pthread_join(my_thread_2, 0);
  return 0;
}

// NOT DETECTED
// Why: the Analyzer thinks that bit-field accesses are separate.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON32-C_noncompliant.c
// C17: https://cigix.me/c17#3.14.p3
// UB: ?
// COMPILE: gcc -lpthread
