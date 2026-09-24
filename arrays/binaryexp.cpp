#include <iostream> 
using namespace std;

int main() {
    
    long binF;
    double x;
    double ans = 1;
    cin >> x >> binF;
     
    while(binF > 0) {
        if (binF % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binF /= 10;
    }
    cout << ans << endl;
    return 0;
}