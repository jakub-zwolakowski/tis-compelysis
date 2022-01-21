#include <stdio.h>
#include <string.h>

#define FILENAME "my_file"
#define BUFFERSIZE 42

int main(void) {
    // Prepare the file
    FILE *file;
    if ((file = fopen(FILENAME, "w")) == NULL) {
        /* Handle error */
        return 1;
    }
    fclose(file);
    // Open the file for reading
    if ((file = fopen(FILENAME, "r")) == NULL) {
        return 1;
    }
    // Test
    int rc;
    fpos_t offset;
    memset(&offset, 0, sizeof(offset));
    rc = fsetpos(file, &offset); // UB
    if (rc != 0) {
        return rc;
    }
    // Close the file
    fclose(file);
    // Goodbye
    return 0;
}
