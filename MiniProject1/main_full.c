#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

// checks
int checkWin(char[MAX_SIZE][MAX_SIZE], int);
int checkDraw(char[MAX_SIZE][MAX_SIZE], int);

void updateScore(char);
void printBoard(char[MAX_SIZE][MAX_SIZE], int);
void playerMove(char[MAX_SIZE][MAX_SIZE], int, char);
void aiMove(char[MAX_SIZE][MAX_SIZE], int);
void initializeBoard(char[MAX_SIZE][MAX_SIZE], int);

int main(void) {
    int size = 0;
    int opponent = 0;
    char board[MAX_SIZE][MAX_SIZE];

    int win = 0;

    // prompt user for the size of the board (only prompted once at the start of the program)
    do {
        printf("input the size of the grid you would like to play on (from 3 to 10): ");
        scanf("%d", &size);

        // number is invalid - reset
        if (size < 3 || size > 10) {
            printf("%d is an invalid number\n\n", size);
            size = 0;
        }
    } while (size == 0);

    // repeatedly ask player to play game (unless 3 is input)
    while (1) {
        // prompt player to decide whether to play against CPU or themselves
        printf(
            "Choose who to play against: \n\
        1 - Local player \n\
        2 - AI\n\
        3 - Exit program\n");
        scanf("%d", &opponent);

        if (opponent == 3)
            break; // exit program

        if (opponent < 0 || opponent > 2) // invalid number
            printf("\033[31mINVALID INPUT\033[0m\n");
        else if (opponent == 2) {
            initializeBoard(board, size);
            for (int i = 1; i < (size * size) + 1; i++) {
                // for player O
                printBoard(board, size);
                playerMove(board, size, 'O');
                printBoard(board, size);

                win = checkWin(board, size);
                if (win)
                    break;

                if (i == (size * size))
                    break;

                // for CPU player X
                aiMove(board, size);
                i++;

                win = checkWin(board, size);
                if (win)
                    break;
            }

            if (win == 1) {
                printf("%c wins this game.\n", 'O');
                updateScore('O');
            } else if (win == 2) {
                printf("%c wins this game.\n", 'X');
                updateScore('X');
            } else
                printf("no one wins.\n");
        } else {
            initializeBoard(board, size);
            for (int i = 1; i < (size * size) + 1; i++) {
                // for player O
                printBoard(board, size);
                playerMove(board, size, 'O');
                printBoard(board, size);

                win = checkWin(board, size);
                if (win)
                    break;

                if (i == (size * size))
                    break;

                // for player X
                playerMove(board, size, 'X');
                printBoard(board, size);
                i++;

                win = checkWin(board, size);
                if (win)
                    break;
            }

            if (win == 1) {
                printf("%c wins this game.\n", 'O');
                updateScore('O');
            } else if (win == 2) {
                printf("%c wins this game.\n", 'X');
                updateScore('X');
            } else
                printf("no one wins.\n");
            // printf("%s wins this game\n", (win == 1 ? "O" : (win == 0 ? "no one" : "X")));
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

// when CPU is controlling the X's - if there is a one-step winning move it is played, otherwise it is played at random
void aiMove(char board[MAX_SIZE][MAX_SIZE], int size) {
    int blockX = -1, blockY = -1; // rolling block - prioritize a winning > blocking move

    for (int row = 0; row < size; row++) { // check if an ally or rivalling row is full minus one
        int x = -1, y = -1;                // determine occupying character and the absent cell location
        char occupant = '\0';

        for (int col = 0; col < size; col++) {
            if (board[row][col] == ' ') // case 1: empty cell
                if (x == -1) {          // first empty cell
                    x = row;
                    y = col;
                } else { // second empty cell - no action
                    x = -1;
                    break;
                }
            else { // case 2: occupied cell
                if (occupant == '\0')
                    occupant = board[row][col];         // first filled cell - assign as row occupation
                else if (occupant != board[row][col]) { // conflicted row - no action
                    x = -1;
                    break;
                } // continue if cell matches row occupation
            }
        }

        if (x != -1 && occupant == 'X') { // winning move
            board[x][y] = 'X';
            return;
        } else if (x != -1 && occupant == 'O') { // blocking move (save for later)
            blockX = x, blockY = y;
        }
    }

    // check if an ally or rivalling column is full minus one
    for (int col = 0; col < size; col++) {
        // occupant character and the absent cell location
        int x = -1, y = -1;
        char occupant = '\0';

        for (int row = 0; row < size; row++) {
            if (board[row][col] == ' ') // empty cell
                if (x == -1) {          // first
                    x = row;
                    y = col;
                } else { // second - no action
                    x = -1;
                    break;
                }
            else { // occupied
                if (occupant == '\0')
                    occupant = board[row][col];         // first filled cell - assign
                else if (occupant != board[row][col]) { // conflict - no action
                    x = -1;
                    break;
                } // continue if cell matches
            }
        }

        if (x != -1 && occupant == 'X') { // winning
            board[x][y] = 'X';
            return;
        } else if (x != -1 && occupant == 'O') { // blocking
            blockX = x, blockY = y;
        }
    }

    // check if an ally or rivalling diagonal is full minus one
    int diagX = -1, diagY = -1;
    char diagOccupant = '\0';
    for (int i = 0; i < size; i++) {
        if (board[i][i] == ' ') {
            if (diagX == -1)
                diagX = i, diagY = i; // found empty cell
            else {                    // more than one empty - no action
                diagX = -1;
                break;
            }
        } else {
            if (diagOccupant == '\0')
                diagOccupant = board[i][i];         // occupying char found
            else if (diagOccupant != board[i][i]) { // conflict - no action
                diagX = -1;
                break;
            }
        }
    }

    if (diagX != -1 && diagOccupant == 'X') { // winning
        board[diagX][diagY] = 'X';
        return;
    } else if (diagX != -1 && diagOccupant == 'O')
        blockX = diagX, blockY = diagY; // blocking

    // check if an ally or rivalling reverse diagonal is full minus one
    diagX = -1, diagY = -1;
    diagOccupant = '\0';
    for (int i = 0; i < size; i++) {
        if (board[size - i - 1][size - i - 1] == ' ') {
            if (diagX == -1)
                diagX = size - i - 1, diagY = size - i - 1;
            else {
                diagX = -1;
                break;
            }
        } else {
            if (diagOccupant == '\0')
                diagOccupant = board[size - i - 1][size - i - 1];
            else if (diagOccupant != board[size - i - 1][size - i - 1]) {
                diagX = -1;
                break;
            }
        }
    }

    if (diagX != -1 && diagOccupant == 'X') {
        board[diagX][diagY] = 'X';
        return;
    } else if (diagX != -1 && diagOccupant == 'O')
        blockX = diagX, blockY = diagY;

    // NO WINNING MOVES FOUND - check if blocking move was found
    if (blockX != -1) {
        board[blockX][blockY] = 'X';
        return;
    }

    // NO WINNING OR BLOCKING MOVES FOUND - list all the possible places for the AI to move
    int available[99][2];

    // check the entire board for possible places to play
    int availI = 0;
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++) {
            if (board[row][col] == ' ') { // empty cell found
                available[availI][0] = row;
                available[availI][1] = col;
                availI++; // start filling next slot
            }
        }

    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    int randI = rand() % availI; // select a random index in the availability table that was previously filled

    int randX = available[randI][0], randY = available[randI][1]; // retrieve coords and write cell
    board[randX][randY] = 'X';
}

// returns 0 (no win), 1 (win for O), 2 (win for X)
int checkWin(char board[MAX_SIZE][MAX_SIZE], int size) {
    // for horizontal lines
    for (int row = 0; row < size; row++) {
        for (int col = 1; col < size; col++) {
            if (board[row][col] == ' ' || board[row][col] != board[row][0])
                break;
            if (col == size - 1) // if j is at end, this means that row is vaild
                return board[row][0] == 'O' ? 1 : 2;
        }
    }

    // for vertical lines
    for (int col = 0; col < size; col++) {
        for (int row = 1; row < size; row++) {
            if (board[row][col] == ' ' || board[row][col] != board[0][col])
                break;
            if (row == size - 1) // if j is at end, this means that col is vaild
                return board[0][col] == 'O' ? 1 : 2;
        }
    }

    // for diagonal lines
    for (int i = 0; i < size; i++) {
        if (board[i][i] == ' ' || board[i][i] != board[0][0])
            break;
        if (i == size - 1)
            return board[0][0] == 'O' ? 1 : 2;
    }

    // for reverse-diagonal lines
    for (int i = 0; i < size; i++) {
        if (board[i][size - i - 1] == ' ' || board[i][size - i - 1] != board[0][size - 1])
            break;
        if (i == size - 1)
            return board[0][size - 1] == 'O' ? 1 : 2;
    }

    return 0;
}

// displays board/grid to terminal
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
        if (row < size - 1)
            for (int i = 0; i < (size * 3) + (size - 1); i++)
                printf("-");
    }
    printf("\n");
}

