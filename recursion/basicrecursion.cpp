#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {

    if(n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}
int sumN(int n) {

    if(n == 1) {
        return 1;
    }

    return n + sumN(n-1);
}
int fibN(int n) {

    if(n == 1) {
        return 0;
    } else if(n == 2) {
        return 1;
    }

    return fibN(n-1) + fibN(n-2);
}
bool isSorted(const vector <int>& arr, int n) {

    if(n == 0 || n == 1) return true;

    return arr[n-1] >= arr[n-2] && isSorted(arr,n-1);
}
int binarySearch(const vector<int> &arr, int target, int st, int end) {
    
    if(st > end) return -1;
    int mid = st + (end-st)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) end = mid-1;
    else st = mid+1;
    return binarySearch(arr,target,st,end);
}
int main() {
    vector <int> arr = {1,2,3,4,5};
    cout << binarySearch(arr,15,0,4);
    return 0;
}