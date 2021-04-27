#include <stdlib.h>
#include <string.h>

enum { SIG_DESC_SIZE = 32 };

typedef struct {
  char sig_desc[SIG_DESC_SIZE];
} signal_info;

void f_noncompliant(size_t num_of_records, size_t temp_num,
                    const char *tmp2, size_t tmp2_size_bytes) {
  signal_info *start = (signal_info *)calloc(num_of_records,
                                          sizeof(signal_info));

  if (tmp2 == NULL) {
    /* Handle error */
    return;
  } else if (temp_num > num_of_records) {
    /* Handle error */
    return;
  } else if (tmp2_size_bytes < SIG_DESC_SIZE) {
    /* Handle error */
    return;
  }

  signal_info *point = start + temp_num - 1;
  memcpy(point->sig_desc, tmp2, SIG_DESC_SIZE);
  point->sig_desc[SIG_DESC_SIZE - 1] = '\0';
  /* ... */
  free(start);
}

void f_compliant(size_t num_of_records, size_t temp_num,
                 const char *tmp2, size_t tmp2_size_bytes) {
  signal_info *start = (signal_info *)calloc(num_of_records,
                                           sizeof(signal_info));
  if (start == NULL) {
    /* Handle allocation error */
    return;
  } else if (tmp2 == NULL) {
    /* Handle error */
    return;
  } else if (temp_num > num_of_records) {
    /* Handle error */
    return;
  } else if (tmp2_size_bytes < SIG_DESC_SIZE) {
    /* Handle error */
    return;
  }

  signal_info *point = start + temp_num - 1;
  memcpy(point->sig_desc, tmp2, SIG_DESC_SIZE);
  point->sig_desc[SIG_DESC_SIZE - 1] = '\0';
  /* ... */
  free(start);
}

const char tmp2[512];

void main(void) {
  size_t num_of_records = 42;
  size_t temp_num = 1;
  size_t tmp2_size_bytes = sizeof tmp2;
  f_compliant(num_of_records, temp_num, tmp2, tmp2_size_bytes);
  f_noncompliant(num_of_records, temp_num, tmp2, tmp2_size_bytes);
}
