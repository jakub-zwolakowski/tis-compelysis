#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *childThread(void *val) {
  /*
   * Depending on the order of thread execution, the object
   * referred to by val may be out of its lifetime, resulting
   * in a potentially incorrect result being printed out.
   */
  int *res = (int *)val;
#ifdef __TRUSTINSOFT_TMPBUG__
  /* Bug (probably) in mthread - backtrace if printf is used here. */
  *res + 0;
#else
  printf("Result: %d\n", *res);
#endif
  return NULL;
}
 
void createThread(pthread_t *tid) {
  /* Store 1 in val on the stack. */
  int val = 1;
  int result;
  if ((result = pthread_create(tid, NULL, childThread, &val)) != 0) {
    /* Handle error */
    return;
  }
}
 
int main(void) {
  pthread_t tid;
  int result;
  createThread(&tid);
  if ((result = pthread_join(tid, NULL)) != 0) {
    /* Handle error */
    return 1;
  }
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_Automatic_Storage_noncompliant.c
// C17: ?
// UB: This is not an UB directly, but causes an access to an unititialized left-value.
// COMPILE: gcc -lpthread
