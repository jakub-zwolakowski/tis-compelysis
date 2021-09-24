#include <stdio.h>

int main(void) {
    if (fclose(stdout) == EOF) {
        printf("oh no!\n");
        return 1;
    }
    printf("stdout successfully closed.\n");
    return 0;
}
