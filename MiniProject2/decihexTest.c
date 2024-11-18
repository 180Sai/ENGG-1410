#include "decihex.h"
#include <stdio.h>
#include <string.h>

// minimum, maximum range of tested unsigned decimal integers
#define TEST_MIN -200
#define TEST_MAX 200

// tests the functionality of decihex.h
int main(void) {

    for (int i = TEST_MIN; i <= TEST_MAX; i++) {
        // test decihex() function
        char hex[hlen(i)];
        decihex(i, hex);

        // test hexdeci() function
        int deci;
        hexdeci(hex, &deci, (int)strlen(hex));

        printf("%d->\033[38;2;255;215;0m%s\033[0m->%d", i, hex, deci);

        printf("%s", (i % 5) ? " ... " : "\n");
    }
}
