#include <string.h>
#include <stdio.h>

int checkpass_noncompliant(const char *password) {
  if (strcmp(password, "pass") == 0) {
    return 1;
  }
}

void f_noncompliant(const char *userinput) {
  if (checkpass_noncompliant(userinput)) {
    printf("Success\n");
  }
}

int checkpass_compliant(const char *password) {
  if (strcmp(password, "pass") == 0) {
    return 1;
  }
  return 0;
}

void f_compliant(const char *userinput) {
  if (checkpass_compliant(userinput)) {
    printf("Success!\n");
  }
}

int main(void) {
  char pass[] = "pass";
  char not_a_pass[] = "Doom... Doom. Doooooom!!!";
  f_compliant(pass);
  f_noncompliant(pass);
  return 0;
}
