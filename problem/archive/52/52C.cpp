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

// 区间更新-自定义结点
const int N = 2e5 + 3;

int a[N];

struct Node {
    int l = 0, r = 0;
    long long val = LLONG_MAX, lazy = 0;
};

// 范围为左闭右闭区间
class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree(int n) {
        s.resize(n * 4);
    }

    void push(int root) {
        for (int i = 0; i < 2; i++) {
            s[root * 2 + i].val += s[root].lazy;
            s[root * 2 + i].lazy += s[root].lazy;
        }
        s[root].lazy = 0;
        merge(root);
    }

    void merge(int root) {
        s[root].val = min(s[root * 2].val, s[root * 2 + 1].val);
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].val = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R, int delta) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val += delta;
            s[root].lazy += delta;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, delta);
        if (R > m) update(root * 2 + 1, L, R, delta);
        merge(root);
    }
    
    long long query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        long long ans = LLONG_MAX;
        int m = l + (r - l) / 2;
        if (L <= m) ans = min(ans, query(root * 2, L, R));
        if (R > m) ans = min(ans, query(root * 2 + 1, L, R));
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    rep(i, n) cin >> a[i + 1];
    SegmentTree tree(n);
    tree.build(1, 1, n);
    int m; cin >> m;
    while (m--) {
        int l, r, d, q = 0;
        cin >> l >> r;
        l++; r++;
        if (cin.get() != '\n') {
            cin >> d;
            q = 1;
        }
        if (q) {
            if (l <= r) {
                tree.update(1, l, r, d);
            } else {
                tree.update(1, l, n, d);
                tree.update(1, 1, r, d);
            }
        } else {
            if (l <= r) {
                cout << tree.query(1, l, r) << endl;
            } else {
                cout << min(tree.query(1, l, n), tree.query(1, 1, r)) << endl;
            }
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