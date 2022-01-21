#include <unistd.h>

int main(void) {
  if (!(getuid() && geteuid() == 0)) {
    /* ... */
    return 0;
  }
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: NOPE
// UB: NOPE
