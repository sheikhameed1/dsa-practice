#include <iostream>
#include <vector>
using namespace std;

int totalLength(vector <int> boardLengths) {
    int sum = 0;
    for(int i = 0; i < boardLengths.size(); i++) {
        sum += boardLengths[i];
    }
    return sum;
}

bool isPossible(vector <int> &boardLengths, int n, int m, int cap) {
    int painters = 1, load = 0;
    for(int i = 0; i < n; i++) {
        if(boardLengths[i] > cap) return false;
        load += boardLengths[i];
        if(load > cap) {
            painters++;
            load = boardLengths[i];
        }
    }
    if(painters > m) {
        return false;
    } else {
        return true;
    }
}

int painterPartition(vector <int> &boardLengths, int n, int m) {
    if(m > n) return -1;
    int st = 0, end = totalLength(boardLengths);
    int ans = 0;
    while(st <= end) {
        int mid = st + (end - st)/2;
        if(isPossible(boardLengths, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
}

int main() {
    vector <int> boardLengths = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << painterPartition(boardLengths, n, m);

    return 0;
}