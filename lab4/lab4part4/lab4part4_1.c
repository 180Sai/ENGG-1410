#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/**
 * Prompts the user for a sequence of characters that create an arithmetic expression composed of summation.
 * (e.g. 1 + 2 + 3 + 5 - 3 - 2 - 10) The program validates that the sequence creates a proper expression.
 *
 */
int main(void)
{
    char userChar;
    int number = 0;
    int sum = 0, sign = 1; // sign initialized to 1 for positive
    bool isAcceptSign = true;
    printf("Enter sequence of characters with numbers to add/subtract.\nUse \"=\" to finish.\n");

    do
    {
        scanf(" %c", &userChar);
        if (userChar == '=')
            break;

        if (isAcceptSign && !(userChar >= '0' && userChar <= '9'))
        { // is a sign and is accepting sign
            if (userChar != '+' && userChar != '-')
            {
                printf("Invalid! Re-enter sign.\n");
                continue;
            }
            sum += sign * number;
            sign = (userChar == '+') ? 1 : -1;
            number = 0;
            isAcceptSign = false;
        }
        else
        { // is a number
            if (userChar < '0' || userChar > '9')
            {
                printf("Invalid! Re-enter number.\n");
                continue;
            }
            number +=
                (number == 0) ? (userChar - '0')
                              : (userChar - '0') * (int)pow(10, log10(number + 1));
            isAcceptSign = true;
        }
    } while (sum >= 0);

    if (sum < 0)
    {
        printf("Sum fell below zero.\n");
    }
    else
    {
        printf("The sum is %d.", sum);
    }

    return 0;
}
