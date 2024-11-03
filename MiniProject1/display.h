#pragma once
#include "globalVar.h"

void printBoard(char board[MAX_SIZE][MAX_SIZE], int size) {
    // printf("\e[0;0H\e[2J");

    for (int row = 0; row < size; row++) {
        printf("\n %c ", board[row][0]);
        for (int col = 1; col < size - 1; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|");
        printf(" %c ", board[row][size - 1]);

        printf("\n");
        if (row < size - 1) for (int i = 0; i < (size * 3) + (size - 1); i++) printf("-");
    }
    printf("\n");
}