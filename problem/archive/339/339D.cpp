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
    int val = 0;
};

Node merge(const Node& u, const Node& v, const int& h) {
    Node p;
    if (h & 1) p.val = u.val | v.val;
    else p.val = u.val ^ v.val;
    return p;
}

class SegmentTree {
public:
    vector<Node> s;
    
    SegmentTree(int n) {
        s.resize(n * 4);
    }
    
    void update(int root, int l, int r, int idx, int val, int h) {
        if (l == r) {
            s[root].val = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val, h - 1);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val, h - 1);
        }
        s[root] = merge(s[root * 2], s[root * 2 + 1], h);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    SegmentTree tree(1 << n);
    rep(i, 1 << n) {
        int x; cin >> x;
        tree.update(1, 1, 1 << n, i + 1, x, n);
    }

    while (m--) {
        int p, b; cin >> p >> b;
        tree.update(1, 1, 1 << n, p, b, n);
        cout << tree.s[1].val << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}