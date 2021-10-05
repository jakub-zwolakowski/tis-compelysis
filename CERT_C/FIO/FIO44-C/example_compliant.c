#include <stdio.h>
#include <string.h>

#define FILENAME "my_file"
#define BUFFERSIZE 42

int opener(FILE *file) {
    int rc;
    fpos_t offset;
    
    if (file == NULL) {
        return -1;
    }
    
    rc = fgetpos(file, &offset);
    if (rc != 0 ) {
        return rc;
    }
    
    /* Read in data from file */
    char data[BUFFERSIZE + 1];
    if (fread(data, 1, BUFFERSIZE, file) < BUFFERSIZE) {
        /* Handle there not being data */
        return 1;
    }
    data[BUFFERSIZE] = '\0';
    printf("fread in opener: %s\n", data);
    
    rc = fsetpos(file, &offset);
    if (rc != 0 ) {
        return rc;
    }
    
    return 0;
}

int prepare_file(void) {
    // Prepare the file
    FILE *file;
    file = fopen(FILENAME, "w");
    if (file == NULL) {
        /* Handle error */
        return 1;
    }
    char data[BUFFERSIZE];
    memset(data, 42, BUFFERSIZE);
    if (fwrite(data, BUFFERSIZE, 1, file) != 1) {
        /* Handle error */
        return 2;
    }
    fclose(file);
    return 0;
}

int main(void) {
    FILE *file;
    int ret;

    // Prepare file
    if((ret = prepare_file()) != 0) {
        return ret;
    };
    // Open the file for reading
    file = fopen(FILENAME, "r");
    // Test noncompliant
    opener(file);
    // Close the file
    fclose(file);

    return 0;
}

// NOT DETECTED
// CMD: tis-analyzer --interpreter example_compliant.c
// C17: https://cigix.me/c17#7.21.9.3.p2
// UB: "The fsetpos function is called to set a position that was not returned by a previous successful call to the fgetpos function on a stream associated with the same file (7.21.9.3)."
