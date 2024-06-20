#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This function return whether the number is valid in the position (row,col)
 * @param table the sudoku table
 * @param row
 * @param col
 * @param number
 * @return true if valid, false otherwise
 */
bool is_valid(int **table, int row, int col, int number)
{
    // Check if the number is already in the row
    for(int i = 0; i < 9 ; i++)
    {

    }
}



int main() {
    int sudoku_table[9][9] = {
            {4, 0, 0, 0, 0, 0, 8, 0, 5},
            {0, 3, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 7, 0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0, 0, 6, 0},
            {0, 0, 0, 0, 8, 0, 4, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 6, 0, 3, 0, 7, 0},
            {5, 0, 0, 2, 0, 0, 0, 0, 0},
            {1, 0, 4, 0, 0, 0, 0, 0, 0}
    };
}
