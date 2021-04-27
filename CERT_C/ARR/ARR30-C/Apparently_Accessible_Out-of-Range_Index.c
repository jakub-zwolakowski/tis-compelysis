#include <stddef.h>
#define COLS 5
#define ROWS 7
static int matrix[ROWS][COLS];

void init_matrix_noncompliant(int x) {
  for (size_t i = 0; i < COLS; i++) {
    for (size_t j = 0; j < ROWS; j++) {
      matrix[i][j] = x;
    }
  }
}

void init_matrix_compliant(int x) {
  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLS; j++) {
      matrix[i][j] = x;
    }
  }
}

void main(void) {
  init_matrix_compliant(42);
  init_matrix_noncompliant(42);
}
