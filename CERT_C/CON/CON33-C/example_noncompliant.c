#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

int f(void *arg) {
  int errnum = *((int *) arg);
  char *errmsg = strerror(errnum); /* Data race */
  printf("errnum = %2d : %s\n", errnum, errmsg);
  return 0;
}

enum { max_threads = 16 };

int main(void) {
  thrd_t threads[max_threads];

  int errnums[max_threads];
  for (int i = 0; i < max_threads; i++) {
    errnums[i] = i;
  }

  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], f, &errnums[i])) {
      /* Handle error */
      return 1;
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Handle error */
      return 2;
    }
  }

  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
