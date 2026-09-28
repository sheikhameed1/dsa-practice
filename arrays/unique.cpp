#include <iostream>
#include <vector>
using namespace std;

vector <int> uniqueE(vector<int> &nums) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        int freq = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[i] == nums[j]) {
                freq++;
            }
        }
        if(freq == 1) {
            result.push_back(nums[i]);
        }
        }
        return result;
}

int main() {

    vector <int> nums = {2, 4, 6, 8, 7, 3, 5, 1, 3, 5, 2};
    vector <int> result  = uniqueE(nums);

    for(int val : result) {
            cout << val << " ";
        }
        cout << endl;
    return 0;
}