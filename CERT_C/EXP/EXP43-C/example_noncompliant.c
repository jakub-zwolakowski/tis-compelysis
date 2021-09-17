int *restrict a;
int *restrict b;
 
int c[42];
extern int c[];
  
int main(void) {
  c[0] = 17;
  c[1] = 18;
  a = &c[0];
  b = &c[1];
  a = b; /* Undefined behavior */
  /* ... */
  return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter test_EXP43-C_noncompliant.c
// C17: https://cigix.me/c17#6.7.3.1
// UB: "A restrict-qualified pointer is assigned a value based on another restricted pointer whose associated block neither began execution before the block associated with this pointer, nor ended before the assignment"
