#pragma once
#include <math.h>
#include <string.h>

// macro for error handling (out of bounds)
#ifdef DECIHEX_WARNING_ENABLE
#include <stdio.h>
#endif

// length of string created by decihex
int hlen(int deci) {
    int length = 0;
    do {
        length++;
        deci /= 16;
    } while (deci > 0);

    return length + 1;
}

// fills string hex[] with hexidecimal characters (uppercase) of unsigned decimal integer
void decihex(int deci, char *hex) {
// macro for negative decimal number warning
#ifdef DECIHEX_WARNING_ENABLE
    if (deci < 0)
        printf("\n\033[38;2;238;210;2m\twarning: decimal number is out of bounds\033[0m\n");
#endif

    int digCount = 0;
    do {
        int digit = deci % 16;

        char number = (char)digit + '0',
             letter = (char)digit - 10 + 'A';
        hex[digCount] = (digit < 10) ? number : letter;

        deci /= 16, digCount++;
    } while (deci > 0);

    // digits are currently in reverse order - convert to proper
    char hextmp[digCount + 1];
    strcpy(hextmp, hex);

    for (int i = 0; i < digCount; i++) {
        hex[i] = hextmp[digCount - 1 - i];
    }
    hex[digCount] = '\0';
}

// converts string hex[] to decimal
void hexdeci(char *hex, int *deci, int hexlen) {
// macro for undefined hexadecimal character warning
#ifdef DECIHEX_WARNING_ENABLE
    for (int i = 0; i < hexlen; i++)
        if (!(hex[i] >= '0' && hex[i] <= '9') && !(hex[i] >= 'A' && hex[i] <= 'F')) {
            printf("\n\033[38;2;238;210;2m\twarning: hexadecimal number is out of bounds\033[0m\n");
            break;
        }
#endif

    *deci = 0;

    for (int i = hexlen - 1; i >= 0; i--) {
        int number = (int)hex[i] - '0',
            letter = (int)hex[i] - 'A';
        int digit = (letter < 0) ? number : letter + 10;

        *deci += digit * (int)pow(16, hexlen - 1 - i);
    }
}