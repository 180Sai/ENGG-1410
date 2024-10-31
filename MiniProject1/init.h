#pragma once
#include "globalVar.h"

void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int size)
{
    // fill entire 2D array with space
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}