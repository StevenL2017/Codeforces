#include <iostream>
#include <cstdio>
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
#include <random>

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
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

class SegmentTree {
private:
    vector<int> g;

public:
    SegmentTree(int n) {
        g.resize(n * 4);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            g[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        g[root] = gcd(g[root * 2], g[root * 2 + 1]);
    }
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return g[root];
        }
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = gcd(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    SegmentTree tree(n);
    map<int, vi> idx;
    rep(i, n) {
        int s; cin >> s;
        tree.update(1, 1, n, i + 1, s);
        idx[s].push_back(i + 1);
    }

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        auto g = tree.query(1, 1, n, l, r);
        auto left = lower_bound(idx[g].begin() ,idx[g].end(), l) - idx[g].begin();
        auto right = upper_bound(idx[g].begin() ,idx[g].end(), r) - idx[g].begin();

        cout << r - l + 1 - (right - left) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}