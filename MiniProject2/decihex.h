#pragma once

// returns the number of digits required to fit a decimal number in hexadecimal
int digitsDecihex(int num) {
    int digCount = 0;
    for (; num > 0; num /= 16) digCount++;
    return digCount;
}

// fills hex[] with the hexidecimal characters in uppercase
void decihex(int num, char hex[]) {
    int digCount = 0;
    for (; num > 0; digCount++, num /= 16) {
        int digit = num % 16;

        hex[digCount] = (digit < 10) ? ((char)digit + '0') : ((char)(digit - 10) + 'A');
    }

    hex[digCount] = '\0';
}