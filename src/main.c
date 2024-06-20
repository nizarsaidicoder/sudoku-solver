#include <unistd.h>
#include "sudoku.h"

int main()
{
    int sudoku_grid[9][9] = {
        {6, 0, 9, 2, 0, 3, 5, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 4, 0, 9, 0, 0, 7},
        {7, 0, 5, 0, 0, 0, 9, 0, 3},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {4, 0, 6, 0, 0, 0, 8, 0, 5},
        {3, 0, 0, 8, 0, 1, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 4, 9, 0, 2, 7, 0, 8}};
    sudoku_print(sudoku_grid);
    printf("\n");
    if (sudoku_solve(sudoku_grid))
    {
        sudoku_print(sudoku_grid);
        printf("Sudoku solved successfully!\n");
    }
    else
    {
        printf("No solution found!\n");
    }
    return 0;
}
