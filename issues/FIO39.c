#include <stdio.h>
#include <string.h>

#define WRITE_BUFFER_SIZE 4
#define READ_BUFFER_SIZE 2

int main(void) {
    const char *file_name = "my_file";
    char data[READ_BUFFER_SIZE];
    char append_data[WRITE_BUFFER_SIZE];
    FILE *file;
    memset(append_data, 42, WRITE_BUFFER_SIZE);
    // Open for reading and updating, read, then write, then close.
    if ((file = fopen(file_name, "a+")) == NULL) {
        printf("fopen error\n");
        return 1;
    }
    if (fread(data, 1, READ_BUFFER_SIZE, file) < READ_BUFFER_SIZE) {
        printf("fread error\n");
        return 2;
    }
    if (fwrite(append_data, 1, WRITE_BUFFER_SIZE, file) != WRITE_BUFFER_SIZE) {
        printf("fwrite error\n");
        return 3;
    }
    if (fclose(file) == EOF) {
        printf("fclose error\n");
        return 4;
    }
    printf("done!\n");
    return 0;
}
