#include <stdio.h>

int main(void) {
  int encComb;
  printf("Enter an encrypted 4 - digit combination :");
  scanf("%d", &encComb);

  // Determine the 4 digits of the encrypted combinaiton .
  int d4 = 0, d3 = 0, d2 = 0, d1 = 0;
  d4 = encComb / 1000;

  encComb = encComb % 1000;
  d3 = encComb / 100;

  encComb = encComb % 100;
  d2 = encComb / 10;

  encComb = encComb % 10;
  d1 = encComb;

  // printing the decryped combination : d4 and d1 are swaped .
  // d3 and d2 are 9 s complemented
  printf("\n The real combination is : %d%d%d%d \n ", d1, 9-d3, 9-d2, d4);

  return 0;
}