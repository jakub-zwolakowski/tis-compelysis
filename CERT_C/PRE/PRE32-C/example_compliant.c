#include <stdlib.h>
#include <string.h>

void func(const char *src) {
  /* Validate the source string; calculate size */
  int size = strlen(src);
  char *dest;
  /* malloc() destination string */
  dest = malloc(sizeof(char) * (size + 1));
  #ifdef PLATFORM1
    memcpy(dest, src, 12);
  #else
    memcpy(dest, src, 24);
  #endif
  /* ... */
  free(dest);
}

int main(void) {
  func("123456789012345678901234567890");
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_PRE32-C_compliant.c
// C17: https://cigix.me/c17#7.1.4.p1 and https://cigix.me/c17#6.10.3.p11
// UB: "There are sequences of preprocessing tokens within the list of macro arguments that would otherwise act as preprocessing directives"
