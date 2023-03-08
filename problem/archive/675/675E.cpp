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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

class SegmentTree {
private:
    vector<long long> mn;

public:
    SegmentTree(int n) {
        mn.resize(n * 4, 1e18);
    }
    
    void update(int root, int l, int r, int idx, long long val) {
        if (l == r) {
            mn[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mn[root] = min(mn[root * 2], mn[root * 2 + 1]);
    }
    
    long long query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[root];
        }
        long long ans = 1e18;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = min(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n - 1); in(a);

    vector<pair<int, int>> b(n - 1);
    rep(i, n - 1) {
        b[i] = {a[i], i + 1};
    }
    sortd(b);

    vector<ll> f(n + 1, 0);
    SegmentTree tree(n);
    tree.update(1, 1, n, n, n);
    rep(k, n - 1) {
        int j = b[k].first, i = b[k].second;
        f[i] = tree.query(1, 1, n, i + 1, j) + n - i - j;
        tree.update(1, 1, n, i, f[i] + i);
    }

    ll ans = 0;
    repa(i, 1, n) {
        ans += f[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}