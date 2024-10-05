#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;
    double dot_product, magnitude_A, magnitude_B, cos_theta, theta_radian, theta_degree;

    // Prompting user for coordinates of point A
    printf("Enter point A as (x1,y1): ");
    scanf("%lf,%lf", &x1, &y1);

    // Prompting user for coordinates of point B
    printf("Enter point A as (x2,y2): ");
    scanf("%lf,%lf", &x2, &y2);

    // enter your logic below this line.


    // Calculate the terms of vectors OA and OB

    dot_product = (x1*x2+y1*y2)/(sqrt(x1 * x1 + y1 * y1)*sqrt(x2 * x2 + y2 * y2));

    // Calculate the magnitudes of vectors OA and OB
    magnitude_A = sqrt(x1 * x1 + y1 * y1); //this one is done for you. Write equation for magnitube_B below

    magnitude_B = sqrt(x2 * x2 + y2 * y2);

    // Calculate cos(θ) using the cosine rule

    cos_theta = dot_product;

    // Calculate the angle θ in radians

    theta_radian = acos(cos_theta);

    // Convert the angle from radians to degrees

    theta_degree = theta_radian * (180/M_PI);

    // Output the angle in both radians and degrees
    printf("The angle theta between the two points is: %.3f radian or %.2f degree\n", theta_radian, theta_degree);

    return 0;
}
