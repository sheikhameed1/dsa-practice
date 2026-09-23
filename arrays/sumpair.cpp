#include <iostream>
#include <vector>
using namespace std;

vector <int> sumPair(vector <int> nums,int target) {
    // Best Approach --> Two pointer approach
    vector <int> ans;
    for(int i = 0, j = nums.size() - 1;i < j;) { // nums.size() gives number of elements.
        int SP = nums[i] + nums[j];
        if(SP < target) {
            i++;
        }
        if(SP > target) {
            j--;
        }
        if(SP == target) {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
int main() {

    int target;
    vector <int> nums = {2, 4, 7, 13, 19, 23}; // sorted array
    cout << "enter target : ";
    cin >> target;
    vector <int> ans = sumPair(nums, target);
    cout <<  ans[0] << ", " << ans[1] << endl;
    
    return 0;
}