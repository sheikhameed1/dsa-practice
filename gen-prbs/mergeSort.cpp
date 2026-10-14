#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int e) {

    vector<int> temp;
    int i = st, j = mid+1;

    while(i <= mid && j <= e) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++) {

        arr[i+st] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int st, int e) {

    if(st >= e) {
        return;
    }

    int mid = st + (e - st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,st,mid,e);
}

int main() {

    vector<int> arr = {6,32,2,9,15};
    mergeSort(arr,0,arr.size()-1);

    for(int &val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}