#include <iostream> 
using namespace std;

double myPow(double x, int n) {
      double result = 1.0;
      long long binF = n;
        if(n<0) {
            x = 1/x;
            binF = -binF;
        }
        while(binF != 0) {
            int num = binF % 2;
            if(num == 1) {
                result *= x;
            }
            x = x*x;
            binF /= 2;
        }
        return result;
}
int main() {
    cout << myPow(2.0,10);
    return 0;
}