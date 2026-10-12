#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ratInMaze(vector<vector<int>>& maze, int n, int row, int col, string& path, vector<string>& ans) {

    
    if(row<0 || col<0 || row>n-1 || col>n-1 || maze[row][col] == 0) {
        return;
    }
    if(row == n-1 && col == n-1) {
        ans.push_back(path);
        return;
    }
    maze[row][col] = 0;

    ratInMaze(maze,n,row+1,col,path += 'D',ans);
    path.pop_back();

    ratInMaze(maze,n,row-1,col,path += 'U',ans);
    path.pop_back();

    ratInMaze(maze,n,row,col+1,path += 'R',ans);
    path.pop_back();

    ratInMaze(maze,n,row,col-1,path += 'L',ans);
    path.pop_back();
    maze[row][col] = 1;
}

int main() {

    vector<vector<int>> maze = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans;
    string path = "";
    int n = maze.size();
    ratInMaze(maze,4,0,0,path,ans);
    
    for(string str : ans) {
        cout << str << endl;
    }
    
    return 0;
}