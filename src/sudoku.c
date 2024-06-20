#include "sudoku.h"

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
    // Check if the number is already in the subgrid
    int subgrid_row = (row / 3) * 3;
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
void sudoku_print(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("------+-------+------\n");
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                printf("| ");
            }
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
bool solve(int grid[9][9], int start_row, int start_col)
{
    for (int i = start_row; i < 9; i++)
    {
        for (int j = start_col; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int n = 1; n <= 9; n++)
                {
                    if (is_valid(grid, i, j, n))
                    {
                        grid[i][j] = n;

                        if (solve(grid, i - 1, j - 1))
                            return true;
                        grid[i][j] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoku_solve(int grid[9][9])
{
    solve(grid, 0, 0);
}
