static int i = 20; /* Definition, internal linkage */
int i; /* Undefined, linkage disagreement with previous */

static int j; /* Tentative definition, internal linkage */
int j; /* Undefined, linkage disagreement with previous */

int main(void) {
    return 0;
}
