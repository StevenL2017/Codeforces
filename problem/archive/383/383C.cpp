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

const int N = 2e5 + 3;

int a[N];

struct Node {
    int l = 0, r = 0;
    long long val = 0, lazy = 0;
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
        if (l != r && s[root].lazy) {
            auto m = l + (r - l) / 2;
            s[root * 2].val += s[root].lazy * (m - l + 1);
            s[root * 2].lazy += s[root].lazy;
            s[root * 2 + 1].val += s[root].lazy * (r - m);
            s[root * 2 + 1].lazy += s[root].lazy;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        s[root].val = s[root * 2].val + s[root * 2 + 1].val;
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

    void update(int root, int L, int R, int val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val += val * (r - l + 1);
            s[root].lazy += val;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, val);
        if (R > m) update(root * 2 + 1, L, R, val);
        merge(root);
    }

    long long query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        long long ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans += query(root * 2, L, R);
        if (R > m) ans += query(root * 2 + 1, L, R);
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi b(n); in(b);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int t = 0;
    vector<int> tin(n), tout(n), dep(n);
    function<void(int, int, int)> dfs = [&] (int node, int fa, int d) {
        dep[node] = d;
        tin[node] = ++t;
        for (auto& nxt: e[node]) {
            if (nxt == fa) continue;
            dfs(nxt, node, d ^ 1);
        }
        tout[node] = t;
    };
    dfs(0, -1, 0);

    vector<SegmentTree> tree(2, SegmentTree(t));
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int x, val;
            cin >> x >> val;
            x--;
            tree[dep[x]].update(1, tin[x], tout[x], val);
        } else {
            int x; cin >> x;
            x--;
            cout << b[x] + tree[dep[x]].query(1, tin[x], tin[x]) - tree[dep[x] ^ 1].query(1, tin[x], tin[x]) << endl;
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