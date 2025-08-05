#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index (the highest value before rotation)
int findPivot(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] >= nums[0]) {
            // Pivot is on the right side
            start = mid + 1;
        } else {
            // Pivot is on the left side (including mid)
            end = mid;
        }
    }
    return start;
}

int main() {
    vector<int> nums = {7, 9, 1, 2, 3};
    int pivotIndex = findPivot(nums);
    cout << "Pivot index: " << pivotIndex << endl;
    return 0;
}
