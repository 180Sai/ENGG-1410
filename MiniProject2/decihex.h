#pragma once

// returns the number of digits required to fit a decimal number in hexadecimal
int digitsDecihex(int num) {
    int digCount = 0;
    for (; num > 0; num /= 16) digCount++;
    return digCount;
}

// fills string hex[] with the hexidecimal characters in uppercase
void decihex(int num, char hex[]) {
    int digCount = 0;
    for (; num > 0; digCount++, num /= 16) {
        int digit = num % 16;

        hex[digCount] = (digit < 10) ? ((char)digit + '0') : ((char)(digit - 10) + 'A');
    }

    hex[digCount] = '\0';
}

// converts string num[] to decimal
void hexdeci(char num[], int *deci) {
    for (int i = 0; i < sizeof(num); i++) {
        if (num[i] == '\0') break;
        *deci += (num[i] - 'A' < 0) ? (int)(num[i] - '0') : (int)(num[i] - 'A');
    }
}