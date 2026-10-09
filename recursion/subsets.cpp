#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector <int>& arr, vector<int>& ans, int i) {

    if(i == arr.size()) {
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubsets(arr,ans,i+1);

    ans.pop_back(); // remove element in last layer

    //exclude
    printSubsets(arr,ans,i+1);
}
int main() {

    vector<int> arr = {1,2,3};
    vector<int> ans;
    int i = 0;
    printSubsets(arr,ans,i);

    return 0;
}