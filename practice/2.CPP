#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalPages(const vector <int> &pages) {
    int sum = 0;
    for(int val : pages) {
        sum += val;
    }
    return sum;
}

bool isValid(const vector <int> &pages, int k, int cap) {
    int students = 1, load = 0;
    for(int i = 0; i < pages.size(); i++) {
        load += pages[i];
        if(load > cap) {
            load = pages[i];
            students++;
        }
    } 
    return students <= k;
}

int allocateBooks(const vector<int> &pages, int k) {
    if(pages.size() < k) return -1;
    int low = *max_element(pages.begin(),pages.end()), high = totalPages(pages);
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low)/2 ;
        if(isValid(pages,k,mid)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}
int main() {
    vector <int> arr = {12,34,67,90};
    int k = 2;
    cout << allocateBooks(arr,k);
    return 0;
}