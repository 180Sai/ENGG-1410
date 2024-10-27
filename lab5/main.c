#include <stdio.h>
#include <time.h>

// self learned headers to be removed after testing completion
#include "arithmetic.h"
#include "inputValidation.h"

int main() {
  // run program forever
  while (1) {
    char o = 'f';  // if this does not change it means that scanf is not working
    int b1, n1, n2, b2;

    // check for vaild input
    // takes pointer as input is checked inside
    switch (VaildInput(&o, &b1, &n1, &n2, &b2)) {
      case 0:
        // this means the function returned 0 repersenting the input being
        // invalid
        break;

      case 2:
        // this means the function returned 2 meaning user wants to exit so
        // break out of loop
        return 0;
        break;

      default:
        // input is vaild so print output
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