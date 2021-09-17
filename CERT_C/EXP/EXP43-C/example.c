int *restrict a_noncompliant;
int *restrict b_noncompliant;
 
int c_noncompliant[42];
extern int c_noncompliant[];
  
int main_noncompliant(void) {
  c_noncompliant[0] = 17;
  c_noncompliant[1] = 18;
  a_noncompliant = &c_noncompliant[0];
  b_noncompliant = &c_noncompliant[1];
  a_noncompliant = b_noncompliant; /* Undefined behavior */
  /* ... */
  return 0;
}

int *a_compliant;
int *b_compliant;
 
int c_compliant[42];
extern int c_compliant[];
  
int main_compliant(void) {
  c_compliant[0] = 17;
  c_compliant[1] = 18;
  a_compliant = &c_compliant[0];
  b_compliant = &c_compliant[1];
  a_compliant = b_compliant; /* Defined behavior */
  /* ... */
  return 0;
}

int main(void) {
  main_compliant();
  main_noncompliant();
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_EXP43-C.c
// C17: https://cigix.me/c17#6.7.3.1
// UB: "A restrict-qualified pointer is assigned a value based on another restricted pointer whose associated block neither began execution before the block associated with this pointer, nor ended before the assignment"
