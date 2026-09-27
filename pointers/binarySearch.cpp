#include <iostream>
#include <vector>
using namespace std;
// iterators
bool binarySearch(vector<int> &nums, int target) {
    int s = 0, e = nums.size()-1;
    while(e>=s) {
        int mid = s + (e-s)/2;               // reason = if s and e are near INT_MAX 
        if(nums[mid] == target) return true; // then (s+e) may cause errors.
        if(nums[mid] < target) {
            s = mid+1;
        }
        if(nums[mid] > target) {
            e = mid-1;
        }
    }
    return false;
}

    // recursion
bool binSearch(vector <int> nums, int target, int st, int end) {
    if(st<=end) {
        int mid = st + (end-st)/2;
        if (nums[mid] < target) {
            return binSearch(nums,target,mid+1,end);
        }
        else if (nums[mid] > target) {
            return binSearch(nums,target,st,mid-1);
        }
        else return true;
    }
    return false;
}


int main() {
    vector<int> nums = {23, 54, 67, 92, 101};
    cout << binSearch(nums, 92,0,nums.size()-1);
    return 0;
}