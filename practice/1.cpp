#include <iostream>
#include <vector>
using namespace std;

int binSch(vector <int> arr, int target) {
    int s = 0, e = arr.size()-1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(arr[mid] == target) return mid; 
        else if(arr[mid] > target) e = mid-1;
        else s = mid+1;
    }
    return -1;
}

int singleElement(vector<int> &arr) {
    if(arr.size() == 1) return 0;
    if(arr[0] != arr[1]) return 0;
    if(arr[arr.size()-1] != arr[arr.size()-2]) return arr.size()-1;
    int s = 1, e = arr.size()-2;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) {
            return mid;
        } else if(arr[mid] == arr[mid-1]) {
            if(mid%2 == 0) e = mid-1;
            else s = mid+1;
        } else {
            if(mid%2 == 0) s = mid+1;
            else e = mid-1;
        }
    }
    return -1;
}
void bubbleSort(vector <int> &arr) {
    for(int i = arr.size()-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void selectionSort(vector <int> &arr) {
    for(int i = 0; i < arr.size()-1; i++) {
        int smallest = i;
        for(int j = i; j < arr.size(); j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        swap(arr[smallest],arr[i]);
    }
}
void insertionSort(vector <int> &arr) {
    for(int i = 1; i < arr.size(); i++) {
        int curr = arr[i];
        int prev = i-1;
        // MAKE PLACE TILL A[prev] > CURRENT ELEMENT
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr; // PLACED
    }
}

int main() {
    vector <int> arr = {6,2,7,45,2,98,11,23};
    insertionSort(arr);
    for(int val : arr) {
        cout << val << " ";
    }
    return 0;
}