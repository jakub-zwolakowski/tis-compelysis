#include <stdatomic.h>
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
  
enum { max_threads = 5 };

pthread_mutex_t lock_noncompliant;
/* Atomic so multiple threads can modify safely */
atomic_int completed_noncompliant = ATOMIC_VAR_INIT(0);

void *do_work_noncompliant(void *arg) {
  int *i = (int *)arg;
 
  if (*i == 0) { /* Creation thread */
    if (0 != pthread_mutex_init(&lock_noncompliant, NULL)) {
      /* Handle error */
      return NULL;
    }
    atomic_store(&completed_noncompliant, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Creation %d\n", *i, completed_noncompliant);
  #endif
  } else if (*i < max_threads - 1) { /* Worker thread */
    if (0 != pthread_mutex_lock(&lock_noncompliant)) {
      /* Handle error */
      return NULL;
    }
    /* Access data protected by the lock_noncompliant */
    atomic_fetch_add(&completed_noncompliant, 1);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Worker %d\n", *i, completed_noncompliant);
  #endif
    if (0 != pthread_mutex_unlock(&lock_noncompliant)) {
      /* Handle error */
      return NULL;
    }
  } else { /* Destruction thread */
    pthread_mutex_destroy(&lock_noncompliant);
  #ifndef __TRUSTINSOFT_ANALYZER__
    printf("noncompliant %d, Destruction %d\n", *i, completed_noncompliant);
  #endif
  }
  return NULL;
}
  
int main_noncompliant(void) {
  pthread_t threads[max_threads];

#ifndef __TRUSTINSOFT_ANALYZER__
  printf("noncompliant beginning\n");
#endif
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads[i], NULL, do_work_noncompliant, &i)) {
      /* Handle error */
      return 0;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(threads[i], 0)) {
      /* Handle error */
      return 0;
    }
  }
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("noncompliant end\n");
#endif
  return 0;
}

pthread_mutex_t lock_compliant;
/* Atomic so multiple threads can increment safely */
atomic_int completed_compliant = ATOMIC_VAR_INIT(0);

void *do_work_compliant(void *dummy) {
  /* Lock */
  if (0 != pthread_mutex_lock(&lock_compliant)) {
    /* Handle error */
    return NULL;
  }
  /* Access data protected by the lock_compliant */
  atomic_fetch_add(&completed_compliant, 1);
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant %d\n", completed_compliant);
#endif
  /* Unlock */
  if (0 != pthread_mutex_unlock(&lock_compliant)) {
    /* Handle error */
    return NULL;
  }
 
  return NULL;
}

int main_compliant(void) {
  pthread_t threads[max_threads];
 
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant beginning\n");
#endif
  if (0 != pthread_mutex_init(&lock_compliant, NULL)) {
    /* Handle error */
    return 0;
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads[i], NULL, do_work_compliant, NULL)) {
      /* Handle error */
      return 0;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(threads[i], 0)) {
      /* Handle error */
      return 0;
    }
  }
 
  pthread_mutex_destroy(&lock_compliant);
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("compliant end\n");
#endif
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// Does not match creating and joining a thread.
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races test_CON31-C.c
// COMPILE: gcc -lpthread
