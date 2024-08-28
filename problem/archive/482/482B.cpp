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

const int N = 1e5 + 3;

int a[N];

struct Node {
    int l = 0, r = 0, val = 0;
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
        s[root].val = s[root * 2].val & s[root * 2 + 1].val;
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
    
    int query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        int ans = -1;
        int m = l + (r - l) / 2;
        if (L <= m) ans &= query(root * 2, L, R);
        if (R > m) ans &= query(root * 2 + 1, L, R);
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> qs;
    vector<vi> pre(n + 2, vi(30));
    while (m--) {
        int l, r, q;
        cin >> l >> r >> q;
        qs.push_back({l, r, q});
        for (int i = 0; i < 30; i++) {
            if (q >> i & 1) {
                pre[l][i]++;
                pre[r + 1][i]--;
            }
        }
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            pre[j][i] += pre[j - 1][i];
            if (pre[j][i] > 0) {
                a[j] |= (1 << i);
            }
        }
    }

    SegmentTree tree(n);
    for (auto v: qs) {
        if (tree.query(1, v[0], v[1]) != v[2]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}