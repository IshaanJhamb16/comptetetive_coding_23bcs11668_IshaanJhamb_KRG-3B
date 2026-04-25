#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long A = a, B = b;
        long long mod = 1e9 + 7;
        long long L = (A * B) / gcd(A, B);

        long long low = min(A, B);
        long long high = (long long)n * min(A, B);
        long long res = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = (mid / A) + (mid / B) - (mid / L);

            if (count >= n) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res % mod;
    }
};