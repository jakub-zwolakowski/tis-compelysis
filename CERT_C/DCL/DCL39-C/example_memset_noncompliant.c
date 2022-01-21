#include <string.h>
 
struct test {
  int a;
  char b;
  int c;
};
 
/* Safely copy bytes to user space */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg;
 
  /* Set all bytes (including padding bytes) to zero */
  memset(&arg, 0, sizeof(arg));
 
  arg.a = 1;
  arg.b = 2;
  arg.c = 3;
 
  copy_to_user(usr_buf, &arg, sizeof(arg));
}

int main(void) {
  char usr_buf[100];
  do_stuff(usr_buf);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer -val example_memset_noncompliant.c
// C17: NOPE
// UB: NOPE
