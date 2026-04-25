#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve_for_target(const vector<ll>& h, ll target) {
    ll ones = 0, twos = 0;
    for (ll x : h) {
        ll diff = target - x;
        twos += diff / 2;
        ones += diff % 2;
    }

    if (ones > twos) {
        return 2 * ones - 1;
    }

    ll low = 0, high = 2e18, res = 2e18;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_ones = (mid + 1) / 2;
        ll total_twos = mid / 2;

        if (total_ones >= ones && total_twos + (total_ones - ones) / 2 >= twos) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> h(n);
        ll max_h = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            max_h = max(max_h, h[i]);
        }

        cout << min(solve_for_target(h, max_h), solve_for_target(h, max_h + 1)) << "\n";
    }
    return 0;
}