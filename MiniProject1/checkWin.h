#pragma once
#include "globalVar.h"

int checkWin(char board[MAX_SIZE][MAX_SIZE], int size)
{
    // check horizontal lines
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (board[i][j] != ' ')
                if (board[i][j] == board[i][0])
                    break;
            if (j == size - 1)
                return 1;
        }
    }

    // check vertical lines
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (board[j][i] != ' ')
                if (board[j][i] == board[0][i])
                    break;

            if (j == size - 1)
                return 1;
        }
    }

    // diagonal
    for (int i = 0; i < size; i++)
    {
        if (board[i][i] == ' ')
            break;
        if (board[i][i] != board[i][0])
            break;
        if (i == size - 1)
            return 1;
    }

    // reverse diagonal
    for (int i = size - 1; i >= 0; i--)
    {
        if (board[i][i] == ' ')
            break;
        if (board[i][i] != board[i][size - 1])
            break;
        if (i == 0)
            return 1;
    }

    return 0;
}
