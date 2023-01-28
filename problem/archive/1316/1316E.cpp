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

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vi a(n); in(a);
    vector<vi> s(n, vi(p));
    rep(i, n) in(s[i]);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] > a[j]; });

    int m = 1 << p;
    vector<vector<ll>> f(n + 1, vector<ll>(m, -1));
    f[0][0] = 0;
    rep(i, n) {
        int j = idx[i];
        rep(mask, m) {
            rep(x, p) {
                if ((mask >> x & 1) && f[i][mask ^ (1 << x)] != -1) {
                    f[i + 1][mask] = max(f[i + 1][mask], f[i][mask ^ (1 << x)] + s[j][x]);
                }
            }
            if (f[i][mask] == -1) continue;
            if (i - __builtin_popcount(mask) < k) {
                f[i + 1][mask] = max(f[i + 1][mask], f[i][mask] + a[j]);
            } else {
                f[i + 1][mask] = max(f[i + 1][mask], f[i][mask]);
            }
        }
    }

    cout << f[n][m - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}