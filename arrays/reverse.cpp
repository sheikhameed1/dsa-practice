#include <iostream>

using namespace std;

void reverse(int arr[] , int size) {
    for(int i=0; i < size/2; i++) {
        swap(arr[i],arr[size - 1 - i]);
        // int a = arr[size - 1 - i];
        // arr[size - 1 - i] = arr[i];
        // arr[i] = a;
    }
    return;
}
int main () {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    reverse(arr, size);

    for(int i=0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    return 0;
}