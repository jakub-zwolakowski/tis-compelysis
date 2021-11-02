// USELESS: malloc never fails.

#include <string.h>
#include <stdlib.h>

char *my_malloc(size_t size) {
  return NULL;
}

char *init_block_noncompliant(size_t block_size, size_t offset,
                              char *data, size_t data_size) {
  char *buffer = my_malloc(block_size);
  if (data_size > block_size || block_size - data_size < offset) {
    /* Data won't fit in buffer, handle error */
    return NULL;
  }
  memcpy(buffer + offset, data, data_size);
  return buffer;
}

char *init_block_compliant(size_t block_size, size_t offset,
                           char *data, size_t data_size) {
  char *buffer = my_malloc(block_size);
  if (NULL == buffer) {
    /* Handle error */
    return NULL;
  }
  if (data_size > block_size || block_size - data_size < offset) {
    /* Data won't fit in buffer, handle error */
    return NULL;
  }
  memcpy(buffer + offset, data, data_size);
  return buffer;
}

int main(void) {
  char data[] = "Foo";
  char *block1 = init_block_compliant(7, 0, data, sizeof (data));
  char *block2 = init_block_noncompliant(7, 0, data, sizeof (data));
  return 0;
}
