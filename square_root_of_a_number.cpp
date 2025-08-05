#include <iostream>
using namespace std;

// Only integer part of square root
int squareRoot(int number) {
    int start = 0, end = number;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mid * mid == number) {
            return mid;
        } else if (mid * mid < number) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int num = 50;
    cout << "Square root (integer part) of " << num << " is " << squareRoot(num) << endl;
    return 0;
}
