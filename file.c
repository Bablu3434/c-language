
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLUMNS 7

/* Read one command per line */
static int read_command(void)
{
    char line[128];
    size_t position = 0;
    int ch;

    if (fgets(line, sizeof line, stdin) == NULL) {
        return EOF;
    }

    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Discard remaining input */
        }
        return 0;
    }

    while (isspace((unsigned char)line[position])) {
        position++;
    }

    ch = (unsigned char)line[position];

    if (ch == '\0') {
        return 0;
    }

    position++;

    while (isspace((unsigned char)line[position])) {
        position++;
    }

    return line[position] == '\0' ? tolower(ch) : 0;
}

/* Display the game board */
static void show_board(char board[ROWS][COLUMNS])
{
    puts("\n  1 2 3 4 5 6 7");

    for (int row = 0; row < ROWS; row++) {
        putchar('|');

        for (int column = 0; column < COLUMNS; column++) {
            printf(" %c", board[row][column]);
        }

        puts(" |");
    }

    puts("+---------------+");
}

/* Count consecutive pieces in one direction */
static int count_direction(
    char board[ROWS][COLUMNS],
    int row,
    int column,
    int dr,
    int dc)
{
    int count = 0;
    char player = board[row][column];

    row += dr;
    column += dc;

    while (row >= 0 && row < ROWS &&
           column >= 0 && column < COLUMNS &&
           board[row][column] == player) {

        count++;
        row += dr;
        column += dc;
    }

    return count;
}

/* Check whether the latest move wins */
static int has_won(
    char board[ROWS][COLUMNS],
    int row,
    int column)
{
    const int directions[4][2] = {
        {0, 1},   /* Horizontal */
        {1, 0},   /* Vertical */
        {1, 1},   /* Diagonal down-right */
        {1, -1}   /* Diagonal down-left */
    };

    for (int direction = 0; direction < 4; direction++) {
        int dr = directions[direction][0];
        int dc = directions[direction][1];

        int connected =
            1 +
            count_direction(board, row, column, dr, dc) +
            count_direction(board, row, column, -dr, -dc);

        if (connected >= 4) {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    puts("=== CONNECT FOUR ===");
    puts("Two players: X and O. X starts each round.");
    puts("Enter a column (1-7) to drop a piece.");
    puts("Connect four horizontally, vertically, or diagonally to win.");
    puts("Enter Q at any prompt to quit.");

    for (;;) {
        char board[ROWS][COLUMNS];
        char player = 'X';
        int moves = 0;

        memset(board, '.', sizeof board);
        show_board(board);

        /* One complete round */
        for (;;) {
            int command;
            int column;
            int row;

            printf("Player %c, choose a column (1-7): ", player);
            fflush(stdout);

            command = read_command();

            if (command == EOF || command == 'q') {
                puts("\nThanks for playing!");
                return 0;
            }

            if (command < '1' || command > '7') {
                puts("Invalid input. Choose a column from 1 to 7.");
                continue;
            }

            column = command - '1';

            /* Find the lowest empty position */
            for (row = ROWS - 1; row >= 0; row--) {
                if (board[row][column] == '.') {
                    break;
                }
            }

            if (row < 0) {
                puts("That column is full. Choose another column.");
                continue;
            }

            /* Place the current player's piece */
            board[row][column] = player;
            moves++;

            show_board(board);

            /* Check for a winner */
            if (has_won(board, row, column)) {
                printf("Player %c wins!\n", player);
                break;
            }

            /* Check for a draw */
            if (moves == ROWS * COLUMNS) {
                puts("It's a draw!");
                break;
            }

            /* Switch players */
            player = (player == 'X') ? 'O' : 'X';
        }

        /* Ask whether to play another round */
        for (;;) {
            int command;

            printf("Play again? (Y/N): ");
            fflush(stdout);

            command = read_command();

            if (command == 'y') {
                break;
            }

            if (command == EOF || command == 'n' ||
                command == 'q') {
                puts("\nThanks for playing!");
                return 0;
            }

            puts("Please enter Y or N (or Q to quit).");
        }
    }
}
