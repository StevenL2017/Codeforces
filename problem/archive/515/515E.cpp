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

int n, m;
ll d[N], h[N];

struct Node {
    int l = 0, r = 0;
    long long val = LLONG_MIN, left = LLONG_MIN, right = LLONG_MIN;
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
        s[root].left = max(s[root * 2].left, s[root * 2 + 1].left);
        s[root].right = max(s[root * 2].right, s[root * 2 + 1].right);
        s[root].val = max({s[root * 2].left + s[root * 2 + 1].right, s[root * 2].val, s[root * 2 + 1].val});
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].left = 2 * h[l] - d[l - 1];
            s[root].right = 2 * h[l] + d[l - 1];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    Node query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root];
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(root * 2, L, R);
        }
        else if (L > m) {
            return query(root * 2 + 1, L, R);
        }
        else {
            auto left = query(root * 2, L, R);
            auto right = query(root * 2 + 1, L, R);
            Node res;
            res.left = max(left.left, right.left);
            res.right = max(left.right, right.right);
            res.val = max({left.left + right.right, left.val, right.val});
            return res;
        }
    }
};

void solve() {
    cin >> n >> m;
    repa(i, 1, n + 1) cin >> d[i];
    repa(i, 1, n + 1) cin >> h[i];
    repa(i, 1, n + 1) {
        d[i + n] = d[i];
        h[i + n] = h[i];
    }
    repa(i, 1, 2 * n + 1) d[i] += d[i - 1];

    SegmentTree tree(2 * n);

    while (m--) {
        int l, r; cin >> l >> r;

        if (l <= r) {
            cout << tree.query(1, r + 1, l - 1 + n).val << endl;
        } else {
            cout << tree.query(1, r + 1, l - 1).val << endl;
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