// check if every column within every row has been filled with characters (draw state)
int checkDraw(char board[MAX_SIZE][MAX_SIZE], int size) {
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            if (board[row][col] == ' ')
                return 0;
    return 1;
}

// prompt the player i.e. user to input a set of coordinates to place their character
void playerMove(char board[MAX_SIZE][MAX_SIZE], int size, char player) {
    int x = 11, y = 11;
    int isValid = 0;
    // while ((!(!((x <= size && x > 0) && (y <= size && y > 0)) ? 0 : (board[x - 1][y - 1] == ' '))))
    while (!isValid) {
        printf("enter position in format (row column): ");
        scanf("%d %d", &x, &y);

        // check if coordinates are inside bounds; if not out of bounds then place character
        if (x > size || x < 1)
            printf("row position is out of bounds.\n");
        else if (y > size || y < 1)
            printf("column position is out of bounds.\n");
        else if (board[x - 1][y - 1] != ' ')
            printf("cell is already filled.\n");
        else
            isValid = 1;
    }

    board[x - 1][y - 1] = player;
}

// fill the board with spaces to represent no character present
void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = ' ';
}

// increments the score by 1 based on who won the game
void updateScore(char winner) {
    static int x = 0, o = 0; // static variables retain their value for the length of the program

    (winner == 'X') ? x++ : o++;                  // if the winner is X then increment wins by X by 1, otherwise increment wins by O
    printf("X score: %d\nO score: %d\n\n", x, o); // display both counters to terminal
}
