#include <pthread.h>
#include <stdio.h>

struct multi_threaded_flags {
  unsigned int flag1 : 2;
  unsigned int flag2 : 2;
};
 
struct multi_threaded_flags flags_noncompliant;

void *thread1_noncompliant(void *arg) {
  flags_noncompliant.flag1 = 1;
  return NULL;
}
 
void *thread2_noncompliant(void *arg) {
  flags_noncompliant.flag2 = 2;
  return NULL;
}

int main_noncompliant(void) {
  pthread_t my_thread_1, my_thread_2;
  pthread_create(&my_thread_1, NULL, thread1_noncompliant, NULL);
  pthread_create(&my_thread_2, NULL, thread2_noncompliant, NULL);
  pthread_join(my_thread_1, 0);
  pthread_join(my_thread_2, 0);
  return 0;
}
 
struct mtf_mutex {
  struct multi_threaded_flags s;
  pthread_mutex_t mutex;
};
 
struct mtf_mutex flags_compliant;

void *thread1_compliant(void *arg) {
  if (0 != pthread_mutex_lock(&flags_compliant.mutex)) {
    /* Handle error */
    return NULL;
  }
  flags_compliant.s.flag1 = 1;
  if (0 != pthread_mutex_unlock(&flags_compliant.mutex)) {
    /* Handle error */
    return NULL;
  }
  return NULL;
}
  
void *thread2_compliant(void *arg) {
  if (0 != pthread_mutex_lock(&flags_compliant.mutex)) {
    /* Handle error */
    return NULL;
  }
  flags_compliant.s.flag2 = 2;
  if (0 != pthread_mutex_unlock(&flags_compliant.mutex)) {
    /* Handle error */
    return NULL;
  }
  return NULL;
}

int main_compliant(void) {
  pthread_t my_thread_1, my_thread_2;
  pthread_create(&my_thread_1, NULL, thread1_compliant, NULL);
  pthread_create(&my_thread_2, NULL, thread2_compliant, NULL);
  pthread_join(my_thread_1, 0);
  pthread_join(my_thread_2, 0);
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// Why: the Analyzer thinks that bit-field accesses are separate.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON32-C.c
// C17: https://cigix.me/c17#3.14.p3
// UB: ?
// COMPILE: gcc -lpthread
