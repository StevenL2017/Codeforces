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
    int val1 = 0, val2 = 0, mn1 = 2e9, mn2 = 2e9, mx1 = -2e9, mx2 = -2e9;
};

class SegmentTree {
private:
    int n;
    vector<Node> s;

public:
    SegmentTree() {}

    SegmentTree(int n) {
        n = n;
        s.resize(n * 4);
        build(1, 1, n);
    }

    Node merge(const Node& u, const Node& v) {
        Node p;
        p.mn1 = min(u.mn1, v.mn1);
        p.mn2 = min(u.mn2, v.mn2);
        p.mx1 = max(u.mx1, v.mx1);
        p.mx2 = max(u.mx2, v.mx2);
        p.val1 = max({u.val1, v.val1, v.mx1 - u.mn1});
        p.val2 = max({u.val2, v.val2, u.mx2 - v.mn2});
        return p;
    }

    void build(int root, int l, int r) {
        if (l == r) {
            s[root].mn1 = a[l] - l;
            s[root].mx1 = a[l] - l;
            s[root].mn2 = a[l] - (n + 1 - l);
            s[root].mx2 = a[l] - (n + 1 - l);
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        s[root] = merge(s[root * 2], s[root * 2 + 1]);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            s[root].mn1 = val - idx;
            s[root].mx1 = val - idx;
            s[root].mn2 = val - (n + 1 - idx);
            s[root].mx2 = val - (n + 1 - idx);
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        s[root] = merge(s[root * 2], s[root * 2 + 1]);
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
        return merge(query(root * 2, l, m, L, R), query(root * 2 + 1, m + 1, r, L, R));
    }

    int query_all() {
        auto q = query(1, 1, n, 1, n);
        return max(q.val1, q.val2);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree tree(n);
    cout << tree.query_all() << endl;

    while (q--) {
        int p, x;
        cin >> p >> x;

        tree.update(1, 1, n, p, x);
        cout << tree.query_all() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}