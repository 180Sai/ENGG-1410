#pragma once
#include "globalVar.h"

void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player)
{
    int x = 11, y = 11;
    int isValid = 0;
    // while ((!(!((x <= size && x > 0) && (y <= size && y > 0)) ? 0 : (board[x - 1][y - 1] == ' '))))
    while (!isValid)
    {
        printf("enter position in format (row column): ");
        scanf("%d %d", &x, &y);

        if (x > size || x < 1) printf("row position is out of bounds.\n");
        if (y > size || y < 1) printf("column position is out of bounds.\n");
        if (board[x - 1][y - 1] == ' ') printf("cell is already filled.\n");
        else isValid = 1;
    }

    board[x - 1][y - 1] = player;
}
