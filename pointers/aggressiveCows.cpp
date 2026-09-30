#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible(vector <int> stallDist, int cows, int maxGap) {
    int placedCows = 1, lastcow = stallDist[0];
    // Placed cows aggressively starting from first place
    for(int i = 1; i < stallDist.size(); i++) { 
        if(maxGap <= (stallDist[i] - lastcow)) {
            placedCows++;
            lastcow = stallDist[i];
        }
    }
    if(placedCows < cows) {
        return false;
    } else {
        return true;
    }
}

int aggressiveCows(vector <int> &stallDist, int cows) {
    if(cows > stallDist.size()) return -1;
    sort(stallDist.begin(), stallDist.end());
    int low = 1, high = stallDist.back() - stallDist.front();
    int maxGap = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        // if yes then check if greater gap is possible
        if(isPossible(stallDist, cows, mid)) { 
            maxGap = mid;
            low = mid + 1;
        // check for a smaller gap
        } else {         
            high = mid - 1;
        }
    }
    return maxGap;
}

int main() {
    vector <int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows);
    return 0;
}