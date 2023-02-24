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

const int N = 1e5 + 3;

int a[N];

struct Node {
    int l = 0, r = 0;
    long long val = 0, mx = 0;
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree() {}

    SegmentTree(int n) {
        s.resize(n * 4);
        build(1, 1, n);
    }

    void merge(int root) {
        s[root].val = s[root * 2].val + s[root * 2 + 1].val;
        s[root].mx = max(s[root * 2].mx, s[root * 2 + 1].mx);
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].val = a[l];
            s[root].mx = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R, int val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val = val;
            s[root].mx = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, val);
        if (R > m) update(root * 2 + 1, L, R, val);
        merge(root);
    }

    void update_mod(int root, int L, int R, int val) {
        if (s[root].mx < val) {
            return;
        }
        auto l = s[root].l, r = s[root].r;
        if (l == r) {
            s[root].mx %= val;
            s[root].val = s[root].mx;
            return;
        }
        int m = l + (r - l) / 2;
        if (L <= m) update_mod(root * 2, L, R, val);
        if (R > m) update_mod(root * 2 + 1, L, R, val);
        merge(root);
    }
    
    long long query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        long long ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans += query(root * 2, L, R);
        if (R > m) ans += query(root * 2 + 1, L, R);
        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    rep(i, n) cin >> a[i + 1];

    SegmentTree tree(n);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << tree.query(1, l, r) << endl;
        }
        else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update_mod(1, l, r, x);
        }
        else {
            int k, x; cin >> k >> x;
            tree.update(1, k, k, x);
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