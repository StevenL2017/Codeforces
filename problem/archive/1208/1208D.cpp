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

ll a[N];

struct Node {
    int l = 0, r = 0;
    long long val = LLONG_MAX, lazy = 0;
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
    
    void update(int root, int L, int R, ll val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val += val;
            s[root].lazy += val;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, val);
        if (R > m) update(root * 2 + 1, L, R, val);
        merge(root);
    }
    
    int query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (l == r) {
            return l;
        }
        push(root);
        int ans = -1;
        int m = l + (r - l) / 2;
        if (s[root * 2 + 1].val == 0) {
            ans = query(root * 2 + 1, L, R);
        } else {
            ans = query(root * 2, L, R);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi ans(n);
    SegmentTree tree(n);
    for (int i = 1; i <= n; i++) {
        int last = tree.query(1, 1, n);
        ans[last - 1] = i;
        tree.update(1, last, last, (ll)(1e11));
        tree.update(1, last + 1, n, -i);
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}