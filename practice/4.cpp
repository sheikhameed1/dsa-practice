#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums) {

    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

void selectionSort(vector<int>& nums) {

    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        int smallest = i;
        for(int j = i+1; j < n; j++) {
            if(nums[j] < nums[smallest]) smallest = j;
        }
        swap(nums[i],nums[smallest]);
    }
}

void insertionSort(vector<int>& nums) {

    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        int temp = nums[i+1];
        int pvt = i;
        while(nums[pvt] > temp && pvt >= 0) {
            nums[pvt] = nums[pvt+1];
            pvt--;
        }
        pvt++;
        nums[pvt] = temp;
    }
}

void merge(vector<int>& nums, int st, int mid, int end) {

    vector<int> temp;

    int i = st, j = mid+1;
    while(i <= mid && j <= end) {
        if(nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while(j <= end) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++) {
        nums[st+i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int st, int end) {

    if(st < end) {

        int mid = st + (end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums,mid+1,end);

        // Merge
        merge(nums,st,mid,end);
    }
}

int partition(vector<int>& nums, int st, int end) {

    int idx = st;
    for(int j = st; j <= end; j++) {
        if(nums[j] <= nums[end]) {
            swap(nums[idx],nums[j]);
            idx++;
        }
    }
    return --idx;
}

void quickSort(vector<int>& nums, int st, int end) {

    if(st < end) {

        int pindex = partition(nums,st,end);

        quickSort(nums,st,pindex-1);
        quickSort(nums,pindex+1,end);
    }
}

int main() {

    vector<int> nums = {34,76,5,3,12,8,67,6};
    quickSort(nums,0,nums.size()-1);
    
    for(int& val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}