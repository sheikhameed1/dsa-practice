#include <iostream>
#include <climits>
using namespace std;
// we have to define number of coloumns for the compiler
pair<int,int> isPresent(int matrix[][3], int rows, int clms, int target) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < clms; j++) {
            if(matrix[i][j] == target) {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int maxRowSum(int matrix[][3],int rows, int clms) {
    int maxSum = INT_MIN;
    for(int i = 0; i < rows; i++) {
        int currSum = 0;
        for(int j = 0; j < clms; j++) {
            currSum += matrix[i][j];
        }
        maxSum = max(currSum,maxSum);
    }
    return maxSum;
}

int maxClmSum(int matrix[][3],int rows, int clms) {
    int maxSum = INT_MIN;
    for(int i = 0; i < clms; i++) {
        int currSum = 0;
        for(int j = 0; j < rows; j++) {
            currSum += matrix[j][i];
        }
        maxSum = max(currSum,maxSum);
    }
    return maxSum;
}

int diagSum(int matrix[][4], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
        if(i != n-i-1) {
            sum += matrix[i][n-i-1];
        }
    }
    
    return sum;
}
int main() {

    int matrix[4][4] = {{1,2,3,0},{4,5,6,0},{7,8,9,0},{10,11,12,0}};
    int n = 4;
    cout << diagSum(matrix,n);
    return 0;
}