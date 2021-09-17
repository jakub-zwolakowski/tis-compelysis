#ifndef MY_HEADER_H
#define MY_HEADER_H
 
/* Contents of <my_header.h> */
int f_compliant(void);
 
#endif /* MY_HEADER_H */

#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_
 
/* Contents of <my_header.h> */
int f_noncompliant(void);

#endif /* _MY_HEADER_H_ */

int f_compliant(void) {
  return 42;
}

int f_noncompliant(void) {
  return 42;
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_DCL37-C.c
// C17: https://cigix.me/c17#7.1.3.p2
// UB: "The program declares or defines a reserved identifier, other than as allowed by 7.1.4 (7.1.3)."

