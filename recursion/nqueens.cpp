#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board,int row, int col, int n) {

    //row
    for(int i = 0; i < n; i++) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }
    //col
    for(int i = 0; i < n; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }
    //left diag
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    //right diag
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void nQueens(vector<string>& board, vector<vector<string>>& ans, int row, int n) {

    if(row == n) {
        ans.push_back(board);
        return;
    }

    for(int i = 0; i < n; i++) {

        if(isSafe(board,row,i,n)) {
            board[row][i] = 'Q';
            nQueens(board,ans,row+1,n);
            board[row][i] = '.';
        }
    }
}

int main() {

    cout << "enter side of board : ";
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board,ans,0,n);

    for(const vector<string>& board : ans) {

        for(const string& row : board) {

            for(const char& place : row) {
                cout << place << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}