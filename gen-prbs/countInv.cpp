#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {

    vector<int> temp;

    int countInv = 0;
    int i = st, j = mid+1;
    while(i <= mid && j <= end) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            countInv += mid-i+1;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int i = 0; i < temp.size(); i++) {
        arr[st+i] = temp[i];
    }
    return countInv;
}

int inversions(vector<int>& arr, int st, int end) {

    if( st < end) {
    int mid = st + (end-st)/2;

    int leftcount = inversions(arr,st,mid);
    int rightcount = inversions(arr,mid+1,end);

    int countInv = merge(arr,st,mid,end);

    return countInv+rightcount+leftcount;
    }
    return 0;
}
int main() {

    vector<int> arr = {5,4,3,2,9};
    cout << inversions(arr,0,arr.size()-1);
    return 0;
}