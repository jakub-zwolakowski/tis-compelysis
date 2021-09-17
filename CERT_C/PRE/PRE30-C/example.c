#define assign_noncompliant(uc1, uc2, val) uc1##uc2 = val
 
void func_noncompliant(void) {
  int \u0401;
  /* ... */
  assign_noncompliant(\u04, 01, 4);
  /* ... */
}

#define assign_compliant(ucn, val) ucn = val
  
void func_compliant(void) {
  int \u0401;
  /* ... */
  assign_compliant(\u0401, 4);
  /* ... */
}

int main(void) {
  func_compliant();
  func_noncompliant();
  return 0;
}

// DETECTED! BUT ALSO FALSE POSITIVE...
// CMD: tis-analyzer --interpreter test_PRE30-C.c
// C17: https://cigix.me/c17#5.1.1.2 bullet point 4
// UB: "Token concatenation produces a character sequence matching the syntax of a universal character name"
