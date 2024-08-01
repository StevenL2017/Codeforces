#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

class SegmentTree {
private:
    int n_;
    vector<int> g;

public:
    SegmentTree(int n) {
        n_ = n;
        g.resize(n * 4, 0);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            g[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        g[root] = gcd(g[root * 2], g[root * 2 + 1]);
    }
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return g[root];
        }
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = gcd(ans, query(root * 2, l, m, L, R));
        }
        if (R > m) {
            ans = gcd(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }

    int query_cnt(int root, int l, int r, int L, int R, int x) {
        if (L <= l && r <= R) {
            if (g[root] % x == 0) return 0;
            while (root * 2 + 1 < n_ * 4) {
                if (g[root * 2] % x != 0) {
                    if (g[root * 2 + 1] % x != 0) {
                        return 2;
                    }
                    root = root * 2;
                } else {
                    root = root * 2 + 1;
                }
            }
            return 1;
        }
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans += query_cnt(root * 2, l, m, L, R, x);
            if (ans > 1) return ans;
        }
        if (R > m) {
            ans += query_cnt(root * 2 + 1, m + 1, r, L, R, x);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    SegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        tree.update(1, 1, n, i + 1, a[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            int c = tree.query_cnt(1, 1, n, l, r, x);
            if (c > 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            int i, y;
            cin >> i >> y;
            tree.update(1, 1, n, i, y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}