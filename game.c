#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

int carPosition;
int enemyX, enemyY;
int score = 0;
int gameOver = 0;

// Clear screen
void clearScreen() {
    system("cls");
}

// Draw game
void drawGame() {
    clearScreen();

    printf("================================\n");
    printf("        🚗 CAR RACING GAME\n");
    printf("================================\n");
    printf("Score: %d\n", score);
    printf("Controls: A = Left | D = Right | Q = Quit\n\n");

    for (int y = 0; y < HEIGHT; y++) {

        printf("|");

        for (int x = 0; x < WIDTH; x++) {

            if (y == HEIGHT - 2 && x == carPosition) {
                printf("A");   // Player car
            }
            else if (y == enemyY && x == enemyX) {
                printf("X");   // Enemy car
            }
            else if (x == 0 || x == WIDTH - 1) {
                printf("|");
            }
            else {
                printf(" ");
            }
        }

        printf("|\n");
    }

    printf("\n");
}

// Move enemy
void moveEnemy() {

    enemyY++;

    // Enemy reaches bottom
    if (enemyY >= HEIGHT - 2) {

        // Collision
        if (enemyX == carPosition) {
            gameOver = 1;
            return;
        }

        score++;

        // New enemy position
        enemyY = 0;
        enemyX = rand() % (WIDTH - 2) + 1;
    }
}

// Main function
int main() {

    srand(time(NULL));

    carPosition = WIDTH / 2;

    enemyX = rand() % (WIDTH - 2) + 1;
    enemyY = 0;

    while (!gameOver) {

        drawGame();

        // Check keyboard
        if (_kbhit()) {

            char key = _getch();

            // Move left
            if (key == 'a' || key == 'A') {

                if (carPosition > 1) {
                    carPosition--;
                }
            }

            // Move right
            else if (key == 'd' || key == 'D') {

                if (carPosition < WIDTH - 2) {
                    carPosition++;
                }
            }

            // Quit
            else if (key == 'q' || key == 'Q') {
                gameOver = 1;
            }
        }

        moveEnemy();

        Sleep(150);
    }

    clearScreen();

    printf("================================\n");
    printf("          GAME OVER!\n");
    printf("================================\n");

    printf("\nYour Score: %d\n", score);

    printf("\nThanks for playing! 🚗\n");

    return 0;
}