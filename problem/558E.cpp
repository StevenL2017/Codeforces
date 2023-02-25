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

string a;

struct Node {
    int l = 0, r = 0;
    int val[26], lazy[26];
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

    void push(int root, int idx) {
        auto l = s[root].l, r = s[root].r;
        if (s[root].lazy[idx] != -1) {
            s[root].val[idx] = s[root].lazy[idx] * (r - l + 1);
            if (l != r) {
                s[root * 2].lazy[idx] = s[root].lazy[idx];
                s[root * 2 + 1].lazy[idx] = s[root].lazy[idx];
            }
            s[root].lazy[idx] = -1;
        }
    }

    void merge(int root, int idx) {
        s[root].val[idx] = s[root * 2].val[idx] + s[root * 2 + 1].val[idx];
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            for (int i = 0; i < 26; i++) {
                s[root].val[i] = 0;
                s[root].lazy[i] = -1;
            }
            s[root].val[a[l - 1] - 'a'] = 1;
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        for (int i = 0; i < 26; i++) {
            s[root].lazy[i] = -1;
            merge(root, i);
        }
    }
    
    void update(int root, int idx, int L, int R, int val) {
        push(root, idx);
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val[idx] = val * (r - l + 1);
            s[root].lazy[idx] = val;
            return;
        }
        if (L > r || R < l) return;
        update(root * 2, idx, L, R, val);
        update(root * 2 + 1, idx, L, R, val);
        merge(root, idx);
    }
    
    int query(int root, int idx, int L, int R) {
        push(root, idx);
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val[idx];
        }
        if (L > r || R < l) return 0;
        int ans = 0;
        ans += query(root * 2, idx, L, R);
        ans += query(root * 2 + 1, idx, L, R);
        return ans;
    }

    void get(int root, int idx, int L, int R) {
        push(root, idx);
        if (!s[root].val[idx]) return;
        auto l = s[root].l, r = s[root].r;
        if (l == r) {
            a[l - 1] = idx + 'a';
            return;
        }
        get(root * 2, idx, L, R);
        get(root * 2 + 1, idx, L, R);
    }
};

void solve() {
    int n, q;
    cin >> n >> q >> a;

    SegmentTree tree(n);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        vi cnt(26, 0);
        for (int idx = 0; idx < 26; idx++) {
            cnt[idx] = tree.query(1, idx, i, j);
        }
        int cur = (k ? i : j);
        for (int idx = 0; idx < 26; idx++) {
            if (!cnt[idx]) continue;
            tree.update(1, idx, i, j, 0);
            if (k) {
                tree.update(1, idx, cur, cur + cnt[idx] - 1, 1);
                cur += cnt[idx];
            } else {
                tree.update(1, idx, cur - cnt[idx] + 1, cur, 1);
                cur -= cnt[idx];
            }
        }
    }

    for (int idx = 0; idx < 26; idx++) {
        tree.get(1, idx, 1, n);
    }

    cout << a << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}