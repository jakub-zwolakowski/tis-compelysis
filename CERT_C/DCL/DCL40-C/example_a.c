/* In a.c */

extern int i_compliant;   /* UB 15 */

int f_compliant(void) {
  return ++i_compliant;   /* UB 37 */
}

extern int i_noncompliant;   /* UB 15 */

int f_noncompliant(void) {
  return ++i_noncompliant;   /* UB 37 */
}
