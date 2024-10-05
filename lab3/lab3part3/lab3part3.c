#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int dice1, dice2, sum;
//   char play_again;
  srand(2);  // Seed the random number generator


  dice2 = rand()%6 + 1;
  dice1 = rand()%6 + 1;
  sum = dice1 + dice2;


  printf("You rolled a %d and a %d.\n", dice1, dice2);
  printf("The sum is %d.\n", sum);

  if (sum == 7 || sum == 11) 
  {
    printf("You win!\n");
  } 
  else if ( sum == 2 || sum == 3 || sum == 12) 
  {
    printf("You lose!\n");
  } 
  else 
  {
    printf("No win or loss, play again.\n");
  }
  return 0;
}
