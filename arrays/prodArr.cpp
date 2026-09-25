// Product of every element of array except itself
#include <iostream>
#include <vector>
using namespace std;

vector <int> prodArr(vector<int> arr) {
      // OPTIMAL APPROACH
    int n = arr.size();
    vector <int> ans(n,1);
    
    for(int i = 1; i < n; i++) {
        ans[i] = ans[i-1] * arr[i-1];
    }
    int prod = 1;
    for(int j = n-2; j >= 0; j--) {
        prod *= arr[j+1];
        ans[j] *= prod;
    }
    return ans;
     //    BRUTE FORCE
    // for(int i = 0; i < arr.size(); i++) {
    //     int prod = 1;
    //     for(int j = 0; j < arr.size(); j++) {
    //         if(j == i) {
    //             continue;
    //         }
    //     prod *= arr[j];
    // }
    // ans.push_back(prod);
    // }
    // return ans;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<int> result = prodArr(arr);
    for(int x : result) {
        cout << x << ", ";
    }
    return 0;
}