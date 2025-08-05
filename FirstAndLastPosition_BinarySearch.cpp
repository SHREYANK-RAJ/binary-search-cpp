#include <bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of a key using binary search
int findFirstOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  // keep checking towards the left
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Function to find the last occurrence of a key using binary search
int findLastOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;  // keep checking towards the right
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Function that returns the first and last position of a given element
pair<int, int> findFirstAndLastPosition(vector<int>& arr, int key) {
    int first = findFirstOccurrence(arr, key);
    int
