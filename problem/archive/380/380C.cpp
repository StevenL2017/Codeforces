#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

struct Node {
    // a: max len of subseq, b: number of unused open, c: number of unused close
    int a = 0, b = 0, c = 0;
};

Node merge(const Node& u, const Node& v) {
    auto t = min(u.b, v.c);
    Node p;
    p.a = u.a + v.a + 2 * t;
    p.b = u.b + v.b - t;
    p.c = u.c + v.c - t;
    return p;
}

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree(int n) {
        s.resize(n * 4);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            // 0: open, 1: close
            if (val == 0) s[root].a = 0, s[root].b = 1, s[root].c = 0;
            else s[root].a = 0, s[root].b = 0, s[root].c = 1;
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
    string s; int m;
    cin >> s >> m;

    int n = ssz(s);
    SegmentTree tree(n);
    rep(i, n) {
        tree.update(1, 1, n, i + 1, s[i] == '(' ? 0 : 1);
    }

    while (m--) {
        int l, r; cin >> l >> r;
        cout << tree.query(1, 1, n, l, r).a << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}