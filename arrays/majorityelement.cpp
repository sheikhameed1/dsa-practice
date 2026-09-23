#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int majorityElement(vector<int> nums) {

    //    MOORE'S ALGORITHM
   int freq = 0, ans = 0;
    for(int i : nums) {
       if (freq == 0) {
        ans = nums[i];
       }
       if (nums[i] == ans) {
        freq++;
       } else {
        freq--;
       }
    }
    return ans;
    //    SORTING
    // int n = nums.size();
    // sort(nums.begin(),nums.end());
    // int freq = 1;
    // for(int i = 1; i < n; i++) {
    //     if(nums[i] == nums[i-1]) {
    //         freq++;
    //     } else {
    //         freq = 1;
    //     }
    //     if(freq > n/2) {
    //         return nums[i];
    //     }
    // }
    // return nums[0];

    //    BRUTE FORCE
    // int n = nums.size();
    // for(int i : nums) {
    //     int count = 0;
    //         for(int j : nums) {
    //        if(nums[i] == nums[j]) {
    //         count++;
    //        }
    //     }
    //     if(count > n/2) {
    //         return nums[i];
    //     }
    // }
    // return -1;
}
int main() {

    vector<int> nums = {1, 2, 2, 1, 1, 2, 2}; // majority element always exists.
    cout << "The majority element is : " << majorityElement(nums);
    return 0;
}