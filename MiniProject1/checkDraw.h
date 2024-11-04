#pragma once
#include "globalVar.h"

int checkDraw(char board[MAX_SIZE][MAX_SIZE], int size)
{
    for(int row = 0; row < size; row++) for (int col = 0; col < size; col++) if(board[row][col] == ' ') return 0;
    return 1;
}