#pragma once
#include "globalVar.h"

void printBoard(char board[MAX_SIZE][MAX_SIZE], int size)
{
    printf("\e[1;1H\e[2J"); // clear all characters in terminal starting from first character

    // add two lines for every row in grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0;
             j < (size * 3) // add three hyphens for every character in row,
                     + (size - 1);
             j++) // plus three lines
        {
            if (!i)
                break;   // do not print first line
            printf("-"); // horizontal lines (no detail)
        }

        printf("\n %c", board[i][0]); // goes to next line, starts character on horizontal line
        for (int j = 1; j < size - 1; j++)
            printf(" | %c", board[i][j]); // horizontal lines that half detail

        printf(" | %c \n", board[i][size - 1]); // ending character on horizontal line, goes to next line
    }
}