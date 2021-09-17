#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void trstr(char *c_str, char orig, char rep) {
  while (*c_str != '\0') {
    if (*c_str == orig) {
      *c_str = rep;
    }
    ++c_str;
  }
}

void func(void) {
  char *env = getenv("TEST_ENV");
  if (env == NULL) {
    /* Handle error */
    return;
  }
  printf("%s\n", env);
  trstr(env,'"', '_');
  printf("%s\n", env);
}

int main(void) {
  char *env;
  // Stub the environment
  setenv("TEST_ENV", "I \"love\" you", 1);
  // Test noncompliant
  func();
  // Check
  env = getenv("TEST_ENV");
  printf("check: %s\n", env);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_ENV30-C_noncompliant.c
// C17: https://cigix.me/c17#7.22.4.6.p4
// UB: "The string set up by the getenv or strerror function is modified by the program"
