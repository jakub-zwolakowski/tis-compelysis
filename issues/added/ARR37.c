struct s {
  short x, y;
};

int main(int c) {
  // Array
  int arr[] = { 42, 0 };
  int *int_array_ptr = &(arr[0]);
  // Variable
  int i = 42;
  int *int_variable_ptr = &i;
  // Structure
  struct s s = { 42, 0 };
  short *struct_field_ptr = &s.x;

  switch(c) {
  case 0:
    // Array
    int_array_ptr++; // OK!
    return *int_array_ptr;
  case 1:
    // Variable
    int_variable_ptr++; // UB
    return 0;
  case 2:
    // Structure
    struct_field_ptr++; // UB
    return *struct_field_ptr;
  }
  return 0;
}
