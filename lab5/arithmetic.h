#pragma once
#include "base.h"

int operate(char o, int b1, int n1, int n2, int b2)
{
  n1 = ctofb10(n1, b1, 1); // take the first number and convert it from base b1 to base 10
  n2 = ctofb10(n2, b1, 1); // take the second number and convert it from to base 10

  // nested ternary operator switches between different operators
  // returns final number to desired base (b2)
  return o == '+' ? ctofb10(add(n1, n2), b2, 0)                            // operator is '+': convert sum of n1, n2 from base 10 to base b2
                  : (o == '-' ? ctofb10(sub(n1, n2), b2, 0)                // operator is '-': convert difference of n1-n2 to base b2
                              : (o == '*' ? ctofb10(mult(n1, n2), b2, 0)   // operator is '*': convert product of n1, n2 to base b2
                                          : ctofb10(div(n1, n2), b2, 0))); // operator is (implied) '/': convert quotient of n1/n2 to base b2
}

// add a and b
int add(int a, int b) { return a + b; }

// subtract b from a
int sub(int a, int b) { return a - b; }

// multiply a and b
int mult(int a, int b) { return a * b; }

// divide a by b
int div(int a, int b) { return a / b; }