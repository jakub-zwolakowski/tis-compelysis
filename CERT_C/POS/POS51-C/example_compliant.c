#include <pthread.h>
#include <stdlib.h>


typedef struct {
  int balance;
  pthread_mutex_t balance_mutex;
  unsigned int id; /* Should never be changed after initialized */
} bank_account;

typedef struct {
  bank_account *from;
  bank_account *to;
  int amount;
} deposit_thr_args;

unsigned int global_id = 1;

int create_bank_account(bank_account **ba, int initial_amount) {
  int result;
  bank_account *nba = malloc(sizeof(bank_account));
  if (nba == NULL) {
    /* Handle error */
    return 1;
  }
 
  nba->balance = initial_amount;
  result = pthread_mutex_init(&nba->balance_mutex, NULL);
  if (result != 0) {
    /* Handle error */
    free(nba);
    return 1;
  }
 
  nba->id = global_id++;
  *ba = nba;

  return 0;
}

void *deposit(void *ptr) {
  deposit_thr_args *args = (deposit_thr_args *)ptr;
  int result;
 
  if (args->from->id == args->to->id)
        return NULL;
 
  /* Ensure proper ordering for locking */
  if (args->from->id < args->to->id) {
    if ((result = pthread_mutex_lock(&(args->from->balance_mutex))) != 0) {
      /* Handle error */
      pthread_mutex_unlock(&(args->from->balance_mutex));
      return NULL;
    }
    if ((result = pthread_mutex_lock(&(args->to->balance_mutex))) != 0) {
      /* Handle error */
      pthread_mutex_unlock(&(args->to->balance_mutex));
      return NULL;
    }
  } else {
    if ((result = pthread_mutex_lock(&(args->to->balance_mutex))) != 0) {
      /* Handle error */
      pthread_mutex_unlock(&(args->to->balance_mutex));
      return NULL;
    }
    if ((result = pthread_mutex_lock(&(args->from->balance_mutex))) != 0) {
      /* Handle error */
      pthread_mutex_unlock(&(args->from->balance_mutex));
      return NULL;
    }
  }
 
  /* Not enough balance to transfer */
  if (args->from->balance < args->amount) {
    if ((result = pthread_mutex_unlock(&(args->from->balance_mutex))) != 0) {
      /* Handle error */
      return NULL;
    }
    if ((result = pthread_mutex_unlock(&(args->to->balance_mutex))) != 0) {
      /* Handle error */
      return NULL;
    }
    return NULL;
  }
 
  args->from->balance -= args->amount;
  args->to->balance += args->amount;
 
  if ((result = pthread_mutex_unlock(&(args->from->balance_mutex))) != 0) {
    /* Handle error */
    return NULL;
  }
  if ((result = pthread_mutex_unlock(&(args->to->balance_mutex))) != 0) {
    /* Handle error */
    return NULL;
  }
 
  return NULL;
}
 
int main(void) {
  pthread_t thr1, thr2;
  int result;
  deposit_thr_args *arg1 = NULL;
  deposit_thr_args *arg2 = NULL;
  bank_account *ba1 = NULL;
  bank_account *ba2 = NULL;

  if (0 != create_bank_account(&ba1, 1000)) {
    /* Handle error */
    return 1;
  }
  if (0 != create_bank_account(&ba2, 1000)) {
    /* Handle error */
    pthread_mutex_destroy(&ba1->balance_mutex);
    free(ba1);
    return 1;
  }
 
  arg1 = malloc(sizeof(deposit_thr_args));
  if (arg1 == NULL) {
    /* Handle error */
    goto cleanup;
  }
  arg2 = malloc(sizeof(deposit_thr_args));
  if (arg2 == NULL) {
    /* Handle error */
    goto cleanup;
  }
 
  arg1->from = ba1;
  arg1->to = ba2;
  arg1->amount = 100;
 
  arg2->from = ba2;
  arg2->to = ba1;
  arg2->amount = 100;
 
  /* Perform the deposits */
  if ((result = pthread_create(&thr1, NULL, deposit, (void *)arg1)) != 0) {
    /* Handle error */
    goto cleanup1;
  }
  if ((result = pthread_create(&thr2, NULL, deposit, (void *)arg2)) != 0) {
    /* Handle error */
    goto cleanup2;
  }

cleanup2:
  pthread_join(thr2, NULL);
cleanup1:
  pthread_join(thr1, NULL);
cleanup:
  pthread_mutex_destroy(&ba1->balance_mutex);
  pthread_mutex_destroy(&ba2->balance_mutex);
  free(ba1);
  free(ba2);
  free(arg1);
  free(arg2);
 
  pthread_exit(NULL);
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: ?
