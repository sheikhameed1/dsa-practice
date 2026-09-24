#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int> prices) {
        //Brute force
    // int maxProf = 0;
    // int currProf = 0; 
    // int n = prices.size();
    // for (int i = 0; i < n - 1; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //          currProf = prices[j] - prices[i];
    //          maxProf = max(maxProf,currProf);
    //     }
    // }
    // return maxProf; 
       // Optimal approach
       int bestBuy = prices[0];
       int maxPrf = 0;
       for(int i = 1; i < prices.size(); i++) { 
        if (prices[i] > bestBuy) {            // Kya aaj profit nikal sakta hai
            maxPrf = max(maxPrf,prices[i] - bestBuy);
        }
          bestBuy = min(bestBuy,prices[i]); // Kya aaj ka din bestBuy ban sakta hai
       } 
       return maxPrf;
}
int main() {
     vector<int> prices = {7,1,5,3,6,4};
     cout << maxProfit(prices) << endl;
    return 0;
}