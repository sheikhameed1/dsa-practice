#include <iostream>
#include <vector>
using namespace std;

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
int main() {
    vector<int> nums = {23, 54, 67, 92, 101};
    cout << binarySearch(nums, 97);
    return 0;
}