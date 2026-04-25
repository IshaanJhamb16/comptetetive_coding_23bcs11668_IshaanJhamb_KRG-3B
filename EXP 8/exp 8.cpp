#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int sum_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum_b += b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(10001, -1e9));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int s = 0; s <= 100 * j; s++) {
                if (dp[j][s] < 0) continue;
                dp[j + 1][s + a[i]] = max(dp[j + 1][s + a[i]], dp[j][s] + b[i]);
            }
        }
    }

    cout << fixed << setprecision(10);
    for (int k = 1; k <= n; k++) {
        double max_v = 0;
        for (int s = 0; s <= 10000; s++) {
            if (dp[k][s] < 0) continue;
            double current = min((double)s, (dp[k][s] + (double)sum_b) / 2.0);
            max_v = max(max_v, current);
        }
        cout << max_v << (k == n ? "" : " ");
    }
    cout << endl;

    return 0;
}