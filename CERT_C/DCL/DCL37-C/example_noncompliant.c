#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_
 
/* Contents of <my_header.h> */
int f(void);

#endif /* _MY_HEADER_H_ */

int f(void) {
  return 42;
}

int main(void) {
  f();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_DCL37-C_noncompliant.c
// C17: https://cigix.me/c17#7.1.3.p2
// UB: "The program declares or defines a reserved identifier, other than as allowed by 7.1.4 (7.1.3)."

