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

const int N = 2e5 + 3;

int a[N];

ll calc(int x) {
    return x * 1ll * (x + 1) / 2;
}

struct Node {
    ll val = 1; // answer in the middle (not in prefix or suffix)
    int pre = 0; // length of longest non-decreasing prefix
    int suf = 0; // length of longest non-decreasing suffix
    bool whole = true; // if whole segment is non-decreasing
    int len = 1; // length of the segment
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree(int n) {
        s.resize(n * 4);
    }

    Node merge(const Node& u, const Node& v, int l, int r) {
        Node p; p.len = u.len + v.len;
        int m = l + (r - l) / 2;
        if (u.whole && v.whole) {
            if (a[m] > a[m + 1]) {
                p.val = 0;
                p.pre = u.len;
                p.suf = v.len;
                p.whole = false;
            } else {
                p.val = calc(p.len);
                p.pre = 0;
                p.suf = 0;
                p.whole = true;
            }
        }
        else if (u.whole) {
            if (a[m] > a[m + 1]) {
                p.val = calc(v.pre) + v.val;
                p.pre = u.len;
                p.suf = v.suf;
                p.whole = false;
            } else {
                p.val = v.val;
                p.pre = u.len + v.pre;
                p.suf = v.suf;
                p.whole = false;
            }
        }
        else if (v.whole) {
            if (a[m] > a[m + 1]) {
                p.val = u.val + calc(u.suf);
                p.pre = u.pre;
                p.suf = v.len;
                p.whole = false;
            } else {
                p.val = u.val;
                p.pre = u.pre;
                p.suf = u.suf + v.len;
                p.whole = false;
            }
        }
        else {
            if (a[m] > a[m + 1]) {
                p.val = u.val + calc(u.suf) + calc(v.pre) + v.val;
                p.pre = u.pre;
                p.suf = v.suf;
                p.whole = false;
            } else {
                p.val = u.val + calc(u.suf + v.pre) + v.val;
                p.pre = u.pre;
                p.suf = v.suf;
                p.whole = false;
            }
        }
        return p;
    }

    void build(int root, int l, int r) {
        if (l == r) {
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        s[root] = merge(s[root * 2], s[root * 2 + 1], l, r);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        s[root] = merge(s[root * 2], s[root * 2 + 1], l, r);
    }
    
    Node query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return s[root];
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(root * 2, l, m, L, R);
        }
        if (L > m) {
            return query(root * 2 + 1, m + 1, r, L, R);
        }
        return merge(query(root * 2, l, m, L, R), query(root * 2 + 1, m + 1, r, L, R), l, r);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    rep(i, n) cin >> a[i + 1];
    SegmentTree tree(n);
    tree.build(1, 1, n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            a[x] = y;
            tree.update(1, 1, n, x, y);
        } else {
            int l, r; cin >> l >> r;
            auto node = tree.query(1, 1, n, l, r);
            cout << node.val + calc(node.pre) + calc(node.suf) << endl;
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