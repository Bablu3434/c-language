#include <stdio.h>

int main() {
    // A 2D array with 2 rows and 3 columns
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("Printing the 2D Matrix:\n");
    
    // The outer loop iterates through the rows
    for (int i = 0; i < 2; i++) {
        
        // The inner loop iterates through the columns of the current row
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        
        // Move to the next line after finishing a row
        printf("\n"); 
    }

    return 0;
}