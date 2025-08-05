// Peak Index in a Mountain Array using Binary Search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If the mid element is smaller than the next one,
            // peak lies on the right side
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            // Otherwise, the peak is at mid or to the left
            else {
                high = mid;
            }
        }

        // At the end of the loop, low == high and both point to the peak
        return low;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> mountainArr = {1, 3, 5, 7, 6, 4, 2};
    int peakIndex = sol.peakIndexInMountainArray(mountainArr);

    cout << "Peak index is: " << peakIndex << endl; // Should output 3

    return 0;
}
