#pragma once

/**
 * validate input
 */
int VaildInput(char* o, int* b1, int* n1, int* n2, int* b2) {
  // takes in pointers so it can return multiple outputs
  // this is necessary as all scanf is placed in function instead of outside

  printf("Give input ($ to stop): ");  // prompt for input
  scanf(" %c", o);                     // get input

  int notEsc = 50;  // varible to exit after finishing read

  switch (*o) {
    // exit if no value has been read for o
    case 'f':
      printf("Invalid operator\n");
      notEsc = 0;
      return;
      break;
    case '+':
      // o is vaild no need to check if o is vaild exit switch
      break;
    case '-':
      // o is vaild no need to check if o is vaild exit switch
      break;
    case '*':
      // o is vaild no need to check if o is vaild exit switch
      break;
    case '/':
      // o is vaild no need to check if o is vaild exit switch
      break;
    case '$':
      return 2;  // o is $ so return 2 to repersent exit
      break;

    default:
      printf("Invalid operator\n");
      notEsc = 0;
  }

  scanf(" %d", b1);  //" %d" takes input from previous line instead of waiting
                     //for user to type again
  scanf(" %d", n1);  //" %d" takes input from previous line instead of waiting
                     //for user to type again
  scanf(" %d", n2);  //" %d" takes input from previous line instead of waiting
                     //for user to type again
  scanf(" %d", b2);  //" %d" takes input from previous line instead of waiting
                     //for user to type again

  // as previous lines will take input from previous input invaild operator must
  // be handeled after input so input is cleared
  if (notEsc != 50) {
    return 0;  // return 0 to repersent invalid input
  }

  // check if input base is in range
  if (*b1 < 2 || *b1 > 10) {
    printf("Invalid base\n");
    return 0;  // return 0 to repersent invalid input
  }

  // check if output base is in range
  if (*b2 < 0 || *b2 > 10) {
    printf("Invalid base\n");
    return 0;  // return 0 to repersent invalid input
  }

  // checks if every digit in the first number are in range zero to (input base
  // - 1)
  int t1 = *n1;
  for (int i = 0; t1 > 0; i++) {
    int digit = t1 % 10;
    t1 /= 10;
    if (digit < 0 || digit > *b1) {
      printf("Invalid digits in operand\n");
      return 0;  // return 0 to repersent invalid input
    }
  }

  // checks if every digit in the second number are in range zero to (input base
  // - 1)
  int t2 = *n2;
  for (int i = 0; t2 > 0; i++) {
    int digit = t2 % 10;
    t2 /= 10;
    if (digit < 0 || digit > *b1) {
      printf("Invalid digits in operand\n");
      return 0;  // return 0 to repersent invalid input
    }
  }

  return 1;  // return 1 to repersent valid input
}