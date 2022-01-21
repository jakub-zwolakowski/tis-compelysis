#include <stdlib.h>
#include <stdio.h>

#define ENV_VAR "TEST_ENV"

int main(void) {
  // Stub the environment
  setenv(ENV_VAR, "I \"love\" you", 1);
  // Get the environment
  char *env = getenv(ENV_VAR);
  if (env == NULL) {
    /* Handle error */
    return 1;
  }
  printf("%s\n", env);
  // Modify the string
  env[2] = '_';
  env[7] = '_';
  printf("%s\n", env);
  // Get the environment again
  env = getenv(ENV_VAR);
  printf("%s\n", env);
  return 0;
}
