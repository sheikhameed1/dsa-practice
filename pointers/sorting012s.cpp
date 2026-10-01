#include <iostream>
#include <vector>
using namespace std;

 void sortColors(vector<int>& nums) {
        // Dutch National Flag
        // arr --> [0 to l][l to mid][unsorted][h+1 to n-1]
        int l = 0, mid = 0, h = nums.size()-1;
        while(mid <= h) {
            if(nums[mid] == 0) {
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid],nums[h]);
                h--;
            }
        }
    }

int main() {
    vector <int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    sortColors(nums);
    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}