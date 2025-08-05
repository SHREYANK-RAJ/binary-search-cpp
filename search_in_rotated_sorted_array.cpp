#include <iostream>
#include <vector>
using namespace std;

// Function to find pivot (index of smallest element)
int findPivot(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;

    while (s < e) {
        int m = s + (e - s) / 2;
        if (arr[m] >= arr[0]) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return s;
}

// Normal binary search
int binarySearch(vector<int>& arr, int s, int e, int key) {
    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == key) return m;
        else if (arr[m] < key) s = m + 1;
        else e = m - 1;
    }
    return -1;
}

// Search in rotated sorted array
int search(vector<int>& arr, int key) {
    int pivot = findPivot(arr);

    if (key >= arr[pivot] && key <= arr[arr.size()-1]) {
        return binarySearch(arr, pivot, arr.size()-1, key);
    } else {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main() {
    vector<int> arr = {7, 9, 1, 2, 3};
    int key = 2;
    int index = search(arr, key);
    cout << "Element found at index: " << index << endl;
    return 0;
}
