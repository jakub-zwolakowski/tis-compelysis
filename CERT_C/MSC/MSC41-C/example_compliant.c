#include <stdio.h>
#include <string.h>

/* Returns nonzero if authenticated */
extern int authenticate(const char* code);
 
int main() {
#define CODE_LEN 50
  char code[CODE_LEN];
  printf("Please enter your authentication code:\n");

  FILE *fp;
  fp = fopen("code_file" , "r");
  if(fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fgets(code, sizeof(code), fp);

  fclose(fp);

  int flag = authenticate(code);
  memset(code, 0, sizeof(code));
  if (!flag) {
    printf("Access denied\n");
    return -1;
  }
  printf("Access granted\n");
  // ...Work with system...
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c example_auth.c
// C17: ?
// UB: ?
