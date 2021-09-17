#include <pthread.h>
#include <stdio.h>
 
static volatile int account_balance;
 
void debit(int amount) {
  account_balance -= amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance);
#endif
}
 
void credit(int amount) {
  account_balance += amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("%d\n", account_balance);
#endif
}

void *do_debit(void *arg) {
  debit(42);
  return NULL;
}

void *do_credit(void *arg) {
  credit(42);
  return NULL;
}

enum { max_threads = 5 };

int main(void) {
  /* ... */
  pthread_t threads_debit[max_threads];
  pthread_t threads_credit[max_threads];
  for (size_t i = 0; i < max_threads; i++) {
    if (0 != pthread_create(&threads_debit[i], NULL, do_debit, NULL)) {
      /* Handle error */
      return 0;
    }
    if (0 != pthread_create(&threads_credit[i], NULL, do_credit, NULL)) {
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

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread test_CON43-C_noncompliant.c
// C17: https://cigix.me/c17#5.1.2.4.p35
// UB: "The execution of a program contains a data race"
// COMPILE: gcc -lpthread
