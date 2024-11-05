#include "display.h"
#include "init.h"
#include "playerMove.h"
#include "checkWin.h"

int main(void)
{
    int size = 0;
    int opponent = 0;
    char board[MAX_SIZE][MAX_SIZE];

    int win = 0;

    while(1)
    {
        if (!size)
        {
            printf("what size grid would you like to play on (3-10): ");
            scanf("%d", &size);
            if(size < 3 || size > 10)
                size = 0;
            continue;
        }
        
        printf("Would you like to play against \n\t1: A player \n\t2: The Computer\n your choice: ");
        scanf("%d", &opponent);
        
        if (opponent < 0 || opponent > 2)
            printf("\033[31mINVALID INPUT\033[0m\n");
        
        else if(opponent == 2)
        {
            printf("The computer is mad try again later");
            continue;
        }
        else
        {
            initializeBoard(board, size);
            for(int i = 1; i < (size*size)+1; i++)
            {
                //for player O
                printBoard(board, size);
                playerMove(board, size, 'O');
                printBoard(board, size);

                win = checkWin(board, size);
                if(win) break;


                if(i == (size*size)) break;

                //for player X
                playerMove(board, size, 'X');
                printBoard(board, size);
                i++;
                
                win = checkWin(board, size);
                if(win) break;
            }

            printf("%s wins this game\n", (win == 1 ? "O" : (win == 0 ? "no one" : "X")));
        }
    }

    return 0;
}

/*
3
1
1 1
1 2
1 3
2 2
3 2
2 1
2 3
3 3
3 1
*/