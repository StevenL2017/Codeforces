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
const int K = 20;

int a[N];

struct Node {
    int l = 0, r = 0, lazy = 0, cnt[K];
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
            for (int i = 0; i < K; i++) {
                if (s[root].lazy >> i & 1) {
                    s[root * 2].cnt[i] = (m - l + 1) - s[root * 2].cnt[i];
                    s[root * 2 + 1].cnt[i] = (r - m) - s[root * 2 + 1].cnt[i];
                }
            }
            s[root * 2].lazy ^= s[root].lazy;
            s[root * 2 + 1].lazy ^= s[root].lazy;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        for (int i = 0; i < K; i++) {
            s[root].cnt[i] = s[root * 2].cnt[i] + s[root * 2 + 1].cnt[i];
        }
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            for (int i = 0; i < K; i++) {
                if (a[l] >> i & 1) {
                    s[root].cnt[i]++;
                }
            }
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
            for (int i = 0; i < K; i++) {
                if (val >> i & 1) {
                    s[root].cnt[i] = (r - l + 1) - s[root].cnt[i];
                }
            }
            s[root].lazy ^= val;
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
            long long cur = 0;
            for (int i = 0; i < K; i++) {
                cur += s[root].cnt[i] * 1ll * pow(2, i);
            }
            return cur;
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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree tree(n);

    int m; cin >> m;
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << tree.query(1, l, r) << endl;
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(1, l, r, x);
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