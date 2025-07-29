#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <vector>
#include <algorithm> 
#include <random>

using namespace std;

// function to print the grid
void printGrid(int grid[9][9]){
    for (int r = 0; r < 9; r++){
        // horizontal seperation between rows 
        if (r % 3 == 0 || r == 0) cout << "-------+--------+-------\n";
        for (int c = 0; c < 9; c++){
            // vertical seperator
            if (c % 3 == 0 || c == 0) cout << "| ";
            if (grid[r][c] == 0) cout << "0 ";
            else cout << grid[r][c] << ' ';
        }
        cout << "| \n";
    }
    cout << "-------+--------+-------\n";
}

// if placing number in a cell is safe
bool isSafe(int grid[9][9], int row, int col, int num){
    // check row for duplicate 
    for (int c = 0; c < 9; c++){
        if (grid[row][c] == num) return false;
    }
    
    // check col for duplicates 
    for (int r = 0; r < 9; r++){
        if (grid[r][col] == num) return false;
    }

    // check 3x3 subgrid for duplicates 
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (grid[r + startRow][c + startCol] == num) return false;
        }
    }

    // all checks passed
    return true;
}

bool solveSudoku(int grid[9][9], int row, int col, mt19937& rng){
    // Base case: if row reaches 9, grid is filled
    if (row == 9) return true;

    // move to next row if col reaches 9
    if (col == 9) return solveSudoku(grid, row+1, 0, rng);

    // skip already filled cells (for pre-filled grids, not used here) 
    if (grid[row][col] != 0) return solveSudoku(grid, row, col+1, rng);

    // try numbers 1-9 in random order 
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(numbers.begin(), numbers.end(), rng);

    for (int num : numbers){
        if (isSafe(grid, row, col, num)){
            // place the number
            grid[row][col] = num;

            // recurse to next call 
            if (solveSudoku(grid, row, col+1, rng)) return true;

            // otherwise remove number and backtrack 
            grid[row][col] = 0;
        }
    }

    return false;

}

void createPuzzle(int solvedGrid[9][9], int puzzleGrid[9][9], int digitsToRemove, mt19937& rng){
    // copy solved grid to puzzle grid 
    for (int r = 0; r < 9; r++){
        for (int c = 0; c < 9; c++){
            puzzleGrid[r][c] = solvedGrid[r][c];
        }
    }

    uniform_int_distribution<int> dist(0, 8);
    // randomly remove digits
    while (digitsToRemove > 0){
        int row = dist(rng); // random row 0-8
        int col = dist(rng); // random col 0-8

        // only remove if not-empty
        if (puzzleGrid[row][col] != 0){
            puzzleGrid[row][col] = 0;
            digitsToRemove--;
        }
    }
}

int main(){
    // seed random time generator with current time ensuring new grid each run 
    random_device rd;
    mt19937 rng(rd());

    // initialize grid with 0s 
    int grid[9][9] = {0};
    // creates solved sudoku grid
    solveSudoku(grid, 0, 0, rng);
    // creates the puzzle
    int puzzle[9][9] = {0};

    createPuzzle(grid, puzzle, 40, rng);
    printGrid(puzzle);
    cout << '\n';
    printGrid(grid);
}
