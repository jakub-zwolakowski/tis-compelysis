static int I_noncompliant = 12;
extern inline void func_noncompliant(int a) {
  int b = a * I_noncompliant;
  /* ... */
}

int I_compliant = 12;
extern inline void func_compliant(int a) {
  int b = a * I_compliant;
  /* ... */
}

void main(void) {
  func_compliant(42);
  func_noncompliant(42);
}

// DOES NOT WORK
