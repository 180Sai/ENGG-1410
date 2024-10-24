#include <stdio.h>
#include <time.h>

// self made headers to be removed after testing completion
#include "arithmetic.h"
#include "inputValidation.h"

int main() {
  while (1 > 0) {
    char o = 'f';
    int b1;
    int n1;
    int n2;
    int b2;

    switch (VaildInput(&o, &b1, &n1, &n2, &b2)) {
      case 0:
        break;

      case 2:
        return 0;
        break;

      default:
        printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", n1, o, n2, b1,
               ctofb10(n1, b1, 1), o, ctofb10(n2, b1, 1),
               operate(o, b1, n1, n2, b2), b2);
        break;
    }
  }
}

/*
- 6 205 43 7
& 9 74 57 10
/ 9 74 57 10
% 2 10 01 8
+ 2 10 01 8
$
*/