#include <stdio.h>
#define MAX_SIZE 10

int main(void)
{
    int size = 0;
    int opponent = 0;
    char board[MAX_SIZE][MAX_SIZE];

    int win = 0;

    while(1)
    {
        // prompt user for size 
        if (!size)
        {
            printf("what size grid would you like to play on (3-10): ");
            scanf("%d", &size);
            if(size < 3 || size > 10) size = 0; // reset size value if invalid

            continue; // keep skipping thru code until a valid input is received
        }
        
        // prompt player to decide whether to play against CPU or themselves 
        printf("Choose who to play against: \n\t\
            1. A player \n\t\
            2. The Computer\n");
        scanf("%d", &opponent);
        
        // 
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

            if (win == 1) 
                printf("%c wins this game.\n", 'O');
            else if (win == 2)
                printf("%c wins this game.\n", 'X');
            else 
                printf("no one wins.");
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

void AIMove(int *x, int *y) {
    
}

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

void printBoard(char board[MAX_SIZE][MAX_SIZE], int size) {
    // printf("\e[0;0H\e[2J");

    for (int row = 0; row < size; row++) {
        // print columns in row
        printf("\n %c ", board[row][0]);
        for (int col = 1; col < size - 1; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|");
        printf(" %c ", board[row][size - 1]);

        printf("\n");

        // add lines to separate rows from each other
        if (row < size - 1) for (int i = 0; i < (size * 3) + (size - 1); i++) printf("-");
    }
    printf("\n");
}

int checkDraw(char board[MAX_SIZE][MAX_SIZE], int size)
{
    for(int row = 0; row < size; row++) for (int col = 0; col < size; col++) 
        if(board[row][col] == ' ') return 0;
    return 1;
}

void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player)
{
    int x = 11, y = 11;
    int isValid = 0;
    // while ((!(!((x <= size && x > 0) && (y <= size && y > 0)) ? 0 : (board[x - 1][y - 1] == ' '))))
    while (!isValid)
    {
        printf("enter position in format (row column): ");
        scanf("%d %d", &x, &y);

        if (x > size || x < 1) printf("row position is out of bounds.\n");
        if (y > size || y < 1) printf("column position is out of bounds.\n");
        if (board[x - 1][y - 1] == ' ') printf("cell is already filled.\n");
        else isValid = 1;
    }

    board[x - 1][y - 1] = player;
}
