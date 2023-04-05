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

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}

void solve() {
    int n; cin >> n;
    vector<vi> e(n);
    vector<vi> d(n, vi(n, n));
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        d[u][v] = d[v][u] = 1;
    }

    rep(i, n) {
        d[i][i] = 0;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<vi> f(n + 1, vi(n + 1, 0));
    repa(i, 1, n + 1) {
        f[0][i] = 1;
    }
    repa(i, 1, n + 1) {
        repa(j, 1, n + 1) {
            f[i][j] = divide(add(f[i - 1][j], f[i][j - 1]), 2);
        }
    }

    int ans = 0;
    rep(u, n) {
        rep(v, u) {
            int cur = 0;
            rep(s, n) {
                if (d[s][u] + d[u][v] == d[s][v]) {
                    cur = add(cur, 1);
                }
                else if (d[s][v] + d[v][u] == d[s][u]) {
                    continue;
                }
                else {
                    auto c = d[s][u] + d[s][v] - d[u][v];
                    c /= 2;
                    auto a = d[s][u] - c;
                    auto b = d[s][v] - c;
                    cur = add(cur, f[a][b]);
                }
            }
            cur = divide(cur, n);
            ans = add(ans, cur);
        }
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