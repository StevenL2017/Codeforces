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

struct Node {
    int l = 0, r = 0;
    int val0 = 0, val1 = 0, lazy = 0;
};

class SegmentTree {
private:
    vector<Node> s;
    vi a;
    string f;

public:
    SegmentTree() {}

    SegmentTree(int n, vi a_, string f_) {
        s.resize(n * 4);
        a = a_;
        f = f_;
        build(1, 1, n);
    }

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (l != r && s[root].lazy) {
            auto m = l + (r - l) / 2;
            swap(s[root * 2].val0, s[root * 2].val1);
            s[root * 2].lazy ^= 1;
            swap(s[root * 2 + 1].val0, s[root * 2 + 1].val1);
            s[root * 2 + 1].lazy ^= 1;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        s[root].val0 = s[root * 2].val0 ^ s[root * 2 + 1].val0;
        s[root].val1 = s[root * 2].val1 ^ s[root * 2 + 1].val1;
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            if (f[l - 1] == '0') s[root].val0 ^= a[l - 1];
            else s[root].val1 ^= a[l - 1];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            swap(s[root].val0, s[root].val1);
            s[root].lazy ^= 1;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R);
        if (R > m) update(root * 2 + 1, L, R);
        merge(root);
    }
    
    int query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val0;
        }
        push(root);
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans ^= query(root * 2, L, R);
        if (R > m) ans ^= query(root * 2 + 1, L, R);
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);
    string s;
    cin >> s;

    int xor_ = 0;
    for (auto x: a) {
        xor_ ^= x;
    }
    SegmentTree tree(n, a, s);

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            tree.update(1, l, r);
        } else {
            int g;
            cin >> g;
            if (g == 0) {
                cout << tree.query(1, 1, n) << " ";
            } else {
                cout << (tree.query(1, 1, n) ^ xor_) << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}