#include <iostream>
using namespace std;

void isUnique(int arr[], int size) {
    for(int i = 0; i < size; i++) {
     int count = 0;
        for(int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count +=1;
            }
            }
        if (count == 1) {
            cout << arr[i] << endl;
        }
        }
    }


int main() {

    int arr[] = {2, 4, 6, 8, 7, 3, 5, 1, 3, 5, 2};
    int size = 11;
    isUnique(arr,size);

    return 0;
}