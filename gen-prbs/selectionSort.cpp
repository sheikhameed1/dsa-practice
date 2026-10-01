#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector <int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int smallestI = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[smallestI]) {
                smallestI = j;
            }
        }
        swap(arr[i],arr[smallestI]);
    }
}

int main() {
    vector <int> arr = {4, 1, 5, 2, 3};
    selectionSort(arr);
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}