#include <stdio.h>

int main(void)
{
    double x, y;

    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &x);

    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf", &y);

    int quad1 = ((x > 0) && (y > 0));
    int quad2 = ((x < 0) && (y > 0));
    int quad3 = ((x < 0) && (y < 0));
    // int quad4 = ((x > 0) && (y < 0));

    int yAxis = ((x==0));
    int xAxis = ((y==0));

    if(xAxis)
    {
        if(yAxis)
        {
            printf("(%lf, %lf) is on the origin.", x, y);
            return;
        }
        printf("(%lf, %lf) is on the x-axis.", x, y);
        return;
    }
    else if(yAxis)
    {
        printf("(%lf, %lf) is on the y-axis.", x, y);
        return;
    }
    else if (quad1)
    {
        printf("(%lf, %lf) is in quadrant I.", x, y);
        return;
    }
    else if (quad2)
    {
        printf("(%lf, %lf) is in quadrant II.", x, y);
        return;
    }
    else if (quad3)
    {
        printf("(%lf, %lf) is in quadrant III.", x, y);
        return;
    }

    printf("(%lf, %lf) is in quadrant IV.", x, y);
    return;

}