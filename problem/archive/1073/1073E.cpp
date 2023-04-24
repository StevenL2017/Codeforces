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

const int MOD = 998244353;

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

int k;
const int N = 20;
const int M = 1 << 10;
pair<ll, int> f[N][M][2];

int calcdp(string s) {
    rep(i, N) {
        rep(j, M) {
            f[i][j][0] = f[i][j][1] = {0ll, 0};
        }
    }

    int n = ssz(s);
    f[0][0][1] = {1ll, 0};
    rep(i, n) {
        auto bound = s[i] - '0';
        rep(mask, M) {
            if (f[i][mask][0].first == 0 && f[i][mask][1].first == 0) continue;
            for (int j = (i == 0); j < 10; j++) {
                auto nmask = mask | (1 << j);
                auto cnt = f[i][mask][0].first;
                auto val = add(f[i][mask][0].second, mul(j, mul(binpow(10, n - 1 - i), cnt % MOD)));
                f[i + 1][nmask][0].first += cnt;
                f[i + 1][nmask][0].second = add(f[i + 1][nmask][0].second, val);
            }
            for (int j = (i == 0); j <= bound; j++) {
                auto nmask = mask | (1 << j);
                auto cnt = f[i][mask][1].first;
                auto val = add(f[i][mask][1].second, mul(j, mul(binpow(10, n - 1 - i), cnt % MOD)));
                f[i + 1][nmask][j == bound].first += cnt;
                f[i + 1][nmask][j == bound].second = add(f[i + 1][nmask][j == bound].second, val);
            }
        }
    }

    int ans = 0;
    rep(mask, M) {
        if (__builtin_popcount(mask) > k) continue;
        ans = add(ans, f[n][mask][0].second);
        ans = add(ans, f[n][mask][1].second);
    }
    return ans;
}

int calc(ll n) {
    int ans = 0;
    string s = to_string(n);
    repa(i, 1, ssz(s)) {
        ans = add(ans, calcdp(string(i, '9')));
    }
    ans = add(ans, calcdp(s));
    return ans;
}

void solve() {
    ll l, r; cin >> l >> r >> k;

    cout << sub(calc(r), calc(l - 1)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}