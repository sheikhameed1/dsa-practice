#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int start, int end) {
    
    // --- BRUTE FORCE ---

    // vector<int> left;
    // vector<int> right;
    // int pivot = arr[end];

    // for(int i = start; i < end; i++) {
    //     if(arr[i] <= pivot) {
    //         left.push_back(arr[i]);
    //     } else {
    //         right.push_back(arr[i]);
    //     }
    // }
    // for(int i = 0; i < left.size(); i++) {
    //     arr[start+i] = left[i];
    // }
    // arr[left.size()] = pivot;
    // for(int i = 0; i < right.size(); i++) {
    //     arr[start+left.size()+1+i] = right[i];
    // }
    // return left.size();

    int idx = start;
    for(int j = start; j <= end; j++) {
        
        if(arr[j] <= arr[end]) {
            swap(arr[idx],arr[j]);
            idx++;
        }
    }
    return idx-1;
}

void quickSort(vector<int>& arr, int start, int end) {

    if(start < end) {

        int pidx = partition(arr,start,end);

        quickSort(arr, start, pidx-1);

        quickSort(arr, pidx+1, end);
    }

}
int main() {

    vector<int> arr = {6,32,2,9,15};
    quickSort(arr,0,arr.size()-1);

    for(int &val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}