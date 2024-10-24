#pragma once

/**
 * validate input
 */
int VaildInput(char* o, int* b1, int* n1, int* n2, int* b2) {
  printf("Give input ($ to stop): ");
  scanf("%1000s[^\n]", o);

  int notEsc = 50;

  switch (*o) {
    case 'f':
      printf("Invalid operator\n");
      notEsc = 0;
      break;
    case '+':
      /* code */
      break;
    case '-':
      /* code */
      break;
    case '*':
      /* code */
      break;
    case '/':
      /* code */
      break;
    case '$':
      return 2;
      break;

    default:
      printf("Invalid operator\n");
      notEsc = 0;
  }

  scanf(" %d", b1);
  scanf(" %d", n1);
  scanf(" %d", n2);
  scanf(" %d", b2);

  if (notEsc != 50) {
    return 0;
  }

  if (*b1 < 2 || *b1 > 10) {
    printf("Invalid base\n");
    return 0;
  }

  if (*b2 < 0 || *b2 > 10) {
    printf("Invalid base\n");
    return 0;
  }

  int t1 = *n1;
  for (int i = 0; t1 > 0; i++) {
    int digit = t1 % 10;
    t1 /= 10;
    if (digit < 0 || digit > *b1) {
      printf("Invalid digits in operand\n");
      return 0;
    }
  }

  int t2 = *n2;
  for (int i = 0; t2 > 0; i++) {
    int digit = t2 % 10;
    t2 /= 10;
    if (digit < 0 || digit > *b1) {
      printf("Invalid digits in operand\n");
      return 0;
    }
  }

  return 1;
}