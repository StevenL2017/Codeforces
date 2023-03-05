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
const int MAXN = 1e2 + 3;

int factorial[MAXN];

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

int inverse[MAXN];

void get_inverse() {
    inverse[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        inverse[i] = inv(i);
    }
}

int comb(long long n, int k) {
    if (k > n) return 0;
    if (n - k < k) k = n - k;
    n %= MOD;
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans = mul(ans, n - i);
        ans = mul(ans, inverse[i + 1]);
    } 
    return ans;
}

void solve() {
    int n; ll s;
    cin >> n >> s;
    vector<ll> f(n); in(f);

    get_inverse();
    int ans = 0;
    rep(mask, 1 << n) {
        ll x = s;
        int tot = 0;
        rep(i, n) {
            if (mask >> i & 1) {
                x -= (f[i] + 1);
                tot++;
            }
        }
        if (x < 0) continue;
        auto cur = comb(x + n - 1, n - 1);
        if (tot & 1) cur = -cur;
        ans = add(ans, cur);
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