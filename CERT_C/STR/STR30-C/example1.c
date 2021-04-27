void f_noncompliant() {
  char *str  = "string literal";
  str[0] = 'S';
}

void f_compliant() {
  char str[] = "string literal";
  str[0] = 'S';
}

void main(void) {
  f_compliant();
  f_noncompliant();
}
