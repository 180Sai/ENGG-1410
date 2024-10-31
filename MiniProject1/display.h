#pragma once
#include "globalVar.h"

void printBoard(char board[MAX_SIZE][MAX_SIZE], int size)
{
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size * 3) + (size - 1); j++)
        {
            if (!i)
                break;
            printf("-");
        }
        printf("\n %c", board[i][0]);
        for (int j = 1; j < size - 1; j++)
        {
            printf(" | %c", board[i][j]);
        }
        printf(" | %c \n", board[i][size - 1]);
    }
}