#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifdef C11_THREADS
#include <thread.h>
#else
#include "../c11threads.h"
#endif

struct node_t {
  void *node;
  struct node_t *next;
};
  
struct node_t list;
static mtx_t lock;
static cnd_t condition;

static int i = 0;

int consume_list_element(void *arg) {
  if (thrd_success != mtx_lock(&lock)) {
    /* Handle error */
    mtx_unlock(&lock);
    return thrd_error;
  }
  
  if (list.next == NULL) {
    if (thrd_success != cnd_wait(&condition, &lock)) {
      /* Handle error */
      return thrd_error;
    }
  }
 
  /* Proceed when condition holds */
  struct node_t *n = list.next;
  printf("Node = %d\n", *((int *) n->node));
  free(n->node);
  list.next = n->next;
  free(n);
 
  if (thrd_success != mtx_unlock(&lock)) {
    /* Handle error */
    return thrd_error;
  }

  return thrd_success;
}

void broadcast(void) {
  if (thrd_success != mtx_lock(&lock)) {
    /* Handle error */
    mtx_unlock(&lock);
    return;
  }

  cnd_broadcast(&condition);

  if (thrd_success != mtx_unlock(&lock)) {
    /* Handle error */
    return;
  }
}

void add_new_node(struct node_t *add_here, int i) {
  struct node_t *n = malloc(sizeof(struct node_t));
  n->node = malloc(sizeof(int));
  *((int *) n->node) = i;

  n->next = add_here->next;
  add_here->next = n;
}

enum { max_threads = 6 };

int main(void) {
  cnd_init(&condition);
  mtx_init(&lock, mtx_plain);

  list.next = NULL;
  list.node = NULL;

  thrd_t consumers[max_threads];
  for (int i = 0; i < max_threads; i++) {
    thrd_create(&consumers[i], consume_list_element, NULL);
  }
  
  sleep(1);

  add_new_node(&list, 41);
  add_new_node(&list, 42);
  add_new_node(&list, 43);
  for (int i = 0; i < max_threads; i++) {
    broadcast();
  }

  sleep(1);

  add_new_node(&list, 44);
  add_new_node(&list, 45);
  add_new_node(&list, 46);
  for (int i = 0; i < max_threads; i++) {
    broadcast();
  }

  for (int i = 0; i < max_threads; i++) {
    thrd_join(consumers[i], NULL);
  }

  mtx_destroy(&lock);
  cnd_destroy(&condition);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val -slevel 1000 -mthread -mt-write-races example_noncompliant.c
// C17: ?
// UB: ?
// COMPILE: gcc -lpthread
