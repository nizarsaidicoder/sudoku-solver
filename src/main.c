#include <time.h>
#include <unistd.h>
#include "sudoku.h"

int main()
{
    // int sudoku_grid[9][9] = {
    //     {4, 0, 0, 0, 0, 0, 8, 0, 5},
    //     {0, 3, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 7, 0, 0, 0, 0, 0},
    //     {0, 2, 0, 0, 0, 0, 0, 6, 0},
    //     {0, 0, 0, 0, 8, 0, 4, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 6, 0, 3, 0, 9, 0},
    //     {5, 0, 0, 2, 0, 0, 0, 0, 0},
    //     {1, 0, 4, 0, 0, 0, 0, 0, 0}};

    // evil version
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
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    sudoku_solve(sudoku_grid);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to solve: %f seconds\n", cpu_time_used);

    sudoku_print(sudoku_grid);
    return 0;
}
