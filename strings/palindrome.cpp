#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool myIsAlnum(char ch) {
    if((ch >= 'a' && ch <= 'z') ||
       (ch >= 'A' && ch <= 'Z') ||
       (ch >= '1' && ch <= '9')) {
        return true;
    } else return false;
}

bool isPalindrome(const string &s) {
    int l = 0, r = s.length()-1;
    while(l < r) {
        if(!myIsAlnum(s[l])) {
            l++; 
            continue;
        }
        if(!myIsAlnum(s[r])) {
            r--; 
            continue;
        }
        if(tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main() {
    string str;
    getline(cin,str);
    cout << isPalindrome(str);
    return 0;
}