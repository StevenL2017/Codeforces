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
    rep(i, n - 1) {
        int p; cin >> p;
        e[p - 1].push_back(i + 1);
        e[i + 1].push_back(p - 1);
    }

    vi sz(n, 1), zero(n, 0);
    function<void(int, int)> dfs1 = [&] (int u, int p) {
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs1(v, u);
            int temp = add((zero[v] ? 0 : sz[v]), 1);
            if (!temp) {
                zero[u]++;
                temp = 1;
            }
            sz[u] = mul(sz[u], temp);
        }
    };
    dfs1(0, -1);

    vi f(n, 0);
    function<void(int, int)> dfs2 = [&] (int u, int p) {
        f[u] = zero[u] ? 0 : sz[u];
        for (auto& v: e[u]) {
            if (v == p) continue;
            int temp = add((zero[v] ? 0 : sz[v]), 1);
            if (!temp) {
                zero[u]--;
                temp = 1;
            }
            sz[u] = divide(sz[u], temp);
            temp = add((zero[u] ? 0 : sz[u]), 1);
            if (!temp) {
                zero[v]++;
                temp = 1;
            }
            sz[v] = mul(sz[v], temp);
            dfs2(v, u);
            temp = add((zero[u] ? 0 : sz[u]), 1);
            if (!temp) {
                zero[v]--;
                temp = 1;
            }
            sz[v] = divide(sz[v], temp);
            temp = add((zero[v] ? 0 : sz[v]), 1);
            if (!temp) {
                zero[u]++;
                temp = 1;
            }
            sz[u] = mul(sz[u], temp);
        }
    };
    dfs2(0, -1);

    out(f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}