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

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vi> f(m + 1, vi(n + 1, 0)), g(m + 1, vi(n + 1, 0));
    f[0][0] = g[0][n] = 1;
    rep(i, m) {
        repa(j, 1, n + 1) {
            rep(k, j + 1) {
                f[i + 1][j] = add(f[i + 1][j], f[i][k]);
            }
            repa(k, j, n + 1) {
                g[i + 1][j] = add(g[i + 1][j], g[i][k]);
            }
        }
    }

    int ans = 0;
    repa(i, 1, n + 1) {
        int a = f[m][i], b = 0;
        repa(j, i, n + 1) {
            b = add(b, g[m][j]);
        }
        ans = add(ans, mul(a, b));
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