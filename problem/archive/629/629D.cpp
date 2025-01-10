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

#define M_PI 3.14159265358979323846

class SegmentTree {
private:
    vector<ll> mx;

public:
    SegmentTree(int n) {
        mx.resize(n * 4, 0);
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
        if (L > R) return 0;
        if (L <= l && r <= R) {
            return mx[root];
        }
        ll ans = 0;
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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        int r, h;
        cin >> r >> h;
        a[i] = h * 1ll * r * r;
    }

    vector<ll> b = a;
    sort(b.begin(), b.end());
    SegmentTree tree(n);
    vector<ll> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
        if (i) f[i] = max(f[i], tree.query(1, 1, n, 1, lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + a[i]);
        tree.update(1, 1, n, lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1, f[i]);
    }

    long double ans = M_PI * *max_element(f.begin(), f.end());
    cout.precision(20);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}