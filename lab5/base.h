#pragma once
#include <math.h>
#include <stdio.h>

/**
 * Converts a number from a base-b to base-10.
 *
 * Numbers can be converted from base-10 to base-b by repeatedly:
 * (a) dividing the base-10 number by b and
 * (b) multiplying the remainder by increasing powers of 10, starting from 0.
 *
 * Converting from base-b to base-10 instead divides by 10 and multiplies the remainder by increasing powers (start from 0) of b.
 */
int ctofb10(int n, int b, int istoTen)
{
  int b2;
  if (istoTen) // if true then convert base-b to 10, else convert to base-10 to b
  {
    b2 = b; // b2 is the base to start from
    b = 10; // b is the base to end with (divisor)
  }
  else
  {
    b2 = 10;
  }

  int nResult = 0;                    // final number
  for (int power = 0; n > 0; power++) // keeep dividing by b until n is 0; increment power by 1 every iteration
  {
    int digit = n % b;
    n /= b;
    nResult += digit * (int)pow(b2, power); // multiply remainder by the b2^power
  }

  return nResult;
}