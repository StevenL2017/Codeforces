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

class SegmentTreeMax {
private:
    vector<ll> mx;

public:
    SegmentTreeMax(int n) {
        mx.resize(n * 4, -2e18);
    }
    
    void update(int root, int l, int r, int idx, ll val) {
        if (l == r) {
            mx[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mx[root] = max(mx[root * 2], mx[root * 2 + 1]);
    }
    
    ll query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        ll ans = -2e18;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = max(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

class SegmentTreeMin {
private:
    vector<ll> mn;

public:
    SegmentTreeMin(int n) {
        mn.resize(n * 4, 2e18);
    }
    
    void update(int root, int l, int r, int idx, ll val) {
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
    
    ll query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[root];
        }
        ll ans = 2e18;
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
    int n, q; cin >> n >> q;
    vi a(n), b(n); in(a); in(b);

    vi c(n);
    rep(i, n) {
        c[i] = b[i] - a[i];
    }

    SegmentTreeMax tree_mx(n + 1);
    SegmentTreeMin tree_mn(n + 1);
    tree_mx.update(1, 1, n + 1, 1, 0);
    tree_mn.update(1, 1, n + 1, 1, 0);
    vector<ll> pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i] + c[i];
        tree_mx.update(1, 1, n + 1, i + 2, pre[i + 1]);
        tree_mn.update(1, 1, n + 1, i + 2, pre[i + 1]);
    }

    while (q--) {
        int l, r; cin >> l >> r;

        if (pre[r] - pre[l - 1] != 0) {
            cout << -1 << endl;
            continue;
        }

        auto mn = tree_mn.query(1, 1, n + 1, l + 1, r + 1);
        if (mn - pre[l - 1] < 0) {
            cout << -1 << endl;
            continue;
        }

        auto mx = tree_mx.query(1, 1, n + 1, l + 1, r + 1);
        cout << mx - pre[l - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}