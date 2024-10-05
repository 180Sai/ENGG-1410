#include <math.h>
#include <stdio.h>

int main(void) {
  double bill;        
  double percentage;  
  int numOfPeople; 

  printf("Enter the original bill amount: ");  
  scanf("%lf", &bill);                         

  printf("Enter the tip percentage: ");  
  scanf("%lf", &percentage);

  printf("Enter the number of people splitting the bill: ");  
                                                              
  scanf("%d", &numOfPeople);  

  double afterTip = (bill * (percentage / 100)) + bill;  
  double forEach = afterTip / numOfPeople;               

  printf("Each person should pay: %.2f", forEach);  
}