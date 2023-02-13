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
    ll n, k; cin >> n >> k;

    vector<pair<ll, int>> p;
    for (ll x = 2; x * x <= n; x++) {
        if (n % x == 0) {
            int c = 0;
            while (n % x == 0) {
                n /= x;
                c++;
            }
            p.emplace_back(x, c);
        }
    }
    if (n > 1) p.emplace_back(n, 1);

    int ans = 1;
    for (auto& [x, c]: p) {
        vector<vi> f(k + 1, vi(c + 1, 0));
        f[0][c] = 1;
        rep(i, k) {
            rep(j, c + 1) {
                int cur = divide(f[i][j], j + 1);
                rep(t, j + 1) {
                    f[i + 1][t] = add(f[i + 1][t], cur);
                }
            }
        }

        int y = 1, cur = 0;
        rep(j, c + 1) {
            cur = add(cur, mul(y, f[k][j]));
            y = mul(y, (int)(x % MOD));
        }
        ans = mul(ans, cur);
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