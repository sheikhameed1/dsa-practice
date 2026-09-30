// Book Allocation Problem

// There are N books, each ith book has A[i] number of pages.

// You have to allocate books to M number of students so that the maximum number of
// pages allocated to a student is minimum.

// . Each book should be allocated to a student.
// . Each student has to be allocated at least one book.
// . Allotment should be in contiguous order.

// Calculate and return that minimum possible number.

// Return -1 if a valid assignment is not possible.

#include <iostream>
#include <vector>
using namespace std;

int calculatetotalpages(vector <int> pages) {
    int sum = 0;
    for(int i = 0; i < pages.size(); i++) {
        sum += pages[i];
    }
    return sum;
}

bool isValid(vector <int> &pages, int n, int m, int mid) {
    int students = 1, load = 0;
    for(int i = 0; i < n; i++) {
        if(pages[i] > mid) return false; // if any book > cap (not possible)
        load += pages[i];
        if(load > mid) {
            students++;
            load = pages[i];  // give the current book to next student
        }
    }
    if(students > m) {
        return false;
    } else {
        return true;
    }
}

int allocateBooks(vector<int> &pages, int n, int m) {
    int s = 0, e = calculatetotalpages(pages);
    int ans = 0;
    if(m>n) return -1;
    while(s <= e) {
        int mid = s + (e-s)/2;            // Cap to check
        if(isValid(pages, n, m, mid)) {   // It returns if the cap is valid
            ans = mid;                    // and we store that answer and further check 
            e = mid - 1;                  // for a better answer
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> pages = {15, 17, 20};
    int n = 3, m = 2;

    cout << allocateBooks(pages, n, m) << endl;

    return 0;
}