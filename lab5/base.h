#pragma once
#include <math.h>
#include <stdio.h>

/**
 * Converts a number from a base-b to base-10.
 */
int convertToOrFromBase10(int n, int b, int istoTen) {
  int b2;
  if (istoTen) {
    b2 = b;
    b = 10;
  } else {
    b2 = 10;
  }

  int nResult = 0;
  for (int power = 0; n > 0; power++) {
    int digit = n % b;
    n /= b;
    nResult += digit * (int)pow(b2, power);
  }

  return nResult;
}