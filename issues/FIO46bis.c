#include <stdio.h>

int main() {
    fclose(stdout);
    fputs("Undefined behaviour is about to occur", stdout);
    return 0;
}