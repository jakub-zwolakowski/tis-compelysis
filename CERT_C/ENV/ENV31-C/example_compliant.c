#include <stdio.h>
#include <stdlib.h>
  
extern char **environ;
 
int func(void) {
  if (setenv("MY_NEW_VAR", "new_value", 1) != 0) {
    /* Handle error */
    return 0;
  }
  if (environ != NULL) {
    for (size_t i = 0; environ[i] != NULL; ++i) {
      puts(environ[i]);
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
  func();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: ?
// UB: ?
