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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

vector<ll> f[61];

void precalc() {
    for (int i = 2; i < 61; i++) {
        ll x = 1ll;
        do {
            f[i].push_back(x);
            if (x > 2e18 / i) break;
            x = f[i].back() * i;
        } while (x <= 1e18);
    }
}

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

int mul(ll x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    ll l, r;
    cin >> l >> r;

    auto solve = [&] (ll n) -> int {
        int ans = 0;
        for (int i = 2; (1ll << i) <= n; i++) {
            auto left = 1ll << i;
            auto right = min((1ll << (i + 1)) - 1, n);
            int m = ssz(f[i]);
            for (int j = 0; j < m; j++) {
                if (f[i][j] > right) break;
                auto L = max(left, f[i][j]);
                auto R = min(right, (j == m - 1 ? LLONG_MAX : (f[i][j + 1] - 1)));
                if (L <= R) ans = add(ans, mul(R - L + 1, j));
            }
        }
        return ans;
    };

    cout << sub(solve(r), solve(l - 1)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}