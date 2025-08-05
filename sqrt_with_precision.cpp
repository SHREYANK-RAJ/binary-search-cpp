#include <iostream>
using namespace std;

// Find square root using binary search + precision handling
double squareRoot(int number, int precision) {
    int start = 0, end = number;
    double ans = 0;

    // Integer part using binary search
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

    // Fractional part
    double step = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += step;
        }
        ans -= step;
        step /= 10;
    }

    return ans;
}

int main() {
    int num = 50;
    int precision = 3;
    cout << "Square root of " << num << " is " << squareRoot(num, precision) << endl;
    return 0;
}
