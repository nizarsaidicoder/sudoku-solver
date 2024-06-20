#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This function return whether the number is valid in the position (row,col)
 * @param table the sudoku grid
 * @param row
 * @param col
 * @param number
 * @return true if valid, false otherwise
 */
bool is_valid(int grid[9][9], int row, int col, int number)
{
    if (number == 0)
        return false;
    // Check if the number is already in the row
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == number)
            return false;
    }
    // Check if the number is already in the column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == number)
            return false;
    }
    Check if the number is already in the subgrid int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++)
    {
        for (int j = subgrid_col; j < subgrid_col + 3; j++)
        {
            if (grid[i][j] == number)
                return false;
        }
    }
    return true;
}


int main()
{
    int sudoku_grid[9][9] = {
        {4, 0, 0, 0, 0, 0, 8, 0, 5},
        {0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 8, 0, 4, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 3, 0, 7, 0},
        {5, 0, 0, 2, 0, 0, 0, 0, 0},
        {1, 0, 4, 0, 0, 0, 0, 0, 0}};
}
