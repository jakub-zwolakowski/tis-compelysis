#include <pthread.h>
#include <stdio.h>

struct multi_threaded_flags {
  volatile unsigned int flag1 : 2;
  volatile unsigned int flag2 : 2;
};
 
union mtf_protect {
  struct multi_threaded_flags s;
  long padding;
};
 
// static_assert(sizeof(long) >= sizeof(struct multi_threaded_flags));
 
struct mtf_mutex {
  union mtf_protect u;
  pthread_mutex_t mutex;
};
 
struct mtf_mutex flags;
 
void *thread1(void *arg) {
  int result;
  if ((result = pthread_mutex_lock(&flags.mutex)) != 0) {
    /* Handle error */
    return NULL;
  }
  flags.u.s.flag1 = 1;
  if ((result = pthread_mutex_unlock(&flags.mutex)) != 0) {
    /* Handle error */
    return NULL;
  }
  return NULL;
}
 
void *thread2(void *arg) {
  int result;
  if ((result = pthread_mutex_lock(&flags.mutex)) != 0) {
    /* Handle error */
    return NULL;
  }
  flags.u.s.flag2 = 2;
  if ((result = pthread_mutex_unlock(&flags.mutex)) != 0) {
    /* Handle error */
    return NULL;
  }
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

// NOT DETECTED
// Why: the Analyzer thinks that bit-field accesses are separate.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_bit-field_compliant.c
// C17: https://cigix.me/c17#3.14.p3
// UB: ?
// COMPILE: gcc -lpthread
