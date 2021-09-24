#include <stdlib.h>
#include <stdio.h>

int some_condition = 0;

void exit1(void) {
    printf("exit1\n");
    return;
}
  
void exit2(void) {
    printf("exit2\n");
    exit(0);
}

int main(void) {
    if (atexit(exit1) != 0) {
        return 1;
    }
    if (atexit(exit2) != 0) {
        return 2;
    }
    some_condition = 1;
    exit(0);
}
