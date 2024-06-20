#include "sudoku.h"

/**
 * Check if the number is valid to be placed in the grid
 * @param grid The sudoku grid
 * @param row The row index
 * @param col The column index
 * @param number The number to be checked
 * @return true if the number is valid, false otherwise
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
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + start_row][j + start_col] == number)
                return false;
        }
    }
    return true;
}
/**
 * Print the sudoku grid
 * @param grid The sudoku grid
 */
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
/**
 * Solve the sudoku puzzle
 * @param grid The sudoku grid
 * @param start_row The starting row index
 * @param start_col The starting column index
 * @return true if the sudoku is solved, false otherwise
 */
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
/**
 * Solve the sudoku puzzle
 * @param grid The sudoku grid
 * @return true if the sudoku is solved, false otherwise
 */
bool sudoku_solve(int grid[9][9])
{
    return solve(grid, 0, 0);
}
