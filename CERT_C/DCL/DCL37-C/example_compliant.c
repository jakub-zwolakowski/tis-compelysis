#ifndef MY_HEADER_H
#define MY_HEADER_H
 
/* Contents of <my_header.h> */
int f(void);
 
#endif /* MY_HEADER_H */

int f(void) {
  return 42;
}

int main(void) {
  f();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_DCL37-C_compliant.c
// C17: https://cigix.me/c17#7.1.3.p2
// UB: "The program declares or defines a reserved identifier, other than as allowed by 7.1.4 (7.1.3)."

