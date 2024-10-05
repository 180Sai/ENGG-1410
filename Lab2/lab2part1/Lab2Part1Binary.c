#include <stdio.h>

int main(void) {
  int integer;

  printf("Enter number to convert to base 2: ");
  scanf("%d", &integer);

  if (integer < 1 && integer > 15) {
    printf("we only take integer's that are more then 1 and less then 16");
    return 0;
  }

  int lastDigit = integer % 2;
  integer /= 2;

  int thirdDigit = integer % 2;
  integer /= 2;

  int secondDigit = integer % 2;
  integer /= 2;

  int firstDigit = integer % 2;
  integer /= 2;

  printf("The four digits of that number are as follows:\n");
  printf("Most significant digit: %d\n", firstDigit);
  printf("Next digit: %d\n", secondDigit);
  printf("Next digit: %d\n", thirdDigit);
  printf("Least significant digit: %d\n", lastDigit);

  return 0;
}
