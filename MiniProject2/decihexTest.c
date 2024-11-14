#include "decihex.h"
#include <stdio.h>
#include <string.h>

// minimum, maximum range of tested unsigned decimal integers
#define TEST_MIN 0
#define TEST_MAX 2000

// tests the functionality of decihex.h.
int main(void) {
    for (int i = 0; i < 200; i++) {
        char hex[digitsDecihex(i)];
        decihex(i, hex);

        if (i % 10 != 0 || i == 0)
            printf("%d ->\033[38;2;255;215;0m %s \033[0m| ", i, hex);
        else
            printf("%d ->\033[38;2;255;215;0m %s\033[0m\n", i, hex);
    }
}
