#include <stdio.h>

int main()
{
    int a = -1;
    int b = -1;
    do
    {
        printf("Enter two non-negative integers: ");
        scanf("%d %d", &a, &b);
    } while (a < 0 || b < 0);
    
    // do
    // {
    //     printf("please enter a positive integer: ");
    //     scanf("%d", &a);

    // } while (a < 0);

    // do
    // {
    //     printf("please enter another positive integer: ");
    //     scanf("%d", &b);

    // } while (b < 0);

    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int ra = a, rb =b;

    while (a != b)
    {
        if (a > b)
            a = a-b;
        else
            b = b-a;
    }
    

    printf("the gcd of %d, and %d is %d", ra, rb, a);
}