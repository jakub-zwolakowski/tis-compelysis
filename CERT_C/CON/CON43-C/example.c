#include <pthread.h>
#include <stdio.h>
 
enum { max_threads = 5 };

static volatile int account_balance_noncompliant;
 
void debit_noncompliant(int amount) {
  account_balance_noncompliant -= amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance_noncompliant);
#endif
}
 
void credit_noncompliant(int amount) {
  account_balance_noncompliant += amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance_noncompliant);
#endif
}

void *do_debit_noncompliant(void *arg) {
  debit_noncompliant(42);
  return NULL;
}

void *do_credit_noncompliant(void *arg) {
  credit_noncompliant(42);
  return NULL;
}

int main_noncompliant(void) {
  /* ... */
  pthread_t threads_debit[max_threads];
  pthread_t threads_credit[max_threads];
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads_debit[i], NULL, do_debit_noncompliant, NULL)) {
      /* Handle error */
      return 0;
    }
    if (0 != pthread_create(&threads_credit[i], NULL, do_credit_noncompliant, NULL)) {
      /* Handle error */
      return 0;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(threads_debit[i], 0)) {
      /* Handle error */
      return 0;
    }
    if (0 != pthread_join(threads_credit[i], 0)) {
      /* Handle error */
      return 0;
    }
  }
  return 0;
}

static int account_balance_compliant;
static pthread_mutex_t account_lock;
  
int debit_compliant(int amount) {
  if (pthread_mutex_lock(&account_lock) != 0) {
    return -1;   /* Indicate error to caller */
  }
  account_balance_compliant -= amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance_compliant);
#endif
  if (pthread_mutex_unlock(&account_lock) != 0) {
    return -1;   /* Indicate error to caller */
  }
  return 0;   /* Indicate success */
}
 
int credit_compliant(int amount) {
  if (pthread_mutex_lock(&account_lock) != 0) {
    return -1;   /* Indicate error to caller */
  }
  account_balance_compliant += amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance_compliant);
#endif
  if (pthread_mutex_unlock(&account_lock) != 0) {
    return -1;   /* Indicate error to caller */
  }
  return 0;   /* Indicate success */
}

void *do_debit_compliant(void *arg) {
  debit_compliant(42);
  return NULL;
}

void *do_credit_compliant(void *arg) {
  credit_compliant(42);
  return NULL;
}

int main_compliant(void) {
  if(pthread_mutex_init(&account_lock, NULL) != 0) {
    /* Handle error */
    return 0;
  }
  /* ... */
  pthread_t threads_debit[max_threads];
  pthread_t threads_credit[max_threads];
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads_debit[i], NULL, do_debit_compliant, NULL)) {
      /* Handle error */
      return 0;
    }
    if (0 != pthread_create(&threads_credit[i], NULL, do_credit_compliant, NULL)) {
      /* Handle error */
      return 0;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_join(threads_debit[i], 0)) {
      /* Handle error */
      return 0;
    }
    if (0 != pthread_join(threads_credit[i], 0)) {
      /* Handle error */
      return 0;
    }
  }
  pthread_mutex_destroy(&account_lock);
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread test_CON43-C.c
// C17: https://cigix.me/c17#5.1.2.4.p35
// UB: "The execution of a program contains a data race"
// COMPILE: gcc -lpthread
