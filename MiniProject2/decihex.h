#pragma once
#include <math.h>
#include <string.h>

// returns the number of digits required to fit a decimal number in hexadecimal
int digitsDecihex(int deci) {
    int digCount = 0;
    for (; deci > 0; deci /= 16) digCount++;
    return digCount;
}

// fills string hex[] with the hexidecimal characters (uppercase) of unsigned decimal integer
void decihex(int deci, char *hex) {
    int digCount = 0;
    do {
        int digit = deci % 16;

        char number = (char)digit + '0', letter = (char)digit - 10 + 'A';
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

// converts string num[] to decimal
void hexdeci(char *hex, int *deci, int hexlen) {
    *deci = 0;

    for (int i = hexlen - 1; i >= 0; i--) {
        int number = hex[i] - '0', letter = hex[i] - 'A';
        int digit = (letter < 0) ? number : letter + 10;

        *deci += digit * (int)pow(16, hexlen - 1 - i);
    }
}