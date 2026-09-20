#include <iostream>
#include <climits>
using namespace std;

int main() {
    int nums[8] = {43,-56,87,34,-7,432,-56,65};
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i=0; i<8; i++) {
     if (smallest > nums[i] && nums[i] >= 0) {
        smallest = nums[i];
     }
     if (largest < nums[i] && nums[i] >= 0) {
        largest = nums[i];
     }
    }
    if (smallest == INT_MAX) {
      cout << "No positive number in dataset" << endl;
      return 0;
    }
    cout << smallest << endl;
    if (largest == INT_MIN) {
      cout << "No positive number in dataset" << endl;
      return 0;
    }
    cout << largest << endl;
    return 0;
}