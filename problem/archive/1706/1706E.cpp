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

class UnionFind {
private:
    int N;
    int *f;
    int *w;

public:
    UnionFind(int n) :
        N(n) {
        f = new int[N]();
        w = new int[N]();
        for (int i = 0; i < N; i++) {
            f[i] = -1;
            w[i] = INT_MAX;
        }
    }
    
    ~UnionFind() {
        delete[] f;
        delete[] w;
    }

    int find(int x) {
        return (f[x] < 0 ? x : find(f[x]));
    }

    bool merge(int x, int y, int weight) {
        int x_ = find(x), y_ = find(y);
        if (x_ == y_) return false;
        if (f[x_] > f[y_]) swap(x_, y_);
        f[x_] += f[y_];
        f[y_] = x_;
        w[y_] = weight;
        return true;
    }

    int weight(int x, int y) {
        int ans = 0;
        while (x != y) {
            if (w[x] < w[y]) {
                ans = w[x];
                x = f[x];
            } else {
                ans = w[y];
                y = f[y];
            }
        }
        return ans;
    }
};

class SegmentTree {
private:
    vector<int> mx;

public:
    SegmentTree(int n) {
        mx.resize(n * 4, -2e9);
    }
    
    void update(int root, int l, int r, int idx, int val) {
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
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        int ans = -2e9;
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
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind uf(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        uf.merge(u, v, i + 1);
    }

    vi weights(n - 1);
    rep(i, n - 1) {
        weights[i] = uf.weight(i, i + 1);
    }

    SegmentTree tree(n);
    rep(i, n - 1) {
        tree.update(1, 1, n, i + 1, weights[i]);
    }

    vi ans(q, 0);
    rep(i, q) {
        int l, r; cin >> l >> r;
        if (l == r) continue;
        ans[i] = tree.query(1, 1, n, l, r - 1);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}