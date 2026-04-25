#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

const ll MOD = 1e15 + 7;
const ll BASE = 5;

ll get_hash(const string& s) {
    ll h = 0;
    for (char c : s) {
        h = (h * BASE + (c - 'a' + 1));
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<ll> hashes;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hashes.insert(get_hash(s));
    }

    while (m--) {
        string s;
        cin >> s;
        ll current_hash = get_hash(s);
        bool found = false;

        ll power = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[i]) continue;

                ll next_hash = current_hash;
                next_hash = (next_hash - (ll)(s[i] - 'a' + 1) * power);
                next_hash = (next_hash + (ll)(c - 'a' + 1) * power);

                if (hashes.count(next_hash)) {
                    found = true;
                    break;
                }
            }
            if (found) break;
            power *= BASE;
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}