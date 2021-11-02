#include <stdio.h>

const char *p = "At the beginning I was here";

void dont_do_this(void) {
  const char c_str[] = "This will change";
  p = c_str; /* Dangerous */
}

void this_is_OK(void) {
  const char c_str[] = "Everything OK";
  const char *p = c_str;
  /* ... */
}

void innocuous(void) {
  printf("%s\n", p);
}

int main(void) {
  this_is_OK();
  innocuous();
  dont_do_this();
  innocuous();
  return 0;
}
