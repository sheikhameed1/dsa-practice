#include <iostream>
using namespace std;
#include <vector>
int Mwater(vector<int> heights) {
    // brute force
    // int n = heights.size();
    // int maxWater = 0;
    // for(int i = 0; i < n-1; i++){
    //     for(int j = i + 1; j < n; j++) {
    //         int Area = (j-i) * (min(heights[i],heights[j]));
    //         maxWater = max(maxWater,Area);
    //     }
    // }
    // return maxWater;

               // Optimal approach
    int n = heights.size();
    int maxVol = 0;
    int lp = 0, rp = n-1;
    while(lp < rp) {
    int currVol = (rp - lp) * (min(heights[lp],heights[rp]));
    maxVol = max(maxVol,currVol);
    heights[lp] < heights[rp] ? lp++ : rp--;
}
    return maxVol;
}
int main() {
  vector<int> heights = {1,8,6,2,5,4,8,3,7};
  cout << Mwater(heights) << endl;
   return 0;
}