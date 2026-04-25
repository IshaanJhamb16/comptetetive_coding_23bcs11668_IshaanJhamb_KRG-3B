#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    // Faster I/O for large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

   
    vector<pair<ll, int>> events;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

   
    sort(events.begin(), events.end());

   
    vector<ll> ans(n + 1, 0);
    
    int current_coverage = 0;
    for (int i = 0; i < events.size() - 1; i++) {
        current_coverage += events[i].second;
        
       
        ll segment_length = events[i+1].first - events[i].first;
        
        if (current_coverage >= 1 && current_coverage <= n) {
            ans[current_coverage] += segment_length;
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << (k == n ? "" : " ");
    }
    cout << endl;

    return 0;
}