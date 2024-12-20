#pragma once
#include "globalVar.h"

// returns 0 (no win), 1 (win for O), 2 (win for X)
int checkWin(char board[MAX_SIZE][MAX_SIZE], int size)
{
    // for horizontal lines
    for (int row = 0; row < size; row++)
    {
        for (int col = 1; col < size; col++)
        {
            if (board[row][col] == ' ' || board[row][col] != board[row][0])
                break;
            if (col == size - 1)                      //if j is at end, this means that row is vaild
                return board[row][0] == 'O' ? 1:2;
        }
    }

    // for vertical lines
    for (int col = 0; col < size; col++)
    {
        for (int row = 1; row < size; row++)
        {
            if (board[row][col] == ' ' || board[row][col] != board[0][col])
                break;
            if (row == size - 1)                      //if j is at end, this means that col is vaild
                return board[0][col] == 'O' ? 1:2;
        }
    }

    // for diagonal lines
    for(int i = 0; i < size; i++)
    {
        if (board[i][i] == ' ' || board[i][i] != board[0][0])
            break;
        if(i == size-1)
            return board[0][0] == 'O' ? 1:2;
    }

    // for reverse-diagonal lines
    for(int i = 0; i < size; i++)
    {
        if (board[i][size-i-1] == ' ' || board[i][size-i-1] != board[0][size-1])
            break;
        if(i == size-1)
            return board[0][size-1] == 'O' ? 1:2;
    }

    return 0;
}
