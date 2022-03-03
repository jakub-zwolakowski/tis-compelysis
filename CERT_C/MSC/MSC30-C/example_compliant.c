#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
enum { len = 12 }; 
 
void func(void) {
  /*
   * id will hold the ID, starting with the characters
   *  "ID" followed by a random integer.
   */
  char id[len]; 
  int r;
  int num;
  /* ... */
  struct timespec ts;
  if (timespec_get(&ts, TIME_UTC) == 0) {
    /* Handle error */
  }
  srandom(ts.tv_nsec ^ ts.tv_sec);  /* Seed the PRNG */
  /* ... */
  r = random();  /* Generate a random integer */
  num = snprintf(id, len, "ID%-d", r);  /* Generate the ID */
  /* ... */
  printf("Generated identifier = \"%s\"\n", id);
}

enum { iterations = 10 };

int main(void) {
  for (size_t i = 0; i < iterations; i++) {
    func();
  }
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
