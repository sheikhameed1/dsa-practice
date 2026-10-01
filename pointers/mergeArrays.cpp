#include <iostream>
#include <vector>
using namespace std;

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // My approach (lengthy --> check all cases separately)
        int e1 = m-1, e2 = n-1;
        if(m==0) {
            while(e2>=0) {
                nums1[e2] = nums2[e2];
                e2--;
            } return;
        }
        if(n==0) return;
        for(int i = (m+n)-1; i >= 0; i--) {
            if(nums1[e1] > nums2[e2]) {
                nums1[i] = nums1[e1];
                e1--;
                if(e1 < 0) {
                    while(e2>=0) {
                        nums1[e2] = nums2[e2];
                        e2--, i--;
                    }
                }
            } else {
                nums1[i] = nums2[e2];
                e2--;
                if(e2 < 0) return;
            }
        }
    }

void merge2(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m+n-1, i = m-1, j = n-1;

    while(i >= 0 && j >= 0) {
        if(A[i] >= B[j]) {
            A[idx--]= A[i--];
        } else {
            A[idx--]=B[j--];
        }
    }

    while(j >= 0) {
        A[idx--] = B[j--];
    }
}
int main() {
    vector <int> nums1 = {1, 2, 3, 0, 0, 0};
    vector <int> nums2 = {2, 5, 6};

    merge2(nums1,3,nums2,3);

    for(int val : nums1) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}