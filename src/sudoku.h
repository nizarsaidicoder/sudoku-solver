#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sudoku_print(int grid[9][9]);
bool is_valid(int grid[9][9], int row, int col, int number);
bool solve(int grid[9][9], int start_row, int start_col);
bool sudoku_solve(int grid[9][9]);
