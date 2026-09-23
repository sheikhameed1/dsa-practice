#include <iostream>
#include <climits>
using namespace std;

int main() {
   int arr[] = {3, -4, 5, 4, -1, 7, -8};
  // Kadane's Algorithm
   int maxSum = INT_MIN;
   int currSum = 0;
   for(int i = 0; i < sizeof(arr)/4; i++) {
    currSum+=arr[i];
    maxSum = max(currSum,maxSum);
    if (currSum<0) {
        currSum = 0;
    }
   }
        //   BRUTE FORCE
//    for(int start = 0; start < sizeof(arr)/4; start++ ) {
//     int currentSum = 0;
//     for(int end = start; end < sizeof(arr)/4; end++ ) {
//     currentSum += arr[end];
//     maxSum = max(currentSum,maxSum);
//     }
// }
cout << maxSum;
    return 0;
}