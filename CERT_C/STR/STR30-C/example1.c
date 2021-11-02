void f_noncompliant() {
  char *str  = "string literal";
  str[0] = 'S';
}

void f_compliant() {
  char str[] = "string literal";
  str[0] = 'S';
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
