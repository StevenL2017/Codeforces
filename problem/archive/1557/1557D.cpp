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
    pair<int, int> val = {0, -1}, lazy = {0, -1};
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

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (l != r && s[root].lazy != make_pair(0, -1)) {
            auto m = l + (r - l) / 2;
            s[root * 2].val = max(s[root * 2].val, s[root].lazy);
            s[root * 2].lazy = s[root].lazy;
            s[root * 2 + 1].val = max(s[root * 2 + 1].val, s[root].lazy);
            s[root * 2 + 1].lazy = s[root].lazy;
            s[root].lazy = {0, -1};
        }
    }

    void merge(int root) {
        s[root].val = max(s[root * 2].val, s[root * 2 + 1].val);
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R, pair<int, int> val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val = val;
            s[root].lazy = val;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, val);
        if (R > m) update(root * 2 + 1, L, R, val);
        merge(root);
    }
    
    pair<int, int> query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        pair<int, int> ans = {0, -1};
        int m = l + (r - l) / 2;
        if (L <= m) ans = max(ans, query(root * 2, L, R));
        if (R > m) ans = max(ans, query(root * 2 + 1, L, R));
        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> seg(n);
    vector<int> x;
    rep(i, m) {
        int idx, l, r;
        cin >> idx >> l >> r;
        seg[idx - 1].emplace_back(l, r);
        x.push_back(l);
        x.push_back(r);
    }

    sorta(x);
    x.erase(unique(x.begin(), x.end()), x.end());
    rep(i, n) {
        for (auto& it: seg[i]) {
            it.first = upper_bound(x.begin(), x.end(), it.first) - x.begin();
            it.second = upper_bound(x.begin(), x.end(), it.second) - x.begin();
        }
    }

    SegmentTree tree(ssz(x));
    vi path(n, -1);
    rep(i, n) {
        pair<int, int> mx = {0, -1};
        for (auto& it: seg[i]) {
            mx = max(mx, tree.query(1, it.first, it.second));
        }
        path[i] = mx.second;
        for (auto& it: seg[i]) {
            tree.update(1, it.first, it.second, make_pair(mx.first + 1, i));
        }
    }

    pair<int, int> mx = tree.query(1, 1, ssz(x));
    vi vis(n, 0);
    int cur = mx.second;
    while (cur != -1) {
        vis[cur] = 1;
        cur = path[cur];
    }

    cout << n - mx.first << endl;
    rep(i, n) {
        if (!vis[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}