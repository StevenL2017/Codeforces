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

const int N = 3e5 + 3;
const int M = 1e6 + 3;

int a[N], d[M];

struct Node {
    int l = 0, r = 0;
    long long val = 0, lazy = 0;
    int mx = 0;
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
    
    void update(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (l == r) {
            s[root].val = d[s[root].val];
            s[root].mx = d[s[root].mx];
            return;
        }
        if (L <= l && r <= R) {
            if (s[root].mx <= 2) {
                return;
            }
            update(root * 2, L, R);
            update(root * 2 + 1, L, R);
            merge(root);
            return;
        }
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R);
        if (R > m) update(root * 2 + 1, L, R);
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            d[j]++;
        }
    }

    SegmentTree tree(n);

    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            tree.update(1, l, r);
        } else {
            cout << tree.query(1, l, r) << endl;
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