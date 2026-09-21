#include <iostream>
using namespace std;

int linearsearch(int arr[],int size,int target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, -4, 8, 9, 13, 7};
    cout << linearsearch(arr, 7, 8) << endl;
    return 0;
}