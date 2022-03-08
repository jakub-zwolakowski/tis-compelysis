#include <stdlib.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif
  
typedef struct {
  int balance;
  mtx_t balance_mutex;
} bank_account;
 
typedef struct {
  bank_account *from;
  bank_account *to;
  int amount;
} transaction;
 
int create_bank_account(bank_account **ba,
                         int initial_amount) {
  bank_account *nba = (bank_account *)malloc(
    sizeof(bank_account)
  );
  if (nba == NULL) {
    /* Handle error */
    return 1;
  }
 
  nba->balance = initial_amount;
  if (thrd_success
      != mtx_init(&nba->balance_mutex, mtx_plain)) {
    /* Handle error */
    free(nba);
    return 1;
  }
 
  *ba = nba;
  
  return 0;
}
 
int deposit(void *ptr) {
  transaction *args = (transaction *)ptr;
 
  if (thrd_success != mtx_lock(&args->from->balance_mutex)) {
    /* Handle error */
    return thrd_error;
  }
 
  /* Not enough balance to transfer */
  if (args->from->balance < args->amount) {
    if (thrd_success
        != mtx_unlock(&args->from->balance_mutex)) {
      /* Handle error */
      return thrd_error;
    }
    return -1; /* Indicate error */
  }
  if (thrd_success != mtx_lock(&args->to->balance_mutex)) {
    /* Handle error */
  }
 
  args->from->balance -= args->amount;
  args->to->balance += args->amount;
 
  if (thrd_success
      != mtx_unlock(&args->from->balance_mutex)) {
    /* Handle error */
    return thrd_error;
  }
 
  if (thrd_success
      != mtx_unlock(&args->to->balance_mutex)) {
    /* Handle error */
    return thrd_error;
  }
 
  free(ptr);
  return 0;
}
 
int main(void) {
  thrd_t thr1, thr2;
  transaction *arg1;
  transaction *arg2;
  bank_account *ba1;
  bank_account *ba2;
 
  if (0 != create_bank_account(&ba1, 1000)) {
    /* Handle error */
    return 1;
  }
  if (0 != create_bank_account(&ba2, 1000)) {
    /* Handle error */
    mtx_destroy(&ba1->balance_mutex);
    free(ba1);
    return 1;
  }
 
  arg1 = (transaction *)malloc(sizeof(transaction));
  if (arg1 == NULL) {
    /* Handle error */
    goto cleanup;
  }
  arg2 = (transaction *)malloc(sizeof(transaction));
  if (arg2 == NULL) {
    /* Handle error */
    free(arg1);
    goto cleanup;
  }
  arg1->from = ba1;
  arg1->to = ba2;
  arg1->amount = 100;
 
  arg2->from = ba2;
  arg2->to = ba1;
  arg2->amount = 100;
 
  /* Perform the deposits */
  if (thrd_success
     != thrd_create(&thr1, deposit, (void *)arg1)) {
    /* Handle error */
    goto cleanup1;
  }
  if (thrd_success
      != thrd_create(&thr2, deposit, (void *)arg2)) {
    /* Handle error */
    goto cleanup2;
  }

cleanup2:
  thrd_join(thr2, NULL);
cleanup1:
  thrd_join(thr1, NULL);
cleanup:
  mtx_destroy(&ba1->balance_mutex);
  mtx_destroy(&ba2->balance_mutex);
  free(ba1);
  free(ba2);

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
