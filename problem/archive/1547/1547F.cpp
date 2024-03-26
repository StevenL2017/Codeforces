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
    vector<int> g;

public:
    SegmentTree(int n) {
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
};

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    SegmentTree tree(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        tree.update(1, 1, 2 * n, i + 1, a[i % n]);
    }

    auto check = [&] (int x) -> bool {
        int target = tree.query(1, 1, 2 * n, 1, x + 1);
        for (int i = 0; i < n; i++) {
            int cur = tree.query(1, 1, 2 * n, i + 1, i + 1 + x);
            if (cur != target) return false;
        }
        return true;
    };

    int left = 0, right = n, ans = right;
    while (left <= right) {
        auto mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}