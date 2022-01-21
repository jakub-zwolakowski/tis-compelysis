#include <pthread.h>
#include <stdio.h>

struct multi_threaded_flags {
  unsigned int flag1 : 2;
  unsigned int flag2 : 2;
};
 
struct multi_threaded_flags flags;

void *thread1(void *arg) {
  flags.flag1 = 1;
  return NULL;
}
 
void *thread2(void *arg) {
  flags.flag1 = 2;
  return NULL;
}

int main(void) {
  pthread_t my_thread_1, my_thread_2;
  pthread_create(&my_thread_1, NULL, thread1, NULL);
  pthread_create(&my_thread_2, NULL, thread2, NULL);
  pthread_join(my_thread_1, 0);
  pthread_join(my_thread_2, 0);
  return 0;
}
