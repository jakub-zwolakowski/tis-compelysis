#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void free_list_noncompliant(struct node *head) {
  for (struct node *p = head; p != NULL; p = p->next) {
    free(p);
  }
}

void free_list_compliant(struct node *head) {
  struct node *q;
  for (struct node *p = head; p != NULL; p = q) {
    q = p->next;
    free(p);
  }
}

struct node *make_list(int elts) {
  struct node *previous_node = NULL;
  struct node *current_node;
  int i;
  for (i = 0; i < elts; i++) {
    current_node = malloc(sizeof (struct node));
    current_node->value = i;
    current_node->next = previous_node;
  }
  return current_node;
}

void main(void) {
  struct node *head;
  head = make_list(3);
  free_list_compliant(head);
  head = make_list(3);
  free_list_noncompliant(head);
}
