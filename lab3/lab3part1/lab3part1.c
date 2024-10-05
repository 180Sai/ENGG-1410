#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    double discriminant, root1, root2;

    printf("Enter values for a, b, c: (in the format \"a b c\")\n");
    scanf("%d %d %d", &a, &b, &c);

    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        printf("The roots are imaginary.");
    else
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        if (discriminant == 0)
            printf("The roots are real and equal.\n\
            Root 1 = Root 2: %f",
                   root1);
        else
            printf("The roots are real and distinct.\nRoot 1: %.2f\nRoot 2: %.2f", root1, root2);
    }

    return 0;
}
