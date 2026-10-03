#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while(n>0) {
        count++;
        n /= 10;
    }
    return count;
}

int pow(int x, int n) {
    if(n < 0) {
        x = 1/x;
        n = -n;
    }
    int binF = n;
    int ans = 1;
    while(binF > 0) {
        int digit = binF%2;
        if(digit == 1) {
            ans *= x;
        }
        x *= x;
        binF /= 2;
    }
    return ans;
}

bool isArmstrong(int n) {
    int digits = countDigits(n);
    int armN = 0, orig = n;
    while(n>0) {
        int digit = n%10;
        armN += pow(digit,digits);
        n /= 10;
    }
    return armN == orig;
}

int main() {
    int n = 9754;
    cout << isArmstrong(n);
    return 0;
}
