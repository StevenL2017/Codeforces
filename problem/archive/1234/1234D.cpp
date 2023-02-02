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
    int val = 0;
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree(int n) {
        s.resize(n * 4);
    }

    Node merge(const Node& u, const Node& v) {
        Node p;
        p.val = u.val | v.val;
        return p;
    }

    void build(int root, int l, int r) {
        if (l == r) {
            s[root].val = 1 << a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        s[root] = merge(s[root * 2], s[root * 2 + 1]);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            s[root].val = 1 << val;
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
};

void solve() {
    string s; cin >> s;
    int q; cin >> q;

    int n = ssz(s);
    SegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        a[i + 1] = s[i] - 'a';
    }
    tree.build(1, 1, n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos; char c;
            cin >> pos >> c;

            tree.update(1, 1, n, pos, c - 'a');
        } else {
            int l, r; cin >> l >> r;

            cout << __builtin_popcount(tree.query(1, 1, n, l, r).val) << endl;
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