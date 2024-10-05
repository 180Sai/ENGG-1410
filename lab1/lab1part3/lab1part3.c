#include <stdio.h>

int main(void) {
  const double KG_PER_POUND = 2.2;
  const double OUNCES_PER_POUND = 16.0;
  double weight;

  printf(" Please enter a weight in kilograms : ");
  scanf("%lf", &weight);

  double weightInPounds = weight * KG_PER_POUND;

  int poundsNoDecimal = weightInPounds;

  double totalOunces = (weightInPounds - poundsNoDecimal) * OUNCES_PER_POUND;
  int ounces = totalOunces;
  totalOunces = totalOunces - ounces;

  printf("%d pounds , %d ounces , %.2f ounces remainder \n", poundsNoDecimal,
         ounces, totalOunces);
}