#include <stdio.h>
#include <math.h>

int main() {
  int u, l;
  while (1) {
    printf("Enter the lower and upper bounds of the interval: ");
    scanf("%d %d", &l, &u);
    if (l > u)
      printf("Invalid Input\n");
    else if (l > 0 && u > 0)
      break;
  }

  printf("Prime numbers in the interval [%d, %d]: ", l, u);
  for (l; l < u+1; l++) 
  {
        int prime = 1;
        if(l < 2)
            continue;
        for(int i = 2; i <= sqrt(l); i++)
        {
            if((l%i) == 0)
            {
                prime = 0;
                break;
            }
        }
        if(prime)
            printf("%d, ", l);
  }
}