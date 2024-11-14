#pragma once

// returns the number of digits required to fit a decimal number in hexadecimal
int digitsDecihex(int deci) {
    int digCount = 0;
    for (; deci > 0; deci /= 16) digCount++;
    return digCount;
}

// fills string hex[] with the hexidecimal characters in uppercase
void decihex(int deci, char hex[]) {
    int digCount = 0;
    for (; deci > 0; digCount++, deci /= 16) {
        int digit = deci % 16;

        hex[digCount] = (digit < 10) ? ((char)digit + '0') : ((char)(digit - 10) + 'A');
    }

    hex[digCount] = '\0';
}

// converts string num[] to decimal
void hexdeci(char hex[], int *deci) {
    for (int i = 0; i < sizeof(hex); i++) {
        if (hex[i] == '\0') break;
        *deci += (hex[i] - 'A' < 0) ? (int)(hex[i] - '0') : (int)(hex[i] - 'A');
    }
}