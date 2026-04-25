#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n, k, a[MAXN];
vector<int> pos[MAXN];
int b[MAXN];

struct Node {
    int count;
    int left, right;
} tree[MAXN * 40];

int roots[MAXN], node_count = 0;

int update(int prev_node, int l, int r, int val) {
    int curr = ++node_count;
    tree[curr] = tree[prev_node];
    tree[curr].count++;
    if (l == r) return curr;
    int mid = l + (r - l) / 2;
    if (val <= mid) tree[curr].left = update(tree[prev_node].left, l, mid, val);
    else tree[curr].right = update(tree[prev_node].right, mid + 1, r, val);
    return curr;
}

int query(int L_node, int R_node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[R_node].count - tree[L_node].count;
    int mid = l + (r - l) / 2;
    int res = 0;
    if (ql <= mid) res += query(tree[L_node].left, tree[R_node].left, l, mid, ql, qr);
    if (qr > mid) res += query(tree[L_node].right, tree[R_node].right, mid + 1, r, ql, qr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        int sz = pos[a[i]].size();
        if (sz > k) b[i] = pos[a[i]][sz - k - 1];
        else b[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        roots[i] = update(roots[i - 1], 0, n, b[i]);
    }

    int q, last_ans = 0;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = (x + last_ans) % n + 1;
        int r = (y + last_ans) % n + 1;
        if (l > r) swap(l, r);
        
        last_ans = query(roots[l - 1], roots[r], 0, n, 0, l - 1);
        cout << last_ans << "\n";
    }

    return 0;
}