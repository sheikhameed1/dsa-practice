#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector <int> &stalls, int cows, int currmaxDist) {
    int reqCows = 1, dist = 0;
    for(int i = 0; i < stalls.size()-1; i++) {
        dist += stalls[i+1] - stalls[i];
        if(dist >= currmaxDist) {
            dist = 0;
            reqCows++;
        }
    }
    return reqCows >= cows;
}

int aggressiveCows(vector <int> &stalls, int cows) {
    if(stalls.size() < cows) return -1;
    sort(stalls.begin(),stalls.end());
    int low = 0;
    int high = stalls.back()-stalls.front();
    int maxDist = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(isPossible(stalls,cows,mid)) {
            maxDist = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return maxDist;
}
int main() {
    vector <int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << aggressiveCows(stalls,cows);
    return 0;
}
