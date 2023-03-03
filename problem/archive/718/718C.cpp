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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;
const int N = 2;

struct Matrix {
    long long a[N + 1][N + 1];

    void init() { memset(a, 0, sizeof(a)); }

    // i k j could be faster than i j k
    Matrix operator*(const Matrix& b) const {
        Matrix res;
        res.init();
        for (int i = 1; i <= N; ++i)
            for (int k = 1; k <= N; ++k)
                for (int j = 1; j <= N; ++j)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return res;
    }

    Matrix operator+(const Matrix& b) const {
        Matrix res;
        res.init();
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                res.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
        return res;
    }
};

// n is count of matrix multiplications
Matrix qpow(long long n) {
    Matrix ans, base;
    ans.init();
    base.init();
    ans.a[1][1] = ans.a[2][2] = 1;
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans;
}

int a[MAXN];

struct Node {
    int l = 0, r = 0;
    Matrix val, lazy;
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
        if (l != r) {
            s[root * 2].val = s[root * 2].val * s[root].lazy;
            s[root * 2].lazy = s[root * 2].lazy * s[root].lazy;
            s[root * 2 + 1].val = s[root * 2 + 1].val * s[root].lazy;
            s[root * 2 + 1].lazy = s[root * 2 + 1].lazy * s[root].lazy;
            s[root].lazy.init();
            s[root].lazy.a[1][1] = s[root].lazy.a[2][2] = 1;
        }
    }

    void merge(int root) {
        s[root].val = s[root * 2].val + s[root * 2 + 1].val;
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        s[root].lazy.init();
        s[root].lazy.a[1][1] = s[root].lazy.a[2][2] = 1;
        if (l == r) {
            s[root].val = qpow(a[l]);
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R, Matrix val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val = s[root].val * val;
            s[root].lazy = s[root].lazy * val;
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
            return s[root].val.a[1][2];
        }
        push(root);
        long long ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans += query(root * 2, L, R);
        ans %= MOD;
        if (R > m) ans += query(root * 2 + 1, L, R);
        ans %= MOD;
        return ans;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    rep(i, n) cin >> a[i + 1];

    SegmentTree tree(n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(1, l, r, qpow(x));
        } else {
            int l, r;
            cin >> l >> r;
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