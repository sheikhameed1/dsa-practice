#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& grid, int row, int col, int val) {

    //ROW
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == val) {
            return false;
        }
    }
    //COL
    for(int i = 0; i < 9; i++) {
        if(grid[i][col] == val) {
            return false;
        }
    }
    //BLOCK
    row = (row/3)*3;
    col = (col/3)*3;
    for(int i = row; i < row+3; i++) {
        for(int j = col; j < col+3; j++) {
            if(grid[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool sudokusolver(vector<vector<int>>& grid, int row, int col) {

    if(col == 9) {
        col = 0;
        row++;
    }
    if(row == 9) {
        return true;
    }
    if(grid[row][col] != 0) {
        return sudokusolver(grid,row,col+1);
    }

    for(int val = 1; val <= 9; val++) {

        if(isSafe(grid,row,col,val)) {
            grid[row][col] = val;
            if(sudokusolver(grid,row,col+1)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
vector<vector<int>> grid = {{5,3,0,0,7,0,0,0,0},
                            {6,0,0,1,9,5,0,0,0},
                            {0,9,8,0,0,0,0,6,0},
                            {8,0,0,0,6,0,0,0,3},
                            {4,0,0,8,0,3,0,0,1},
                            {7,0,0,0,2,0,0,0,6},
                            {0,6,0,0,0,0,2,8,0},
                            {0,0,0,4,1,9,0,0,5},
                            {0,0,0,0,8,0,0,7,9}};
    sudokusolver(grid,0,0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << grid[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}