#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the board
void displayBoard() {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

// Check winner
int checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Check draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int player = 1;
    int choice;
    char mark;

    printf("=================================\n");
    printf("       TIC - TAC - TOE GAME      \n");
    printf("=================================\n");

    while (1) {
        displayBoard();

        // Select player
        mark = (player == 1) ? 'X' : 'O';

        printf("\nPlayer %d [%c], enter position (1-9): ",
               player, mark);
        scanf("%d", &choice);

        // Convert position to row and column
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check invalid position
        if (choice < 1 || choice > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        // Check already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        // Place X or O
        board[row][col] = mark;

        // Check winner
        if (checkWinner()) {
            displayBoard();
            printf("\n*********************************\n");
            printf("       PLAYER %d WINS! 🎉\n", player);
            printf("*********************************\n");
            break;
        }

        // Check draw
        if (checkDraw()) {
            displayBoard();
            printf("\n*********************************\n");
            printf("          GAME DRAW! 🤝\n");
            printf("*********************************\n");
            break;
        }

        // Change player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}