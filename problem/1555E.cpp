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

struct Seg {
    int l, r, w;
};

struct Node {
    int val = 0, lazy = 0;
};

// 范围为左闭右闭区间
class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree(int n) {
        s.resize(n * 4);
    }

    void push(int root) {
        for (int i = 0; i < 2 && root * 2 + i < ssz(s); i++) {
            s[root * 2 + i].lazy += s[root].lazy;
        }
        s[root].val += s[root].lazy;
        s[root].lazy = 0;
    }

    void merge(int root) {
        s[root].val = min(s[root * 2].val, s[root * 2 + 1].val);
    }
    
    void update(int root, int l, int r, int L, int R, int delta) {
        push(root);
        if (L >= R) return;
        if (L == l && r == R) {
            s[root].lazy += delta;
            push(root);
            return;
        }
        int m = l + (r - l) / 2;
        update(root * 2, l, m, L, min(m, R), delta);
        update(root * 2 + 1, m, r, max(m, L), R, delta);
        merge(root);
    }

    int query() {
        return s[1].val + s[1].lazy;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Seg> a(n);
    rep(i, n) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }

    sort(a.begin(), a.end(), [&] (const Seg& x, const Seg& y) { return x.w < y.w; });
    SegmentTree tree(m);
    int ans = INT_MAX;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && tree.query() == 0) {
            tree.update(1, 1, m, a[j].l, a[j].r, 1);
            j++;
        }
        if (tree.query() == 0) {
            break;
        }
        ans = min(ans, a[j - 1].w - a[i].w);
        tree.update(1, 1, m, a[i].l, a[i].r, -1);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}