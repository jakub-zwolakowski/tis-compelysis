#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum { MAX_ALLOCATION = 1000 };

int f_noncompliant(int argc, const char *argv[]) {
  char *c_str = NULL;
  size_t len;

  if (argc == 2) {
    len = strlen(argv[1]) + 1;
    if (len > MAX_ALLOCATION) {
      /* Handle error */
      return EXIT_FAILURE;
    }
    c_str = (char *)malloc(len);
    if (c_str == NULL) {
      /* Handle error */
      return EXIT_FAILURE;
    }
    strcpy(c_str, argv[1]);
  } else {
    c_str = "usage: $>a.exe [string]";
    printf("%s\n", c_str);
  }
  free(c_str);
  return 0;
}

int f_compliant(int argc, const char *argv[]) {
  char *c_str = NULL;
  size_t len;

  if (argc == 2) {
    len = strlen(argv[1]) + 1;
    if (len > MAX_ALLOCATION) {
      /* Handle error */
      return EXIT_FAILURE;
    }
    c_str = (char *)malloc(len);
    if (c_str == NULL) {
      /* Handle error */
      return EXIT_FAILURE;
    }
    strcpy(c_str, argv[1]);
  } else {
    printf("%s\n", "usage: $>a.exe [string]");
    return EXIT_FAILURE;
  }
  free(c_str);
  return 0;
}

void main(void) {
  char *argv[2];
  argv[0] = "Foo";
  argv[1] = "Bar";
  f_compliant(2, argv);
  f_compliant(1, argv);
  f_noncompliant(2, argv);
  f_noncompliant(1, argv);
}
