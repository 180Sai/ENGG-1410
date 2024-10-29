#include <math.h>
#include <stdio.h>

// ENGG*1410*01016
// Eric Cao, Jeremiah George
// October 27, 2024

/**
 * validate input
 */
int VaildInput(char *o, int *b1, int *n1, int *n2, int *b2) {
    // takes in pointers so it can return multiple outputs
    // this is necessary as all scanf is placed in function instead of outside

    printf("Give input ($ to stop): "); // prompt for input
    scanf(" %c", o);                    // get input

    int notEsc = 50; // variable to exit after finishing read

    switch (*o) {
        // exit if no value has been read for o
        case 'f':
            printf("Invalid operator\n");
            notEsc = 0;
            return 0;
            break;
        case '+':
            // o is vaild no need to check if o is vaild exit switch
            break;
        case '-':
            // o is vaild no need to check if o is vaild exit switch
            break;
        case '*':
            // o is vaild no need to check if o is vaild exit switch
            break;
        case '/':
            // o is vaild no need to check if o is vaild exit switch
            break;
        case '$':
            return 2; // o is $ so return 2 to represent exit
            break;

        default:
            printf("Invalid operator\n");
            notEsc = 0;
    }

    scanf(" %d", b1); //" %d" takes input from previous line instead of waiting
                      // for user to type again
    scanf(" %d", n1); //" %d" takes input from previous line instead of waiting
                      // for user to type again
    scanf(" %d", n2); //" %d" takes input from previous line instead of waiting
                      // for user to type again
    scanf(" %d", b2); //" %d" takes input from previous line instead of waiting
                      // for user to type again

    // as previous lines will take input from previous input invaild operator must
    // be handeled after input so input is cleared
    if (notEsc != 50) {
        return 0; // return 0 to represent invalid input
    }

    // check if input base is in range
    if (*b1 < 2 || *b1 > 10) {
        printf("Invalid base\n");
        return 0; // return 0 to represent invalid input
    }

    // check if output base is in range
    if (*b2 < 0 || *b2 > 10) {
        printf("Invalid base\n");
        return 0; // return 0 to represent invalid input
    }

    // checks if every digit in the first number are in range zero to (input base - 1)
    int t1 = *n1;
    for (int i = 0; t1 > 0; i++) {
        int digit = t1 % 10;
        t1 /= 10;
        if (digit < 0 || digit > *b1) {
            printf("Invalid digits in operand\n");
            return 0; // return 0 to represent invalid input
        }
    }

    // checks if every digit in the second number are in range zero to (input base - 1)
    int t2 = *n2;
    for (int i = 0; t2 > 0; i++) {
        int digit = t2 % 10;
        t2 /= 10;
        if (digit < 0 || digit > *b1) {
            printf("Invalid digits in operand\n");
            return 0; // return 0 to represent invalid input
        }
    }

    return 1; // return 1 to represent valid input
}

// Converts a number from base-b to base-10 or vice versa.
int ctofb10(int n, int b, int istoTen) {
    int b2;
    if (istoTen) { // if true then convert from base b to 10, else convert from base 10 to b
        b2 = b;    // starting base
        b = 10;    // target base
    } else {
        b2 = 10;
    }

    int nResult = 0; // final number

    // keep dividing by target base until n is 0; increment power by 1 every iteration
    for (int power = 0; n > 0; power++) {
        int remainder = n % b;
        n /= b;
        nResult += remainder * (int)pow(b2, power); // multiply remainder by the (starting base) ^ power
    }

    return nResult;
}

// add a and b
int add(int a, int b) { return a + b; }

// subtract b from a
int sub(int a, int b) { return a - b; }

// multiply a and b
int mult(int a, int b) { return a * b; }

// divide a by b
int div(int a, int b) { return a / b; }

int operate(char o, int b1, int n1, int n2, int b2) {
    n1 = ctofb10(n1, b1, 1); // take the first number and convert it from base b1 to base 10
    n2 = ctofb10(n2, b1, 1); // take the second number and convert it from to base 10

    // nested ternary operator chooses based on which operator is given, returns final number in the desired base (b2)
    return o == '+' ? ctofb10(add(n1, n2), b2, 0)                            // operator is '+': convert sum of n1, n2 from base 10 to base b2
                    : (o == '-' ? ctofb10(sub(n1, n2), b2, 0)                // operator is '-': convert difference of n1-n2 to base b2
                                : (o == '*' ? ctofb10(mult(n1, n2), b2, 0)   // operator is '*': convert product of n1, n2 to base b2
                                            : ctofb10(div(n1, n2), b2, 0))); // operator is (implied) '/': convert quotient of n1/n2 to base b2
}

int main() {
    // run program forever
    while (1) {
        char o = 'f'; // if this does not change it means that scanf is not working
        int b1, n1, n2, b2;

        // check for vaild input
        // takes pointer as input is checked inside
        switch (VaildInput(&o, &b1, &n1, &n2, &b2)) {
            case 0:
                // function returned 0 representing the input being invalid
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