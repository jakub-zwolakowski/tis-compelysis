#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *childThread(void *val) {
  /* Correctly prints 1 */
  int *res = (int *)val;
#ifdef __TRUSTINSOFT_TMPBUG__
  /* Bug (probably) in mthread. */
  *res + 0;
#else
  printf("Result: %d\n", *res);
#endif
  free(res);
  return NULL;
}
 
void createThread(pthread_t *tid) {
  int result;
  /* Copy data into dynamic memory */
  int *val = malloc(sizeof(int));
 
  if (!val) {
    /* Handle error */
    return;
  }
  *val = 1;
  if ((result = pthread_create(tid, NULL, childThread, val)) != 0) {
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
  }
  return 0;
}

// DETECTED!
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_Allocated_Storage_compliant.c
// C17: ?
// COMPILE: gcc -lpthread
