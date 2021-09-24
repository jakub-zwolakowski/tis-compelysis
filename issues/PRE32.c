#include <stdlib.h>
#include <string.h>

#define MEMCPY(dest, src, size) memcpy(dest, src, size)

int main(void) {
  const char *src = "Héhéhé!... Quoi?";
  char *dest = malloc(sizeof(char) * 100);
  MEMCPY(dest, src,
    #ifdef TEST
      10
    #else
      16
    #endif
  );
  return 0;
}
