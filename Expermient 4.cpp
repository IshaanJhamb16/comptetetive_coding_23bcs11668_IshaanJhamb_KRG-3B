#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return (a * b) / gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll L = min(a, b);
        ll R = (ll)n * min(a, b);
        ll common = lcm(a, b);
        ll ans = L;
        ll mod = 1e9 + 7;

        while (L <= R) {
            ll mid = L + (R - L) / 2;
            ll count = (mid / a) + (mid / b) - (mid / common);

            if (count >= n) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return ans % mod;
    }
};