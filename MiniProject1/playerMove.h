#pragma once
#include "globalVar.h"

void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player)
{
    int x = 11, y = 11;
    while (!(!((x <= size && x > 0) && (y <= size && y > 0)) ? 0 : (board[x - 1][y - 1] == ' ')))
    {
        printf("enter postion in format (x, y): ");
        scanf("%d %d", &x, &y);
    }

    board[x - 1][y - 1] = player;
}
