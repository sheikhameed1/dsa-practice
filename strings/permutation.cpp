#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    unordered_map <char,int> freq;
    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i]]++;
    }
    unordered_map <char,int> freqw;
    for(int i = 0; i < s1.length(); i++) {
        freqw[s2[i]]++;
    }
    if(freq == freqw) {
        return true;
    }
    for(int i = 1, j = s1.length();j < s2.length(); i++, j++) {
        freqw[s2[i-1]]--;
        if(freqw[s2[i-1]] == 0) {
            freqw.erase(s2[i-1]);
        }
        freqw[s2[j]]++;
        if(freq == freqw) {
                return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "rebgsfuibahfgh";
    cout << checkInclusion(s1,s2) << endl;
    return 0;
}