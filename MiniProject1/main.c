#include <stdio.h>

#include "display.h"
#include "init.h"
#include "playerMove.h"
#include "checkWin.h"

int main(void)
{
    int size = 3;
    char board[MAX_SIZE][MAX_SIZE];

    initializeBoard(board, size);
    printBoard(board, size);

    playerMove(board, size, 'O');
    printBoard(board, size);

    playerMove(board, size, 'O');
    printBoard(board, size);

    playerMove(board, size, 'O');
    printBoard(board, size);

    printf("\n\n win: %d \n\n", checkWin(board, size));
    return 0;
}