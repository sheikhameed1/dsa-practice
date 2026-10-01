#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector <int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(isSwap == false) return;
    }
}

int main() {
    vector <int> arr = {4, 1, 5, 2, 3};
    bubbleSort(arr);
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}