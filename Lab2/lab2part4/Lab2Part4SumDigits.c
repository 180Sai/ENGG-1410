#include <stdio.h>
#include <math.h>

int main(void)
{
    int integer;

    printf("enter value between 1 and 99999: ");
    scanf("%d", &integer);

    integer = abs(integer);

    if(!(integer >= 1) || !(integer <= 99999))
    {
        printf("out of bounds, please enter value between 1 and 99999");
        return 0;
    }

    int tthousand, thousand, hun, ten, ones;
    tthousand = integer/10000;
    integer %= 10000;

    thousand = integer/1000;
    integer %= 1000;

    hun = integer/100;
    integer %= 100;

    ten = integer/10;
    integer %= 10;

    ones = integer;

    printf("the sum of the digits is: %d + %d + %d + %d + %d = %d", tthousand, thousand, hun, ten, ones, tthousand+thousand+hun+ten+ones);

    return 0;
}