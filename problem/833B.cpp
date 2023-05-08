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

class SegmentTree {
private:
    vector<int> mx;

public:
    SegmentTree(int n) {
        mx.resize(n * 4, -2e9);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            mx[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mx[root] = max(mx[root * 2], mx[root * 2 + 1]);
    }
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        int ans = -2e9;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = max(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    vector<vi> f(n, vi(k + 1, -2e9));
    f[0][1] = 1;

    vector<SegmentTree> trees(k + 1, SegmentTree(n));
    trees[1].update(1, 1, n, 1, 1);

    vi last(n + 1, -1);
    last[a[0]] = 0;

    repa(i, 1, n) {
        repa(j, 1, k + 1) {
            int mx1 = -2e9, mx2 = -2e9;
            if (j > 1) {
                if (last[a[i]] >= 1) mx1 = trees[j - 1].query(1, 1, n, 1, last[a[i]]);
                if (last[a[i]] >= 0) mx2 = trees[j - 1].query(1, 1, n, last[a[i]] + 1, i) + 1;
                else mx2 = f[i - 1][j] + 1;
            } else {
                mx2 = f[i - 1][j] + (int)(last[a[i]] < 0);
            }
            if (mx1 > -2e9) f[i][j] = max(f[i][j], mx1);
            if (mx2 > -2e9) f[i][j] = max(f[i][j], mx2);
            trees[j].update(1, 1, n, i + 1, f[i][j]);

            if (j < k) {
                f[i][j + 1] = max(f[i][j + 1], f[i][j] + 1);
                trees[j + 1].update(1, 1, n, i + 1, f[i][j + 1]);
            }
        }
        last[a[i]] = i;
    }

    cout << f[n - 1][k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}