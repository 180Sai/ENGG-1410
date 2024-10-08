#include <stdbool.h>
#include <stdio.h>

/**
 * Prompts the user for a sequence of characters that create an arithmetic expression composed of summation.
 * (e.g. 1 + 2 + 3 + 5 - 3 - 2 - 10) The program validates that the sequence creates a proper expression.
 *
 */
int main(void)
{
    char userChar;
    int sum = 0, sign = 1; // sign initialized to 1 for positive
    bool number = true;
    printf("Enter sequence of characters with numbers to add/subtract: ");
    scanf(" %c", &userChar);
    do
    {
        if (number)
        {
            while (userChar < '0' || userChar > '9')
            {
                printf("Invalid! Re-enter number.\n");
                scanf(" %c", &userChar);
            }
            sum += sign * (userChar - '0');
            number = false;
        }
        else
        {
            while (userChar != '+' && userChar != '-')
            {
                printf("Invalid! Re-enter sign.\n");
                scanf("%c", &userChar);
            }
            sign = (userChar == '+') ? 1 : -1;
            number = true;
        }
        scanf(" %c", &userChar);
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
