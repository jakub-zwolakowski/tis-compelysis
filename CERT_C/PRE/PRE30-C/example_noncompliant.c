#define assign(uc1, uc2, val) uc1##uc2 = val
 
void func(void) {
  int \u0401;
  /* ... */
  assign(\u04, 01, 4);
  /* ... */
}

int main(void) {
  func();
  return 0;
}

// DETECTED! BUT ALSO FALSE POSITIVE...
// CMD: tis-analyzer --interpreter test_PRE30-C_noncompliant.c
// C17: https://cigix.me/c17#5.1.1.2 bullet point 4
// UB: "Token concatenation produces a character sequence matching the syntax of a universal character name"
