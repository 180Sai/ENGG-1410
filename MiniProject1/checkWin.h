#pragma once
#include "globalVar.h"

int checkWin(char board[MAX_SIZE][MAX_SIZE], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 1; col < size; col++)
        {
            if (board[row][col] == ' ')                 //if space empty don't check row no more
                break;
            if (board[row][col] != board[row][0])         //if space not equal to corrner piece dont check row no more
                break;
            if (col == size - 1)                      //if j is at end, this means that row is vaild
                return 1;
        }
    }

    for (int col = 0; col < size; col++)
    {
        for (int row = 1; row < size; row++)
        {
            if (board[row][col] == ' ')                 //if space empty don't check col no more
                break;
            if (board[row][col] != board[0][col])         //if space not equal to corrner piece dont check col no more
                break;
            if (row == size - 1)                      //if j is at end, this means that col is vaild
                return 1;
        }
    }

    for(int i = 0; i < size; i++)
    {
        if (board[i][i] == ' ')                 //if space empty don't check col no more
            break;
        if (board[i][i] != board[0][0])         //if space not equal to corrner piece dont check col no more
            break;
        if(i == size-1)
            return 1;
    }

    for(int i = 0; i < size; i++)
    {
        if (board[i][size-i-1] == ' ')                 //if space empty don't check col no more
            break;
        if (board[i][size-i-1] != board[0][size-1])         //if space not equal to corrner piece dont check col no more
            break;
        if(i == size-1)
            return 1;
    }

    return 0;
}
