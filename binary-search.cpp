#include <iostream>
using namespace std;

/*
  My binary search on a sorted array.
  I shrink the search range by comparing target with middle.
  Using low + (high - low)/2 to avoid overflow.
  Returns index (0-based) if found, otherwise -1.
*/
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // safe middle

        if (arr[mid] == target) {
            return mid; // found it
        }

        if (target > arr[mid]) {
            // go right
            low = mid + 1;
        } else {
            // go left
            high = mid - 1;
        }
    }

    return -1; // not in array
}

int main() {
    // Example hardcoded test (just to show expected behavior)
    int even[6] = {2, 4, 6, 8, 12, 18};
    int idx = binarySearch(even, 6, 6);
    cout << "Example: Index of 6 in even[] is " << idx << " (should be 2)" << endl;

    // Interactive part so I can try other inputs myself
    int n;
    cout << "\nEnter size of sorted array: ";
    cin >> n;
    int arr[100]; // assuming n <= 100
    cout << "Enter " << n << " sorted numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << key << " found at index " << result << " (0-based)\n";
    else
        cout << key << " not present in array\n";

    return 0;
}
