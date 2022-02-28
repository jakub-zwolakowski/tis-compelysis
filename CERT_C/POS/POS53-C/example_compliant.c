#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutex1; /* Initialized as PTHREAD_MUTEX_ERRORCHECK */
pthread_mutexattr_t attr;
pthread_cond_t cv;

void *waiter1();
void *waiter2();
void *signaler();

int count1 = 0, count2 = 0;
#define COUNT_LIMIT 5

int main() {
  int ret;
  pthread_t thread1, thread2, thread3;

  if ((ret = pthread_mutexattr_init( &attr)) != 0) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_ERRORCHECK)) != 0) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_mutex_init( &mutex1, &attr)) != 0) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_cond_init( &cv, NULL)) != 0) {
    /* handle error */
    return 1;
  }

  if ((ret = pthread_create( &thread1, NULL, &waiter1, NULL))) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_create( &thread2, NULL, &waiter2, NULL))) {
    /* handle error */
    return 1;
  }

  if ((ret = pthread_create( &thread3, NULL, &signaler, NULL))) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_join( thread1, NULL)) != 0) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_join( thread2, NULL)) != 0) {
    /* Handle error */
    return 1;
  }

  if ((ret = pthread_join( thread3, NULL)) != 0) {
    /* Handle error */
    return 1;
  }

  return 0;
}

void *waiter1() {
  int ret;
  while (count1 < COUNT_LIMIT) {
    if ((ret = pthread_mutex_lock(&mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }

    if ((ret = pthread_cond_wait(&cv, &mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }

    printf("count1 = %d\n", ++count1);

    if ((ret = pthread_mutex_unlock(&mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }
  }

  return NULL;
}

void *waiter2() {
  int ret;
  while (count2 < COUNT_LIMIT) {
    if ((ret = pthread_mutex_lock(&mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }

    if ((ret = pthread_cond_wait(&cv, &mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }

    printf("count2 = %d\n", ++count2);

    if ((ret = pthread_mutex_unlock(&mutex1)) != 0) {
      /* Handle error */
      return NULL;
    }
  }

  return NULL;
}

void *signaler() {
  int ret;
  while ((count1 < COUNT_LIMIT) || (count2 < COUNT_LIMIT)) {
    sleep(1);
    printf("signaling\n");
    if ((ret = pthread_cond_signal(&cv)) != 0) {
      /* Handle error */
      return NULL;
    }
  }

  return NULL;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_compliant.c
// C17: ?
// UB: ?
