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

struct Node {
    int l = 0, r = 0;
    int val = 0, lazy = 0;
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree() {}

    SegmentTree(int n, vi& dp) {
        s.resize(n * 4);
        build(1, 1, n, dp);
    }

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (l != r && s[root].lazy != 0) {
            auto m = l + (r - l) / 2;
            s[root * 2].val += s[root].lazy;
            s[root * 2].lazy += s[root].lazy;
            s[root * 2 + 1].val += s[root].lazy;
            s[root * 2 + 1].lazy += s[root].lazy;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        s[root].val = max(s[root * 2].val, s[root * 2 + 1].val);
    }

    void build(int root, int l, int r, vi& dp) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].val = dp[l - 1];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m, dp);
        build(root * 2 + 1, m + 1, r, dp);
        merge(root);
    }
    
    void update(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val += 1;
            s[root].lazy += 1;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R);
        if (R > m) update(root * 2 + 1, L, R);
        merge(root);
    }
    
    int query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans = max(ans, query(root * 2, L, R));
        if (R > m) ans = max(ans, query(root * 2 + 1, L, R));
        return ans;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    vi last(n + 1, -1), p(n, -1);
    rep(i, n) {
        if (last[a[i]] != -1) {
            p[i] = last[a[i]];
        } else {
            p[i] = 0;
        }
        last[a[i]] = i;
    }

    vector<vi> f(k + 1, vi(n, 0));
    set<int> s;
    rep(i, n) {
        s.insert(a[i]);
        f[1][i] = ssz(s);
    }
    auto calc = [&] (int j) {
        SegmentTree tree(n, f[j - 1]);
        rep(i, n) {
            if (p[i] < i) {
                tree.update(1, p[i] + 1, i);
            }
            f[j][i] = max(f[j - 1][i], tree.query(1, 1, i));
        }
    };
    repa(j, 2, k + 1) {
        calc(j);
    }

    cout << f[k][n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}