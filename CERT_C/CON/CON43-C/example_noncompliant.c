#include <stdio.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif
 
static volatile int account_balance;
 
void debit(int amount) {
  account_balance -= amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("account_balance = %3d\n", account_balance);
#endif
}
 
void credit(int amount) {
  account_balance += amount;
#ifndef __TRUSTINSOFT_ANALYZER__
  printf("account_balance = %3d\n", account_balance);
#endif
}

int do_debit(void *arg) {
  int amount = *((int *) arg);
  debit(amount);
  return thrd_success;
}

int do_credit(void *arg) {
  int amount = *((int *) arg);
  credit(amount);
  return thrd_success;
}

enum { max_threads = 5 };

int main(void) {
  /* ... */
  thrd_t threads_debit[max_threads];
  thrd_t threads_credit[max_threads];
  for (size_t i = 0; i < max_threads; i++) {
    int amount = (int) 1;
    if (thrd_success != thrd_create(&threads_debit[i], do_debit, &amount)) {
      /* Handle error */
      return 1;
    }
    if (thrd_success != thrd_create(&threads_credit[i], do_credit, &amount)) {
      /* Handle error */
      return 2;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads_debit[i], NULL)) {
      /* Handle error */
      return 3;
    }
    if (thrd_success != thrd_join(threads_credit[i], NULL)) {
      /* Handle error */
      return 4;
    }
  }
  printf("account_balance = %3d\n", account_balance);
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread example_noncompliant.c
// C17: https://cigix.me/c17#5.1.2.4.p35
// UB: "The execution of a program contains a data race"
// COMPILE: gcc -lpthread
