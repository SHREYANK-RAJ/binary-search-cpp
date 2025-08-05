class Solution {
public:
    // Helper function to find the square root using binary search
    int binarySqrt(int num) {
        long long low = 0, high = num;
        long long mid, result = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            long long square = mid * mid;

            if (square == num) {
                return mid; // Found exact square root
            }

            if (square < num) {
                result = mid; // Store as possible answer and search right
                low = mid + 1;
            } else {
                high = mid - 1; // Search in left half
            }
        }

        return result; // Return integer part of sqrt
    }

    int mySqrt(int x) {
        return binarySqrt(x);
    }
};
