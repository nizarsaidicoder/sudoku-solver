#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
bool sudoku_solve(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    if (is_valid(grid, i, j, n))
                    {
                        grid[i][j] = n;
                        if (sudoku_solve(grid))
                            return true;
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
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
int main()
{
    int sudoku_grid[9][9] = {
        {6, 0, 9, 2, 0, 3, 5, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 7, 0, 4, 0, 9, 0, 0, 7},
        {0, 0, 7, 0, 5, 0, 9, 0, 3},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {4, 0, 6, 0, 8, 0, 1, 0, 5},
        {0, 0, 3, 8, 0, 1, 6, 0, 0},
        {0, 5, 0, 0, 4, 9, 2, 7, 0},
        {5, 4, 0, 0, 9, 2, 7, 0, 8}};

    sudoku_print(sudoku_grid);
    printf("\n");
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    sudoku_solve(sudoku_grid);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to solve: %f seconds\n", cpu_time_used);

    sudoku_print(sudoku_grid);
}
