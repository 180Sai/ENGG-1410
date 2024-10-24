#pragma once
#include "base.h"

int ctofb10(int n, int b, int istoTen) {
  return convertToOrFromBase10(n, b, istoTen);
}

int operate(char o, int b1, int n1, int n2, int b2) {
  n1 = convertToOrFromBase10(n1, b1, 1);
  n2 = convertToOrFromBase10(n2, b1, 1);

  return o == '+' ? ctofb10(add(n1, n2), b2, 0)
                  : (o == '-' ? ctofb10(sub(n1, n2), b2, 0)
                              : (o == '*' ? ctofb10(mult(n1, n2), b2, 0)
                                          : ctofb10(div(n1, n2), b2, 0)));
}

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mult(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }