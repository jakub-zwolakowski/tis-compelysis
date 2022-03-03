#include <string.h>

int authenticate(const char* code) {
  int result = strcmp(code, "correct code");
  return (result == 0);
}
