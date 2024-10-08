#include <stdio.h>

/**
 * 2024-10-08 ENGG-1410 Lab 4
 * Implements the series that estimates pi.
 * Calculates the value based on the number of terms (prompts user).
 */
int main(void)
{
    int termCount;
    double pi = 0;
    printf("Enter the number of terms for pi approximation: ");
    scanf("%d", &termCount);

    if (termCount > 0)
    {
        printf("The input is invalid.");
        return 0;
    }

    for (int i = 0; i <= termCount; i++)
    {
        pi += (i % 2 == 0 ? 1 : -1) / ((double)1 + i * 2);
    }

    pi *= 4;
    printf("Estimated value of pi after %d terms: %.3f", termCount, pi);

    return 0;
}