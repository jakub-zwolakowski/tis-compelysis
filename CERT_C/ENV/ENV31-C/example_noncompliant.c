#include <stdio.h>
#include <stdlib.h>
  
int func(int argc, const char *argv[], const char *envp[]) {
  if (setenv("MY_NEW_VAR", "new_value", 1) != 0) {
    /* Handle error */
    return 0;
  }
  if (envp != NULL) {
    for (size_t i = 0; envp[i] != NULL; ++i) {
      puts(envp[i]);
    }
  }
  return 0;
}

int main(void) {
  int my_argc = 3;
  char *my_arg_1 = "I'm";
  char *my_arg_2 = "sorry";
  char *my_arg_3 = "Dave";
  const char *my_args[] = { my_arg_1, my_arg_2, my_arg_3, NULL };
  func(my_argc, my_args, my_args);
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_noncompliant.c
// C17: ?
// UB: ?
