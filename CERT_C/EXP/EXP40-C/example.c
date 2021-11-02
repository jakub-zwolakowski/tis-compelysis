const int **ipp_noncompliant;
int *ip_noncompliant;
const int i_noncompliant = 42;

void f_noncompliant(void) {
  ipp_noncompliant = &ip_noncompliant; /* Constraint violation */
  *ipp_noncompliant = &i_noncompliant; /* Valid */
  *ip_noncompliant = 0;   /* Modifies constant i (was 42) */
}

int **ipp_compliant;
int *ip_compliant;
int i_compliant = 42;

void f_compliant(void) {
  ipp_compliant = &ip_compliant; /* Valid */
  *ipp_compliant = &i_compliant; /* Valid */
  *ip_compliant = 0; /* Valid */
}

int main(void) {
  f_compliant();
  f_noncompliant();
  return 0;
}
